

/* 头文件包含 */
#include "oal_profiling.h"
#include "oam_ext_if.h"

#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAL_PROFILING_C

/* 全局变量定义 */
#ifdef _PRE_WLAN_PROFLING_SOC
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)
#pragma arm section rwdata = "BTCM", code = "ATCM", zidata = "BTCM", rodata = "ATCM"
OAL_VOLATILE oal_uint32 b_tcm[OAL_RAM_SPACE_SIZE];
#pragma arm section rodata, code, rwdata, zidata  // return to default placement

#pragma arm section rwdata = "BTCM", code = "ATCM", zidata = "BTCM", rodata = "ATCM"
OAL_VOLATILE oal_uint32 a_tcm[OAL_RAM_SPACE_SIZE];
#pragma arm section rodata, code, rwdata, zidata  // return to default placement

OAL_STATIC oal_uint32 w_ram[OAL_RAM_SPACE_SIZE];

OAL_STATIC SHARE_MEM_B oal_uint32 pkt_ram[OAL_RAM_SPACE_SIZE];
#endif
#endif

#ifdef _PRE_WLAN_PROFLING_MIPS
/* 保存tx profiling测试的所有数据 */
oal_profiling_tx_statistic_stru mips_tx_statistic;
EXPORT_SYMBOL(mips_tx_statistic);
/* 保存rx profiling测试的所有数据 */
oal_profiling_rx_statistic_stru mips_rx_statistic;
EXPORT_SYMBOL(mips_rx_statistic);
#endif

oal_thruput_bypass_enum_uint8 thruput_bypass_enable[OAL_THRUPUT_BYPASS_BUTT] = {0};

/* 函数实现 */
#ifdef _PRE_WLAN_PROFLING_SOC
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)

oal_void oal_profiling_read16_single(oal_uint32 ul_addr_start)
{
    oal_uint16 us_val;
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    us_val = OAL_REG_READ16(ul_addr_start);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Single Addr  : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Read Value   : 0x%08x \n\r", us_val);
    OAL_IO_PRINT("Read Cycle   : %d cycles\n\r", ul_cycles);
}


oal_void oal_profiling_read16_ex(oal_uint32 ul_addr_start)
{
    oal_uint16 us_val;
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    us_val = OAL_REG_READ16(ul_addr_start);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Single Addr  : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Read Value   : 0x%08x \n\r", us_val);
    OAL_IO_PRINT("Total Cycle  : %d cycles\n\r", ul_cycles);
    OAL_IO_PRINT("Read Cycle   : %d cycles\n\r", ul_cycles / 32); /* 代表每次读cycle数历经32次读操作 */
}

oal_void oal_profiling_write16_single(oal_uint32 ul_addr_start, oal_uint16 us_val)
{
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    OAL_REG_WRITE16(ul_addr_start, us_val);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Single Addr : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Write Value : 0x%08x \n\r", us_val);
    OAL_IO_PRINT("Write Cycle : %d cycles\n\r", ul_cycles);
}

oal_void oal_profiling_write16_ex(oal_uint32 ul_addr_start, oal_uint16 us_val)
{
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    OAL_REG_WRITE16(ul_addr_start, us_val);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Single Addr  : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Write Value  : 0x%08x \n\r", us_val);
    OAL_IO_PRINT("Write Cycle  : %d cycles\n\r", ul_cycles / 32); /* 代表每次读cycle数历经32次写操作 */
}

oal_void oal_profiling_read32_single(oal_uint32 ul_addr_start)
{
    oal_uint32 ul_val;
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Addr         : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Read Value   : 0x%08x \n\r", ul_val);
    OAL_IO_PRINT("Read Cycle   : %d cycles\n\r", ul_cycles);
}

oal_void oal_profiling_read32_ex(oal_uint32 ul_addr_start)
{
    oal_uint32 ul_val;
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_val = OAL_REG_READ32(ul_addr_start);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Addr         : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Read Value   : 0x%08x \n\r", ul_val);
    OAL_IO_PRINT("Read Cycle   : %d cycles\n\r", ul_cycles / 32); /* 代表每次读cycle数历经32次读操作 */
}

oal_void oal_profiling_write32_single(oal_uint32 ul_addr_start, oal_uint32 ul_val)
{
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Addr        : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Write Value : 0x%08x \n\r", ul_val);
    OAL_IO_PRINT("Write Cycle : %d cycles\n\r", ul_cycles);
}

oal_void oal_profiling_write32_ex(oal_uint32 ul_addr_start, oal_uint32 ul_val)
{
    oal_uint32 ul_cycles;

    enable_cycle_counter();
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    OAL_REG_WRITE32(ul_addr_start, ul_val);
    ul_cycles = get_cycle_count();
    disable_cycle_counter();

    OAL_IO_PRINT("Addr        : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("Write Value : 0x%08x \n\r", ul_val);
    OAL_IO_PRINT("Write Cycle : %d cycles\n\r", ul_cycles / 32); /* 代表每次读cycle数历经32次写操作 */
}

oal_void oal_profiling_read32_many(oal_uint32 ul_addr_start, oal_uint32 ul_addr_end)
{
    oal_uint32 ul_addr = ul_addr_start;
    oal_uint32 ul_val;
    oal_uint32 ul_cycles;
    oal_uint32 ul_num;

    enable_cycle_counter();
    while (ul_addr <= ul_addr_end) {
        ul_val = OAL_REG_READ32(ul_addr);
        ul_addr += sizeof(oal_uint32);  /* 每次偏移4字节 */
    }
    ul_cycles = get_cycle_count();
    disable_cycle_counter();
    ul_num = (ul_addr_end - ul_addr_start) / sizeof(oal_uint32) + 1; /* 计算含有以4字节为单位的内存块个数 */

    OAL_IO_PRINT("Start Addr   : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("End Addr     : 0x%08x \n\r", ul_addr_end);
    OAL_IO_PRINT("32bits Nums  : %d \n\r", ul_num);
    OAL_IO_PRINT("Read Total   : %d cycles\n\r", ul_cycles);
    OAL_IO_PRINT("Read Average : %d cycles\n\r", ul_cycles / ul_num);
}

oal_void oal_profiling_write32_many(oal_uint32 ul_addr_start, oal_uint32 ul_addr_end, oal_uint32 ul_val)
{
    oal_uint32 ul_addr = ul_addr_start;
    oal_uint32 ul_cycles;
    oal_uint32 ul_num;

    enable_cycle_counter();
    while (ul_addr <= ul_addr_end) {
        OAL_REG_WRITE32(ul_addr, ul_val);
        ul_addr += sizeof(oal_uint32);  /* 每次偏移4字节 */
    }
    ul_cycles = get_cycle_count();
    disable_cycle_counter();
    ul_num = (ul_addr_end - ul_addr_start) / sizeof(oal_uint32) + 1; /* 计算含有以4字节为单位的内存块个数 */

    OAL_IO_PRINT("Start Addr   : 0x%08x \n\r", ul_addr_start);
    OAL_IO_PRINT("End Addr     : 0x%08x \n\r", ul_addr_end);
    OAL_IO_PRINT("32bits Nums  : %d \n\r", ul_num);
    OAL_IO_PRINT("Write Total  : %d cycles\n\r", ul_cycles);
    OAL_IO_PRINT("Write Average: %d cycles\n\r", ul_cycles / ul_num);
}

oal_void oal_profiling_check_soc(oal_void)
{
    enable_caches();
    INT_DisableAll();

    OAL_IO_PRINT("\n\r*********************GLB_CTL********************\n\r");
    oal_profiling_write16_ex(0x50000010, 0x1234);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read16_ex(0x50000010);

    OAL_IO_PRINT("\n\r*********************W_CTL**********************\n\r");
    oal_profiling_write16_ex(0x20000010, 0x5678);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read16_ex(0x20000010);

    OAL_IO_PRINT("\n\r*********************COEX_CTL*******************\n\r");
    oal_profiling_write16_ex(0x50010010, 0x9ABC);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read16_ex(0x50010010);

    OAL_IO_PRINT("\n\r*********************SDIO***********************\n\r");
    OAL_IO_PRINT("FUNCTION 0:\n\r");
    oal_profiling_write32_ex(0x20201010, 0xBEEFBEEF);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20201010);  // wrong
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("FUNCTION 1:\n\r");
    oal_profiling_write32_ex(0x2020112C, 0x12345678);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x2020112C);  // wrong

    OAL_IO_PRINT("\n\r*********************MAC************************\n\r");
    OAL_IO_PRINT("BANK0:\n\r");
    oal_profiling_write32_ex(0x20100018, 0x11111111);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20100018);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK1:\n\r");
    oal_profiling_write32_ex(0x201002A8, 0x22222222);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x201002A8);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK2:\n\r");
    oal_profiling_write32_ex(0x20100414, 0x33333333);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20100414);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK3:\n\r");
    oal_profiling_read32_ex(0x20100600);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK4:\n\r");
    oal_profiling_write32_ex(0x20100800, 0x44444444);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20100800);

    OAL_IO_PRINT("\n\r*********************PHY************************\n\r");
    OAL_IO_PRINT("BANK0:\n\r");
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK1:\n\r");
    oal_profiling_write32_ex(0x2012084C, 0x55555555);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x2012084C);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK2:\n\r");
    oal_profiling_write32_ex(0x20120E5C, 0x66666666);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20120E5C);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK3:\n\r");
    oal_profiling_write32_ex(0x20121248, 0x77777777);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20121248);
    OAL_IO_PRINT("\n\r");
    OAL_IO_PRINT("BANK4:\n\r");
    oal_profiling_write32_ex(0x20121498, 0x88888888);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x20121498);

    OAL_IO_PRINT("\n\r*********************BRAM***********************\n\r");
    oal_profiling_read32_ex(0x30000000);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x300E4000);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x301C0000);
    OAL_IO_PRINT("\n\r");
    oal_profiling_write32_ex(0x30178000, 0x99999999);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_ex(0x30178000);

    OAL_IO_PRINT("\n\r*********************BTCM***********************\n\r");
    oal_profiling_write32_single((oal_uint32) & (b_tcm[0]), 0x87654321);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_single((oal_uint32) & (b_tcm[0]));
    OAL_IO_PRINT("\n\r");
    oal_profiling_write32_many((oal_uint32) & (b_tcm[0]),
                               (oal_uint32) & (b_tcm[OAL_RAM_SPACE_SIZE - 1]), 0x12345678);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_many((oal_uint32) & (b_tcm[0]), (oal_uint32) & (b_tcm[OAL_RAM_SPACE_SIZE - 1]));

    OAL_IO_PRINT("\n\r*********************ATCM***********************\n\r");
    oal_profiling_write32_single((oal_uint32) & (a_tcm[0]), 0x87654321);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_single((oal_uint32) & (a_tcm[0]));
    OAL_IO_PRINT("\n\r");
    oal_profiling_write32_many((oal_uint32) & (a_tcm[0]),
                               (oal_uint32) & (a_tcm[OAL_RAM_SPACE_SIZE - 1]), 0x12345678);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_many((oal_uint32) & (a_tcm[0]), (oal_uint32) & (a_tcm[OAL_RAM_SPACE_SIZE - 1]));

    OAL_IO_PRINT("\n\r*********************WRAM***********************\n\r");
    oal_profiling_write32_single((oal_uint32) & (w_ram[0]), 0x87654321);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_single((oal_uint32) & (w_ram[0]));
    OAL_IO_PRINT("\n\r");
    oal_profiling_write32_many((oal_uint32) & (w_ram[0]),
                               (oal_uint32) & (w_ram[OAL_RAM_SPACE_SIZE - 1]), 0x12345678);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_many((oal_uint32) & (w_ram[0]), (oal_uint32) & (w_ram[OAL_RAM_SPACE_SIZE - 1]));
    OAL_IO_PRINT("\n\r");
    oal_profiling_write32_single((oal_uint32)0x000E0000, 0x87654321);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_single((oal_uint32)0x000E0000);

    OAL_IO_PRINT("\n\r*********************PKT_RAM********************\n\r");
    oal_profiling_write32_single((oal_uint32) & (pkt_ram[0]), 0x87654321);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_single((oal_uint32) & (pkt_ram[0]));
    OAL_IO_PRINT("\n\r");
    oal_profiling_write32_many((oal_uint32) & (pkt_ram[0]),
                               (oal_uint32) & (pkt_ram[OAL_RAM_SPACE_SIZE - 1]), 0x12345678);
    OAL_IO_PRINT("\n\r");
    oal_profiling_read32_many((oal_uint32) & (pkt_ram[0]), (oal_uint32) & (pkt_ram[OAL_RAM_SPACE_SIZE - 1]));

    INT_EnableAll();
}
#endif
#endif

#ifdef _PRE_WLAN_PROFLING_MIPS
/*
 * 函 数 名  : oal_profiling_enable_cycles
 * 功能描述  : 打开cycles统计功能
 */
void oal_profiling_enable_cycles(oal_void)
{
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)
    enable_cycle_counter();
#else

#endif
}

/*
 * 函 数 名  : oal_profiling_get_cycles
 * 功能描述  : 获取cycles统计值
 */
oal_uint32 oal_profiling_get_cycles(oal_void)
{
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)
    return get_cycle_count();
#else
    return 0;
#endif
}

/*
 * 函 数 名  : oal_profiling_disable_cycles
 * 功能描述  : 关闭cycles统计功能
 */
void oal_profiling_disable_cycles(oal_void)
{
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)
    disable_cycle_counter();
#else

#endif
}

/*
 * 函 数 名  : oal_profiling_stop_rx_save
 * 功能描述  : 停止接收方向记录，防止数据被覆盖
 */
oal_void oal_profiling_stop_rx_save(oal_void)
{
    mips_rx_statistic.en_switch = OAL_SWITCH_OFF;
}
EXPORT_SYMBOL(oal_profiling_stop_rx_save);

/*
 * 函 数 名  : oal_profiling_stop_tx_save
 * 功能描述  : 停止发送方向记录，防止数据被覆盖
 */
oal_void oal_profiling_stop_tx_save(oal_void)
{
    mips_tx_statistic.en_switch = OAL_SWITCH_OFF;
}
EXPORT_SYMBOL(oal_profiling_stop_tx_save);

/*
 * 函 数 名  : oal_profiling_mips_tx_init
 * 功能描述  : DMAC的发送流程mips统计初始化
 */
oal_uint32 oal_profiling_mips_tx_init(oal_void)
{
    memset_s(&mips_tx_statistic, OAL_SIZEOF(oal_profiling_tx_statistic_stru),
             0, OAL_SIZEOF(oal_profiling_tx_statistic_stru));

    return OAL_SUCC;
}

/*
 * 函 数 名  : oal_profiling_tx_save_data
 * 功能描述  : 发送流程记录数据
 */
oal_void oal_profiling_tx_save_data(oal_profiling_tx_func_enum_uint8 en_func_index)
{
    if (mips_tx_statistic.en_switch == OAL_SWITCH_OFF) {
        return;
    }

    mips_tx_statistic.ast_tx_pass_cycles[0][en_func_index] = cpu_clock(UINT_MAX);
}
EXPORT_SYMBOL(oal_profiling_tx_save_data);

/*
 * 函 数 名  : oal_profiling_irq_save
 * 功能描述  : 发送流程记录数据
 */
oal_void oal_profiling_irq_save(oal_void)
{
    return;
}
EXPORT_SYMBOL(oal_profiling_irq_save);

/*
 * 函 数 名  : oal_profiling_irq_restore
 * 功能描述  : 发送流程记录数据
 */

oal_void oal_profiling_irq_restore(oal_void)
{
    return;
}
EXPORT_SYMBOL(oal_profiling_irq_restore);

oal_void oal_profiling_tx_dump(oal_uint32 ul_packet_idx,
                               oal_uint32 ul_loop,
                               oal_profiling_tx_func_enum_uint8 uc_func_idx)
{
    oal_uint64 ull_cycle_now;
    OAL_STATIC oal_uint64 ull_cycle_last;
    oal_uint64 ull_cycle_offset;

    ull_cycle_now = mips_tx_statistic.ast_tx_pass_cycles[ul_packet_idx][ul_loop];

    if (uc_func_idx == ul_loop) {
        ull_cycle_offset = 0;
    } else {
        ull_cycle_offset = ull_cycle_now - ull_cycle_last;
    }

    ull_cycle_last = ull_cycle_now;

    OAM_WARNING_LOG3(0, OAM_SF_ANY, "Host NO %2d %14lu        %lu\r\n", ul_loop, ull_cycle_now, ull_cycle_offset);
}

EXPORT_SYMBOL(oal_profiling_tx_dump);

/*
 * 函 数 名  : oal_profiling_tx_mips_show
 * 功能描述  : 发送流程显示数据
 */
oal_void oal_profiling_tx_mips_show(oal_void)
{
    oal_uint32 ul_packet_idx;
    oal_uint32 ul_loop;
    oal_uint64 ull_cycle_0;  // ul_cycle_1, ul_cycle_2, ul_cycle_3, ul_cycle_4;

    for (ul_packet_idx = 0; ul_packet_idx < OAL_MIPS_TX_PACKET_MAX_COUNT; ul_packet_idx++) {
        OAM_WARNING_LOG1(0, OAM_SF_ANY, "\r\nTx Time Show: packet number(%d)\r\n", ul_packet_idx);

        /* Time0 */
        OAM_WARNING_LOG0(0, OAM_SF_ANY, "      Current Time        Offset\r\n");
        for (ul_loop = HMAC_PROFILING_FUNC_BRIDGE_VAP_XMIT; ul_loop <= HMAC_PROFILING_FUNC_TX_EVENT_TO_DMAC;
             ul_loop++) {
            oal_profiling_tx_dump(ul_packet_idx, ul_loop, HMAC_PROFILING_FUNC_BRIDGE_VAP_XMIT);
        }
        ull_cycle_0 = mips_tx_statistic.ast_tx_pass_cycles[ul_packet_idx][HMAC_PROFILING_FUNC_TX_EVENT_TO_DMAC] -
                      mips_tx_statistic.ast_tx_pass_cycles[ul_packet_idx][HMAC_PROFILING_FUNC_BRIDGE_VAP_XMIT];
        OAM_WARNING_LOG1(0, OAM_SF_ANY, "Time0: %lu ns\r\n", ull_cycle_0);
        OAM_WARNING_LOG1(0, OAM_SF_ANY, "Tx Total: %lu ns\r\n\n", ull_cycle_0);
    }
    memset_s(&mips_tx_statistic, OAL_SIZEOF(oal_profiling_tx_statistic_stru),
             0, OAL_SIZEOF(oal_profiling_tx_statistic_stru));
}

EXPORT_SYMBOL(oal_profiling_tx_mips_show);

/*
 * 函 数 名  : oal_profiling_mips_rx_init
 * 功能描述  : DMAC的接收流程mips统计初始化
 */
oal_uint32 oal_profiling_mips_rx_init(oal_void)
{
    memset_s(&mips_rx_statistic, OAL_SIZEOF(oal_profiling_rx_statistic_stru),
             0, OAL_SIZEOF(oal_profiling_rx_statistic_stru));

    return OAL_SUCC;
}

/*
 * 函 数 名  : oal_profiling_rx_save_data
 * 功能描述  : 接收流程记录数据
 */
oal_void oal_profiling_rx_save_data(oal_profiling_rx_func_enum_uint8 en_func_index)
{
    if (mips_rx_statistic.en_switch == OAL_SWITCH_OFF) {
        return;
    }

    mips_rx_statistic.ast_rx_pass_cycles[0][en_func_index] = cpu_clock(UINT_MAX);
}
EXPORT_SYMBOL(oal_profiling_rx_save_data);

/*
 * 函 数 名  : oal_profiling_rx_mips_show
 * 功能描述  : 接收流程显示数据
 */
oal_void oal_profiling_rx_mips_show(oal_void)
{
    oal_uint32 ul_packet_idx;
    oal_uint32 ul_loop;
    oal_uint64 ull_cycle_now;
    oal_uint64 ull_cycle_last;
    oal_uint64 ull_cycle_offset;
    oal_uint64 ull_cycle_1;

    for (ul_packet_idx = 0; ul_packet_idx < OAL_MIPS_RX_PACKET_MAX_COUNT; ul_packet_idx++) {
        OAM_WARNING_LOG1(0, OAM_SF_ANY, "\r\nRx Time Show: packet number(%d)\r\n", ul_packet_idx);

        /* 接收中断 */
        OAM_WARNING_LOG0(0, OAM_SF_ANY, "      Current Time        Offset\r\n");

        /* 接收 */
        for (ul_loop = HMAC_PROFILING_FUNC_RX_DATA_ADAPT; ul_loop <= HMAC_PROFILING_FUNC_RX_HMAC_END; ul_loop++) {
            if (ul_loop == HMAC_PROFILING_FUNC_RX_DATA_ADAPT) {
                ull_cycle_now = mips_rx_statistic.ast_rx_pass_cycles[ul_packet_idx][ul_loop];
                ull_cycle_offset = 0;
                if (ull_cycle_now == 0) {
                    ull_cycle_last = 0;
                } else {
                    ull_cycle_last = ull_cycle_now;
                }
            } else {
                ull_cycle_now = mips_rx_statistic.ast_rx_pass_cycles[ul_packet_idx][ul_loop];
                if (ull_cycle_now == 0) {
                    ull_cycle_offset = 0;
                } else {
                    if (ull_cycle_last == 0) {
                        ull_cycle_offset = 0;
                    } else {
                        ull_cycle_offset = ull_cycle_now - ull_cycle_last;
                    }
                    ull_cycle_last = ull_cycle_now;
                }
            }

            OAM_WARNING_LOG3(0, OAM_SF_ANY, "Host NO %2d %14u        %u\r\n", ul_loop, ull_cycle_now, ull_cycle_offset);
        }
        ull_cycle_1 = mips_rx_statistic.ast_rx_pass_cycles[ul_packet_idx][HMAC_PROFILING_FUNC_RX_HMAC_END] -
                      mips_rx_statistic.ast_rx_pass_cycles[ul_packet_idx][HMAC_PROFILING_FUNC_RX_DATA_ADAPT];
        OAM_WARNING_LOG1(0, OAM_SF_ANY, "Rx Hmac Total: %lu ns\r\n", ull_cycle_1);

        OAM_WARNING_LOG1(0, OAM_SF_ANY, "Rx Total: %lu ns\r\n\n", ull_cycle_1);
    }

    memset_s(&mips_rx_statistic, OAL_SIZEOF(oal_profiling_rx_statistic_stru),
             0, OAL_SIZEOF(oal_profiling_rx_statistic_stru));
}
EXPORT_SYMBOL(oal_profiling_rx_mips_show);

oal_uint32 oal_profiling_mips_init(oal_void)
{
    oal_profiling_mips_tx_init();
    oal_profiling_mips_rx_init();

    return OAL_SUCC;
}
EXPORT_SYMBOL(oal_profiling_mips_init);

#endif

oal_uint32 oal_get_thruput_bypass_enable(oal_thruput_bypass_enum_uint8 uc_bypass_type)
{
    return thruput_bypass_enable[uc_bypass_type];
}

oal_void oal_set_thruput_bypass_enable(oal_thruput_bypass_enum_uint8 uc_bypass_type, oal_uint8 uc_value)
{
    if (uc_bypass_type >= OAL_THRUPUT_BYPASS_BUTT) {
        /* 打印临时修改成PRINTK形式，后续51的oal和oam整合成一个ko后，放开OAL调用OAM的限制 */
        OAL_IO_PRINT("oal_get_thruput_bypass_enable::wrong thruput bypass type:%d.\n", uc_bypass_type);
        return;
    }
    thruput_bypass_enable[uc_bypass_type] = uc_value;
}

#ifndef _PRE_PC_LINT
oal_module_symbol(oal_get_thruput_bypass_enable);
oal_module_symbol(oal_set_thruput_bypass_enable);
#endif

