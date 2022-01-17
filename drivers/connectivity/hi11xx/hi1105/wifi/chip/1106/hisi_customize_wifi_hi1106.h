

#ifndef __HISI_CUSTOMIZE_WIFI_HI1106_H__
#define __HISI_CUSTOMIZE_WIFI_HI1106_H__

/* 其他头文件包含 */
#include "hisi_customize_wifi.h"
#include "wlan_cali.h"
#include "wlan_customize.h"

/* 宏定义 */
#define CUS_TAG_HOST                 0x21
#define CUS_TAG_RF                   0X22
#define CUS_TAG_DYN_POW              0x23
#define CUS_TAG_POW                  0X24
#define CUS_TAG_CAP                  0x25

/* 用户pwr ref reg的定制化保护阈值 */
#define CUST_PWR_REF_DELTA_HI 40
#define CUST_PWR_REF_DELTA_LO (-40)

/* 枚举定义 */
/* 定制化 HOST CONFIG ID */
typedef enum {
    /* ROAM */
    WLAN_CFG_HOST_ROAM_SWITCH = 0,
    WLAN_CFG_HOST_SCAN_ORTHOGONAL,
    WLAN_CFG_HOST_TRIGGER_B,
    WLAN_CFG_HOST_TRIGGER_A,
    WLAN_CFG_HOST_DELTA_B,
    WLAN_CFG_HOST_DELTA_A,
    WLAN_CFG_HOST_DENSE_ENV_TRIGGER_B,
    WLAN_CFG_HOST_DENSE_ENV_TRIGGER_A,
    WLAN_CFG_HOST_SCENARIO_ENABLE,
    WLAN_CFG_HOST_CANDIDATE_GOOD_RSSI,
    WLAN_CFG_HOST_CANDIDATE_GOOD_NUM,
    WLAN_CFG_HOST_CANDIDATE_WEAK_NUM,
    WLAN_CFG_HOST_INTERVAL_VARIABLE,

    /* 性能 */
    WLAN_CFG_HOST_AMPDU_TX_MAX_NUM,  // 7
    WLAN_CFG_HOST_DMA_LATENCY,
    WLAN_CFG_HOST_LOCK_CPU_TH_HIGH,
    WLAN_CFG_HOST_LOCK_CPU_TH_LOW,
    WLAN_CFG_HOST_IRQ_AFFINITY,
    WLAN_CFG_HOST_IRQ_TH_LOW,
    WLAN_CFG_HOST_IRQ_TH_HIGH,
    WLAN_CFG_HOST_IRQ_PPS_TH_LOW,
    WLAN_CFG_HOST_IRQ_PPS_TH_HIGH,
#ifdef _PRE_WLAN_FEATURE_AMPDU_TX_HW
    WLAN_CFG_HOST_HW_AMPDU,
    WLAN_CFG_HOST_HW_AMPDU_TH_LOW,
    WLAN_CFG_HOST_HW_AMPDU_TH_HIGH,
#endif
#ifdef _PRE_WLAN_FEATURE_MULTI_NETBUF_AMSDU
    WLAN_CFG_HOST_AMPDU_AMSDU_SKB,
    WLAN_CFG_HOST_AMSDU_AMPDU_TH_LOW,
    WLAN_CFG_HOST_AMSDU_AMPDU_TH_MIDDLE,
    WLAN_CFG_HOST_AMSDU_AMPDU_TH_HIGH,
#endif
#ifdef _PRE_WLAN_TCP_OPT
    WLAN_CFG_HOST_TCP_ACK_FILTER,
    WLAN_CFG_HOST_TCP_ACK_FILTER_TH_LOW,
    WLAN_CFG_HOST_TCP_ACK_FILTER_TH_HIGH,
#endif
    WLAN_CFG_HOST_TX_SMALL_AMSDU,
    WLAN_CFG_HOST_SMALL_AMSDU_HIGH,
    WLAN_CFG_HOST_SMALL_AMSDU_LOW,
    WLAN_CFG_HOST_SMALL_AMSDU_PPS_HIGH,
    WLAN_CFG_HOST_SMALL_AMSDU_PPS_LOW,

    WLAN_CFG_HOST_TX_TCP_ACK_BUF,
    WLAN_CFG_HOST_TCP_ACK_BUF_HIGH,
    WLAN_CFG_HOST_TCP_ACK_BUF_LOW,
    WLAN_CFG_HOST_TCP_ACK_BUF_HIGH_40M,
    WLAN_CFG_HOST_TCP_ACK_BUF_LOW_40M,
    WLAN_CFG_HOST_TCP_ACK_BUF_HIGH_80M,
    WLAN_CFG_HOST_TCP_ACK_BUF_LOW_80M,
    WLAN_CFG_HOST_TCP_ACK_BUF_HIGH_160M,
    WLAN_CFG_HOST_TCP_ACK_BUF_LOW_160M,
    WLAN_CFG_HOST_TX_TCP_ACK_BUF_USERCTL,
    WLAN_CFG_HOST_TCP_ACK_BUF_USERCTL_HIGH,
    WLAN_CFG_HOST_TCP_ACK_BUF_USERCTL_LOW,

    WLAN_CFG_HOST_RX_DYN_BYPASS_EXTLNA,
    WLAN_CFG_HOST_RX_DYN_BYPASS_EXTLNA_HIGH,
    WLAN_CFG_HOST_RX_DYN_BYPASS_EXTLNA_LOW,

    /* 接收ampdu+amsdu */
    WLAN_CFG_HOST_RX_AMPDU_AMSDU_SKB,
    WLAN_CFG_HOST_RX_AMPDU_BITMAP,

    /* 低功耗 */
    WLAN_CFG_HOST_PS_MODE,
    /* SCAN */
    WLAN_CFG_HOST_RANDOM_MAC_ADDR_SCAN,
    /* 11AC2G */
    WLAN_CFG_HOST_11AC2G_ENABLE,
    /* 11ac2g开关 */                    // 56
    WLAN_CFG_HOST_DISABLE_CAPAB_2GHT40, /* 2ght40禁止开关 */

    /* probe req应答模式功能配置 */
    WLAN_CFG_HOST_PROBE_RESP_MODE, /* BIT7~BIT4:动态功能开关 ;BIT3~BIT0:功能模式 , 目前此配置仅针对p2p dev设备有效 */
    WLAN_CFG_HOST_MIRACAST_SINK_ENABLE, /* miracast_sink特性开关 */
    WLAN_CFG_HOST_REDUCE_MIRACAST_LOG, /* miracast log 降级开关 */
    WLAN_CFG_HOST_CORE_BIND_CAP, /* 是否支持cpu绑定 */

    /* sta keepalive */
    WLAN_CFG_HOST_LTE_GPIO_CHECK_SWITCH, /* lte?????? */
    WLAN_HOST_ATCMDSRV_ISM_PRIORITY,
    WLAN_HOST_ATCMDSRV_LTE_RX,
    WLAN_HOST_ATCMDSRV_LTE_TX,
    WLAN_HOST_ATCMDSRV_LTE_INACT,
    WLAN_HOST_ATCMDSRV_ISM_RX_ACT,
    WLAN_HOST_ATCMDSRV_BANT_PRI,
    WLAN_HOST_ATCMDSRV_BANT_STATUS,
    WLAN_HOST_ATCMDSRV_WANT_PRI,
    WLAN_HOST_ATCMDSRV_WANT_STATUS,
    WLAN_CFG_HOST_DDR_FREQ,
    /* 注册WiFi动态锁频麒麟接口 */
    WLAN_CFG_HOST_LOCK_CPU_FREQ,
    /* 优化特性开关 */
    WLAN_CFG_HOST_OPTIMIZED_FEATURE_SWITCH,

    WLAN_CFG_HOST_BUTT,
} wlan_host_cfg_enum;

typedef enum {
    /* 动态校准 */
    WLAN_CFG_DYN_CALI_DSCR_ITERVL,
    WLAN_CFG_FAR_DIST_POW_GAIN_SWITCH,

    /* 2G RF前端 */
    WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND_START,  // 33
    WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND1 = WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND_START,
    WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND2,
    WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND3,
    WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND_END = WLAN_CFG_RF_RX_INSERTION_LOSS_2G_BAND3,
    /* 5G RF前端 */
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND_START,  // 37
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND1 = WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND_START,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND2,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND3,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND4,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND5,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND6,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND7,
    WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND_END = WLAN_CFG_RF_RX_INSERTION_LOSS_5G_BAND7,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND_START,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND0 = WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND_START,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND1,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND2,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND3,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND4,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND5,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND6,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND7,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND8,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND9,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND10,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND11,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND12,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND13,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND14,
    WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND_END = WLAN_CFG_RF_RX_INSERTION_LOSS_6G_BAND14,
#endif
    /* 用于定制化计算PWR RF值的偏差 */
    WLAN_CFG_RF_PWR_REF_RSSI_2G_20M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_2G_40M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_5G_20M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_5G_40M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_5G_80M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_5G_160M_MULT4,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_RF_PWR_REF_RSSI_6G_20M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_6G_40M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_6G_80M_MULT4,
    WLAN_CFG_RF_PWR_REF_RSSI_6G_160M_MULT4,
#endif
    /* 用于定制化计算RSSI的偏差 */
    WLAN_CFG_RF_AMEND_RSSI_2G_20M,
    WLAN_CFG_RF_AMEND_RSSI_2G_40M,
    WLAN_CFG_RF_AMEND_RSSI_2G_11B,

    WLAN_CFG_RF_AMEND_RSSI_5G_20M,
    WLAN_CFG_RF_AMEND_RSSI_5G_40M,
    WLAN_CFG_RF_AMEND_RSSI_5G_80M,
    WLAN_CFG_RF_AMEND_RSSI_5G_160M,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_RF_AMEND_RSSI_6G_20M,
    WLAN_CFG_RF_AMEND_RSSI_6G_40M,
    WLAN_CFG_RF_AMEND_RSSI_6G_80M,
    WLAN_CFG_RF_AMEND_RSSI_6G_160M,
#endif
    /* FEM 03考虑2g */
    WLAN_CFG_RF_LNA_BYPASS_GAIN_DB_2G,
    WLAN_CFG_RF_LNA_GAIN_DB_2G,
    WLAN_CFG_RF_PA_GAIN_DB_B0_2G,
    WLAN_CFG_RF_PA_GAIN_DB_B1_2G,
    WLAN_CFG_RF_PA_GAIN_LVL_2G,
    WLAN_CFG_EXT_SWITCH_ISEXIST_2G,
    WLAN_CFG_EXT_PA_ISEXIST_2G,
    WLAN_CFG_EXT_LNA_ISEXIST_2G,
    WLAN_CFG_LNA_ON2OFF_TIME_NS_2G,
    WLAN_CFG_LNA_OFF2ON_TIME_NS_2G,
    WLAN_CFG_RF_LNA_BYPASS_GAIN_DB_5G,
    WLAN_CFG_RF_LNA_GAIN_DB_5G,
    WLAN_CFG_RF_PA_GAIN_DB_B0_5G,
    WLAN_CFG_RF_PA_GAIN_DB_B1_5G,
    WLAN_CFG_RF_PA_GAIN_LVL_5G,
    WLAN_CFG_EXT_SWITCH_ISEXIST_5G,
    WLAN_CFG_EXT_PA_ISEXIST_5G,
    WLAN_CFG_EXT_LNA_ISEXIST_5G,
    WLAN_CFG_LNA_ON2OFF_TIME_NS_5G,
    WLAN_CFG_LNA_OFF2ON_TIME_NS_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_RF_LNA_BYPASS_GAIN_DB_6G,
    WLAN_CFG_RF_LNA_GAIN_DB_6G,
    WLAN_CFG_RF_PA_GAIN_DB_B0_6G,
    WLAN_CFG_RF_PA_GAIN_DB_B1_6G,
    WLAN_CFG_RF_PA_GAIN_LVL_6G,
    WLAN_CFG_EXT_SWITCH_ISEXIST_6G,
    WLAN_CFG_EXT_PA_ISEXIST_6G,
    WLAN_CFG_EXT_LNA_ISEXIST_6G,
    WLAN_CFG_LNA_ON2OFF_TIME_NS_6G,
    WLAN_CFG_LNA_OFF2ON_TIME_NS_6G,
#endif
    WLAN_CFG_FEM_MODE_2G,
    WLAN_CFG_FEM_MODE_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_FEM_MODE_6G,
#endif
    WLAN_CFG_DELTA_CCA_ED_HIGH_20TH_2G,
    WLAN_CFG_DELTA_CCA_ED_HIGH_40TH_2G,
    WLAN_CFG_DELTA_CCA_ED_HIGH_20TH_5G,
    WLAN_CFG_DELTA_CCA_ED_HIGH_40TH_5G,
    WLAN_CFG_DELTA_CCA_ED_HIGH_80TH_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_DELTA_CCA_ED_HIGH_20TH_6G,
    WLAN_CFG_DELTA_CCA_ED_HIGH_40TH_6G,
    WLAN_CFG_DELTA_CCA_ED_HIGH_80TH_6G,
#endif
    WLAN_CFG_RF_CALI_BUTT,
} wlan_rf_cfg_enum;

/* 特性功能定制化 CAP CONFIG ID */
typedef enum {
    /* 校准开关 */
    WLAN_CFG_CAP_CALI_POLICY,
    WLAN_CFG_CAP_CALI_MASK_2G,
    WLAN_CFG_CAP_CALI_MASK_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_CAP_CALI_MASK_6G,
#endif
    WLAN_CFG_CAP_CALI_ONLINE_MASK,
    WLAN_CFG_CAP_CALI_DATA_MASK,

    WLAN_CFG_CAP_BW_MAX_WITH,
    WLAN_CFG_CAP_LDPC_CODING,
    WLAN_CFG_CAP_RX_STBC,
    WLAN_CFG_CAP_TX_STBC,
    WLAN_CFG_CAP_SU_BFER,
    WLAN_CFG_CAP_SU_BFEE,
    WLAN_CFG_CAP_MU_BFER,
    WLAN_CFG_CAP_MU_BFEE,

    WLAN_CFG_CAP_1024_QAM,
    WLAN_CFG_CAP_HISI_PRIV_IE,
    WLAN_CFG_CAP_VOE_SWITCH,
    WLAN_CFG_CAP_11AX_SWITCH,
    WLAN_CFG_CAP_HTC_SWITCH,
    WLAN_CFG_CAP_MULTI_BSSID_SWITCH,
    WLAN_CFG_CAP_DYNAMIC_DBAC_SWITCH,

    /* DBDC */
    WLAN_CFG_CAP_DBDC_RADIO,
    WLAN_CFG_CAP_DBDC,
    WLAN_CFG_CAP_FASTSCAN_SWITCH,

    /* 天线切换功能 */
    WLAN_CFG_CAP_ANT_SWITCH,
    /* 国家码自学习开关 */
    WLAN_CFG_CAP_COUNRTYCODE_SELFSTUDY_CFG,
    WLAN_CFG_CAP_DEGRADATION_CAP,

    /* MCM */
    WLAN_CFG_CAP_RADIO_CAP,
    WLAN_CFG_CAP_RADIO_CAP_6G,
    WLAN_CFG_CAP_MCM_CUSTOM_FUNCTION_MASK,
    WLAN_CFG_CAP_MCM_FUNCTION_MASK,

    /* linkloss门限固定开关 */
    WLAN_CFG_CAP_LINKLOSS_THRESHOLD_FIXED,

    /* 160M APUT使能 */
    WLAN_CFG_CAP_APUT_160M_ENABLE,
    /* 屏蔽硬件上报的雷达信号 */
    WLAN_CFG_CAP_RADAR_ISR_FORBID,

    /* 限流 */
    WLAN_CFG_CAP_DOWNLOAD_RATE_LIMIT_PPS,
#ifdef _PRE_WLAN_FEATURE_TXOPPS
    WLAN_CFG_CAP_TXOPPS_SWITCH,
#endif
    WLAN_CFG_CAP_OVER_TEMPER_PROTECT_THRESHOLD,
    WLAN_CFG_CAP_OVER_TEMP_PRO_ENABLE,
    WLAN_CFG_CAP_OVER_TEMP_PRO_REDUCE_PWR_ENABLE,
    WLAN_CFG_CAP_OVER_TEMP_PRO_SAFE_TH,
    WLAN_CFG_CAP_OVER_TEMP_PRO_OVER_TH,
    WLAN_CFG_CAP_OVER_TEMP_PRO_PA_OFF_TH,

    WLAN_CAP_DSSS2OFDM_DBB_PWR_BO_VAL,
    WLAN_CFG_CAP_EVM_PLL_REG_FIX,

    /* M_BSSID */
    WLAN_CFG_CAP_AC_SUSPEND,

    /* 动态bypass外置LNA方案 */
    WLAN_CFG_CAP_DYN_BYPASS_EXTLNA,
    WLAN_CFG_CAP_CTRL_FRAME_TX_CHAIN,
    WLAN_CFG_CAP_CTRL_11B_DOUBLE_CHAIN_BO_POW,

    /* 非高优先级hcc流控类型 0:SDIO 1:GPIO */
    WLAN_CFG_CAP_HCC_FLOWCTRL_TYPE,
#ifdef _PRE_WLAN_FEATURE_MBO
    WLAN_CFG_CAP_MBO_SWITCH,
#endif
    /* DC流控特性定制化开关 */
    WLAN_CFG_CAP_DC_FLOWCTL_SWITCH,
    /* phy相关能力定制化 */
    WLAN_CFG_CAP_PHY_CAP_SWITCH,

    WLAN_CFG_CAP_HAL_PS_RSSI_PARAM,
    WLAN_CFG_CAP_HAL_PS_PPS_PARAM,
    WLAN_CFG_CAP_HIEX_CAP,

    /* FEM pow saving 50 */
    WLAN_CFG_CAP_FEM_DELT_POW,
    WLAN_CFG_CAP_FEM_ADJ_TPC_TBL_START_IDX,
    /*  低功耗定制化  */
    WLAN_CFG_CAP_POWERMGMT_SWITCH,
    WLAN_CFG_CAP_MIN_FAST_PS_IDLE,  // How many 20ms
    WLAN_CFG_CAP_MAX_FAST_PS_IDLE,
    WLAN_CFG_CAP_AUTO_FAST_PS_THRESH_SCREENON,
    WLAN_CFG_CAP_AUTO_FAST_PS_THRESH_SCREENOFF,

    /* 可维可测 */
    WLAN_CFG_CAP_LOGLEVEL,
    /*  性能  */
    WLAN_CFG_CAP_USED_MEM_FOR_START,
    WLAN_CFG_CAP_USED_MEM_FOR_STOP,
    WLAN_CFG_CAP_SDIO_D2H_ASSEMBLE_COUNT,
    WLAN_CFG_CAP_SDIO_H2D_ASSEMBLE_COUNT,
    /* LINKLOSS */
    WLAN_CFG_CAP_LINK_LOSS_THRESHOLD_BT,  // 13,这里不能直接赋值
    WLAN_CFG_CAP_LINK_LOSS_THRESHOLD_DBAC,
    WLAN_CFG_CAP_LINK_LOSS_THRESHOLD_NORMAL,
    /* 自动调频 */
    WLAN_CFG_CAP_PSS_THRESHOLD_LEVEL_0,  // 16
    WLAN_CFG_CAP_PSS_THRESHOLD_LEVEL_1,
    WLAN_CFG_CAP_PSS_THRESHOLD_LEVEL_2,
    WLAN_CFG_CAP_PSS_THRESHOLD_LEVEL_3,
    WLAN_CFG_CAP_DEVICE_TYPE_LEVEL_0,
    WLAN_CFG_CAP_DEVICE_TYPE_LEVEL_1,
    WLAN_CFG_CAP_DEVICE_TYPE_LEVEL_2,
    WLAN_CFG_CAP_DEVICE_TYPE_LEVEL_3,
    /* btcoex mcm rssi */
    WLAN_CFG_CAP_BTCOEX_THRESHOLD_MCM_DOWN,
    WLAN_CFG_CAP_BTCOEX_THRESHOLD_MCM_UP,
    WLAN_CFG_CAP_FTM,
    WLAN_CFG_CAP_FTM_BOARD_DELAY,
    WLAN_CFG_CAP_FAST_MODE,
    WLAN_CFG_CAP_TRX_SWITCH,
#ifdef _PRE_WLAN_FEATURE_NRCOEX
    /* 5g nr coex */
    WLAN_CFG_CAP_NRCOEX_ENABLE,
    WLAN_CFG_CAP_NRCOEX_VERSION,
    WLAN_CFG_CAP_NRCOEX_HW,
    WLAN_CFG_CAP_NRCOEX_ADVANCE_LOW_POWER,
    WLAN_CFG_CAP_NRCOEX_RULE0_FREQ,
    WLAN_CFG_CAP_NRCOEX_RULE0_40M_20M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE0_160M_80M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE0_40M_20M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE0_160M_80M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE0_40M_20M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE0_160M_80M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE0_SMALLGAP0_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE0_GAP01_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE0_GAP12_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE0_RXSLOT_RSSI,
    WLAN_CFG_CAP_NRCOEX_RULE1_FREQ,
    WLAN_CFG_CAP_NRCOEX_RULE1_40M_20M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE1_160M_80M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE1_40M_20M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE1_160M_80M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE1_40M_20M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE1_160M_80M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE1_SMALLGAP0_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE1_GAP01_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE1_GAP12_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE1_RXSLOT_RSSI,
    WLAN_CFG_CAP_NRCOEX_RULE2_FREQ,
    WLAN_CFG_CAP_NRCOEX_RULE2_40M_20M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE2_160M_80M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE2_40M_20M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE2_160M_80M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE2_40M_20M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE2_160M_80M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE2_SMALLGAP0_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE2_GAP01_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE2_GAP12_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE2_RXSLOT_RSSI,
    WLAN_CFG_CAP_NRCOEX_RULE3_FREQ,
    WLAN_CFG_CAP_NRCOEX_RULE3_40M_20M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE3_160M_80M_GAP0,
    WLAN_CFG_CAP_NRCOEX_RULE3_40M_20M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE3_160M_80M_GAP1,
    WLAN_CFG_CAP_NRCOEX_RULE3_40M_20M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE3_160M_80M_GAP2,
    WLAN_CFG_CAP_NRCOEX_RULE3_SMALLGAP0_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE3_GAP01_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE3_GAP12_ACT,
    WLAN_CFG_CAP_NRCOEX_RULE3_RXSLOT_RSSI,
#endif

    WLAN_CFG_CAP_BUTT,
} wlan_cap_cfg_enum;

/* 定制化 NVRAM PARAMS INDEX */
typedef enum {
    NVRAM_PARA_INDEX_0,
    NVRAM_PARA_INDEX_1,
    NVRAM_PARA_INDEX_2,
    NVRAM_PARA_INDEX_3,
    NVRAM_PARA_INDEX_4,
    NVRAM_PARA_INDEX_5,
    NVRAM_PARA_INDEX_6,
    NVRAM_PARA_INDEX_7,
    NVRAM_PARA_INDEX_8,
    NVRAM_PARA_INDEX_9,
    NVRAM_PARA_INDEX_10,
    NVRAM_PARA_INDEX_11,
    /* 2.4g 5g 20M mcs9
      2.4g 5g 20M mcs10 11
      2.4g 5g 40M mcs10 11
      2.4g 5g 80M mcs10 11
      5g 160M mcs0~3
      5g 160M mcs10~11 */
    NVRAM_PARA_INDEX_12,
    NVRAM_PARA_INDEX_13,
    NVRAM_PARA_INDEX_14,
    NVRAM_PARA_INDEX_15,
    NVRAM_PARA_INDEX_16,
    NVRAM_PARA_INDEX_17,
    /* 5G 功率与IQ校准UPC上限值 */
    NVRAM_PARA_INDEX_IQ_MAX_UPC,
    NVRAM_PARA_BACKOFF_POW,
    /* 2G 低功率修正值 */
    NVRAM_PARA_DSSS_2G_LOW_POW_AMEND,
    NVRAM_PARA_OFDM_2G_LOW_POW_AMEND,
    NVRAM_PARA_TXPWR_INDEX_BUTT,
    NVRAM_PARA_BASE_TXPWR_2G_C0, /* 2.4g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_2G_C1, /* 2.4g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_2G_C2, /* 2.4g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_2G_C3, /* 2.4g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_5G_C0, /* 5g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_5G_C1, /* 5g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_5G_C2, /* 5g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_5G_C3, /* 5g基准发射功率 */
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_BASE_TXPWR_6G_C0, /* 6g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_6G_C1, /* 6g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_6G_C2, /* 6g基准发射功率 */
    NVRAM_PARA_BASE_TXPWR_6G_C3, /* 6g基准发射功率 */
#endif
    NVRAM_PARA_BASE_INDEX_BUTT,
    /* MIMO基准发射功率差值 */
    NVRAM_PARA_2G_DELT_BASE_POWER_23,
    NVRAM_PARA_5G_DELT_BASE_POWER_23,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_6G_DELT_BASE_POWER_23,
#endif
    NVRAM_PARA_INDEX_24_RSV,
    /* FCC C0边带最大目标发射功率 */
    NVRAM_PARA_FCC_C0_START_INDEX,
    NVRAM_PARA_FCC_5G_20M_C0 = NVRAM_PARA_FCC_C0_START_INDEX,
    NVRAM_PARA_FCC_5G_40M_C0,
    NVRAM_PARA_FCC_5G_80M_C0,
    NVRAM_PARA_FCC_5G_160M_C0,
    NVRAM_PARA_FCC_2P4_C0_CH1,
    NVRAM_PARA_FCC_2P4_C0_CH2,
    NVRAM_PARA_FCC_2P4_C0_CH3,
    NVRAM_PARA_FCC_2P4_C0_CH4,
    NVRAM_PARA_FCC_2P4_C0_CH5,
    NVRAM_PARA_FCC_2P4_C0_CH6,
    NVRAM_PARA_FCC_2P4_C0_CH7,
    NVRAM_PARA_FCC_2P4_C0_CH8,
    NVRAM_PARA_FCC_2P4_C0_CH9,
    NVRAM_PARA_FCC_2P4_C0_CH10,
    NVRAM_PARA_FCC_2P4_C0_CH11,
    NVRAM_PARA_FCC_2P4_C0_CH12,
    NVRAM_PARA_FCC_2P4_C0_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_FCC_6G_20M_C0,
    NVRAM_PARA_FCC_6G_40M_C0,
    NVRAM_PARA_FCC_6G_80M_C0,
    NVRAM_PARA_FCC_SUB_SIDE_6G_20M_C0,
    NVRAM_PARA_FCC_SUB_SIDE_6G_40M_C0,
    NVRAM_PARA_FCC_SUB_SIDE_6G_80M_C0,
    NVRAM_PARA_FCC_6G_160M_C0,
#endif
    NVRAM_PARA_FCC_C0_END_INDEX_BUTT,

    /* FCC C1边带最大目标发射功率 */
    NVRAM_PARA_FCC_C1_START_INDEX,
    NVRAM_PARA_FCC_5G_20M_C1 = NVRAM_PARA_FCC_C1_START_INDEX,
    NVRAM_PARA_FCC_5G_40M_C1,
    NVRAM_PARA_FCC_5G_80M_C1,
    NVRAM_PARA_FCC_5G_160M_C1,
    NVRAM_PARA_FCC_2P4_C1_CH1,
    NVRAM_PARA_FCC_2P4_C1_CH2,
    NVRAM_PARA_FCC_2P4_C1_CH3,
    NVRAM_PARA_FCC_2P4_C1_CH4,
    NVRAM_PARA_FCC_2P4_C1_CH5,
    NVRAM_PARA_FCC_2P4_C1_CH6,
    NVRAM_PARA_FCC_2P4_C1_CH7,
    NVRAM_PARA_FCC_2P4_C1_CH8,
    NVRAM_PARA_FCC_2P4_C1_CH9,
    NVRAM_PARA_FCC_2P4_C1_CH10,
    NVRAM_PARA_FCC_2P4_C1_CH11,
    NVRAM_PARA_FCC_2P4_C1_CH12,
    NVRAM_PARA_FCC_2P4_C1_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_FCC_6G_20M_C1,
    NVRAM_PARA_FCC_6G_40M_C1,
    NVRAM_PARA_FCC_6G_80M_C1,
    NVRAM_PARA_FCC_SUB_SIDE_6G_20M_C1,
    NVRAM_PARA_FCC_SUB_SIDE_6G_40M_C1,
    NVRAM_PARA_FCC_SUB_SIDE_6G_80M_C1,
    NVRAM_PARA_FCC_6G_160M_C1,
#endif
    NVRAM_PARA_FCC_C1_END_INDEX_BUTT,

    /* FCC C2边带最大目标发射功率 */
    NVRAM_PARA_FCC_C2_START_INDEX,
    NVRAM_PARA_FCC_5G_20M_C2 = NVRAM_PARA_FCC_C2_START_INDEX,
    NVRAM_PARA_FCC_5G_40M_C2,
    NVRAM_PARA_FCC_5G_80M_C2,
    NVRAM_PARA_FCC_5G_160M_C2,
    NVRAM_PARA_FCC_2P4_C2_CH1,
    NVRAM_PARA_FCC_2P4_C2_CH2,
    NVRAM_PARA_FCC_2P4_C2_CH3,
    NVRAM_PARA_FCC_2P4_C2_CH4,
    NVRAM_PARA_FCC_2P4_C2_CH5,
    NVRAM_PARA_FCC_2P4_C2_CH6,
    NVRAM_PARA_FCC_2P4_C2_CH7,
    NVRAM_PARA_FCC_2P4_C2_CH8,
    NVRAM_PARA_FCC_2P4_C2_CH9,
    NVRAM_PARA_FCC_2P4_C2_CH10,
    NVRAM_PARA_FCC_2P4_C2_CH11,
    NVRAM_PARA_FCC_2P4_C2_CH12,
    NVRAM_PARA_FCC_2P4_C2_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_FCC_6G_20M_C2,
    NVRAM_PARA_FCC_6G_40M_C2,
    NVRAM_PARA_FCC_6G_80M_C2,
    NVRAM_PARA_FCC_SUB_SIDE_6G_20M_C2,
    NVRAM_PARA_FCC_SUB_SIDE_6G_40M_C2,
    NVRAM_PARA_FCC_SUB_SIDE_6G_80M_C2,
    NVRAM_PARA_FCC_6G_160M_C2,
#endif
    NVRAM_PARA_FCC_C2_END_INDEX_BUTT,

    /* FCC C3边带最大目标发射功率 */
    NVRAM_PARA_FCC_C3_START_INDEX,
    NVRAM_PARA_FCC_5G_20M_C3 = NVRAM_PARA_FCC_C3_START_INDEX,
    NVRAM_PARA_FCC_5G_40M_C3,
    NVRAM_PARA_FCC_5G_80M_C3,
    NVRAM_PARA_FCC_5G_160M_C3,
    NVRAM_PARA_FCC_2P4_C3_CH1,
    NVRAM_PARA_FCC_2P4_C3_CH2,
    NVRAM_PARA_FCC_2P4_C3_CH3,
    NVRAM_PARA_FCC_2P4_C3_CH4,
    NVRAM_PARA_FCC_2P4_C3_CH5,
    NVRAM_PARA_FCC_2P4_C3_CH6,
    NVRAM_PARA_FCC_2P4_C3_CH7,
    NVRAM_PARA_FCC_2P4_C3_CH8,
    NVRAM_PARA_FCC_2P4_C3_CH9,
    NVRAM_PARA_FCC_2P4_C3_CH10,
    NVRAM_PARA_FCC_2P4_C3_CH11,
    NVRAM_PARA_FCC_2P4_C3_CH12,
    NVRAM_PARA_FCC_2P4_C3_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_FCC_6G_20M_C3,
    NVRAM_PARA_FCC_6G_40M_C3,
    NVRAM_PARA_FCC_6G_80M_C3,
    NVRAM_PARA_FCC_SUB_SIDE_6G_20M_C3,
    NVRAM_PARA_FCC_SUB_SIDE_6G_40M_C3,
    NVRAM_PARA_FCC_SUB_SIDE_6G_80M_C3,
    NVRAM_PARA_FCC_6G_160M_C3,
#endif
    NVRAM_PARA_FCC_C3_END_INDEX_BUTT,

    /* CE C0边带最大目标发射功率 */
    NVRAM_PARA_CE_C0_START_INDEX,
    NVRAM_PARA_CE_5G_20M_C0 = NVRAM_PARA_CE_C0_START_INDEX,
    NVRAM_PARA_CE_5G_40M_C0,
    NVRAM_PARA_CE_5G_80M_C0,
    NVRAM_PARA_CE_5G_160M_C0,
    NVRAM_PARA_CE_2P4_C0_CH1,
    NVRAM_PARA_CE_2P4_C0_CH2,
    NVRAM_PARA_CE_2P4_C0_CH3,
    NVRAM_PARA_CE_2P4_C0_CH4,
    NVRAM_PARA_CE_2P4_C0_CH5,
    NVRAM_PARA_CE_2P4_C0_CH6,
    NVRAM_PARA_CE_2P4_C0_CH7,
    NVRAM_PARA_CE_2P4_C0_CH8,
    NVRAM_PARA_CE_2P4_C0_CH9,
    NVRAM_PARA_CE_2P4_C0_CH10,
    NVRAM_PARA_CE_2P4_C0_CH11,
    NVRAM_PARA_CE_2P4_C0_CH12,
    NVRAM_PARA_CE_2P4_C0_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_CE_6G_20M_C0,
    NVRAM_PARA_CE_6G_40M_C0,
    NVRAM_PARA_CE_6G_80M_C0,
    NVRAM_PARA_CE_SUB_SIDE_6G_20M_C0,
    NVRAM_PARA_CE_SUB_SIDE_6G_40M_C0,
    NVRAM_PARA_CE_SUB_SIDE_6G_80M_C0,
    NVRAM_PARA_CE_6G_160M_C0,
#endif
    NVRAM_PARA_CE_C0_END_INDEX_BUTT,

    /* CE C1边带最大目标发射功率 */
    NVRAM_PARA_CE_C1_START_INDEX,
    NVRAM_PARA_CE_5G_20M_C1 = NVRAM_PARA_CE_C1_START_INDEX,
    NVRAM_PARA_CE_5G_40M_C1,
    NVRAM_PARA_CE_5G_80M_C1,
    NVRAM_PARA_CE_5G_160M_C1,
    NVRAM_PARA_CE_2P4_C1_CH1,
    NVRAM_PARA_CE_2P4_C1_CH2,
    NVRAM_PARA_CE_2P4_C1_CH3,
    NVRAM_PARA_CE_2P4_C1_CH4,
    NVRAM_PARA_CE_2P4_C1_CH5,
    NVRAM_PARA_CE_2P4_C1_CH6,
    NVRAM_PARA_CE_2P4_C1_CH7,
    NVRAM_PARA_CE_2P4_C1_CH8,
    NVRAM_PARA_CE_2P4_C1_CH9,
    NVRAM_PARA_CE_2P4_C1_CH10,
    NVRAM_PARA_CE_2P4_C1_CH11,
    NVRAM_PARA_CE_2P4_C1_CH12,
    NVRAM_PARA_CE_2P4_C1_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_CE_6G_20M_C1,
    NVRAM_PARA_CE_6G_40M_C1,
    NVRAM_PARA_CE_6G_80M_C1,
    NVRAM_PARA_CE_SUB_SIDE_6G_20M_C1,
    NVRAM_PARA_CE_SUB_SIDE_6G_40M_C1,
    NVRAM_PARA_CE_SUB_SIDE_6G_80M_C1,
    NVRAM_PARA_CE_6G_160M_C1,
#endif
    NVRAM_PARA_CE_C1_END_INDEX_BUTT,

    /* CE C2边带最大目标发射功率 */
    NVRAM_PARA_CE_C2_START_INDEX,
    NVRAM_PARA_CE_5G_20M_C2 = NVRAM_PARA_CE_C2_START_INDEX,
    NVRAM_PARA_CE_5G_40M_C2,
    NVRAM_PARA_CE_5G_80M_C2,
    NVRAM_PARA_CE_5G_160M_C2,
    NVRAM_PARA_CE_2P4_C2_CH1,
    NVRAM_PARA_CE_2P4_C2_CH2,
    NVRAM_PARA_CE_2P4_C2_CH3,
    NVRAM_PARA_CE_2P4_C2_CH4,
    NVRAM_PARA_CE_2P4_C2_CH5,
    NVRAM_PARA_CE_2P4_C2_CH6,
    NVRAM_PARA_CE_2P4_C2_CH7,
    NVRAM_PARA_CE_2P4_C2_CH8,
    NVRAM_PARA_CE_2P4_C2_CH9,
    NVRAM_PARA_CE_2P4_C2_CH10,
    NVRAM_PARA_CE_2P4_C2_CH11,
    NVRAM_PARA_CE_2P4_C2_CH12,
    NVRAM_PARA_CE_2P4_C2_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_CE_6G_20M_C2,
    NVRAM_PARA_CE_6G_40M_C2,
    NVRAM_PARA_CE_6G_80M_C2,
    NVRAM_PARA_CE_SUB_SIDE_6G_20M_C2,
    NVRAM_PARA_CE_SUB_SIDE_6G_40M_C2,
    NVRAM_PARA_CE_SUB_SIDE_6G_80M_C2,
    NVRAM_PARA_CE_6G_160M_C2,
#endif
    NVRAM_PARA_CE_C2_END_INDEX_BUTT,

    /* CE C3边带最大目标发射功率 */
    NVRAM_PARA_CE_C3_START_INDEX,
    NVRAM_PARA_CE_5G_20M_C3 = NVRAM_PARA_CE_C3_START_INDEX,
    NVRAM_PARA_CE_5G_40M_C3,
    NVRAM_PARA_CE_5G_80M_C3,
    NVRAM_PARA_CE_5G_160M_C3,
    NVRAM_PARA_CE_2P4_C3_CH1,
    NVRAM_PARA_CE_2P4_C3_CH2,
    NVRAM_PARA_CE_2P4_C3_CH3,
    NVRAM_PARA_CE_2P4_C3_CH4,
    NVRAM_PARA_CE_2P4_C3_CH5,
    NVRAM_PARA_CE_2P4_C3_CH6,
    NVRAM_PARA_CE_2P4_C3_CH7,
    NVRAM_PARA_CE_2P4_C3_CH8,
    NVRAM_PARA_CE_2P4_C3_CH9,
    NVRAM_PARA_CE_2P4_C3_CH10,
    NVRAM_PARA_CE_2P4_C3_CH11,
    NVRAM_PARA_CE_2P4_C3_CH12,
    NVRAM_PARA_CE_2P4_C3_CH13,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_CE_6G_20M_C3,
    NVRAM_PARA_CE_6G_40M_C3,
    NVRAM_PARA_CE_6G_80M_C3,
    NVRAM_PARA_CE_SUB_SIDE_6G_20M_C3,
    NVRAM_PARA_CE_SUB_SIDE_6G_40M_C3,
    NVRAM_PARA_CE_SUB_SIDE_6G_80M_C3,
    NVRAM_PARA_CE_6G_160M_C3,
#endif
    NVRAM_PARA_CE_C3_END_INDEX_BUTT,

    /* C0 SAR CONTROL */
    NVRAM_PARA_C0_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_C0 = NVRAM_PARA_C0_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_C0,
    NVRAM_PARA_SAR_LVL3_C0,
    NVRAM_PARA_SAR_LVL4_C0,
    NVRAM_PARA_SAR_LVL5_C0,
    NVRAM_PARA_SAR_LVL6_C0,
    NVRAM_PARA_SAR_LVL7_C0,
    NVRAM_PARA_SAR_LVL8_C0,
    NVRAM_PARA_SAR_LVL9_C0,
    NVRAM_PARA_SAR_LVL10_C0,
    NVRAM_PARA_SAR_LVL11_C0,
    NVRAM_PARA_SAR_LVL12_C0,
    NVRAM_PARA_SAR_LVL13_C0,
    NVRAM_PARA_SAR_LVL14_C0,
    NVRAM_PARA_SAR_LVL15_C0,
    NVRAM_PARA_SAR_LVL16_C0,
    NVRAM_PARA_SAR_LVL17_C0,
    NVRAM_PARA_SAR_LVL18_C0,
    NVRAM_PARA_SAR_LVL19_C0,
    NVRAM_PARA_SAR_LVL20_C0,
    NVRAM_PARA_C0_SAR_END_INDEX_BUTT,

    /* C1 SAR CONTROL */
    NVRAM_PARA_C1_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_C1 = NVRAM_PARA_C1_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_C1,
    NVRAM_PARA_SAR_LVL3_C1,
    NVRAM_PARA_SAR_LVL4_C1,
    NVRAM_PARA_SAR_LVL5_C1,
    NVRAM_PARA_SAR_LVL6_C1,
    NVRAM_PARA_SAR_LVL7_C1,
    NVRAM_PARA_SAR_LVL8_C1,
    NVRAM_PARA_SAR_LVL9_C1,
    NVRAM_PARA_SAR_LVL10_C1,
    NVRAM_PARA_SAR_LVL11_C1,
    NVRAM_PARA_SAR_LVL12_C1,
    NVRAM_PARA_SAR_LVL13_C1,
    NVRAM_PARA_SAR_LVL14_C1,
    NVRAM_PARA_SAR_LVL15_C1,
    NVRAM_PARA_SAR_LVL16_C1,
    NVRAM_PARA_SAR_LVL17_C1,
    NVRAM_PARA_SAR_LVL18_C1,
    NVRAM_PARA_SAR_LVL19_C1,
    NVRAM_PARA_SAR_LVL20_C1,
    NVRAM_PARA_C1_SAR_END_INDEX_BUTT,

    /* C2 SAR CONTROL */
    NVRAM_PARA_C2_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_C2 = NVRAM_PARA_C2_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_C2,
    NVRAM_PARA_SAR_LVL3_C2,
    NVRAM_PARA_SAR_LVL4_C2,
    NVRAM_PARA_SAR_LVL5_C2,
    NVRAM_PARA_SAR_LVL6_C2,
    NVRAM_PARA_SAR_LVL7_C2,
    NVRAM_PARA_SAR_LVL8_C2,
    NVRAM_PARA_SAR_LVL9_C2,
    NVRAM_PARA_SAR_LVL10_C2,
    NVRAM_PARA_SAR_LVL11_C2,
    NVRAM_PARA_SAR_LVL12_C2,
    NVRAM_PARA_SAR_LVL13_C2,
    NVRAM_PARA_SAR_LVL14_C2,
    NVRAM_PARA_SAR_LVL15_C2,
    NVRAM_PARA_SAR_LVL16_C2,
    NVRAM_PARA_SAR_LVL17_C2,
    NVRAM_PARA_SAR_LVL18_C2,
    NVRAM_PARA_SAR_LVL19_C2,
    NVRAM_PARA_SAR_LVL20_C2,
    NVRAM_PARA_C2_SAR_END_INDEX_BUTT,

    /* C3 SAR CONTROL */
    NVRAM_PARA_C3_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_C3 = NVRAM_PARA_C3_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_C3,
    NVRAM_PARA_SAR_LVL3_C3,
    NVRAM_PARA_SAR_LVL4_C3,
    NVRAM_PARA_SAR_LVL5_C3,
    NVRAM_PARA_SAR_LVL6_C3,
    NVRAM_PARA_SAR_LVL7_C3,
    NVRAM_PARA_SAR_LVL8_C3,
    NVRAM_PARA_SAR_LVL9_C3,
    NVRAM_PARA_SAR_LVL10_C3,
    NVRAM_PARA_SAR_LVL11_C3,
    NVRAM_PARA_SAR_LVL12_C3,
    NVRAM_PARA_SAR_LVL13_C3,
    NVRAM_PARA_SAR_LVL14_C3,
    NVRAM_PARA_SAR_LVL15_C3,
    NVRAM_PARA_SAR_LVL16_C3,
    NVRAM_PARA_SAR_LVL17_C3,
    NVRAM_PARA_SAR_LVL18_C3,
    NVRAM_PARA_SAR_LVL19_C3,
    NVRAM_PARA_SAR_LVL20_C3,
    NVRAM_PARA_C3_SAR_END_INDEX_BUTT,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    /* 6G C0 SAR CONTROL */
    NVRAM_PARA_6G_C0_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_6G_C0 = NVRAM_PARA_6G_C0_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_6G_C0,
    NVRAM_PARA_SAR_LVL3_6G_C0,
    NVRAM_PARA_SAR_LVL4_6G_C0,
    NVRAM_PARA_SAR_LVL5_6G_C0,
    NVRAM_PARA_SAR_LVL6_6G_C0,
    NVRAM_PARA_SAR_LVL7_6G_C0,
    NVRAM_PARA_SAR_LVL8_6G_C0,
    NVRAM_PARA_SAR_LVL9_6G_C0,
    NVRAM_PARA_SAR_LVL10_6G_C0,
    NVRAM_PARA_SAR_LVL11_6G_C0,
    NVRAM_PARA_SAR_LVL12_6G_C0,
    NVRAM_PARA_SAR_LVL13_6G_C0,
    NVRAM_PARA_SAR_LVL14_6G_C0,
    NVRAM_PARA_SAR_LVL15_6G_C0,
    NVRAM_PARA_SAR_LVL16_6G_C0,
    NVRAM_PARA_SAR_LVL17_6G_C0,
    NVRAM_PARA_SAR_LVL18_6G_C0,
    NVRAM_PARA_SAR_LVL19_6G_C0,
    NVRAM_PARA_SAR_LVL20_6G_C0,
    NVRAM_PARA_6G_C0_SAR_END_INDEX_BUTT,

    /* 6G C1 SAR CONTROL */
    NVRAM_PARA_6G_C1_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_6G_C1 = NVRAM_PARA_6G_C1_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_6G_C1,
    NVRAM_PARA_SAR_LVL3_6G_C1,
    NVRAM_PARA_SAR_LVL4_6G_C1,
    NVRAM_PARA_SAR_LVL5_6G_C1,
    NVRAM_PARA_SAR_LVL6_6G_C1,
    NVRAM_PARA_SAR_LVL7_6G_C1,
    NVRAM_PARA_SAR_LVL8_6G_C1,
    NVRAM_PARA_SAR_LVL9_6G_C1,
    NVRAM_PARA_SAR_LVL10_6G_C1,
    NVRAM_PARA_SAR_LVL11_6G_C1,
    NVRAM_PARA_SAR_LVL12_6G_C1,
    NVRAM_PARA_SAR_LVL13_6G_C1,
    NVRAM_PARA_SAR_LVL14_6G_C1,
    NVRAM_PARA_SAR_LVL15_6G_C1,
    NVRAM_PARA_SAR_LVL16_6G_C1,
    NVRAM_PARA_SAR_LVL17_6G_C1,
    NVRAM_PARA_SAR_LVL18_6G_C1,
    NVRAM_PARA_SAR_LVL19_6G_C1,
    NVRAM_PARA_SAR_LVL20_6G_C1,
    NVRAM_PARA_6G_C1_SAR_END_INDEX_BUTT,

    /* 6G C2 SAR CONTROL */
    NVRAM_PARA_6G_C2_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_6G_C2 = NVRAM_PARA_6G_C2_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_6G_C2,
    NVRAM_PARA_SAR_LVL3_6G_C2,
    NVRAM_PARA_SAR_LVL4_6G_C2,
    NVRAM_PARA_SAR_LVL5_6G_C2,
    NVRAM_PARA_SAR_LVL6_6G_C2,
    NVRAM_PARA_SAR_LVL7_6G_C2,
    NVRAM_PARA_SAR_LVL8_6G_C2,
    NVRAM_PARA_SAR_LVL9_6G_C2,
    NVRAM_PARA_SAR_LVL10_6G_C2,
    NVRAM_PARA_SAR_LVL11_6G_C2,
    NVRAM_PARA_SAR_LVL12_6G_C2,
    NVRAM_PARA_SAR_LVL13_6G_C2,
    NVRAM_PARA_SAR_LVL14_6G_C2,
    NVRAM_PARA_SAR_LVL15_6G_C2,
    NVRAM_PARA_SAR_LVL16_6G_C2,
    NVRAM_PARA_SAR_LVL17_6G_C2,
    NVRAM_PARA_SAR_LVL18_6G_C2,
    NVRAM_PARA_SAR_LVL19_6G_C2,
    NVRAM_PARA_SAR_LVL20_6G_C2,
    NVRAM_PARA_6G_C2_SAR_END_INDEX_BUTT,

    /* 6G C3 SAR CONTROL */
    NVRAM_PARA_6G_C3_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL1_6G_C3 = NVRAM_PARA_6G_C3_SAR_START_INDEX,
    NVRAM_PARA_SAR_LVL2_6G_C3,
    NVRAM_PARA_SAR_LVL3_6G_C3,
    NVRAM_PARA_SAR_LVL4_6G_C3,
    NVRAM_PARA_SAR_LVL5_6G_C3,
    NVRAM_PARA_SAR_LVL6_6G_C3,
    NVRAM_PARA_SAR_LVL7_6G_C3,
    NVRAM_PARA_SAR_LVL8_6G_C3,
    NVRAM_PARA_SAR_LVL9_6G_C3,
    NVRAM_PARA_SAR_LVL10_6G_C3,
    NVRAM_PARA_SAR_LVL11_6G_C3,
    NVRAM_PARA_SAR_LVL12_6G_C3,
    NVRAM_PARA_SAR_LVL13_6G_C3,
    NVRAM_PARA_SAR_LVL14_6G_C3,
    NVRAM_PARA_SAR_LVL15_6G_C3,
    NVRAM_PARA_SAR_LVL16_6G_C3,
    NVRAM_PARA_SAR_LVL17_6G_C3,
    NVRAM_PARA_SAR_LVL18_6G_C3,
    NVRAM_PARA_SAR_LVL19_6G_C3,
    NVRAM_PARA_SAR_LVL20_6G_C3,
    NVRAM_PARA_6G_C3_SAR_END_INDEX_BUTT,
#endif
#ifdef _PRE_WLAN_FEATURE_TAS_ANT_SWITCH
    NVRAM_PARA_TAS_ANT_SWITCH_EN,
    /* TAS PWR CONTROL */
    NVRAM_PARA_TAS_PWR_CTRL_2G,
    NVRAM_PARA_TAS_PWR_CTRL_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_TAS_PWR_CTRL_6G,
#endif
#endif
    NVRAM_PARA_5G_FCC_CE_HIGH_BAND_MAX_PWR,

    NVRAM_PARA_TPC_RU_POWER_2G_20M,
    NVRAM_PARA_TPC_RU_POWER_2G_40M,
    NVRAM_PARA_TPC_RU_POWER_5G_20M,
    NVRAM_PARA_TPC_RU_POWER_5G_40M,
    NVRAM_PARA_TPC_RU_POWER_5G_80M,
    NVRAM_PARA_TPC_RU_POWER_5G_160M,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_TPC_RU_POWER_6G_20M,
    NVRAM_PARA_TPC_RU_POWER_6G_40M,
    NVRAM_PARA_TPC_RU_POWER_6G_80M,
    NVRAM_PARA_TPC_RU_POWER_6G_160M,
#endif
    NVRAM_PARA_TPC_RU_MAX_POWER_2G_C0,
    NVRAM_PARA_TPC_RU_MAX_POWER_2G_C1,
    NVRAM_PARA_TPC_RU_MAX_POWER_2G_C2,
    NVRAM_PARA_TPC_RU_MAX_POWER_2G_C3,
    NVRAM_PARA_TPC_RU_MAX_POWER_5G_C0,
    NVRAM_PARA_TPC_RU_MAX_POWER_5G_C1,
    NVRAM_PARA_TPC_RU_MAX_POWER_5G_C2,
    NVRAM_PARA_TPC_RU_MAX_POWER_5G_C3,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_TPC_RU_MAX_POWER_6G_C0,
    NVRAM_PARA_TPC_RU_MAX_POWER_6G_C1,
    NVRAM_PARA_TPC_RU_MAX_POWER_6G_C2,
    NVRAM_PARA_TPC_RU_MAX_POWER_6G_C3,
#endif
    NVRAM_PARA_TPC_RU_MAX_POWER_2G,
    NVRAM_PARA_TPC_RU_MAX_POWER_5G,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    NVRAM_PARA_TPC_RU_MAX_POWER_6G,
#endif
    NVRAM_PARA_PWR_INDEX_BUTT,
} wlan_nvram_cfg_enum;

/* 03产侧nvram参数 */
typedef enum {
    /* pa */
    WLAN_CFG_DYN_POW_RATIO_PA2GCCKA0,
    WLAN_CFG_DYN_POW_RATIO_PA2GA0,
    WLAN_CFG_DYN_POW_RATIO_PA2G40A0,
    WLAN_CFG_DYN_POW_RATIO_PA5GA0,
    /* add 5g low power part */
    WLAN_CFG_DYN_POW_RATIO_PA5GA0_LOW,
    /* 5g Band1& 2g CW */
    WLAN_CFG_DYN_POW_RATIO_PA5GA0_BAND1,
    WLAN_CFG_DYN_POW_RATIO_PA5GA0_BAND1_LOW,

    WLAN_CFG_DYN_POW_RATIO_PA2GCCKA1,
    WLAN_CFG_DYN_POW_RATIO_PA2GA1,
    WLAN_CFG_DYN_POW_RATIO_PA2G40A1,
    WLAN_CFG_DYN_POW_RATIO_PA5GA1,
    WLAN_CFG_DYN_POW_RATIO_PA5GA1_LOW,
    /* 5g Band1& 2g CW */
    WLAN_CFG_DYN_POW_RATIO_PA5GA1_BAND1,
    WLAN_CFG_DYN_POW_RATIO_PA5GA1_BAND1_LOW,

    WLAN_CFG_DYN_POW_RATIO_PA2GCCKA2,
    WLAN_CFG_DYN_POW_RATIO_PA2GA2,
    WLAN_CFG_DYN_POW_RATIO_PA2G40A2,
    WLAN_CFG_DYN_POW_RATIO_PA5GA2,
    WLAN_CFG_DYN_POW_RATIO_PA5GA2_LOW,
    /* 5g Band1& 2g CW */
    WLAN_CFG_DYN_POW_RATIO_PA5GA2_BAND1,
    WLAN_CFG_DYN_POW_RATIO_PA5GA2_BAND1_LOW,

    WLAN_CFG_DYN_POW_RATIO_PA2GCCKA3,
    WLAN_CFG_DYN_POW_RATIO_PA2GA3,
    WLAN_CFG_DYN_POW_RATIO_PA2G40A3,
    WLAN_CFG_DYN_POW_RATIO_PA5GA3,
    WLAN_CFG_DYN_POW_RATIO_PA5GA3_LOW,
    /* 5g Band1& 2g CW */
    WLAN_CFG_DYN_POW_RATIO_PA5GA3_BAND1,
    WLAN_CFG_DYN_POW_RATIO_PA5GA3_BAND1_LOW,
    /* 6G Band 0~14 */
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND0,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND1,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND2,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND3,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND4,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND5,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND6,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND7,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND8,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND9,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND10,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND11,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND12,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND13,
    WLAN_CFG_DYN_POW_RATIO_PA6G_BAND14,
#endif
    WLAN_CFG_DYN_POW_MUFREQ_2GCCK_C0,
    WLAN_CFG_DYN_POW_MUFREQ_2G20_C0,
    WLAN_CFG_DYN_POW_MUFREQ_2G40_C0,
    WLAN_CFG_DYN_POW_MUFREQ_5G160_C0,

    WLAN_CFG_DYN_POW_MUFREQ_2GCCK_C1,
    WLAN_CFG_DYN_POW_MUFREQ_2G20_C1,
    WLAN_CFG_DYN_POW_MUFREQ_2G40_C1,
    WLAN_CFG_DYN_POW_MUFREQ_5G160_C1,

    WLAN_CFG_DYN_POW_MUFREQ_2GCCK_C2,
    WLAN_CFG_DYN_POW_MUFREQ_2G20_C2,
    WLAN_CFG_DYN_POW_MUFREQ_2G40_C2,
    WLAN_CFG_DYN_POW_MUFREQ_5G160_C2,

    WLAN_CFG_DYN_POW_MUFREQ_2GCCK_C3,
    WLAN_CFG_DYN_POW_MUFREQ_2G20_C3,
    WLAN_CFG_DYN_POW_MUFREQ_2G40_C3,
    WLAN_CFG_DYN_POW_MUFREQ_5G160_C3,
    /* DPN */
    WLAN_CFG_DYN_POW_2G_CORE0_DPN_11B,
    WLAN_CFG_DYN_POW_2G_CORE1_DPN_11B,
    WLAN_CFG_DYN_POW_2G_CORE2_DPN_11B,
    WLAN_CFG_DYN_POW_2G_CORE3_DPN_11B,
    WLAN_CFG_DYN_POW_2G_CORE0_DPN_OFDM_20M,
    WLAN_CFG_DYN_POW_2G_CORE1_DPN_OFDM_20M,
    WLAN_CFG_DYN_POW_2G_CORE2_DPN_OFDM_20M,
    WLAN_CFG_DYN_POW_2G_CORE3_DPN_OFDM_20M,
    WLAN_CFG_DYN_POW_2G_CORE0_DPN_OFDM_40M,
    WLAN_CFG_DYN_POW_2G_CORE1_DPN_OFDM_40M,
    WLAN_CFG_DYN_POW_2G_CORE2_DPN_OFDM_40M,
    WLAN_CFG_DYN_POW_2G_CORE3_DPN_OFDM_40M,

    WLAN_CFG_DYN_POW_5G_CORE0_DPN_20M,
    WLAN_CFG_DYN_POW_5G_CORE1_DPN_20M,
    WLAN_CFG_DYN_POW_5G_CORE2_DPN_20M,
    WLAN_CFG_DYN_POW_5G_CORE3_DPN_20M,
    WLAN_CFG_DYN_POW_5G_CORE0_DPN_40M,
    WLAN_CFG_DYN_POW_5G_CORE1_DPN_40M,
    WLAN_CFG_DYN_POW_5G_CORE2_DPN_40M,
    WLAN_CFG_DYN_POW_5G_CORE3_DPN_40M,
    WLAN_CFG_DYN_POW_5G_CORE0_DPN_80M,
    WLAN_CFG_DYN_POW_5G_CORE1_DPN_80M,
    WLAN_CFG_DYN_POW_5G_CORE2_DPN_80M,
    WLAN_CFG_DYN_POW_5G_CORE3_DPN_80M,
    WLAN_CFG_DYN_POW_5G_CORE0_DPN_160M,
    WLAN_CFG_DYN_POW_5G_CORE1_DPN_160M,
    WLAN_CFG_DYN_POW_5G_CORE2_DPN_160M,
    WLAN_CFG_DYN_POW_5G_CORE3_DPN_160M,
#ifdef _PRE_WLAN_FEATURE_6G_EXTEND
    WLAN_CFG_DYN_POW_6G_CORE0_DPN_20M,
    WLAN_CFG_DYN_POW_6G_CORE1_DPN_20M,
    WLAN_CFG_DYN_POW_6G_CORE2_DPN_20M,
    WLAN_CFG_DYN_POW_6G_CORE3_DPN_20M,
    WLAN_CFG_DYN_POW_6G_CORE0_DPN_40M,
    WLAN_CFG_DYN_POW_6G_CORE1_DPN_40M,
    WLAN_CFG_DYN_POW_6G_CORE2_DPN_40M,
    WLAN_CFG_DYN_POW_6G_CORE3_DPN_40M,
    WLAN_CFG_DYN_POW_6G_CORE0_DPN_80M,
    WLAN_CFG_DYN_POW_6G_CORE1_DPN_80M,
    WLAN_CFG_DYN_POW_6G_CORE2_DPN_80M,
    WLAN_CFG_DYN_POW_6G_CORE3_DPN_80M,
    WLAN_CFG_DYN_POW_6G_CORE0_DPN_160M,
    WLAN_CFG_DYN_POW_6G_CORE1_DPN_160M,
    WLAN_CFG_DYN_POW_6G_CORE2_DPN_160M,
    WLAN_CFG_DYN_POW_6G_CORE3_DPN_160M,
#endif
    WLAN_CFG_DYN_POW_PARAMS_BUTT,
} wlan_dyn_pow_cfg_enum;
typedef enum {
    CUST_CFG_UINT8,
    CUST_CFG_INT8,
    CUST_CFG_UINT16,
    CUST_CFG_INT16,
    CUST_CFG_UINT32,
    CUST_CFG_INT32,
} cust_data_type;

typedef enum {
    CUST_CHECK_MAX,
    CUST_CHECK_MIN,
    CUST_CHECK_VAL,
} cust_data_check_type;

typedef struct {
    char *name;          /* 定制化项名称 */
    int case_entry;      /* 定制化项枚举变量 */
    void *data_addr;     /* 定制化数据存储地址 */
    uint8_t data_type;   /* 定制化数据存储类型(占用地址) */
    uint8_t data_num;    /* 定制化项中定义数据个数 */
    oal_bool_enum_uint8 en_value_state;  /* 定制化项读取成功状态 */
} wlan_cust_cfg_cmd;

typedef struct {
    void *data_addr;        /* 数据存放地址 */
    uint8_t data_type;      /* 数据类型 */
    uint8_t check_type;     /* 检查类型 */
    int32_t max_val;        /* 最大值 */
    int32_t min_val;        /* 最小值 */
    int32_t default_val;    /* 默认值 */
} wlan_cust_range_stru;

/*  host侧定制化参数结构体  */
typedef struct {
    uint16_t throughput_irq_high;
    uint16_t throughput_irq_low;
    uint32_t irq_pps_high;
    uint32_t irq_pps_low;
    uint16_t lock_cpu_th_high;
    uint16_t lock_cpu_th_low;
    uint16_t dma_latency_val;
    oal_bool_enum_uint8 en_irq_affinity; /* 中断开关 */
} cust_freq_lock_ctl_stru;


typedef struct {
    /* 定制化硬件聚合是否生效,默认为软件聚合 */
    uint8_t ampdu_hw_en;
    uint16_t us_remain_hw_cnt;
    uint16_t throughput_high;
    uint16_t throughput_low;
} cust_tx_ampdu_hw_stru;

typedef struct {
    /* 定制化是否打开amsdu大包聚合 */
    uint8_t large_amsdu_en;
    /* 当前聚合是否为amsdu聚合 */
    uint16_t throughput_high;
    uint16_t throughput_low;
    uint16_t throughput_middle;
} cust_tx_large_amsdu_stru;

typedef enum {
    CUST_MIRACAST_SINK_SWITCH = 0,
    CUST_MIRACAST_REDUCE_LOG_SWITCH = 1,
    CUST_CORE_BIND_SWITCH = 2,
    CUST_FEATURE_SWITCH_BUTT
} cust_hmac_feature_switch_enum;

typedef struct {
    uint8_t buf_en;
    uint16_t throughput_high;
    uint16_t throughput_low;
    uint16_t throughput_high_40m;
    uint16_t throughput_low_40m;
    uint16_t throughput_high_80m;
    uint16_t throughput_low_80m;
    uint16_t throughput_high_160m;
    uint16_t throughput_low_160m;
    uint16_t buf_userctl_high;
    uint16_t buf_userctl_low;
    uint8_t  buf_userctl_test_en;
} cust_tcp_ack_buf_stru;

typedef struct {
    /* 定制化小包amsdu开关 */
    uint8_t en_switch;
    uint16_t throughput_high;
    uint16_t throughput_low;
    uint16_t pps_high;
    uint16_t pps_low;
} cust_small_amsdu_stru;
typedef struct {
    /* 定制化是否打开tcp ack过滤 */
    uint8_t filter_en;
    uint16_t throughput_high;
    uint16_t throughput_low;
} cust_tcp_ack_filt_stru;

typedef struct {
    uint8_t  switch_en;     /* 定制化根据吞吐动态bypass extLNA开关 */
    uint16_t throughput_high;
    uint16_t throughput_low;
} cust_rx_dyn_bypass_extlna_stru;

typedef struct {
    cust_freq_lock_ctl_stru freq_lock;
    cust_tx_ampdu_hw_stru tx_ampdu;
    cust_tx_large_amsdu_stru large_amsdu;     /* 定制化amsdu大包聚合相关参数 */
    cust_small_amsdu_stru small_amsdu;   /* 定制化小包amsdu参数 */

    uint8_t host_rx_ampdu_amsdu;
    oal_bool_enum_uint8 wlan_11ac2g_switch;
    oal_bool_enum_uint8 wlan_probe_resp_mode;
    uint8_t wlan_ps_mode;

    oal_bool_enum_uint8 en_hmac_feature_switch[CUST_FEATURE_SWITCH_BUTT];
    /* addba rsp回复的聚合BAW SIZE */
    uint16_t rx_buffer_size;

    cust_tcp_ack_buf_stru tcp_ack_buf;
    cust_tcp_ack_filt_stru tcp_ack_filt;
    cust_rx_dyn_bypass_extlna_stru dyn_extlna;

    oal_bool_enum_uint8 lock_max_cpu_freq;
    unsigned char roam_switch;
    uint16_t rsv;
} cust_host_cfg_stru;

extern cust_host_cfg_stru g_cust_host;
extern mac_cust_feature_cap_sru g_cust_cap;
extern mac_cust_dyn_pow_sru g_cust_dyn_pow;

extern mac_cus_rf_cali_stru g_cust_rf_cali;
extern mac_customize_rf_front_sru g_cust_rf_front;

oal_bool_enum_uint8 hwifi_get_cust_read_status(int32_t cus_tag, int32_t cfg_id);
uint32_t hwifi_custom_host_read_cfg_init_1106(void);
uint32_t hwifi_hcc_customize_h2d_data_cfg_1106(void);
void hwifi_show_customize_info_1106(void);
void hwifi_rf_cali_data_host_addr_init_1106(void);
uint32_t hwifi_config_init_nvram_main_1106(oal_net_device_stru *pst_cfg_net_dev);
void hwifi_config_cpu_freq_ini_param_1106(void);
void hwifi_config_host_global_ini_param_1106(void);
uint32_t wal_custom_cali_1106(void);
void wal_send_cali_data_1106(oal_net_device_stru *cfg_net_dev);
int32_t hwifi_config_init_1106(int32_t cus_tag);
uint32_t hwifi_get_sar_ctrl_params_1106(uint8_t lvl_num, uint8_t *data_addr, uint16_t *data_len,
    uint16_t dest_len);
#endif  // hisi_customize_wifi_hi1106.h
