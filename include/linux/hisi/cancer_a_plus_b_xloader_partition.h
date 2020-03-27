#ifndef _CANCER_XLOADER_PARTITION_H_
#define _CANCER_XLOADER_PARTITION_H_

#include "hisi_partition.h"
#include "xloader_partition_def.h"

static const struct partition partition_table_emmc[] =
{
  {PART_XLOADER_A,         0,           2*1024,    EMMC_BOOT_MAJOR_PART},
  {PART_RESERVED1,         7*1024,      1024,      EMMC_USER_PART},/* reserved1        1024K  p3*/
  {PART_VRL,               8704,        512,       EMMC_USER_PART},/* VRL              512K   p5*/
  {PART_VRL_BACKUP,        9*1024,      512,       EMMC_USER_PART},/* VRL backup       512K   p6*/
  {PART_NVME,             18*1024,      5*1024,    EMMC_USER_PART},/* nvme              5M    p8*/
  {PART_DDR_PARA,        285*1024,      1*1024,    EMMC_USER_PART},/* DDR_PARA          1M    p17*/
  {PART_LOWPOWER_PARA,   286*1024,      1*1024,    EMMC_USER_PART},/* lowpower_para     1M    p18*/
  {PART_BATT_TP_PARA,    287*1024,      1*1024,    EMMC_USER_PART},/* batt_tp_para      1M    p19*/
  {PART_DFX,             397*1024,     16*1024,    EMMC_USER_PART},/* dfx              16M    p24*/
  {PART_HISEE_IMG_A,     544*1024,      4*1024,    EMMC_USER_PART},/* part_hisee_img_a  4M    p31*/
  {PART_HISEE_FS_A,      552*1024,      8*1024,    EMMC_USER_PART},/* hisee_fs          8M    p33*/
  {PART_FASTBOOT_A,      560*1024,     12*1024,    EMMC_USER_PART},/* fastboot         12M    p34*/
  {PART_VECTOR_A,        572*1024,      4*1024,    EMMC_USER_PART},/* vector_a          4M    p35*/
  {PART_CUST_A,         3792*1024,    192*1024,    EMMC_USER_PART},/* cust            192M    p66*/
#ifdef FILTER_AVS
  {PART_SYSTEM_A,       3984*1024,   3568*1024,    EMMC_USER_PART},/* system         3568M    p67*/
#endif
  {PART_HIBENCH_IMG,   11632*1024,    128*1024,    EMMC_USER_PART},/* hibench_img     128M    p71*/
#ifdef FACTORY_VERSION
  {PART_HIBENCH_LOG,   12784*1024,     32*1024,    EMMC_USER_PART},/* HIBENCH_LOG      32M     p74*/
#endif
  {"0", 0, 0, 0},
};

static const struct partition partition_table_ufs[] =
{
  {PART_XLOADER_A,              0,        2*1024,        UFS_PART_0},
  {PART_RESERVED1,         7*1024,          1024,        UFS_PART_2},/* reserved1          1M     p3*/
  {PART_VRL,                  512,           512,        UFS_PART_3},/* VRL                512K   p1*/
  {PART_VRL_BACKUP,          1024,           512,        UFS_PART_3},/* VRL backup         512K   p2*/
  {PART_NVME,             10*1024,        5*1024,        UFS_PART_3},/* nvme               5M     p4*/
  {PART_DDR_PARA,        277*1024,        1*1024,        UFS_PART_3},/* ddr_para           1M     p13*/
  {PART_LOWPOWER_PARA,   278*1024,        1*1024,        UFS_PART_3},/* lowpower_para      1M     p14*/
  {PART_BATT_TP_PARA,    279*1024,        1*1024,        UFS_PART_3},/* batt_tp_para       1M     p15*/
  {PART_DFX,             389*1024,       16*1024,        UFS_PART_3},/* dfx               16M     p20*/
  {PART_HISEE_IMG_A,     536*1024,        4*1024,        UFS_PART_3},/* part_hisee_img_a   4M     p27*/
  {PART_HISEE_FS_A,      544*1024,        8*1024,        UFS_PART_3},/* hisee_fs           8M     p29*/
  {PART_FASTBOOT_A,      552*1024,       12*1024,        UFS_PART_3},/* fastboot          12M     p30*/
  {PART_VECTOR_A,        564*1024,        4*1024,        UFS_PART_3},/* avs vector         4M     p31*/
  {PART_CUST_A,         3784*1024,      192*1024,        UFS_PART_3},/* cust             192M     p62*/
#ifdef FILTER_AVS
  {PART_SYSTEM_A,       3976*1024,     3568*1024,        UFS_PART_3},/* system          3568M     p63*/ //������xloader�¼���ɸѡ�����ľ��񣬸���system����
#endif
  {PART_HIBENCH_IMG,   11624*1024,      128*1024,        UFS_PART_3},/* hibench_img      128M     p67*/
#ifdef FACTORY_VERSION
  {PART_HIBENCH_LOG,   12776*1024,       32*1024,        UFS_PART_3},/* HIBENCH_LOG      32M      p70*/
#endif
  {"0", 0, 0, 0},
};

#endif
