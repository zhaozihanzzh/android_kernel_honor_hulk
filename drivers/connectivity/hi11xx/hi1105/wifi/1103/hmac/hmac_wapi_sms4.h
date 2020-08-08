
#ifndef __HMAC_WAPI_SMS4_H__
#define __HMAC_WAPI_SMS4_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* 1 头文件包含 */
#undef THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_WAPI_SMS4_H
#ifdef _PRE_WLAN_FEATURE_WAPI
/* 2 宏定义 */
#define Rotl(_x, _y)    (((_x) << (_y)) | ((_x) >> (32 - (_y)))) /* 循环左移 */
#define getbyte(_x, _y) (((unsigned char *)&(_x))[_y])              /* 以y为下标，获取x对应的字节值 */

#define ByteSub(_S, _A)                              \
    ((_S)[((oal_uint32)(_A)) >> 24 & 0xFF] << 24 ^ \
    (_S)[((oal_uint32)(_A)) >> 16 & 0xFF] << 16 ^  \
    (_S)[((oal_uint32)(_A)) >> 8 & 0xFF] << 8 ^    \
    (_S)[((oal_uint32)(_A)) & 0xFF])

#define L1(_B) ((_B) ^ Rotl(_B, 2) ^ Rotl(_B, 10) ^ Rotl(_B, 18) ^ Rotl(_B, 24))
#define L2(_B) ((_B) ^ Rotl(_B, 13) ^ Rotl(_B, 23))

/* 3 枚举定义 */
/* 4 全局变量声明 */
/* 5 消息头定义 */
/* 6 消息定义 */
/* 7 STRUCT定义 */
/* 8 UNION定义 */
/* 9 OTHERS定义 */
/* 10 函数声明 */
extern oal_void hmac_sms4_crypt_etc(oal_uint8 *puc_input, oal_uint8 *puc_output,
                                    oal_uint32 *puc_rk, oal_uint32 ul_rk_len);
extern oal_void hmac_sms4_keyext_etc(oal_uint8 *puc_key, oal_uint32 *pul_rk, oal_uint32 ul_rk_len);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hmac_wapi_sms4.h */

