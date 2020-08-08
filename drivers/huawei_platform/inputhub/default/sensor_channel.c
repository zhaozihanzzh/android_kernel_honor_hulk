/*
 * drivers/inputhub/sensor_channel.c
 *
 * Sensor Hub Channel driver
 *
 * Copyright (c) 2012-2019 Huawei Technologies Co., Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/delay.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <huawei_platform/inputhub/sensorhub.h>
#include "contexthub_route.h"
#include "contexthub_boot.h"
#include "sensor_config.h"
#include "sensor_detect.h"

int first_start_flag;
int ps_first_start_flag;
int sensor_ps_flag;
int sensor_tof_flag;
int apds9253_006_ps_flag;
int als_first_start_flag;
int als_under_tp_first_start_flag;
int gyro_first_start_flag;
int handpress_first_start_flag;
int rohm_rgb_flag;
int avago_rgb_flag;
int is_cali_supported;
int ps_cali_supported;
int  ams_tmd3725_rgb_flag;
int  liteon_ltr582_rgb_flag;
int ltr578_flag;
int apds9922_flag;
int rpr531_flag;
int tmd2745_flag;
int apds9999_rgb_flag;
int  ams_tmd3702_rgb_flag;
int ams_tcs3707_rgb_flag;
int apds9253_rgb_flag;
int vishay_vcnl36658_als_flag;
int vishay_vcnl36832_als_flag;
int stk3338_als_flag;
int ltr2568_als_flag;
int ltr311_als_flag;
int stk3638_als_flag;
int stk32670_als_flag;
int stk32671_als_flag;
int ltr2594_als_flag;
int tsl2591_flag;
int bh1726_flag;
int ams_tcs3701_rgb_flag;
int vd6281_als_flag;
int veml32185_als_flag;
int acc1_first_start_flag;
int gyro1_first_start_flag;

extern char sensor_chip_info[SENSOR_MAX][MAX_CHIP_INFO_LEN];
extern t_ap_sensor_ops_record all_ap_sensor_operations[TAG_SENSOR_END];
extern int flag_for_sensor_test;
extern struct mutex mutex_vibrator;

static bool sensor_switch_flags[TAG_SENSOR_END] = {false,};
uint8_t tag_to_hal_sensor_type[TAG_SENSOR_END];
static uint8_t hal_sensor_type_to_tag[SENSORHUB_TYPE_END];
static DEFINE_MUTEX(mutex_status);

struct sensors_cmd_map {
	int hal_sensor_type;
	int tag;
};

static const struct sensors_cmd_map sensors_cmd_map_tab[] = {
	{ SENSORHUB_TYPE_ACCELEROMETER, TAG_ACCEL },
	{ SENSORHUB_TYPE_LIGHT, TAG_ALS },
	{ SENSORHUB_TYPE_PROXIMITY, TAG_PS },
	{ SENSORHUB_TYPE_GYROSCOPE, TAG_GYRO },
	{ SENSORHUB_TYPE_GRAVITY, TAG_GRAVITY },
	{ SENSORHUB_TYPE_MAGNETIC, TAG_MAG },
	{ SENSORHUB_TYPE_LINEARACCELERATE, TAG_LINEAR_ACCEL },
	{ SENSORHUB_TYPE_ORIENTATION, TAG_ORIENTATION },
	{ SENSORHUB_TYPE_ROTATEVECTOR, TAG_ROTATION_VECTORS },
	{ SENSORHUB_TYPE_PRESSURE, TAG_PRESSURE },
	{ SENSORHUB_TYPE_HALL, TAG_HALL },
	{ SENSORHUB_TYPE_MAGNETIC_FIELD_UNCALIBRATED, TAG_MAG_UNCALIBRATED },
	{ SENSORHUB_TYPE_GAME_ROTATION_VECTOR, TAG_GAME_RV },
	{ SENSORHUB_TYPE_GYROSCOPE_UNCALIBRATED, TAG_GYRO_UNCALIBRATED },
	{ SENSORHUB_TYPE_SIGNIFICANT_MOTION, TAG_SIGNIFICANT_MOTION },
	{ SENSORHUB_TYPE_STEP_DETECTOR, TAG_STEP_DETECTOR },
	{ SENSORHUB_TYPE_STEP_COUNTER, TAG_STEP_COUNTER },
	{ SENSORHUB_TYPE_GEOMAGNETIC_ROTATION_VECTOR, TAG_GEOMAGNETIC_RV },
	{ SENSORHUB_TYPE_HANDPRESS, TAG_HANDPRESS },
	{ SENSORHUB_TYPE_CAP_PROX, TAG_CAP_PROX },
	{ SENSORHUB_TYPE_PHONECALL, TAG_PHONECALL },
	{ SENSORHUB_TYPE_MAGN_BRACKET, TAG_MAGN_BRACKET },
	{ SENSORHUB_TYPE_TILT_DETECTOR, TAG_TILT_DETECTOR },
	{ SENSORHUB_TYPE_META_DATA, TAG_FLUSH_META },
	{ SENSORHUB_TYPE_RPC, TAG_RPC },
	{ SENSORHUB_TYPE_AGT, TAG_AGT },
	{ SENSORHUB_TYPE_COLOR, TAG_COLOR },
	{ SENSORHUB_TYPE_ACCELEROMETER_UNCALIBRATED, TAG_ACCEL_UNCALIBRATED },
	{ SENSORHUB_TYPE_TOF, TAG_TOF },
	{ SENSORHUB_TYPE_DROP, TAG_DROP },
	{ SENSORHUB_TYPE_POSTURE, TAG_POSTURE },
	{ SENSORHUB_TYPE_EXT_HALL, TAG_EXT_HALL },
	{ SENSORHUB_TYPE_ACCELEROMETER1, TAG_ACC1 },
	{ SENSORHUB_TYPE_GYROSCOPE1, TAG_GYRO1 },
	{ SENSORHUB_TYPE_ACCELEROMETER2, TAG_ACC2 },
	{ SENSORHUB_TYPE_LIGHT1, TAG_ALS1 },
	{ SENSORHUB_TYPE_PROXIMITY1, TAG_PS1 },
	{ SENSORHUB_TYPE_MAGNETIC1, TAG_MAG1 },
	{ SENSORHUB_TYPE_CAP_PROX1, TAG_CAP_PROX1 },
	{ SENSORHUB_TYPE_THERMOMETER, TAG_THERMOMETER },
};

static void init_hash_tables(void)
{
	int i;

	for (i = 0; i < sizeof(sensors_cmd_map_tab) / sizeof(sensors_cmd_map_tab[0]); ++i) {
		tag_to_hal_sensor_type[sensors_cmd_map_tab[i].tag] =
			sensors_cmd_map_tab[i].hal_sensor_type;
		hal_sensor_type_to_tag[sensors_cmd_map_tab[i].hal_sensor_type] =
			sensors_cmd_map_tab[i].tag;
	}
}

static bool switch_sensor(int tag, bool enable)
{
	bool result = false;

	mutex_lock(&mutex_status);
	if ((enable && !sensor_switch_flags[tag]) || (!enable)) {
		sensor_switch_flags[tag] = enable;
		result = true;
	}
	hwlog_info("%s ret is %d\n", __func__, result);
	mutex_unlock(&mutex_status);
	return result;
}

static bool ap_sensor_flush(int tag)
{
	struct sensor_data event;
	bool work_on_ap = all_ap_sensor_operations[tag].work_on_ap;

	if (work_on_ap) {
		if (all_ap_sensor_operations[tag].ops.enable) {
			all_ap_sensor_operations[tag].ops.enable(1);
			msleep(60);
		}
		event.type = tag_to_hal_sensor_type[TAG_FLUSH_META];
		event.length = 4;  /* 4 : sensor data length */
		event.value[0] = tag_to_hal_sensor_type[tag];
		return inputhub_route_write_batch(ROUTE_SHB_PORT,
			(char *)&event, event.length +
			OFFSET_OF_END_MEM(struct sensor_data, length), 0);
	}
	return work_on_ap;
}

static int send_sensor_batch_flush_cmd(unsigned int cmd,
	struct ioctl_para *para, int tag)
{
	write_info_t winfo;
	uint32_t subcmd = 0;

	memset(&winfo, 0, sizeof(winfo));
	if (cmd == SHB_IOCTL_APP_SENSOR_BATCH) {
		interval_param_t batch_param;

		batch_param.mode = AUTO_MODE;
		batch_param.period = para->period_ms;

		if (para->period_ms != 0) {
			batch_param.batch_count =
				(para->timeout_ms > para->period_ms) ?
				(para->timeout_ms / para->period_ms) : 1;
		} else {
			batch_param.batch_count = 1;
			hwlog_info("para->period_ms is zero, set count to 1\n");
		}

		hwlog_info("%s batch period=%d, count=%d\n", __func__,
			para->period_ms, batch_param.batch_count);
		return inputhub_sensor_setdelay(tag, &batch_param);
	} else if (cmd == SHB_IOCTL_APP_SENSOR_FLUSH) {
		hwlog_info("flush in %s\n", __func__);
		ap_sensor_flush(tag);
		winfo.cmd = CMD_CMN_CONFIG_REQ;
		winfo.tag = tag;
		subcmd = SUB_CMD_FLUSH_REQ;
		winfo.wr_buf = &subcmd;
		winfo.wr_len = SUBCMD_LEN;

		hwlog_info("flush sensor %s (tag:%d)\n",
			obj_tag_str[tag] ? obj_tag_str[tag] : "TAG_UNKNOWN", tag);
		write_customize_cmd(&winfo, NULL, true);
	}
	return 0;
}

static int send_sensor_cmd(unsigned int cmd, unsigned long arg)
{
	uint8_t app_config[16] = { 0 }; /* 16 :  default app config length */
	uintptr_t arg_tmp = (uintptr_t)arg;
	void __user *argp = (void __user *)arg_tmp;
	int tag;
	int ret;
	struct ioctl_para para;
	interval_param_t delay_param;

	if (flag_for_sensor_test)
		return 0;

	if (copy_from_user(&para, argp, sizeof(para)))
		return -EFAULT;

	delay_param.period = para.delay_ms;
	delay_param.batch_count = 1;
	delay_param.mode = AUTO_MODE;
	delay_param.reserved[0] = TYPE_STANDARD; /* for step counter only */

	if (!(para.shbtype >= SENSORHUB_TYPE_BEGIN &&
		para.shbtype < SENSORHUB_TYPE_END)) {
		hwlog_err("error shbtype %d in %s\n", para.shbtype, __func__);
		return -EINVAL;
	}

	tag = hal_sensor_type_to_tag[para.shbtype];
	switch (cmd) {
	case SHB_IOCTL_APP_ENABLE_SENSOR:
		break;
	case SHB_IOCTL_APP_DISABLE_SENSOR:
		switch_sensor(tag, false);
		if (tag == TAG_STEP_COUNTER)
			return inputhub_sensor_enable_stepcounter(false,
				TYPE_STANDARD);
		else
			return inputhub_sensor_enable(tag, false);
	case SHB_IOCTL_APP_DELAY_SENSOR:
		if (switch_sensor(tag, true)) {
			if (tag == TAG_STEP_COUNTER)
				ret = inputhub_sensor_enable_stepcounter(false,
					TYPE_STANDARD);
			else
				ret = inputhub_sensor_enable(tag, true);
			if (ret) {
				hwlog_err("failed to enable sensor tag %d\n",
					tag);
				return -1;
			}
		}
		if (tag == TAG_STEP_COUNTER) {
			inputhub_sensor_setdelay(tag, &delay_param);
			app_config[0] = 1;
			app_config[1] = TYPE_STANDARD;
			return send_app_config_cmd(TAG_STEP_COUNTER,
				app_config, true);
		} else {
			return inputhub_sensor_setdelay(tag, &delay_param);
		}
	case SHB_IOCTL_APP_SENSOR_BATCH:
		if (switch_sensor(tag, true) &&
			inputhub_sensor_enable(tag, true)) {
			hwlog_err("failed to enable sensor tag %d\n", tag);
			return -1;
		}
	case SHB_IOCTL_APP_SENSOR_FLUSH:
		if (tag == TAG_STEP_COUNTER) {
			ret = send_sensor_batch_flush_cmd(cmd, &para, tag);
			if (ret == 0) {
				/* success */
				app_config[0] = 1;
				app_config[1] = TYPE_STANDARD;
				return send_app_config_cmd(TAG_STEP_COUNTER,
					app_config, true);
			} else {
				/* fail */
				hwlog_err("send_sensor_cmd failed %d in %s %d\n",
					cmd, __func__, __LINE__);
				return ret;
			}
		} else {
			return send_sensor_batch_flush_cmd(cmd, &para, tag);
		}
	default:
		hwlog_err("unknown shb_hal_cmd %d in %s\n", cmd, __func__);
		return -EINVAL;
	}

	return 0;
}

static ssize_t shb_read(struct file *file, char __user *buf, size_t count,
	loff_t *pos)
{
	return inputhub_route_read(ROUTE_SHB_PORT, buf, count);
}

static ssize_t shb_write(struct file *file, const char __user *data,
	size_t len, loff_t *ppos)
{
	hwlog_info("%s need to do\n", __func__);
	return len;
}

static void get_acc_calibrate_data(void)
{
	int ret;

	if (first_start_flag == 0) {
		ret = send_gsensor_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read from nv fail,ret=%d", __func__, ret);
		else
			hwlog_info("read nv success\n");
	}
}

static void get_acc1_calibrate_data(void)
{
	int ret;

	if (strlen(sensor_chip_info[ACC1]) == 0)
		return;

	if (acc1_first_start_flag == 0) {
		ret = send_gsensor1_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read from nv fail,ret=%d", __func__, ret);
		else
			hwlog_info("read nv success\n");
	}
}


extern int send_vibrator_calibrate_data_to_mcu(void);
static void get_vibrator_calibrate_data(void)
{
	int ret;
	static int vib_first_flag = 0;

	if (strlen(sensor_chip_info[VIBRATOR]) == 0)
		return;

	if (vib_first_flag == 0) {
		ret = send_vibrator_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read from nv fail,ret=%d", __func__, ret);
		else
			hwlog_info("%s read nv success\n", __func__);
		vib_first_flag = 1;
	}
}

extern int send_mag_calibrate_data_to_mcu(void);
static void get_mag_calibrate_data(void)
{
	int ret;
	static int mag_first_start_flag = 0;

	if (mag_first_start_flag == 0) {
		mag_current_notify();
		ret = send_mag_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read mag data from nv or send to iom3 failed, ret=%d\n",
				__func__, ret);
		else
			hwlog_info("%s read mag data from nv and send to iom3 success\n",
				__func__);
		mag_first_start_flag = 1;
	}
}

extern int send_mag1_calibrate_data_to_mcu(void);
static void get_mag1_calibrate_data(void)
{
	int ret;
	static int mag1_first_start_flag = 0;

	if (strlen(sensor_chip_info[MAG1]) == 0)
		return;

	if (mag1_first_start_flag == 0) {
		ret = send_mag1_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read mag data from nv or send to iom3 failed, ret=%d\n",
				__func__, ret);
		else
			hwlog_info("%s read mag data from nv and send to iom3 success\n",
				__func__);
		mag1_first_start_flag = 1;
	}
}

extern int send_cap_prox_calibrate_data_to_mcu(void);
static void get_cap_prox_calibrate_data(void)
{
	int ret;
	static int cap_prox_first_start_flag = 0;

	if (cap_prox_first_start_flag == 0) {
		ret = send_cap_prox_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read cap_prox data from nv or send to iom3 failed, ret=%d\n",
				__func__, ret);
		else
			hwlog_info("%s read cap_prox data from nv and send to iom3 success\n",
				__func__);
		cap_prox_first_start_flag = 1;
	}
}

extern int send_cap_prox1_calibrate_data_to_mcu(void);
static void get_cap_prox1_calibrate_data(void)
{
	int ret;
	static int prox1_first_start_flag = 0;

	if (prox1_first_start_flag == 0) {
		ret = send_cap_prox1_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read cap_prox1 data from nv or send to iom3 failed, ret=%d\n",
				__func__, ret);
		else
			hwlog_info("%s read cap_prox1 data from nv and send to iom3 success\n",
				__func__);
		prox1_first_start_flag = 1;
	}
}

static void get_airpress_calibrate_data(void)
{
	int ret;
	static int airpress_first_start_flag = 0;

	if (strlen(sensor_chip_info[AIRPRESS]) == 0)
		return;
	if (airpress_first_start_flag == 0) {
		ret = send_airpress_calibrate_data_to_mcu();
		if (ret) {
			hwlog_err("%s read airpress data from nv or send to iom3 failed, ret=%d\n",
				__func__, ret);
		} else {
			hwlog_info("%s read airpress data from nv and send to iom3 success\n",
				__func__);
			airpress_first_start_flag = 1;
		}
	}
}

extern int send_ps_calibrate_data_to_mcu(void);
extern int send_tof_calibrate_data_to_mcu(void);
static void get_psensor_calibrate_data(void)
{
	int ret = 0;

	if (ps_first_start_flag == 0 && (sensor_ps_flag == 1 || ps_cali_supported == 1)) {
		ret = send_ps_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("get_ps_calibrate_data read from nv fail, ret=%d",
				ret);
		else
			hwlog_info("read nv success\n");
	}
	if (ps_first_start_flag == 0 && sensor_tof_flag == 1) {
		ret = send_tof_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("get_tof_calibrate_data read from nv fail, ret=%d",
				ret);
		else
			hwlog_info("tof read nv success\n");
	}
}

extern int send_als_calibrate_data_to_mcu(void);
extern int get_tpcolor_from_nv(void);

static void get_als_calibrate_data(void)
{
	int ret = 0;
	int bh1749_flag = sensor_get_als_bh1749_flag();
	int bu27006muc_flag = sensor_get_als_bu27006muc_flag();
	if ((als_first_start_flag == 0) &&
		((rohm_rgb_flag == 1) || (avago_rgb_flag == 1) ||
		(ams_tmd3725_rgb_flag == 1) || (liteon_ltr582_rgb_flag == 1) ||
		(is_cali_supported == 1) || (apds9999_rgb_flag == 1) ||
		(ams_tmd3702_rgb_flag == 1) || (apds9253_rgb_flag == 1) ||
		(vishay_vcnl36658_als_flag == 1) || (ams_tcs3701_rgb_flag == 1) ||
		(bh1749_flag == 1) || (vd6281_als_flag == 1) ||
		(ams_tcs3707_rgb_flag == 1) || (bu27006muc_flag == 1))) {
		ret = send_als_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("get_als_calibrate_data read from nv fail, ret=%d",
				ret);
		else
			hwlog_info("read nv success\n");

		ret = get_tpcolor_from_nv();
		if (ret)
			hwlog_err("get_tpcolor_from_nv fail, ret=%d", ret);
		else
			hwlog_info("get_tpcolor_from_nv success\n");
	}
}

extern int read_gyro_offset_from_nv(void);
extern int send_gyro_temperature_offset_to_mcu(void);

static void get_gyro1_calibrate_data(void)
{
	int ret = 0;

	if (strlen(sensor_chip_info[GYRO1]) == 0)
		return;
	if (gyro1_first_start_flag == 0) {
		ret = send_gyro1_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("get_gyro1_calibrate_data read from nv fail,ret=%d",
				ret);
		else
			hwlog_info("gyro_sensor read nv success\n");
	}
}

void get_als_under_tp_calibrate_data(void)
{
	int ret = 0;

	if ((!als_under_tp_first_start_flag) &&
		(apds9253_rgb_flag || ams_tcs3701_rgb_flag ||
		als_data.als_ud_type == ALS_UD_MINUS_TP_RGB)) {
		ret = send_als_under_tp_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read from nv fail,ret=%d", __func__, ret);
		else
			hwlog_info("%s read nv success\n", __func__);
	}
}

static void get_gyro_calibrate_data(void)
{
	int ret = 0;

	if (strlen(sensor_chip_info[GYRO]) == 0)
		return;
	if (gyro_first_start_flag == 0) {
		ret = send_gyro_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("%s read from nv fail,ret=%d", __func__, ret);
		else
			hwlog_info("gyro_sensor read nv success\n");
		ret = send_gyro_temperature_offset_to_mcu();
		if (ret)
			hwlog_err("get_gyro_temperature calibrate_data read from nv fail,ret=%d",
				ret);
		else
			hwlog_info("gyro read temperature offset from nv success\n");
	}
}

static void get_handpress_calibrate_data(void)
{
	int ret = 0;

	if (strlen(sensor_chip_info[HANDPRESS]) == 0)
		return;
	if (handpress_first_start_flag == 0) {
		ret = send_handpress_calibrate_data_to_mcu();
		if (ret)
			hwlog_err("handpress read from nv fail, ret=%d", ret);
		else
			hwlog_info("handpress read nv success\n");
	}
}

static void send_sensor_calib_data(void)
{
	get_acc_calibrate_data();
	get_acc1_calibrate_data();
	get_mag_calibrate_data();
	get_mag1_calibrate_data();
	get_cap_prox_calibrate_data();
	get_cap_prox1_calibrate_data();
	get_airpress_calibrate_data();
	get_psensor_calibrate_data();
	get_als_calibrate_data();
	get_als_under_tp_calibrate_data();
	get_gyro_calibrate_data();
	get_gyro1_calibrate_data();
	get_handpress_calibrate_data();
	get_vibrator_calibrate_data();
}

static long shb_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	uintptr_t arg_tmp = (uintptr_t)arg;
	void __user *argp = (void __user *)arg_tmp;
	int sensor_mcu_mode;

	/*
	 * add sensors of android4.4
	 * MAGNETIC_FIELD_UNCALIBRATED~GEOMAGNETIC_ROTATION_VECTOR
	 */
	switch (cmd) {
	case SHB_IOCTL_APP_ENABLE_SENSOR:
	case SHB_IOCTL_APP_DISABLE_SENSOR:
	case SHB_IOCTL_APP_DELAY_SENSOR:
		break; /* fall through */
	case SHB_IOCTL_APP_GET_SENSOR_MCU_MODE:
		sensor_mcu_mode = getSensorMcuMode();
		hwlog_info("is_sensor_mcu_mode [%d]\n", sensor_mcu_mode);
		if (copy_to_user(argp, &sensor_mcu_mode,
			sizeof(sensor_mcu_mode)))
			return -EFAULT;
		return 0;
	case SHB_IOCTL_APP_SENSOR_BATCH:
		hwlog_info("shb_ioctl cmd : batch flush SHB_IOCTL_APP_SENSOR_BATCH\n");
		break;
	case SHB_IOCTL_APP_SENSOR_FLUSH:
		hwlog_info("shb_ioctl cmd : batch flush SHB_IOCTL_APP_SENSOR_FLUSH\n");
		break;
	default:
		hwlog_err("shb_ioctl unknown cmd : %d\n", cmd);
		return -ENOTTY;
	}
	send_sensor_calib_data();
	return send_sensor_cmd(cmd, arg);
}

/* shb_open: do nothing now */
static int shb_open(struct inode *inode, struct file *file)
{
	hwlog_info("%s ok\n", __func__);
	return 0;
}

/* shb_release: do nothing now */
static int shb_release(struct inode *inode, struct file *file)
{
	hwlog_info("%s ok\n", __func__);
	return 0;
}

static void enable_sensors_when_recovery_iom3(void)
{
	int tag;
	interval_param_t interval_param;

	for (tag = TAG_SENSOR_BEGIN; tag < TAG_SENSOR_END; ++tag) {
		if (sensor_status.status[tag]) {
			/* default delay_ms */
			interval_param.period = sensor_status.delay[tag];
			interval_param.batch_count =
				sensor_status.batch_cnt[tag];
			interval_param.mode = AUTO_MODE;
			interval_param.reserved[0] = TYPE_STANDARD;
			inputhub_sensor_enable_nolock(tag, true);
			inputhub_sensor_setdelay_nolock(tag, &interval_param);
		}
	}
}

static int sensor_recovery_notifier(struct notifier_block *nb,
	unsigned long foo, void *bar)
{
	hwlog_info("%s %lu +\n", __func__, foo);
	switch (foo) {
	case IOM3_RECOVERY_IDLE:
	case IOM3_RECOVERY_START:
	case IOM3_RECOVERY_MINISYS:
	case IOM3_RECOVERY_3RD_DOING:
	case IOM3_RECOVERY_FAILED:
		break;
	case IOM3_RECOVERY_DOING:
		reset_calibrate_data();
		enable_sensors_when_recovery_iom3();
		break;
	default:
		hwlog_err("%s -unknow state %ld\n", __func__, foo);
		break;
	}
	hwlog_info("%s -\n", __func__);
	return 0;
}

static struct notifier_block sensor_recovery_notify = {
	.notifier_call = sensor_recovery_notifier,
	.priority = -1,
};

static const struct file_operations shb_fops = {
	.owner          = THIS_MODULE,
	.llseek         =   no_llseek,
	.read           =   shb_read,
	.write          =   shb_write,
	.unlocked_ioctl = shb_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl   = shb_ioctl,
#endif
	.open           =   shb_open,
	.release        =   shb_release,
};

static struct miscdevice senorhub_miscdev = {
	.minor =    MISC_DYNAMIC_MINOR,
	.name =     "sensorhub",
	.fops =     &shb_fops,
};

static int __init sensorhub_init(void)
{
	int ret;

	if (is_sensorhub_disabled())
		return -1;
	init_hash_tables();
	ret = inputhub_route_open(ROUTE_SHB_PORT);
	if (ret != 0) {
		hwlog_err("cannot open inputhub route err=%d\n", ret);
		return ret;
	}
	ret = misc_register(&senorhub_miscdev);
	if (ret != 0) {
		inputhub_route_close(ROUTE_SHB_PORT);
		hwlog_err("cannot register miscdev err=%d\n", ret);
		return ret;
	}
	register_iom3_recovery_notifier(&sensor_recovery_notify);
	hwlog_info("%s ok\n", __func__);
	return 0;
}

static void __exit sensorhub_exit(void)
{
	inputhub_route_close(ROUTE_SHB_PORT);
	misc_deregister(&senorhub_miscdev);
	hwlog_info("exit %s\n", __func__);
}

late_initcall_sync(sensorhub_init);
module_exit(sensorhub_exit);

MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("SensorHub driver");
MODULE_AUTHOR("Huawei Technologies Co., Ltd.");
