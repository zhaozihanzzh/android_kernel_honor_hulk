/*
 * da_separate_v3_driver codec driver.
 *
 * Copyright (c) 2018 Hisilicon Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __DA_SEPARATE_V3_PMU_REG_DEF_H__
#define __DA_SEPARATE_V3_PMU_REG_DEF_H__

/* reg_codec Base address of Module's Register */
#define DA_SEPARATE_V3_PMU_CODEC_BASE                       (0x0)

/******************************************************************************/
/*                      DA_SEPARATE_V3 reg_codec Registers' Definitions                            */
/******************************************************************************/

#define CLK_EN_CFG_REG         (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F0) /* ʱ��ʹ�����üĴ����� */
#define DAC_ULTR_EN_LEN     1
#define DAC_ULTR_EN_OFFSET  7
#define CODEC_ANA_EN_LEN    1
#define CODEC_ANA_EN_OFFSET 6
#define SIF_EN_LEN          1
#define SIF_EN_OFFSET       5
#define ADC_MIC3_EN_LEN     1
#define ADC_MIC3_EN_OFFSET  4
#define ADCR_EN_LEN         1
#define ADCR_EN_OFFSET      3
#define ADCL_EN_LEN         1
#define ADCL_EN_OFFSET      2
#define DACR_EN_LEN         1
#define DACR_EN_OFFSET      1
#define DACL_EN_LEN         1
#define DACL_EN_OFFSET      0

#define CLK_EDGE_CFG_REG       (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F1) /* ��ģ�ӿ�ʱ����ѡ�� */
#define DAC_ULTR_CLK_EDGE_SEL_LEN    1
#define DAC_ULTR_CLK_EDGE_SEL_OFFSET 5
#define ADC_MIC3_CLK_EDGE_SEL_LEN    1
#define ADC_MIC3_CLK_EDGE_SEL_OFFSET 4
#define ADCR_CLK_EDGE_SEL_LEN        1
#define ADCR_CLK_EDGE_SEL_OFFSET     3
#define ADCL_CLK_EDGE_SEL_LEN        1
#define ADCL_CLK_EDGE_SEL_OFFSET     2
#define DACR_CLK_EDGE_SEL_LEN        1
#define DACR_CLK_EDGE_SEL_OFFSET     1
#define DACL_CLK_EDGE_SEL_LEN        1
#define DACL_CLK_EDGE_SEL_OFFSET     0

#define SIF_LOOPBACK_CFG_REG   (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F2) /* SIF�ӿڻ��ؿ��ơ� */
#define ADC_LOOPBACK_LEN    2
#define ADC_LOOPBACK_OFFSET 2
#define DAC_LOOPBACK_LEN    2
#define DAC_LOOPBACK_OFFSET 0

#define DAC_CHAN_CTRL_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F3) /* DACͨ·���á� */
#define DAC_ULTR_DWA_EN_LEN    1
#define DAC_ULTR_DWA_EN_OFFSET 6
#define DACR_DIN_SEL_LEN       2
#define DACR_DIN_SEL_OFFSET    4
#define DACL_DIN_SEL_LEN       2
#define DACL_DIN_SEL_OFFSET    2
#define DACR_DWA_EN_LEN        1
#define DACR_DWA_EN_OFFSET     1
#define DACL_DWA_EN_LEN        1
#define DACL_DWA_EN_OFFSET     0

#define ADC_CHAN_CTRL_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F4) /* ADCͨ·���á� */
#define ADC_MIC3_DOUT_SEL_LEN    2
#define ADC_MIC3_DOUT_SEL_OFFSET 4
#define ADCR_DOUT_SEL_LEN        2
#define ADCR_DOUT_SEL_OFFSET     2
#define ADCL_DOUT_SEL_LEN        2
#define ADCL_DOUT_SEL_OFFSET     0

#define ANA_IRQ_SIG_STAT_REG   (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F5) /* ģ���ж�ԭʼ״̬�Ĵ����� */
#define HS_DET_IRQ_LEN         1
#define HS_DET_IRQ_OFFSET      3
#define HS_MIC_ECO_IRQ_LEN     1
#define HS_MIC_ECO_IRQ_OFFSET  2
#define HS_MIC_NOR2_IRQ_LEN    1
#define HS_MIC_NOR2_IRQ_OFFSET 1
#define HS_MIC_NOR1_IRQ_LEN    1
#define HS_MIC_NOR1_IRQ_OFFSET 0

#define ANA_IRQM_REG0_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F6) /* ANA_IRQ_REG�ж����μĴ����� */
#define ANA_IRQ_MASK_7_LEN    1
#define ANA_IRQ_MASK_7_OFFSET 7
#define ANA_IRQ_MASK_6_LEN    1
#define ANA_IRQ_MASK_6_OFFSET 6
#define ANA_IRQ_MASK_5_LEN    1
#define ANA_IRQ_MASK_5_OFFSET 5
#define ANA_IRQ_MASK_4_LEN    1
#define ANA_IRQ_MASK_4_OFFSET 4
#define ANA_IRQ_MASK_3_LEN    1
#define ANA_IRQ_MASK_3_OFFSET 3
#define ANA_IRQ_MASK_2_LEN    1
#define ANA_IRQ_MASK_2_OFFSET 2
#define ANA_IRQ_MASK_1_LEN    1
#define ANA_IRQ_MASK_1_OFFSET 1
#define ANA_IRQ_MASK_0_LEN    1
#define ANA_IRQ_MASK_0_OFFSET 0

#define ANA_IRQ_REG0_REG       (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F7) /* ģ���жϼĴ�����0��д1�壬���ϱ��ж���Ϣ�� */
#define HS_DET_IRQ_NEG_LEN         1
#define HS_DET_IRQ_NEG_OFFSET      7
#define HS_DET_IRQ_POS_LEN         1
#define HS_DET_IRQ_POS_OFFSET      6
#define HS_MIC_ECO_IRQ_NEG_LEN     1
#define HS_MIC_ECO_IRQ_NEG_OFFSET  5
#define HS_MIC_ECO_IRQ_POS_LEN     1
#define HS_MIC_ECO_IRQ_POS_OFFSET  4
#define HS_MIC_NOR2_IRQ_NEG_LEN    1
#define HS_MIC_NOR2_IRQ_NEG_OFFSET 3
#define HS_MIC_NOR2_IRQ_POS_LEN    1
#define HS_MIC_NOR2_IRQ_POS_OFFSET 2
#define HS_MIC_NOR1_IRQ_NEG_LEN    1
#define HS_MIC_NOR1_IRQ_NEG_OFFSET 1
#define HS_MIC_NOR1_IRQ_POS_LEN    1
#define HS_MIC_NOR1_IRQ_POS_OFFSET 0

#define DEB_CNT_HS_DET_CFG_REG (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F8) /* hs_det_irqȥ�����á� */
#define BYPASS_DEB_HS_DET_IRQ_LEN    1
#define BYPASS_DEB_HS_DET_IRQ_OFFSET 5
#define DEB_CNT_HS_DET_IRQ_LEN       5
#define DEB_CNT_HS_DET_IRQ_OFFSET    0

#define DEB_CNT_HS_MIC_CFG_REG (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2F9) /* hs_mic_irqȥ�����á� */
#define BYPASS_DEB_HS_MIC_IRQ_LEN    1
#define BYPASS_DEB_HS_MIC_IRQ_OFFSET 5
#define DEB_CNT_HS_MIC_IRQ_LEN       5
#define DEB_CNT_HS_MIC_IRQ_OFFSET    0

#define CODEC_ANA_RW1_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2FA) /* vref/ctcm/ibiasģ��ʹ�ܡ� */
#define IBIAS_PD_LEN      1
#define IBIAS_PD_OFFSET   2
#define AVREF_SEL_LEN     2
#define AVREF_SEL_OFFSET  0

#define CODEC_ANA_RW2_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2FB) /* micpgaʹ�ܡ� */
#define MAINPGA_PD_LEN              1
#define MAINPGA_PD_OFFSET           6
#define AUXPGA_PD_LEN               1
#define AUXPGA_PD_OFFSET            5
#define MIC3PGA_PD_LEN              1
#define MIC3PGA_PD_OFFSET           4
#define MICPGA_WORK_MODE_SEL_LEN    1
#define MICPGA_WORK_MODE_SEL_OFFSET 3
#define MAINPGA_MUTE_LEN            1
#define MAINPGA_MUTE_OFFSET         2
#define AUXPGA_MUTE_LEN             1
#define AUXPGA_MUTE_OFFSET          1
#define MIC3PGA_MUTE_LEN            1
#define MIC3PGA_MUTE_OFFSET         0

#define CODEC_ANA_RW3_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2FC) /* adcʹ�ܡ� */
#define ADCL_PD_LEN       1
#define ADCL_PD_OFFSET    6
#define ADCR_PD_LEN       1
#define ADCR_PD_OFFSET    5
#define ADC3_PD_LEN       1
#define ADC3_PD_OFFSET    4
#define ADCL_MUTE_LEN     1
#define ADCL_MUTE_OFFSET  2
#define ADCR_MUTE_LEN     1
#define ADCR_MUTE_OFFSET  1
#define ADC3_MUTE_LEN     1
#define ADC3_MUTE_OFFSET  0

#define CODEC_ANA_RW4_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2FD) /* dacʹ�ܡ� */
#define DACS_PD_LEN       1
#define DACS_PD_OFFSET    2
#define DACL_PD_LEN       1
#define DACL_PD_OFFSET    1
#define DACR_PD_LEN       1
#define DACR_PD_OFFSET    0

#define CODEC_ANA_RW5_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2FE) /* headphoneʹ�ܡ� */
#define CHARGEPUMP_PD_LEN    1
#define CHARGEPUMP_PD_OFFSET 7
#define POP_PULL_EN_LEN      1
#define POP_PULL_EN_OFFSET   6
#define MIXOUT_HPL_PD_LEN    1
#define MIXOUT_HPL_PD_OFFSET 5
#define MIXOUT_HPR_PD_LEN    1
#define MIXOUT_HPR_PD_OFFSET 4
#define HPL_PD_LEN           1
#define HPL_PD_OFFSET        3
#define HPR_PD_LEN           1
#define HPR_PD_OFFSET        2
#define HPL_MUTE_LEN         1
#define HPL_MUTE_OFFSET      1
#define HPR_MUTE_LEN         1
#define HPR_MUTE_OFFSET      0

#define CODEC_ANA_RW6_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x2FF) /* earphone/lineoutʹ�ܡ� */
#define LOMIXER_PD_LEN       1
#define LOMIXER_PD_OFFSET    6
#define LOUT_PD_LEN          1
#define LOUT_PD_OFFSET       5
#define LOUT_MUTE_LEN        1
#define LOUT_MUTE_OFFSET     4
#define MIXOUT_EAR_PD_LEN    1
#define MIXOUT_EAR_PD_OFFSET 3
#define EPVCM_PD_LEN         1
#define EPVCM_PD_OFFSET      2
#define EAR_PD_LEN           1
#define EAR_PD_OFFSET        1
#define EAR_MUTE_LEN         1
#define EAR_MUTE_OFFSET      0

#define CODEC_ANA_RW7_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x300) /* micbiasʹ�ܡ� */
#define HSMICB_PD_LEN       1
#define HSMICB_PD_OFFSET    6
#define MICB1_PD_LEN        1
#define MICB1_PD_OFFSET     5
#define MICB2_PD_LEN        1
#define MICB2_PD_OFFSET     4
#define HSMICB_DSCHG_LEN    1
#define HSMICB_DSCHG_OFFSET 2
#define MICB1_DSCHG_LEN     1
#define MICB1_DSCHG_OFFSET  1
#define MICB2_DSCHG_LEN     1
#define MICB2_DSCHG_OFFSET  0

#define CODEC_ANA_RW8_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x301) /* mbhdʹ�ܡ� */
#define MBHD_COMP_PD_LEN    1
#define MBHD_COMP_PD_OFFSET 2
#define MBHD_BUFF_PD_LEN    1
#define MBHD_BUFF_PD_OFFSET 1
#define MBHD_ECO_EN_LEN     1
#define MBHD_ECO_EN_OFFSET  0

#define CODEC_ANA_RW9_REG      (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x302) /* mainpga���á� */
#define MICPGA_UNLOCK_ENABLE_LEN    1
#define MICPGA_UNLOCK_ENABLE_OFFSET 6
#define MAINPGA_SEL_LEN             2
#define MAINPGA_SEL_OFFSET          4
#define MAINPGA_BOOST_LEN           1
#define MAINPGA_BOOST_OFFSET        3
#define MAINPGA_GAIN_LEN            3
#define MAINPGA_GAIN_OFFSET         0

#define CODEC_ANA_RW10_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x303) /* auxpga���á� */
#define DISCHARGE_DISABLE_LEN    1
#define DISCHARGE_DISABLE_OFFSET 7
#define HSMIC_VCM_PULL_EN_LEN    1
#define HSMIC_VCM_PULL_EN_OFFSET 6
#define AUXPGA_SEL_LEN           2
#define AUXPGA_SEL_OFFSET        4
#define AUXPGA_BOOST_LEN         1
#define AUXPGA_BOOST_OFFSET      3
#define AUXPGA_GAIN_LEN          3
#define AUXPGA_GAIN_OFFSET       0

#define CODEC_ANA_RW11_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x304) /* mic3pga���á� */
#define MIC3PGA_SEL_LEN      2
#define MIC3PGA_SEL_OFFSET   4
#define ADC3PGA_BOOST_LEN    2
#define ADC3PGA_BOOST_OFFSET 2
#define MIC3PGA_GAIN_LEN     2
#define MIC3PGA_GAIN_OFFSET  0

#define CODEC_ANA_RW12_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x305) /* adcl���á� */
#define IDEL_TONE_CTRL_LEN    2
#define IDEL_TONE_CTRL_OFFSET 6
#define ADCL_MIXIN_DACR_LEN       1
#define ADCL_MIXIN_DACR_OFFSET    5
#define ADCL_MIXIN_DACL_LEN       1
#define ADCL_MIXIN_DACL_OFFSET    4
#define ADCL_MIXIN_REV_LEN        2
#define ADCL_MIXIN_REV_OFFSET     2
#define ADCL_MIXIN_MICPGA2_LEN    1
#define ADCL_MIXIN_MICPGA2_OFFSET 1
#define ADCL_MIXIN_MICPGA1_LEN    1
#define ADCL_MIXIN_MICPGA1_OFFSET 0

#define CODEC_ANA_RW13_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x306) /* adcl���á� */
#define ADCL_DWA_BPS_LEN      1
#define ADCL_DWA_BPS_OFFSET   7
#define ADCL_CLK_DELAY_LEN    3
#define ADCL_CLK_DELAY_OFFSET 4
#define ADCL_DAC_BIAS_LEN     2
#define ADCL_DAC_BIAS_OFFSET  2
#define ADCL_FLSTN_LEN        2
#define ADCL_FLSTN_OFFSET     0

#define CODEC_ANA_RW14_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x307) /* adcr���á� */
#define ADCR_MIXIN_DACR_LEN       1
#define ADCR_MIXIN_DACR_OFFSET    5
#define ADCR_MIXIN_DACL_LEN       1
#define ADCR_MIXIN_DACL_OFFSET    4
#define ADCR_MIXIN_MICPGA1_LEN    1
#define ADCR_MIXIN_MICPGA1_OFFSET 1
#define ADCR_MIXIN_MICPGA2_LEN    1
#define ADCR_MIXIN_MICPGA2_OFFSET 0

#define CODEC_ANA_RW15_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x308) /* adcr���á� */
#define ADCR_DWA_BPS_LEN      1
#define ADCR_DWA_BPS_OFFSET   7
#define ADCR_CLK_DELAY_LEN    3
#define ADCR_CLK_DELAY_OFFSET 4
#define ADCR_DAC_BIAS_LEN     2
#define ADCR_DAC_BIAS_OFFSET  2
#define ADCR_FLSTN_LEN        2
#define ADCR_FLSTN_OFFSET     0

#define CODEC_ANA_RW16_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x309) /* adc3���á� */
#define ADC3_MIXIN_ULTRA_LEN      1
#define ADC3_MIXIN_ULTRA_OFFSET   5
#define ADC3_MIXIN_DACL_LEN       1
#define ADC3_MIXIN_DACL_OFFSET    4
#define ADC3_MIXIN_MICPGA1_LEN    1
#define ADC3_MIXIN_MICPGA1_OFFSET 1
#define ADC3_MIXIN_MICPGA3_LEN    1
#define ADC3_MIXIN_MICPGA3_OFFSET 0

#define CODEC_ANA_RW17_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x30A) /* adc3���á� */
#define ADC3_DWA_BPS_LEN      1
#define ADC3_DWA_BPS_OFFSET   7
#define ADC3_TIMING_LEN       3
#define ADC3_TIMING_OFFSET    4
#define ADC3_CLK_DELAY_LEN    2
#define ADC3_CLK_DELAY_OFFSET 2
#define ADC3_FLSTN_LEN        2
#define ADC3_FLSTN_OFFSET     0

#define CODEC_ANA_RW18_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x30B) /* dac���á� */
#define PULL_CPN_ENABLE_LEN    1
#define PULL_CPN_ENABLE_OFFSET 7
#define DACS_ICTRL_LEN         2
#define DACS_ICTRL_OFFSET      4
#define DACL_ICTRL_LEN         2
#define DACL_ICTRL_OFFSET      2
#define DACR_ICTRL_LEN         2
#define DACR_ICTRL_OFFSET      0

#define CODEC_ANA_RW19_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x30C) /* chargepump���á� */
#define CP_CLKSET_LEN          1
#define CP_CLKSET_OFFSET       7
#define CP_AUTOSOFT_DIS_LEN    1
#define CP_AUTOSOFT_DIS_OFFSET 6
#define CP_SOFT_DLY_CFG_LEN    2
#define CP_SOFT_DLY_CFG_OFFSET 4
#define CP_SW_CFG_LEN          2
#define CP_SW_CFG_OFFSET       2
#define CP_DT_CFG_LEN          2
#define CP_DT_CFG_OFFSET       0

#define CODEC_ANA_RW20_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x30D) /* hp mixer����ѡ�� */
#define MIXOUT_HSL_DACL_LEN    1
#define MIXOUT_HSL_DACL_OFFSET 7
#define MIXOUT_HSL_DACR_LEN    1
#define MIXOUT_HSL_DACR_OFFSET 6
#define MIXOUT_HSR_DACR_LEN    1
#define MIXOUT_HSR_DACR_OFFSET 3
#define MIXOUT_HSR_DACL_LEN    1
#define MIXOUT_HSR_DACL_OFFSET 2

#define CODEC_ANA_RW21_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x30E) /* hp����ѡ�� */
#define HSL_GAIN_LEN    4
#define HSL_GAIN_OFFSET 4
#define HSR_GAIN_LEN    4
#define HSR_GAIN_OFFSET 0

#define CODEC_ANA_RW22_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x30F) /* hp���á� */
#define HSL_MIN_GAIN_LEN    1
#define HSL_MIN_GAIN_OFFSET 5
#define HSR_MIN_GAIN_LEN    1
#define HSR_MIN_GAIN_OFFSET 4
#define STB_CTRL_SEC_LEN    2
#define STB_CTRL_SEC_OFFSET 2
#define STB_CTRL_LEN        2
#define STB_CTRL_OFFSET     0

#define CODEC_ANA_RW23_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x310) /* hp���á� */
#define STB_ACTIVE_CTRL_LEN    1
#define STB_ACTIVE_CTRL_OFFSET 5
#define STB_1N_LEN             1
#define STB_1N_OFFSET          4
#define HPOUT_1K_LOAD_LEN      1
#define HPOUT_1K_LOAD_OFFSET   3
#define STB_N12DB_GAIN_LEN     1
#define STB_N12DB_GAIN_OFFSET  2
#define THD_CTRL_SEL_LEN       2
#define THD_CTRL_SEL_OFFSET    0

#define CODEC_ANA_RW24_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x311) /* hp pop���á� */
#define POP_DIS_LEN        1
#define POP_DIS_OFFSET     6
#define RST_POP_LEN        1
#define RST_POP_OFFSET     5
#define RL_SYNC_EN_LEN     1
#define RL_SYNC_EN_OFFSET  4
#define POP_DLY_CFG_LEN    2
#define POP_DLY_CFG_OFFSET 2
#define PLO_SPD_CFG_LEN    2
#define PLO_SPD_CFG_OFFSET 0

#define CODEC_ANA_RW25_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x312) /* ep mixer���á� */
#define MIXOUT_EAR_DACL_LEN          1
#define MIXOUT_EAR_DACL_OFFSET       7
#define MIXOUT_EAR_DACR_LEN          1
#define MIXOUT_EAR_DACR_OFFSET       6
#define MIXOUT_EAR_DAC_ULTRA_LEN     1
#define MIXOUT_EAR_DAC_ULTRA_OFFSET  5
#define CR_MIXER_EP_DACL_LEN         1
#define CR_MIXER_EP_DACL_OFFSET      3
#define CR_MIXER_EP_DACR_LEN         1
#define CR_MIXER_EP_DACR_OFFSET      2
#define CR_MIXER_EP_DAC_ULTRA_LEN    1
#define CR_MIXER_EP_DAC_ULTRA_OFFSET 1

#define CODEC_ANA_RW26_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x313) /* earphone���á� */
#define EAR_CM_CTRL_LEN    1
#define EAR_CM_CTRL_OFFSET 4
#define EAR_GAIN_LEN       4
#define EAR_GAIN_OFFSET    0

#define CODEC_ANA_RW27_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x314) /* lineout mixer���á� */
#define LOMIX_SEL_DACL_LEN              1
#define LOMIX_SEL_DACL_OFFSET           7
#define LOMIX_SEL_DACR_LEN              1
#define LOMIX_SEL_DACR_OFFSET           6
#define LOMIX_SEL_DAC_ULTRA_LEN         1
#define LOMIX_SEL_DAC_ULTRA_OFFSET      5
#define LOMIX_BOOSTGAIN_DACL_LEN        1
#define LOMIX_BOOSTGAIN_DACL_OFFSET     3
#define LOMIX_BOOSTGAIN_DACR_LEN        1
#define LOMIX_BOOSTGAIN_DACR_OFFSET     2
#define LOMIX_BOOSTGAIN_DACULTRA_LEN    1
#define LOMIX_BOOSTGAIN_DACULTRA_OFFSET 1

#define CODEC_ANA_RW28_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x315) /* lineout���á� */
#define LOUT_VCM_CTRL_LEN    1
#define LOUT_VCM_CTRL_OFFSET 4
#define LOUT_GAIN_LEN        4
#define LOUT_GAIN_OFFSET     0

#define CODEC_ANA_RW29_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x316) /* himicbias���á� */
#define HSMICB_ENB_SDET_LEN       1
#define HSMICB_ENB_SDET_OFFSET    5
#define HSMICB_LONOISE_1P2_LEN    1
#define HSMICB_LONOISE_1P2_OFFSET 4
#define HSMICB_ADJ_LEN            4
#define HSMICB_ADJ_OFFSET         0

#define CODEC_ANA_RW30_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x317) /* micbias1���á� */
#define MICB1_ENB_SDET_LEN       1
#define MICB1_ENB_SDET_OFFSET    5
#define MICB1_LONOISE_1P2_LEN    1
#define MICB1_LONOISE_1P2_OFFSET 4
#define MICB1_ADJ_LEN            4
#define MICB1_ADJ_OFFSET         0

#define CODEC_ANA_RW31_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x318) /* micbias2���á� */
#define MICB2_ENB_SDET_LEN       1
#define MICB2_ENB_SDET_OFFSET    5
#define MICB2_LONOISE_1P2_LEN    1
#define MICB2_LONOISE_1P2_OFFSET 4
#define MICB2_ADJ_LEN            4
#define MICB2_ADJ_OFFSET         0

#define CODEC_ANA_RW32_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x319) /* �������������á� */
#define HSD_INV_LEN         1
#define HSD_INV_OFFSET      6
#define HSD_PULLDOWN_LEN    1
#define HSD_PULLDOWN_OFFSET 5
#define HSE_SEL_LEN         1
#define HSE_SEL_OFFSET      4
#define HSD_VTH_CFG_LEN     2
#define HSD_VTH_CFG_OFFSET  2
#define HSD_EN_LEN          2
#define HSD_EN_OFFSET       0

#define CODEC_ANA_RW33_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x31A) /* �����γ�pop���á� */
#define ANALOG_LOOP_LEN            1
#define ANALOG_LOOP_OFFSET         3
#define PULLOUT_POP_EN1_LEN        1
#define PULLOUT_POP_EN1_OFFSET     2
#define PULLOUT_POP_EN2_LEN        1
#define PULLOUT_POP_EN2_OFFSET     1
#define PULLOUT_HSD_DIR_SEL_LEN    1
#define PULLOUT_HSD_DIR_SEL_OFFSET 0

#define CODEC_ANA_RW34_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x31B) /* mbhd ref���á� */
#define MBHD_VREF_PD_LEN     1
#define MBHD_VREF_PD_OFFSET  7
#define ECO_VTH_SEL_LEN      3
#define ECO_VTH_SEL_OFFSET   4
#define COMPH_VTH_SEL_LEN    2
#define COMPH_VTH_SEL_OFFSET 2
#define COMPL_VTH_SEL_LEN    2
#define COMPL_VTH_SEL_OFFSET 0

#define CODEC_ANA_RW35_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x31C) /* adc/dacʱ�������á� */
#define ADC_CLK_SYS_EDGE_LEN    2
#define ADC_CLK_SYS_EDGE_OFFSET 2
#define DAC_CLK_SEL_EDGE_LEN    2
#define DAC_CLK_SEL_EDGE_OFFSET 0

#define CODEC_ANA_RW36_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x31D) /* rxͨ·chopʱ�����á� */
#define RX_CHOP_BPS_LEN         1
#define RX_CHOP_BPS_OFFSET      6
#define ADC_CHOP_CLK_SEL_LEN    2
#define ADC_CHOP_CLK_SEL_OFFSET 4
#define CTCM_CHOP_BPS_LEN       1
#define CTCM_CHOP_BPS_OFFSET    3
#define CAPLESS_CHOP_BPS_LEN    1
#define CAPLESS_CHOP_BPS_OFFSET 2
#define MICPGA_CHOP_BPS_LEN     1
#define MICPGA_CHOP_BPS_OFFSET  1
#define ADC_SDM_CHOP_BPS_LEN    1
#define ADC_SDM_CHOP_BPS_OFFSET 0

#define CODEC_ANA_RW37_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x31E) /* txͨ·chopʱ�����á� */
#define LOMIX_CHOP_BPS_LEN      1
#define LOMIX_CHOP_BPS_OFFSET   7
#define TX_CHOP_BPS_LEN         1
#define TX_CHOP_BPS_OFFSET      6
#define DAC_CHOP_CLK_SEL_LEN    2
#define DAC_CHOP_CLK_SEL_OFFSET 4
#define DAC_CHOP_BPS_LEN        1
#define DAC_CHOP_BPS_OFFSET     3
#define HS_CHOP_BPS_LEN         1
#define HS_CHOP_BPS_OFFSET      2
#define EPMIX_CHOP_BPS_LEN      1
#define EPMIX_CHOP_BPS_OFFSET   1
#define LOUT_CHOP_BPS_LEN       1
#define LOUT_CHOP_BPS_OFFSET    0

#define CODEC_ANA_RW38_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x31F) /* cp/popʱ�����á� */
#define HS_SYS_CLK_PD_LEN     1
#define HS_SYS_CLK_PD_OFFSET  5
#define CLKPOP_SEL_LEN        1
#define CLKPOP_SEL_OFFSET     4
#define CLKCP_SRC_FREQ_LEN    1
#define CLKCP_SRC_FREQ_OFFSET 3
#define CLKCP_SEL_LEN         3
#define CLKCP_SEL_OFFSET      0

#define CODEC_ANA_RW39_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x320) /* caplessʱ�����á� */
#define CPLS_CLK_FREQ_SEL_LEN     1
#define CPLS_CLK_FREQ_SEL_OFFSET  6
#define CAPLESS_CLK_FQ_SEL_LEN    2
#define CAPLESS_CLK_FQ_SEL_OFFSET 4
#define CLK_CAPLESS_BPS_LEN       1
#define CLK_CAPLESS_BPS_OFFSET    3
#define CAPLESS_CLK_PH_SEL_LEN    1
#define CAPLESS_CLK_PH_SEL_OFFSET 2
#define CAPLESS_CLK_FO_SEL_LEN    2
#define CAPLESS_CLK_FO_SEL_OFFSET 0

#define CODEC_ANA_RW40_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x321) /* ƫ�õ������á� */
#define CODEC_IBIAS_ADJ_LEN     1
#define CODEC_IBIAS_ADJ_OFFSET  7
#define IB05_CTCM_ADJ_LEN       3
#define IB05_CTCM_ADJ_OFFSET    4
#define IB05_CAPLESS_ADJ_LEN    3
#define IB05_CAPLESS_ADJ_OFFSET 0

#define CODEC_ANA_RW41_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x322) /* CODEC_ANA_RW41ƫ�õ������á� */
#define IB05_MICPGA_ADJ_LEN         3
#define IB05_MICPGA_ADJ_OFFSET      4
#define IB05_MICPGALOGIC_ADJ_LEN    3
#define IB05_MICPGALOGIC_ADJ_OFFSET 0

#define CODEC_ANA_RW42_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x323) /* CODEC_ANA_RW42ƫ�õ������á� */
#define IB05_ADCOP1_ADJ_LEN    3
#define IB05_ADCOP1_ADJ_OFFSET 4
#define IB05_ADCOP2_ADJ_LEN    3
#define IB05_ADCOP2_ADJ_OFFSET 0

#define CODEC_ANA_RW43_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x324) /* CODEC_ANA_RW43ƫ�õ������á� */
#define IB05_ADCCOMP_ADJ_LEN    3
#define IB05_ADCCOMP_ADJ_OFFSET 4
#define IB05_DACI2V_ADJ_LEN     3
#define IB05_DACI2V_ADJ_OFFSET  0

#define CODEC_ANA_RW44_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x325) /* CODEC_ANA_RW44ƫ�õ������á� */
#define IB05_HPMIX_ADJ_LEN    3
#define IB05_HPMIX_ADJ_OFFSET 4
#define IB05_HP_ADJ_LEN       3
#define IB05_HP_ADJ_OFFSET    0

#define CODEC_ANA_RW45_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x326) /* CODEC_ANA_RW45ƫ�õ������á� */
#define IB05_HPLOGIC_ADJ_LEN     3
#define IB05_HPLOGIC_ADJ_OFFSET  4
#define IB05_EARLOGIC_ADJ_LEN    3
#define IB05_EARLOGIC_ADJ_OFFSET 0

#define CODEC_ANA_RW46_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x327) /* CODEC_ANA_RW46ƫ�õ������á� */
#define IB05_EARMIX_ADJ_LEN    3
#define IB05_EARMIX_ADJ_OFFSET 4
#define IB05_EAR_ADJ_LEN       3
#define IB05_EAR_ADJ_OFFSET    0

#define CODEC_ANA_RW47_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x328) /* CODEC_ANA_RW47ƫ�õ������á� */
#define IB05_LO_ADJ_LEN         3
#define IB05_LO_ADJ_OFFSET      4
#define IB05_LOLOGIC_ADJ_LEN    3
#define IB05_LOLOGIC_ADJ_OFFSET 0

#define CODEC_ANA_RW48_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x329) /* CODEC_ANA_RW48ƫ�õ������á� */
#define IB05_MICB_ADJ_LEN    3
#define IB05_MICB_ADJ_OFFSET 0

#define CODEC_ANA_RW49_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x32A) /* CODEC_ANA_RW49ƫ�õ������á� */
#define IB05_LOMIX_ADJ_LEN       3
#define IB05_LOMIX_ADJ_OFFSET    4
#define IB05_DACS_I2V_ADJ_LEN    3
#define IB05_DACS_I2V_ADJ_OFFSET 0

#define CODEC_ANA_RW50_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x32B) /* CODEC_ANA_RW50ƫ�õ������á� */
#define CODEC_ANA_RW_50_LEN    8
#define CODEC_ANA_RW_50_OFFSET 0

#define CODEC_ANA_RW51_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x32C) /* CODEC_ANA_RW51�� */
#define CODEC_ANA_RW_51_LEN    8
#define CODEC_ANA_RW_51_OFFSET 0

#define CODEC_ANA_RW52_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x32D) /* CODEC_ANA_RW52�� */
#define CODEC_ANA_RW_52_LEN    8
#define CODEC_ANA_RW_52_OFFSET 0

#define CODEC_ANA_RO01_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x32E) /* CODEC_ANA_RO01�� */
#define CODEC_ANA_RO_01_LEN    8
#define CODEC_ANA_RO_01_OFFSET 0

#define CODEC_ANA_RO02_REG     (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x32F) /* CODEC_ANA_RO02�� */
#define CODEC_ANA_RO_02_LEN    8
#define CODEC_ANA_RO_02_OFFSET 0


/******************************************************************************/
/*                      DA_SEPARATE_V3 ctrl Registers' Definitions                            */
/******************************************************************************/
#define CTRL_REG_CLASSD_CTRL0_REG               (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x17A) /* classd���ƼĴ���0�� */
#define CTRL_REG_CLASSD_GAIN_LEN        2
#define CTRL_REG_CLASSD_GAIN_OFFSET     6
#define CTRL_REG_CLASSD_I_OCP_LEN       2
#define CTRL_REG_CLASSD_I_OCP_OFFSET    4
#define CTRL_REG_CLASSD_DRV_EN_LEN      1
#define CTRL_REG_CLASSD_DRV_EN_OFFSET   3
#define CTRL_REG_CLASSD_MUTE_SEL_LEN    1
#define CTRL_REG_CLASSD_MUTE_SEL_OFFSET 2
#define CTRL_REG_CLASSD_MUTE_LEN        1
#define CTRL_REG_CLASSD_MUTE_OFFSET     1
#define CTRL_REG_REG_CLASSD_EN_LEN      1
#define CTRL_REG_REG_CLASSD_EN_OFFSET   0

#define CTRL_REG_CLASSD_CTRL1_REG               (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x17B) /* classd���ƼĴ���1�� */
#define CTRL_REG_CLASSD_CTRL1_LEN     2
#define CTRL_REGCLASSD_CTRL1_OFFSET   6
#define CTRL_REG_CLASSD_N_SEL_LEN     2
#define CTRL_REG_CLASSD_N_SEL_OFFSET  4
#define CTRL_REG_CLASSD_P_SEL_LEN     2
#define CTRL_REG_CLASSD_P_SEL_OFFSET  2
#define CTRL_REG_CLASSD_I_PUMP_LEN    2
#define CTRL_REG_CLASSD_I_PUMP_OFFSET 0

#define CTRL_REG_CLASSD_CTRL2_REG               (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x17C) /* classd���ƼĴ���2�� */
#define CTRL_REG_CLASSD_RESERVE0_LEN    4
#define CTRL_REG_CLASSD_RESERVE0_OFFSET 4
#define CTRL_REG_CLASSD_CTRL2_LEN       1
#define CTRL_REG_CLASSD_CTRL2_OFFSET    3
#define CTRL_REG_CLASSD_OCP_BPS_LEN     1
#define CTRL_REG_CLASSD_OCP_BPS_OFFSET  2
#define CTRL_REG_CLASSD_DT_SEL_LEN      1
#define CTRL_REG_CLASSD_DT_SEL_OFFSET   1
#define CTRL_REG_CLASSD_PLS_BYP_LEN     1
#define CTRL_REG_CLASSD_PLS_BYP_OFFSET  0

#define CTRL_REG_CLASSD_CTRL3_REG               (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x17D) /* classd���ƼĴ���3�� */
#define CTRL_REG_CLASSD_RESERVE1_LEN    8
#define CTRL_REG_CLASSD_RESERVE1_OFFSET 0

#define CTRL_REG_PMU_SOFT_RST_REG        (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x17E) /* PMU��λ�Ĵ����� */
#define CTRL_REG_SOFT_RST_N_LEN    8
#define CTRL_REG_SOFT_RST_N_OFFSET 0

#define CTRL_REG_DIG_IO_DS_CODEC_CFG_REG  (DA_SEPARATE_V3_PMU_CODEC_BASE + 0x21A) /* ����CODEC IO�������üĴ��� */
#define CTRL_REG_RESERVED_0_LEN       4
#define CTRL_REG_RESERVED_0_OFFSET    4
#define CTRL_REG_ADC_SDATA0_DS_LEN    2
#define CTRL_REG_ADC_SDATA0_DS_OFFSET 2
#define CTRL_REG_ADC_SDATA1_DS_LEN    2
#define CTRL_REG_ADC_SDATA1_DS_OFFSET 0

#endif /* __DA_SEPARATE_V3_PMU_REG_DEF_H__ */
