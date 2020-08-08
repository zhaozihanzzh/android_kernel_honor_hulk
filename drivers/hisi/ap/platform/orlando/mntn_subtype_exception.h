#ifndef __MNTN_SUBTYPE_EXCEPTION_H__
#define __MNTN_SUBTYPE_EXCEPTION_H__ 
#include "soc_acpu_baseaddr_interface.h"
#include "pmic_interface.h"
#include "global_ddr_map.h"
#define PMU_EXCSUBTYPE_REG_OFFSET (PMIC_HRST_REG10_ADDR(0))
enum mmc_exception_subtype
{
 MMC_EXCEPT_INIT_FAIL = 0x0,
 MMC_EXCEPT_CMD_TIMEOUT,
 MMC_EXCEPT_COLDBOOT,
};
enum ddrc_sec_subtype {
 DMSS_UNKNOW_MASTER = 0x0,
 DMSS_LPMCU = 0x1,
 DMSS_IOMCU_M7 = 0x2,
 DMSS_PCIE_1 = 0x3,
 DMSS_PERF_STAT =0x4,
 DMSS_MODEM = 0x5,
 DMSS_DJTAG_M = 0x6,
 DMSS_IOMCU_DMA = 0x7,
 DMSS_UFS = 0x8,
 DMSS_SD = 0x9,
 DMSS_SDIO = 0xa,
 DMSS_CC712 = 0xb,
 DMSS_FD_UL = 0xc,
 DMSS_DPC = 0xd,
 DMSS_USB31OTG = 0xe,
 DMSS_TOP_CSSYS = 0xf,
 DMSS_DMAC = 0x10,
 DMSS_ASP_HIFI = 0x11,
 DMSS_PCIE_0 = 0x12,
 DMSS_ATGS = 0x13,
 DMSS_ASP_DMA = 0x14,
 DMSS_LATMON = 0x15,
 DMSS_ISP = 0x16,
 DMSS_DSS = 0x17,
 DMSS_IPP_SUBSYS_JPGENC = 0x18,
 DMSS_MEDIA_COMMON_CMD = 0x19,
 DMSS_MEDIA_COMMON_RW = 0x1a,
 DMSS_VENC = 0x1b,
 DMSS_VDEC = 0x1c,
 DMSS_IVP = 0x1d,
 DMSS_IPP_SUBSYS_JPGDEC = 0x1e,
 DMSS_IPP_SUBSYS_FD = 0x1f,
 DMSS_IPP_SUBSYS_CPE = 0x20,
 DMSS_IPP_SUBSYS_SLAM = 0x21,
 DMSS_NPU = 0x22,
 DMSS_FCM = 0x23,
 DMSS_GPU = 0x24,
 DMSS_IDI2AXI = 0x25,
 DMSS_HIEPS = 0x26,
};
enum appanic_subtype
{
 HI_APPANIC_RESERVED = 0x0,
 HI_APPANIC_BC_PANIC = 0x1,
 HI_APPANIC_L3CACHE_ECC1 = 0x2,
 HI_APPANIC_SOFTLOCKUP = 0x3,
 HI_APPANIC_OHARDLOCKUP = 0x4,
 HI_APPANIC_HARDLOCKUP = 0x5,
 HI_APPANIC_L3CACHE_ECC2 = 0x6,
 HI_APPANIC_Storage = 0x7,
 HI_APPANIC_ISP = 0x9,
 HI_APPANIC_IVP = 0xa,
 HI_APPANIC_GPU = 0xc,
 HI_APPANIC_MODEM = 0xd,
 HI_APPANIC_CPU0_EDAC_CE = 0x10,
 HI_APPANIC_CPU1_EDAC_CE = 0x11,
 HI_APPANIC_CPU2_EDAC_CE = 0x12,
 HI_APPANIC_CPU3_EDAC_CE = 0x13,
 HI_APPANIC_CPU4_EDAC_CE = 0x14,
 HI_APPANIC_CPU5_EDAC_CE = 0x15,
 HI_APPANIC_CPU6_EDAC_CE = 0x16,
 HI_APPANIC_CPU7_EDAC_CE = 0x17,
 HI_APPANIC_CPU0_EDAC_UE = 0x18,
 HI_APPANIC_CPU1_EDAC_UE = 0x19,
 HI_APPANIC_CPU2_EDAC_UE = 0x1a,
 HI_APPANIC_CPU3_EDAC_UE = 0x1b,
 HI_APPANIC_CPU4_EDAC_UE = 0x1c,
 HI_APPANIC_CPU5_EDAC_UE = 0x1d,
 HI_APPANIC_CPU6_EDAC_UE = 0x1e,
 HI_APPANIC_CPU7_EDAC_UE = 0x1f,
 HI_APPANIC_L3_EDAC_CE = 0x20,
 HI_APPANIC_L3_EDAC_UE = 0x21,
 HI_APPANIC_LB = 0x22,
};
enum apbl31panic_subtype
{
 HI_APBL31PANIC_RESERVED = 0x0,
 HI_APBL31PANIC_ASSERT = 0x1,
};
enum apvndpanic_subtype
{
 HI_APVNDPANIC_RESERVED = 0x0,
 HI_APVNDPANIC_CFI = 0x1,
};
enum apwdt_subtype
{
 HI_APWDT_HW = 0x0,
 HI_APWDT_LPM3 = 0x1,
 HI_APWDT_BL31 = 0x2,
 HI_APWDT_BL31LPM3 = 0x3,
 HI_APWDT_AP = 0x4,
 HI_APWDT_BL31AP = 0x6,
 HI_APWDT_APBL31LPM3 = 0x7,
};
enum lpm3_subtype
{
 PSCI_RESERVED = 0x0,
 PSCI_AP_WDT_LOCAL,
 PSCI_AP_WDT_REMOTE,
 PSCI_M3_WDT_LOCAL,
 PSCI_M3_WDT_REMOTE,
 PSCI_REASON_WDT_END,
 PSCI_AP_SYS_PANIC = PSCI_REASON_WDT_END,
 PSCI_M3_SYS_PANIC,
 PSCI_PMUSSI_PANIC,
 PSCI_CLK_ERR,
 PSCI_REGULATOR_ERR,
 PSCI_OCBC_ERR,
 PSCI_DMA_ERR,
 PSCI_NOC_TIMEOUT,
 PSCI_G3D_PWR_ERR,
 PSCI_CPU_PWR_ERR,
 PSCI_TSENSOR_ERR,
 PSCI_CPUDVFS_ERR,
 PSCI_GPUDVFS_ERR,
 PSCI_MEMRP_ERR,
 PSCI_NOC_BUS_IDLE_PEND,
 PSCI_AHB_TIMEOUT,
 PCSI_PERIVOLT_ERR,
 PSCI_REASON_SYS_EXC_END = 0x1f,
 PSCI_REASON_DDR_UNAVAILABLE_BEGIN = 0x20,
 PSCI_DDR_PANIC = PSCI_REASON_DDR_UNAVAILABLE_BEGIN,
 PSCI_DDR_FATAL_ERR,
 PSCI_DDR_SREF_ERR,
 PSCI_DDR_OSC_ERR,
 PSCI_DDR_TMON_LOW,
 PSCI_DDR_TMON_HIGH,
 PSCI_DDR_GATE_ERR,
 PSCI_UCE0_EXC,
 PSCI_UCE1_EXC,
 PSCI_UCE2_EXC,
 PSCI_UCE3_EXC,
 PSCI_DDR_AREF_ALARM,
 PSCI_DDR_RDTIMEOUT,
 PSCI_DDR_PLLUNLOCK_ERR,
 PSCI_DDR_RETRAIN_ERR,
 PSCI_DDR_TMON_ERR,
 PSCI_DDR_DFS_ENBP_ERR,
 PSCI_DDR_DVALID_ERR,
 PSCI_DDR_DFI_SEL_ERR,
 PSCI_DDR_PLLUNLOCK_LP,
 PSCI_DDR_UNKNOWN_ERR,
 PSCI_UCE_EXC,
 PSCI_DDR_LOAD_INSE_TIMEOUT,
 PSCI_DDR_DFS_EXBP_ERR,
 PSCI_DDR_CORE_VOLT_NULL,
 PSCI_DDR_SCENE_ID_ERR,
 PSCI_REASON_DDR_PANIC_END = 0x5f,
 PSCI_DMA_TIMEOUT = 0x60,
 PSCI_SUBPMU0_PANIC,
 PSCI_SUBPMU1_PANIC,
 PSCI_REASON_DDR_UNAVAILABLE_END = 0x7f,
 PSCI_REASON_DDR_AVAILABLE_BEGIN = 0x80,
 PSCI_DDR_DMSS_VOLT_NULL = PSCI_REASON_DDR_AVAILABLE_BEGIN,
 PSCI_DDR_DMSS_VOLT_ERR,
 PSCI_REASON_DDR_AVAILABLE_END = 0x9f,
 PSCI_REASON_OTHERIP_REQ_BEGIN = 0xa0,
 PSCI_OTHERIP_REQ_MODEM,
 PSCI_OTHERIP_REQ_HIFI,
 PSCI_OTHERIP_REQ_IOMCU,
 PSCI_REASON_OTHERIP_REQ_END = 0xaf,
 PSCI_REASON_MAX,
 PSCI_REASON_UNKNOWN = 0xff,
};
enum mem_repair_subtype {
 OMR_PASS_REBOOT = 0x1,
 OMR_REPAIR_FAIL = 0x2,
 OMR_RETEST_FAIL = 0x3,
};
enum npu_subtype
{
 AICORE_EXCP = 0x0,
 AICORE_TIMEOUT,
 TS_RUNNING_EXCP,
 TS_RUNNING_TIMEOUT,
 TS_INIT_EXCP,
 AICPU_INIT_EXCP,
 AICPU_HEARTBEAT_EXCP,
 POWERUP_FAIL,
 POWERDOWN_FAIL,
 NPU_NOC_ERR,
 SMMU_EXCP,
};
enum pmu_subtype
{
        OCP_BUCK0 = 0x01,
        OCP_BUCK1,
        OCP_BUCK2,
        OCP_BUCK3,
        OCP_BUCK4,
        OCP_BUCK5,
        OCP_LDO5,
        OCP_LDO4,
        OCP_LDO3,
        OCP_LDO2,
        OCP_LDO1,
        OCP_LDO0_2,
        OCP_LDO15,
        OCP_LDO14,
        OCP_LDO13,
        OCP_LDO8,
        OCP_LDO6,
        OCP_LDO23,
        OCP_LDO22,
        OCP_LDO21,
        OCP_LDO20,
        OCP_LDO19,
        OCP_LDO18,
        OCP_LDO17,
        OCP_LDO31,
        OCP_LDO30_2,
        OCP_LDO29,
        OCP_LDO28,
        OCP_LDO27,
        OCP_LDO26,
        OCP_LDO25,
        OCP_LDO24,
        OCP_LDO40,
        OCP_LDO39,
        OCP_LDO38,
        OCP_LDO37,
        LDO_PMUH_OCP,
        OCP_LDO34,
        OCP_LDO33,
        OCP_LDO32,
        SCP_BUCK0,
        SCP_BUCK1,
        SCP_BUCK2,
        SCP_BUCK3,
        SCP_BUCK4,
        SCP_BUCK5,
        SCP_LDOBUFF,
        OCP_CLASSD,
        PMUA_SHORT_F,
        PMUH_SHORT_F,
        VIN_LDOH_SHUTDOWN,
        VSYS_PWRON_SHUTDOWN,
        CALI_PMUH_OCP,
        CALI_LDO26_OCP,
        CALI_BUCK3_SCP,
        CALI_BUCK3_OCP,
        CALI_PMUH_SHORT,
        CALI_PMUA_SHORT,
        RAMP_BUCK0_ABNOR,
        RAMP_BUCK4_ABNOR,
        RAMP_BUCK5_ABNOR,
        RAMP_LDO0_2_ABNOR,
        RAMP_LDO40_ABNOR,
};
enum conn_subtype
{
    CONN_WIFI_EXEC = 0,
    CONN_WIFI_CHAN_EXEC,
    CONN_WIFI_WAKEUP_FAIL,
    CONN_BFGX_EXEC,
    CONN_BFGX_BEAT_TIMEOUT,
    CONN_BFGX_WAKEUP_FAIL,
};
enum hisee_subtype
{
 EXC_SENSOR_CTRL = 0,
 EXC_SIC,
 EXC_MED_ROM,
 EXC_MED_RAM,
 EXC_OTPC,
 EXC_HARD,
 EXC_IPC_MAILBOX,
 EXC_MPU,
 EXC_BUS,
 EXC_TIMER,
 EXC_SEC_EXTERN,
 EXC_WDG,
 EXC_SYSALARM,
 EXC_NV_COUNTER,
 EXC_SWP,
 EXC_COS,
 EXC_BB,
 EXC_MNTN_COS,
 EXC_MNTN_COS_RESET,
 EXC_LIBC,
 EXC_NVM,
 EXC_SECENG_TRNG,
 EXC_SECENG_TRIM,
 EXC_SECENG_SCE,
 EXC_SECENG_RSA,
 EXC_SECENG_SM2,
 EXC_SECENG_KM,
 EXC_SECENG_SCRAMBLING,
 EXC_BOTTOM,
 SIMULATE_EXC_RPMB_KO,
 SIMULATE_EXC_PD_SWIPE,
 EXC_ALARM0,
 EXC_ALARM1,
 EXC_AS2AP_IRQ,
 EXC_DS2AP_IRQ,
 EXC_SENC2AP_IRQ,
 EXC_SENC2AP_IRQ0,
 EXC_SENC2AP_IRQ1,
 EXC_LOCKUP,
 EXC_EH2H_SLV,
 EXC_TSENSOR1,
 EXC_UNKNOWN,
};
enum ivp_subtype {
 IVP_NOC_ERR = 0,
 IVP_SMMU_ERR
};
typedef enum {
 RDR_REG_BACKUP_IDEX_0 = 0,
 RDR_REG_BACKUP_IDEX_1,
 RDR_REG_BACKUP_IDEX_2,
 RDR_REG_BACKUP_IDEX_3,
 RDR_REG_BACKUP_IDEX_MAX
} RDR_REG_BACKUP_IDEX;
enum dss_subtype {
 DSS_NOC_EXCEPTION = 0,
 DSS_DDRC_EXCEPTION,
};
typedef enum {
 CATEGORY_START = 0x0,
 NORMALBOOT,
 PANIC,
 HWWATCHDOG,
 LPM3EXCEPTION,
 BOOTLOADER_CRASH,
 TRUSTZONE_REBOOTSYS,
 MODEM_REBOOTSYS,
 BOOTFAIL,
 HARDWARE_FAULT,
 MODEMCRASH,
 HIFICRASH,
 AUDIO_CODEC_CRASH,
 SENSORHUBCRASH,
 ISPCRASH,
 IVPCRASH,
 TRUSTZONECRASH,
 HISEECRASH,
 UNKNOWNS,
 PRESS10S,
 PRESS6S,
 NPUEXCEPTION,
 CONNEXCEPTION,
 DSSCRASH,
 SUBTYPE = 0xff,
}CATEGORY_SOURCE;
struct exp_subtype {
 unsigned int exception;
 unsigned char category_name[24];
 unsigned char subtype_name[24];
 unsigned int subtype_num;
};
typedef struct exc_special_backup_data {
 unsigned char reset_reason[RDR_REG_BACKUP_IDEX_MAX];
 unsigned int slice;
 unsigned int rtc;
 unsigned int REG_Reg13;
 unsigned int REG_LR1;
 unsigned int REG_PC;
 unsigned int REG_XPSR;
 unsigned int NVIC_CFSR;
 unsigned int NVIC_HFSR;
 unsigned int NVIC_BFAR;
 unsigned char exc_trace;
 unsigned char ddr_exc;
 unsigned short irq_id;
 unsigned int task_id;
} EXC_SPECIAL_BACKUP_DATA_STRU;
typedef struct rdr_reg_backup_head {
 unsigned int idex;
 unsigned int reason[RDR_REG_BACKUP_IDEX_MAX - 1];
} RDR_REG_BACKUP_HEAD_STRU;
typedef struct rdr_reg_backup_data {
 unsigned int Reg0;
 unsigned int Reg1;
 unsigned int Reg2;
 unsigned int Reg3;
 unsigned int Reg4;
 unsigned int Reg5;
 unsigned int Reg6;
 unsigned int Reg7;
 unsigned int Reg8;
 unsigned int Reg9;
 unsigned int Reg10;
 unsigned int Reg11;
 unsigned int Reg12;
 unsigned int Reg13;
 unsigned int MSP;
 unsigned int PSP;
 unsigned int LR0_CONTROL;
 unsigned int LR1;
 unsigned int PC;
 unsigned int XPSR;
 unsigned int PRIMASK;
 unsigned int BASEPRI;
 unsigned int FAULTMASK;
 unsigned int CONTROL;
} RDR_REG_BACKUP_DATA_STRU;
#endif
