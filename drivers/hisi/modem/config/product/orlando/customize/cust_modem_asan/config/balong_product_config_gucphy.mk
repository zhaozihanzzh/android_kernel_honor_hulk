# MD5: 889a6b76f9bd1c96875e8f8cf3b58d87
CFG_ZSP_DSP_CHIP_BB_TYPE		:=21
CFG_NV_VERSION :=nv_boston
CFG_ZSP_DSP_PRODUCT_FORM		:=4
CFG_BOARD                               := SFT
CFG_UPHY_BOARD_TYPE                     := 2
CFG_FEATURE_TEMP_MULTI_MODE_LP          := FEATURE_ON
CFG_FEATURE_GSM_SDR			:= FEATURE_ON
CFG_FEATURE_GSM_SDR_DAIC		:= FEATURE_OFF
CFG_FEATURE_GSM_WHOLE_SDR		:= FEATURE_ON
CFG_FEATURE_XBBE16_NEW_MAIL		:= FEATURE_ON
CFG_FEATURE_SRAM_400K                   := FEATURE_OFF
CFG_FEATURE_EXTERNAL_32K_CLK		:= FEATURE_ON
CFG_FEATURE_SOCP_ON_DEMAND		:= FEATURE_OFF
CFG_FEATURE_TAS				:= FEATURE_ON
CFG_FEATURE_DC_DPA			:= FEATURE_ON
CFG_FEATURE_RFIC_RESET_GPIO_ON		:= FEATURE_OFF
CFG_FEATURE_VIRTUAL_BAND			    := FEATURE_ON
CFG_FEATURE_HI6363                		:= FEATURE_ON
CFG_FEATURE_RTT_TEST                            := FEATURE_ON
CFG_FEATURE_RTT_RANDOM_TEST                     := FEATURE_OFF
CFG_FEATURE_GUTLC_ONE_DSP               := FEATURE_ON
CFG_FEATURE_NX_CORE_OPEN                := FEATURE_ON
CFG_FEATURE_CSDR                        := FEATURE_ON
CFG_FEATURE_HITUNE                      := FEATURE_ON
CFG_CPHY_PUB_DTCM_BASE	    :=0xE347B000
CFG_CPHY_PUB_ITCM_BASE	    :=0xE3523000
CFG_CPHY_PRV_DTCM_BASE	    :=0xE347B000
CFG_CPHY_PRV_ITCM_BASE	    :=0xE3523000
CFG_CPHY_PUB_DTCM_SIZE		:=0x45000
CFG_CPHY_PUB_ITCM_SIZE		:=0x3D000
CFG_CPHY_PRV_DTCM_SIZE		:=0x45000
CFG_CPHY_PRV_ITCM_SIZE		:=0x3D000
CFG_CPHY_PUB_DTCM_GLB_MINUS_LOCAL	    := 0x0
ifeq ($(chip_type),es)
CFG_XTENSA_CORE_X_CACHE             := Phoenix_NX
CFG_LD_MAP_PATH                     := orlando_gutcl_one_dsp_lsp
CFG_XTENSA_CORE_X_SYSTEM            := RH-2018.5
else
CFG_XTENSA_CORE_X_CACHE             := Phoenix_NX
CFG_LD_MAP_PATH                     := orlando_gutcl_one_dsp_lsp
CFG_XTENSA_CORE_X_SYSTEM            := RH-2018.5
endif
CFG_FEATURE_EASYRF                        := FEATURE_OFF
CFG_MODEM_GUPHY_LTO                       := YES
CFG_UPHY_NSCS_CTRL := YES
CFG_GUC_RTT_TEST_ENABLED := YES
CFG_PHY_CBT_ENABLED := YES
