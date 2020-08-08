/*
 * stwlc33_txfw_sram_1100.h
 *
 * stwlc33 tx sram patch
 *
 * Copyright (c) 2019-2019 Huawei Technologies Co., Ltd.
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

/*
 * r321: fix can`t rcv 0x28 cmd from rx
 * r329: fix mis-triggered ocp as tx mode, remove it
 * r341: added a new feature to limit the operating frequency in register
 * r340: set tx ping rx fop
 */

#ifndef _STWLC33_TXFW_SRAM_1100_H_
#define _STWLC33_TXFW_SRAM_1100_H_

/* r340 */
unsigned char stwlc33_txfw_sram_1100h[] = {
	0x10, 0xB5, 0x4F, 0xF0, 0x00, 0x54, 0x4F, 0xF4,
	0x50, 0x70, 0xD4, 0xF8, 0x48, 0x11, 0xC8, 0x81,
	0xD4, 0xF8, 0x4C, 0x11, 0xC8, 0x81, 0xD4, 0xF8,
	0x48, 0x01, 0x10, 0xF8, 0x4D, 0x1F, 0x41, 0xF0,
	0x40, 0x01, 0x01, 0x70, 0xD4, 0xF8, 0x4C, 0x01,
	0x10, 0xF8, 0x4D, 0x1F, 0x41, 0xF0, 0x40, 0x01,
	0x01, 0x70, 0x72, 0xB6, 0x1D, 0x48, 0xA0, 0x63,
	0xD4, 0xF8, 0x88, 0x01, 0xD4, 0xF8, 0x4C, 0x11,
	0x04, 0xF5, 0x86, 0x74, 0x80, 0x79, 0x81, 0xF8,
	0x84, 0x00, 0x00, 0xF0, 0x7D, 0xF8, 0xD4, 0xF8,
	0x20, 0x11, 0x17, 0x48, 0x88, 0x80, 0xD4, 0xF8,
	0x20, 0x11, 0x16, 0x48, 0xC8, 0x86, 0xD4, 0xF8,
	0x20, 0x11, 0x15, 0x48, 0x88, 0x85, 0xD4, 0xF8,
	0x20, 0x11, 0x14, 0x48, 0x08, 0x86, 0xD4, 0xF8,
	0x20, 0x11, 0x13, 0x48, 0x88, 0x86, 0x01, 0x20,
	0x84, 0xF8, 0x74, 0x01, 0xD4, 0xF8, 0x20, 0x21,
	0x10, 0x49, 0xA2, 0xF8, 0x40, 0x10, 0x62, 0x6C,
	0x19, 0x21, 0x82, 0xF8, 0xA7, 0x10, 0xA1, 0x6F,
	0x62, 0x6C, 0x49, 0x7E, 0x49, 0x1C, 0x82, 0xF8,
	0xA8, 0x10, 0x61, 0x6C, 0x81, 0xF8, 0xA9, 0x00,
	0xD4, 0xF8, 0x20, 0x11, 0x08, 0x48, 0x48, 0x87,
	0x62, 0xB6, 0x10, 0xBD, 0xC1, 0x14, 0x00, 0x20,
	0x15, 0x18, 0x00, 0x20, 0xCD, 0x10, 0x00, 0x20,
	0x01, 0x11, 0x00, 0x20, 0xF1, 0x10, 0x00, 0x20,
	0xC1, 0x16, 0x00, 0x20, 0x47, 0x13, 0x00, 0x20,
	0xF5, 0x11, 0x00, 0x20, 0x2D, 0xE9, 0xF0, 0x41,
	0x05, 0x4D, 0x00, 0xF0, 0x72, 0xF8, 0x20, 0xB1,
	0x04, 0x4C, 0x01, 0x26, 0x41, 0xF2, 0x93, 0x11,
	0x08, 0x47, 0x41, 0xF2, 0x51, 0x14, 0x20, 0x47,
	0x2C, 0x02, 0x00, 0x20, 0x44, 0x00, 0x00, 0x20,
	0x70, 0xB5, 0x00, 0xF0, 0x45, 0xFA, 0x00, 0xB1,
	0x70, 0xBD, 0x44, 0xF6, 0x01, 0x20, 0x00, 0x47,
	0x70, 0xB5, 0x00, 0xF0, 0x3A, 0xFC, 0x02, 0x4C,
	0x02, 0x4D, 0x47, 0xF2, 0x5B, 0x70, 0x00, 0x47,
	0x00, 0x38, 0x00, 0x22, 0x74, 0x02, 0x00, 0x20,
	0x40, 0xBA, 0x70, 0x47, 0x40, 0xBA, 0x70, 0x47,
	0x40, 0xBA, 0x70, 0x47, 0xC0, 0xBA, 0x70, 0x47,
	0xC0, 0xBA, 0x70, 0x47, 0xC0, 0xBA, 0x70, 0x47,
	0x4F, 0xEA, 0x30, 0x00, 0x70, 0x47, 0x00, 0x00,
	0x4F, 0xEA, 0x30, 0x00, 0x70, 0x47, 0x00, 0x00,
	0x4F, 0xEA, 0x30, 0x00, 0x70, 0x47, 0x00, 0x00,
	0x30, 0xB5, 0x89, 0xB0, 0x01, 0x20, 0x47, 0xF2,
	0xD3, 0x51, 0x88, 0x47, 0x00, 0x25, 0x4F, 0xF0,
	0x00, 0x54, 0x03, 0x20, 0x84, 0xF8, 0x75, 0x52,
	0x84, 0xF8, 0x46, 0x00, 0xC4, 0xF8, 0xC0, 0x51,
	0xC4, 0xF8, 0xC4, 0x51, 0xC4, 0xF8, 0xC8, 0x51,
	0xC4, 0xF8, 0xCC, 0x51, 0xC4, 0xF8, 0xD0, 0x51,
	0xC4, 0xF8, 0xD4, 0x51, 0x69, 0x46, 0x0E, 0x20,
	0x47, 0xF2, 0x6D, 0x52, 0x90, 0x47, 0x58, 0xB1,
	0x9D, 0xF9, 0x1A, 0x00, 0x00, 0xF5, 0xD6, 0x70,
	0xC4, 0xF8, 0xE0, 0x01, 0x9D, 0xF9, 0x1B, 0x00,
	0x00, 0xF2, 0x55, 0x10, 0xC4, 0xF8, 0xE4, 0x01,
	0x1B, 0x48, 0x1C, 0x49, 0x00, 0x68, 0x08, 0x60,
	0x1B, 0x48, 0x05, 0x80, 0xD4, 0xF8, 0x4C, 0x11,
	0x05, 0x20, 0xA1, 0xF8, 0x80, 0x00, 0x09, 0xB0,
	0x30, 0xBD, 0x10, 0xB5, 0x4F, 0xF0, 0x00, 0x50,
	0x90, 0xF8, 0x44, 0x00, 0x02, 0x28, 0x04, 0xD0,
	0x30, 0x28, 0x06, 0xD0, 0x31, 0x28, 0x0D, 0xD0,
	0x0A, 0xE0, 0x00, 0xF0, 0xFD, 0xF8, 0x01, 0x20,
	0x10, 0xBD, 0x0F, 0x49, 0x00, 0x20, 0x08, 0x80,
	0x0B, 0x48, 0x0C, 0x49, 0x00, 0x68, 0x08, 0x60,
	0x00, 0x20, 0x10, 0xBD, 0xBD, 0xE8, 0x10, 0x40,
	0x00, 0xF0, 0x16, 0xB8, 0x4F, 0xF0, 0x00, 0x50,
	0x08, 0x49, 0xD0, 0xF8, 0x4C, 0x01, 0x0A, 0x68,
	0x40, 0xF8, 0x50, 0x2F, 0x8A, 0x88, 0x82, 0x80,
	0x89, 0x79, 0x81, 0x71, 0x70, 0x47, 0x00, 0x00,
	0x18, 0x0A, 0x00, 0x20, 0x68, 0x1A, 0x00, 0x20,
	0x62, 0x1A, 0x00, 0x20, 0x22, 0x03, 0x00, 0x20,
	0x2D, 0xE9, 0xF0, 0x47, 0x4F, 0xF0, 0x00, 0x56,
	0x63, 0x49, 0xD6, 0xF8, 0xD0, 0x01, 0xDF, 0xF8,
	0x8C, 0xA1, 0x63, 0x4C, 0x08, 0x42, 0x45, 0xF6,
	0xD9, 0x49, 0x45, 0xF6, 0x27, 0x47, 0x4F, 0xF0,
	0x00, 0x05, 0x08, 0xD0, 0x65, 0x80, 0xDA, 0xF8,
	0x00, 0x00, 0xA0, 0x60, 0x21, 0x20, 0x49, 0x46,
	0x88, 0x47, 0x21, 0x20, 0xB8, 0x47, 0xD6, 0xF8,
	0x4C, 0x01, 0xDF, 0xF8, 0x68, 0x81, 0xB0, 0xF8,
	0x80, 0x00, 0xA0, 0x80, 0xD8, 0xF8, 0x00, 0x10,
	0x00, 0x29, 0x5F, 0xD0, 0x61, 0x88, 0x81, 0x42,
	0x00, 0xD3, 0xE8, 0xBB, 0x20, 0x20, 0x49, 0x46,
	0x88, 0x47, 0x20, 0x20, 0xB8, 0x47, 0xD6, 0xF8,
	0x5C, 0x01, 0x01, 0x88, 0x41, 0xF0, 0x40, 0x01,
	0x01, 0x80, 0xD6, 0xF8, 0x60, 0x01, 0x01, 0x88,
	0x41, 0xF0, 0x40, 0x01, 0x01, 0x80, 0x4C, 0x48,
	0x01, 0x68, 0x05, 0x29, 0x50, 0xD9, 0x05, 0x60,
	0xC8, 0xF8, 0x00, 0x50, 0x60, 0x88, 0x47, 0x49,
	0x40, 0x1C, 0x80, 0xB2, 0x01, 0x22, 0x60, 0x80,
	0x10, 0x39, 0x86, 0xF8, 0x5C, 0x50, 0x0A, 0x60,
	0x01, 0x28, 0x09, 0xD1, 0x43, 0x49, 0xA0, 0x68,
	0x88, 0x42, 0x02, 0xD9, 0x4F, 0xF6, 0x30, 0x00,
	0x01, 0xE0, 0x4F, 0xF4, 0xFA, 0x60, 0x20, 0x80,
	0xDF, 0xF8, 0xE8, 0x80, 0xDA, 0xF8, 0x00, 0x10,
	0xA1, 0x60, 0xA8, 0xF1, 0x0C, 0x08, 0xB4, 0xF9,
	0x00, 0x20, 0xD8, 0xF8, 0x00, 0x00, 0x8B, 0x18,
	0x08, 0xF1, 0x04, 0x07, 0x83, 0x42, 0x00, 0xE0,
	0x1C, 0xE0, 0x03, 0xD3, 0xD7, 0xF8, 0x00, 0xC0,
	0x63, 0x45, 0x00, 0xD9, 0x8B, 0x1A, 0x3A, 0x68,
	0x9A, 0x42, 0x00, 0xD2, 0x13, 0x46, 0x98, 0x42,
	0x00, 0xD9, 0x03, 0x46, 0x99, 0x42, 0x0D, 0xD0,
	0x2A, 0x48, 0xCA, 0xF8, 0x00, 0x30, 0x00, 0x1D,
	0x00, 0x22, 0x01, 0x88, 0x18, 0x46, 0x47, 0xF2,
	0xA3, 0x73, 0x98, 0x47, 0x40, 0x46, 0x44, 0xF2,
	0xDF, 0x51, 0x88, 0x47, 0x25, 0x49, 0x09, 0x1D,
	0x08, 0x68, 0x28, 0xB1, 0x62, 0x88, 0xA0, 0x88,
	0x82, 0x42, 0x00, 0xD3, 0x00, 0xB9, 0x0D, 0x60,
	0x00, 0x20, 0xBD, 0xE8, 0xF0, 0x87, 0x30, 0xB5,
	0x4F, 0xF0, 0x00, 0x51, 0x4F, 0xF4, 0xFA, 0x73,
	0x91, 0xF8, 0x54, 0x20, 0x91, 0xF8, 0x60, 0x00,
	0x02, 0xF0, 0x3F, 0x02, 0x12, 0xFB, 0x03, 0xF2,
	0x50, 0x43, 0xC0, 0x09, 0xA1, 0xF8, 0xA8, 0x00,
	0xB1, 0xF8, 0xAA, 0x20, 0x00, 0x24, 0x12, 0x1A,
	0x13, 0xB2, 0xD1, 0xF8, 0x50, 0x21, 0x92, 0xF8,
	0xA9, 0x50, 0x01, 0x2D, 0x18, 0xD1, 0xB8, 0xB1,
	0x92, 0xF8, 0xA7, 0x00, 0x00, 0xEB, 0xC0, 0x05,
	0x05, 0xEB, 0x00, 0x10, 0xB3, 0xEB, 0x80, 0x0F,
	0x0E, 0xDD, 0x11, 0xF8, 0x78, 0x0F, 0x40, 0x1C,
	0xC0, 0xB2, 0x08, 0x70, 0x92, 0xF8, 0xA8, 0x10,
	0x49, 0x1C, 0x88, 0x42, 0x03, 0xD3, 0x07, 0x49,
	0x01, 0x20, 0x10, 0x31, 0x08, 0x60, 0x30, 0xBD,
	0x81, 0xF8, 0x78, 0x40, 0x30, 0xBD, 0x00, 0x00,
	0x00, 0x28, 0x30, 0x00, 0x18, 0x0A, 0x00, 0x20,
	0x60, 0x1A, 0x00, 0x20, 0x3C, 0x3A, 0x00, 0x22,
	0x6C, 0x1A, 0x00, 0x20, 0xD0, 0xFB, 0x01, 0x00,
	0x70, 0xB5, 0x39, 0x48, 0x00, 0x25, 0x05, 0x60,
	0x38, 0x48, 0x00, 0x68, 0x4F, 0xF0, 0x00, 0x54,
	0x10, 0xB1, 0x84, 0xF8, 0x45, 0x50, 0x70, 0xBD,
	0x94, 0xF8, 0x46, 0x00, 0x44, 0xF2, 0x1D, 0x61,
	0x88, 0x47, 0x94, 0xF8, 0x46, 0x00, 0x50, 0x28,
	0x10, 0xD0, 0x08, 0xDC, 0x10, 0x28, 0x4F, 0xD0,
	0x20, 0x28, 0x4D, 0xD0, 0x30, 0x28, 0x4B, 0xD0,
	0x36, 0x28, 0x15, 0xD1, 0x41, 0xE0, 0x51, 0x28,
	0x0B, 0xD0, 0x52, 0x28, 0x02, 0xD0, 0x53, 0x28,
	0x0E, 0xD1, 0x06, 0xE0, 0xD4, 0xF8, 0x4C, 0x01,
	0x10, 0xF8, 0x75, 0x1F, 0x41, 0xF0, 0x08, 0x01,
	0x05, 0xE0, 0xD4, 0xF8, 0x4C, 0x01, 0x10, 0xF8,
	0x75, 0x1F, 0x41, 0xF0, 0x04, 0x01, 0x01, 0x70,
	0xD4, 0xF8, 0x5C, 0x01, 0x01, 0x88, 0x41, 0xF0,
	0x01, 0x01, 0x01, 0x80, 0xD4, 0xF8, 0x60, 0x01,
	0x01, 0x88, 0x41, 0xF0, 0x01, 0x01, 0x01, 0x80,
	0x94, 0xF8, 0x46, 0x10, 0x00, 0x20, 0x35, 0x29,
	0x29, 0xD0, 0x40, 0x29, 0x27, 0xD0, 0x50, 0x29,
	0x25, 0xD0, 0x51, 0x29, 0x23, 0xD0, 0x52, 0x29,
	0x21, 0xD0, 0x53, 0x29, 0x1F, 0xD0, 0x36, 0x29,
	0x1D, 0xD0, 0x01, 0x20, 0x84, 0xF8, 0x46, 0x50,
	0xD4, 0xF8, 0x4C, 0x11, 0x91, 0xF8, 0x84, 0x10,
	0x11, 0xB1, 0xD4, 0xF8, 0x88, 0x21, 0x91, 0x71,
	0xBD, 0xE8, 0x70, 0x40, 0x47, 0xF2, 0xD3, 0x51,
	0x08, 0x47, 0xD4, 0xF8, 0x4C, 0x01, 0x10, 0xF8,
	0x75, 0x1F, 0x41, 0xF0, 0x20, 0x01, 0xCA, 0xE7,
	0xD4, 0xF8, 0x4C, 0x01, 0x10, 0xF8, 0x74, 0x1F,
	0x41, 0xF0, 0x01, 0x01, 0xC3, 0xE7, 0x03, 0x21,
	0x84, 0xF8, 0x46, 0x10, 0xE0, 0xE7, 0x00, 0x00,
	0x5E, 0x00, 0x00, 0x20, 0x00, 0x39, 0x00, 0x22,
	0x10, 0xB5, 0x4F, 0xF0, 0x00, 0x54, 0xD4, 0xF8,
	0x50, 0x21, 0x92, 0xF8, 0x8E, 0x10, 0xCB, 0x07,
	0xD4, 0xF8, 0xE0, 0x10, 0x09, 0xD0, 0x11, 0xB1,
	0x01, 0x29, 0x03, 0xD0, 0x0D, 0xE0, 0x84, 0xF8,
	0xDD, 0x00, 0x45, 0xE0, 0x84, 0xF8, 0xDC, 0x00,
	0x42, 0xE0, 0x00, 0x29, 0xFA, 0xD0, 0x94, 0xF8,
	0xDC, 0x10, 0xFF, 0x29, 0x01, 0xD1, 0x84, 0xF8,
	0xDD, 0x00, 0x94, 0xF8, 0xDC, 0x10, 0x76, 0x29,
	0x10, 0xD1, 0xD4, 0xF8, 0x94, 0x11, 0x01, 0x29,
	0x1C, 0xD0, 0x94, 0xF8, 0xDD, 0x10, 0xC9, 0xB9,
	0xC1, 0x07, 0x17, 0xD0, 0x19, 0x49, 0x01, 0x23,
	0x0B, 0x60, 0x12, 0xF8, 0x88, 0x1F, 0x41, 0xF0,
	0x01, 0x01, 0x11, 0x70, 0x94, 0xF8, 0xDC, 0x10,
	0x80, 0x29, 0x01, 0xD0, 0x81, 0x29, 0x09, 0xD1,
	0xD4, 0xF8, 0x94, 0x21, 0x01, 0x2A, 0x05, 0xD1,
	0x94, 0xF8, 0xDD, 0x20, 0x12, 0xB9, 0xD4, 0xF8,
	0x4C, 0x21, 0x50, 0x54, 0x94, 0xF8, 0xDC, 0x10,
	0xA1, 0xF1, 0x58, 0x02, 0x05, 0x2A, 0x09, 0xD8,
	0xD4, 0xF8, 0x94, 0x21, 0x01, 0x2A, 0x05, 0xD1,
	0x94, 0xF8, 0xDD, 0x20, 0x12, 0xB9, 0xD4, 0xF8,
	0x4C, 0x21, 0x50, 0x54, 0x43, 0xF6, 0xC7, 0x71,
	0x88, 0x47, 0x04, 0x48, 0x14, 0x38, 0x00, 0x68,
	0x54, 0xF8, 0xE0, 0x0F, 0x40, 0x1C, 0x20, 0x60,
	0x10, 0xBD, 0x00, 0x00, 0xAC, 0x34, 0x00, 0x22,
	0x02, 0x48, 0x01, 0x68, 0x49, 0x1C, 0x01, 0x60,
	0x00, 0x20, 0x70, 0x47, 0x6C, 0x1A, 0x00, 0x20,
	0x2D, 0xE9, 0xF0, 0x47, 0x9B, 0x49, 0x08, 0x68,
	0xC2, 0x43, 0x0A, 0x60, 0xC0, 0x07, 0x15, 0xD0,
	0x99, 0x4F, 0x38, 0x78, 0xDF, 0xF8, 0x5C, 0xA2,
	0x00, 0x25, 0x4E, 0x06, 0x0A, 0xF1, 0x20, 0x0A,
	0x45, 0xF6, 0x8B, 0x28, 0x4F, 0xF0, 0x01, 0x09,
	0x02, 0x28, 0x09, 0xD0, 0x38, 0x78, 0x01, 0x28,
	0x78, 0xD0, 0xFF, 0x21, 0x8A, 0xF8, 0x00, 0x10,
	0x48, 0x46, 0x38, 0x70, 0xBD, 0xE8, 0xF0, 0x87,
	0x96, 0xF8, 0x3D, 0x01, 0x40, 0x1C, 0x86, 0xF8,
	0x3D, 0x01, 0xB6, 0xF8, 0x44, 0x01, 0xB6, 0xF8,
	0x44, 0x11, 0x40, 0x09, 0x80, 0x00, 0x00, 0xF1,
	0x00, 0x50, 0xD0, 0xF8, 0x84, 0x03, 0x01, 0xF0,
	0x1F, 0x01, 0xC8, 0x40, 0x00, 0xF0, 0x01, 0x04,
	0x96, 0xF8, 0x3D, 0x01, 0x02, 0x28, 0x15, 0xD3,
	0xA4, 0xB1, 0x86, 0xF8, 0x3D, 0x51, 0xB6, 0xF8,
	0x44, 0x11, 0xB6, 0xF8, 0x46, 0x01, 0x40, 0x1E,
	0x81, 0x42, 0x03, 0xD1, 0x96, 0xF8, 0x3E, 0x01,
	0x01, 0x28, 0x01, 0xD0, 0x40, 0x46, 0x80, 0x47,
	0x96, 0xF8, 0x3E, 0x01, 0x01, 0x28, 0x07, 0xD0,
	0x86, 0xF8, 0x3E, 0x91, 0x96, 0xF8, 0x3D, 0x01,
	0x04, 0x28, 0x12, 0xD3, 0x44, 0xB1, 0x10, 0xE0,
	0x86, 0xF8, 0x3E, 0x51, 0xB6, 0xF8, 0x44, 0x01,
	0x40, 0x1C, 0xA6, 0xF8, 0x44, 0x01, 0xF1, 0xE7,
	0x86, 0xF8, 0x3D, 0x51, 0x40, 0x46, 0x80, 0x47,
	0xB6, 0xF8, 0x44, 0x01, 0x40, 0x1C, 0xA6, 0xF8,
	0x44, 0x01, 0xB6, 0xF8, 0x44, 0x01, 0xB6, 0xF8,
	0x46, 0x11, 0x88, 0x42, 0xB2, 0xD3, 0x3D, 0x70,
	0x66, 0x48, 0x00, 0x1F, 0x01, 0x68, 0x21, 0xF0,
	0x01, 0x01, 0x01, 0x60, 0x4F, 0xF0, 0xE0, 0x21,
	0x40, 0x20, 0xC1, 0xF8, 0x80, 0x01, 0x8A, 0xF8,
	0x00, 0x50, 0xD6, 0xF8, 0x5C, 0x01, 0x01, 0x88,
	0x41, 0xF0, 0x80, 0x01, 0x01, 0x80, 0xD6, 0xF8,
	0x60, 0x01, 0x01, 0x88, 0x41, 0xF0, 0x80, 0x01,
	0x01, 0x80, 0x44, 0xF6, 0xC5, 0x40, 0x80, 0x47,
	0xBD, 0xE8, 0xF0, 0x47, 0x00, 0x21, 0x41, 0xF2,
	0xFD, 0x72, 0x08, 0x46, 0x44, 0xF6, 0x43, 0x13,
	0x18, 0x47, 0xFF, 0xE7, 0x40, 0x46, 0x80, 0x47,
	0x86, 0xF8, 0x3D, 0x51, 0x02, 0x20, 0x84, 0xE7,
	0x70, 0xB5, 0x52, 0x4D, 0x28, 0x68, 0x00, 0x28,
	0x39, 0xD0, 0x4F, 0xF0, 0x00, 0x54, 0x94, 0xF8,
	0xE8, 0x00, 0x00, 0x28, 0x33, 0xD0, 0x41, 0xF6,
	0xF3, 0x40, 0x80, 0x47, 0x01, 0x28, 0x03, 0xD1,
	0x94, 0xF8, 0xAD, 0x00, 0x00, 0x28, 0x2A, 0xD1,
	0x47, 0x48, 0x00, 0x78, 0x00, 0x28, 0x26, 0xD1,
	0x28, 0x60, 0xD4, 0xF8, 0x4C, 0x11, 0x46, 0x48,
	0x51, 0xF8, 0x58, 0x2F, 0x02, 0x60, 0x8A, 0x88,
	0x82, 0x80, 0x89, 0x79, 0x81, 0x71, 0x00, 0xF0,
	0x1B, 0xF8, 0x01, 0x28, 0x17, 0xD1, 0x47, 0xF6,
	0x67, 0x20, 0x80, 0x47, 0x3B, 0x49, 0x08, 0x68,
	0xC0, 0x43, 0x08, 0x60, 0xAF, 0xF2, 0x8F, 0x10,
	0xC4, 0xF8, 0x18, 0x01, 0x4F, 0xF0, 0xE0, 0x21,
	0x40, 0x20, 0xC1, 0xF8, 0x80, 0x02, 0xC1, 0xF8,
	0x00, 0x01, 0x34, 0x48, 0x00, 0x1F, 0x01, 0x68,
	0x41, 0xF0, 0x01, 0x01, 0x01, 0x60, 0x70, 0xBD,
	0x2D, 0xE9, 0xFF, 0x5F, 0x4F, 0xF0, 0x00, 0x0B,
	0x4F, 0xF0, 0x00, 0x51, 0x05, 0x46, 0xA1, 0xF8,
	0x46, 0xB1, 0x5C, 0x46, 0x81, 0xF8, 0x3C, 0xB1,
	0x2B, 0x48, 0x80, 0xF8, 0x00, 0xB0, 0x81, 0xF8,
	0x3E, 0xB1, 0x01, 0x20, 0x81, 0xF8, 0x3F, 0x01,
	0xA1, 0xF8, 0x44, 0xB1, 0x28, 0x4E, 0x14, 0x21,
	0x74, 0x3E, 0x30, 0x46, 0x00, 0xF0, 0x68, 0xF9,
	0x00, 0x94, 0x01, 0x94, 0x02, 0x94, 0x03, 0x94,
	0x28, 0x68, 0xCD, 0xF8, 0x01, 0x00, 0xA8, 0x88,
	0xAD, 0xF8, 0x05, 0x00, 0x9D, 0xF8, 0x01, 0x00,
	0x43, 0xF6, 0x3B, 0x11, 0x88, 0x47, 0x00, 0x28,
	0x31, 0xD0, 0x40, 0x1C, 0x8D, 0xF8, 0x00, 0x00,
	0x68, 0x46, 0x43, 0xF6, 0x21, 0x11, 0x88, 0x47,
	0x00, 0x24, 0xE8, 0x46, 0xB2, 0x46, 0x25, 0x46,
	0x1C, 0xE0, 0x08, 0xEB, 0x05, 0x00, 0x00, 0x21,
	0x46, 0x78, 0x43, 0xF6, 0x09, 0x12, 0x30, 0x46,
	0x90, 0x47, 0x62, 0x09, 0x46, 0xEA, 0x00, 0x20,
	0x0A, 0xEB, 0x82, 0x01, 0x89, 0x46, 0xC0, 0xC9,
	0x40, 0x00, 0x40, 0xF4, 0x80, 0x60, 0x04, 0xF0,
	0x1F, 0x02, 0x59, 0x46, 0x00, 0xF0, 0x1E, 0xF9,
	0x06, 0x43, 0x0F, 0x43, 0x0B, 0x34, 0x6D, 0x1C,
	0xC9, 0xE9, 0x00, 0x67, 0x98, 0xF8, 0x00, 0x00,
	0xA8, 0x42, 0xDE, 0xD8, 0x4F, 0xF0, 0x00, 0x50,
	0xA0, 0xF8, 0x46, 0x41, 0x01, 0x20, 0x04, 0xB0,
	0xBD, 0xE8, 0xF0, 0x9F, 0x10, 0x0C, 0x00, 0x40,
	0x70, 0x1A, 0x00, 0x20, 0x18, 0x38, 0x00, 0x22,
	0xF8, 0x03, 0x00, 0x20, 0x4F, 0xF0, 0x00, 0x50,
	0xD0, 0xF8, 0x98, 0x11, 0xF1, 0xB1, 0xD0, 0xF8,
	0x94, 0x11, 0x01, 0x29, 0x1A, 0xD1, 0x0E, 0x49,
	0xD1, 0xF8, 0x14, 0x23, 0x12, 0xB1, 0x00, 0x22,
	0xC1, 0xF8, 0x14, 0x23, 0xD1, 0xF8, 0x08, 0x23,
	0x12, 0xB9, 0xD1, 0xF8, 0x14, 0x23, 0x6A, 0xB1,
	0x08, 0x4B, 0x01, 0x22, 0x1A, 0x60, 0x02, 0x22,
	0x80, 0xF8, 0x44, 0x20, 0xD1, 0xF8, 0x08, 0x13,
	0x09, 0xB1, 0x50, 0x21, 0x00, 0xE0, 0x51, 0x21,
	0x80, 0xF8, 0x46, 0x10, 0x00, 0x20, 0x70, 0x47,
	0x00, 0x30, 0x00, 0x22, 0x04, 0x39, 0x00, 0x22,
	0x2D, 0xE9, 0xF0, 0x41, 0x67, 0x4F, 0x38, 0x68,
	0x00, 0x26, 0x47, 0xF2, 0xA1, 0x68, 0x41, 0xF2,
	0xA5, 0x05, 0x4F, 0xF0, 0x00, 0x54, 0xC8, 0xB1,
	0x47, 0xF6, 0xC5, 0x10, 0x80, 0x47, 0x62, 0x49,
	0x42, 0xF2, 0x04, 0x10, 0x08, 0x60, 0x60, 0x48,
	0x10, 0x38, 0x01, 0x68, 0x21, 0xF0, 0x07, 0x01,
	0xC9, 0x1C, 0x01, 0x60, 0x3E, 0x60, 0x47, 0xF6,
	0x51, 0x20, 0x80, 0x47, 0x5B, 0x21, 0x42, 0x46,
	0x01, 0x20, 0xA8, 0x47, 0xA4, 0xF8, 0x76, 0x62,
	0xC4, 0xF8, 0x7C, 0x62, 0x55, 0x48, 0x00, 0x1D,
	0x01, 0x68, 0x00, 0x29, 0x4D, 0xD0, 0x06, 0x60,
	0xB4, 0xF8, 0x76, 0x12, 0x94, 0xF8, 0x74, 0x02,
	0x81, 0x42, 0x48, 0xD2, 0x47, 0xF6, 0x5B, 0x20,
	0x80, 0x47, 0xD4, 0xF8, 0x7C, 0x12, 0x42, 0x46,
	0x08, 0x44, 0xC4, 0xF8, 0x7C, 0x02, 0xB4, 0xF8,
	0x76, 0x02, 0x5B, 0x21, 0x40, 0x1C, 0xA4, 0xF8,
	0x76, 0x02, 0x01, 0x20, 0xA8, 0x47, 0x48, 0x48,
	0x18, 0x30, 0x00, 0x68, 0xD4, 0xE9, 0x76, 0x12,
	0x80, 0x1A, 0x40, 0xF2, 0x77, 0x12, 0x50, 0x43,
	0x41, 0x43, 0x08, 0x0C, 0xD4, 0xF8, 0x4C, 0x11,
	0xA1, 0xF8, 0x72, 0x00, 0xD4, 0xF8, 0x4C, 0x11,
	0xA1, 0xF8, 0x70, 0x00, 0x3E, 0x48, 0x14, 0x30,
	0x00, 0x68, 0xD4, 0xF8, 0xE4, 0x11, 0x81, 0x42,
	0x08, 0xD2, 0x40, 0x1A, 0x40, 0xF2, 0x77, 0x11,
	0xD4, 0xF8, 0xE0, 0x21, 0x48, 0x43, 0x42, 0x43,
	0x10, 0x0C, 0x00, 0xE0, 0x00, 0x20, 0xD4, 0xF8,
	0x4C, 0x11, 0xA1, 0xF8, 0x6E, 0x00, 0x34, 0x48,
	0x10, 0x30, 0x00, 0x68, 0xB4, 0xF8, 0xF8, 0x11,
	0x40, 0x1A, 0x87, 0x21, 0x01, 0xEB, 0x50, 0x00,
	0xD4, 0xF8, 0x4C, 0x11, 0x40, 0x42, 0x81, 0xF8,
	0x7A, 0x00, 0xBD, 0xE8, 0xF0, 0x81, 0xD4, 0xF8,
	0x7C, 0x12, 0xB1, 0xFB, 0xF0, 0xF0, 0xA4, 0xF8,
	0x70, 0x00, 0x47, 0xF6, 0x67, 0x20, 0x80, 0x47,
	0x26, 0x49, 0x01, 0x20, 0xF4, 0x31, 0x08, 0x60,
	0xEF, 0xE7, 0x70, 0xB5, 0x4F, 0xF0, 0x00, 0x54,
	0x00, 0x25, 0x94, 0xF8, 0x51, 0x03, 0x30, 0xB3,
	0x94, 0xF8, 0x47, 0x03, 0x41, 0xF2, 0x41, 0x21,
	0x88, 0x47, 0x01, 0x28, 0x1F, 0xD1, 0x1F, 0x48,
	0x05, 0x60, 0x94, 0xF8, 0x47, 0x03, 0x43, 0xF6,
	0x3B, 0x11, 0x88, 0x47, 0x1C, 0x4E, 0x30, 0xB1,
	0x40, 0x1C, 0x84, 0xF8, 0x46, 0x03, 0x30, 0x46,
	0x43, 0xF6, 0x21, 0x11, 0x88, 0x47, 0x18, 0x48,
	0x31, 0x68, 0x25, 0x38, 0x01, 0x60, 0x71, 0x68,
	0x41, 0x60, 0x31, 0x89, 0x01, 0x81, 0xB1, 0x7A,
	0x81, 0x72, 0x12, 0x49, 0x01, 0x20, 0x20, 0x31,
	0x84, 0xF8, 0x51, 0x53, 0x08, 0x60, 0xD4, 0xF8,
	0x84, 0x01, 0x40, 0x7D, 0xC0, 0xF3, 0x00, 0x00,
	0x84, 0xF8, 0x80, 0x02, 0x09, 0x48, 0x14, 0x30,
	0x01, 0x68, 0x39, 0xB1, 0x05, 0x60, 0x94, 0xF8,
	0x75, 0x02, 0x18, 0xB9, 0x01, 0x20, 0x47, 0xF2,
	0xD3, 0x51, 0x88, 0x47, 0xFF, 0xF7, 0x34, 0xFF,
	0xBD, 0xE8, 0x70, 0x40, 0x47, 0xF6, 0xE5, 0x00,
	0x00, 0x47, 0x00, 0x00, 0x0C, 0x38, 0x00, 0x22,
	0x14, 0x24, 0x00, 0x40, 0x30, 0x3A, 0x00, 0x22,
	0x46, 0x03, 0x00, 0x20, 0x20, 0x2A, 0x04, 0xDB,
	0x20, 0x3A, 0x00, 0xFA, 0x02, 0xF1, 0x00, 0x20,
	0x70, 0x47, 0x91, 0x40, 0xC2, 0xF1, 0x20, 0x03,
	0x20, 0xFA, 0x03, 0xF3, 0x19, 0x43, 0x90, 0x40,
	0x70, 0x47, 0xD2, 0xB2, 0x01, 0xE0, 0x00, 0xF8,
	0x01, 0x2B, 0x49, 0x1E, 0xFB, 0xD2, 0x70, 0x47,
	0x00, 0x22, 0xF6, 0xE7, 0x10, 0xB5, 0x13, 0x46,
	0x0A, 0x46, 0x04, 0x46, 0x19, 0x46, 0xFF, 0xF7,
	0xF0, 0xFF, 0x20, 0x46, 0x10, 0xBD, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};
#endif /* _STWLC33_TXFW_SRAM_1100_H_ */
