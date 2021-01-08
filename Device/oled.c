#include "oled.h"

const uint8 code fontx[][5] ={
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x3E, 0x5B, 0x4F, 0x5B, 0x3E},
    {0x3E, 0x6B, 0x4F, 0x6B, 0x3E},
    {0x1C, 0x3E, 0x7C, 0x3E, 0x1C},
    {0x18, 0x3C, 0x7E, 0x3C, 0x18},
    {0x1C, 0x57, 0x7D, 0x57, 0x1C},
    {0x1C, 0x5E, 0x7F, 0x5E, 0x1C},
    {0x00, 0x18, 0x3C, 0x18, 0x00},
    {0xFF, 0xE7, 0xC3, 0xE7, 0xFF},
    {0x00, 0x18, 0x24, 0x18, 0x00},
    {0xFF, 0xE7, 0xDB, 0xE7, 0xFF},
    {0x30, 0x48, 0x3A, 0x06, 0x0E},
    {0x26, 0x29, 0x79, 0x29, 0x26},
    {0x40, 0x7F, 0x05, 0x05, 0x07},
    {0x40, 0x7F, 0x05, 0x25, 0x3F},
    {0x5A, 0x3C, 0xE7, 0x3C, 0x5A},
    {0x7F, 0x3E, 0x1C, 0x1C, 0x08},
    {0x08, 0x1C, 0x1C, 0x3E, 0x7F},
    {0x14, 0x22, 0x7F, 0x22, 0x14},
    {0x5F, 0x5F, 0x00, 0x5F, 0x5F},
    {0x06, 0x09, 0x7F, 0x01, 0x7F},
    {0x00, 0x66, 0x89, 0x95, 0x6A},
    {0x60, 0x60, 0x60, 0x60, 0x60},
    {0x94, 0xA2, 0xFF, 0xA2, 0x94},
    {0x08, 0x04, 0x7E, 0x04, 0x08},
    {0x10, 0x20, 0x7E, 0x20, 0x10},
    {0x08, 0x08, 0x2A, 0x1C, 0x08},
    {0x08, 0x1C, 0x2A, 0x08, 0x08},
    {0x1E, 0x10, 0x10, 0x10, 0x10},
    {0x0C, 0x1E, 0x0C, 0x1E, 0x0C},
    {0x30, 0x38, 0x3E, 0x38, 0x30},
    {0x06, 0x0E, 0x3E, 0x0E, 0x06},
    {0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x5F, 0x00, 0x00},
    {0x00, 0x07, 0x00, 0x07, 0x00},
    {0x14, 0x7F, 0x14, 0x7F, 0x14},
    {0x24, 0x2A, 0x7F, 0x2A, 0x12},
    {0x23, 0x13, 0x08, 0x64, 0x62},
    {0x36, 0x49, 0x56, 0x20, 0x50},
    {0x00, 0x08, 0x07, 0x03, 0x00},
    {0x00, 0x1C, 0x22, 0x41, 0x00},
    {0x00, 0x41, 0x22, 0x1C, 0x00},
    {0x2A, 0x1C, 0x7F, 0x1C, 0x2A},
    {0x08, 0x08, 0x3E, 0x08, 0x08},
    {0x00, 0x80, 0x70, 0x30, 0x00},
    {0x08, 0x08, 0x08, 0x08, 0x08},
    {0x00, 0x00, 0x60, 0x60, 0x00},
    {0x20, 0x10, 0x08, 0x04, 0x02},
    {0x3E, 0x51, 0x49, 0x45, 0x3E},
    {0x00, 0x42, 0x7F, 0x40, 0x00},
    {0x72, 0x49, 0x49, 0x49, 0x46},
    {0x21, 0x41, 0x49, 0x4D, 0x33},
    {0x18, 0x14, 0x12, 0x7F, 0x10},
    {0x27, 0x45, 0x45, 0x45, 0x39},
    {0x3C, 0x4A, 0x49, 0x49, 0x31},
    {0x41, 0x21, 0x11, 0x09, 0x07},
    {0x36, 0x49, 0x49, 0x49, 0x36},
    {0x46, 0x49, 0x49, 0x29, 0x1E},
    {0x00, 0x00, 0x14, 0x00, 0x00},
    {0x00, 0x40, 0x34, 0x00, 0x00},
    {0x00, 0x08, 0x14, 0x22, 0x41},
    {0x14, 0x14, 0x14, 0x14, 0x14},
    {0x00, 0x41, 0x22, 0x14, 0x08},
    {0x02, 0x01, 0x59, 0x09, 0x06},
    {0x3E, 0x41, 0x5D, 0x59, 0x4E},
    {0x7C, 0x12, 0x11, 0x12, 0x7C},
    {0x7F, 0x49, 0x49, 0x49, 0x36},
    {0x3E, 0x41, 0x41, 0x41, 0x22},
    {0x7F, 0x41, 0x41, 0x41, 0x3E},
    {0x7F, 0x49, 0x49, 0x49, 0x41},
    {0x7F, 0x09, 0x09, 0x09, 0x01},
    {0x3E, 0x41, 0x41, 0x51, 0x73},
    {0x7F, 0x08, 0x08, 0x08, 0x7F},
    {0x00, 0x41, 0x7F, 0x41, 0x00},
    {0x20, 0x40, 0x41, 0x3F, 0x01},
    {0x7F, 0x08, 0x14, 0x22, 0x41},
    {0x7F, 0x40, 0x40, 0x40, 0x40},
    {0x7F, 0x02, 0x1C, 0x02, 0x7F},
    {0x7F, 0x04, 0x08, 0x10, 0x7F},
    {0x3E, 0x41, 0x41, 0x41, 0x3E},
    {0x7F, 0x09, 0x09, 0x09, 0x06},
    {0x3E, 0x41, 0x51, 0x21, 0x5E},
    {0x7F, 0x09, 0x19, 0x29, 0x46},
    {0x26, 0x49, 0x49, 0x49, 0x32},
    {0x03, 0x01, 0x7F, 0x01, 0x03},
    {0x3F, 0x40, 0x40, 0x40, 0x3F},
    {0x1F, 0x20, 0x40, 0x20, 0x1F},
    {0x3F, 0x40, 0x38, 0x40, 0x3F},
    {0x63, 0x14, 0x08, 0x14, 0x63},
    {0x03, 0x04, 0x78, 0x04, 0x03},
    {0x61, 0x59, 0x49, 0x4D, 0x43},
    {0x00, 0x7F, 0x41, 0x41, 0x41},
    {0x02, 0x04, 0x08, 0x10, 0x20},
    {0x00, 0x41, 0x41, 0x41, 0x7F},
    {0x04, 0x02, 0x01, 0x02, 0x04},
    {0x40, 0x40, 0x40, 0x40, 0x40},
    {0x00, 0x03, 0x07, 0x08, 0x00},
    {0x20, 0x54, 0x54, 0x78, 0x40},
    {0x7F, 0x28, 0x44, 0x44, 0x38},
    {0x38, 0x44, 0x44, 0x44, 0x28},
    {0x38, 0x44, 0x44, 0x28, 0x7F},
    {0x38, 0x54, 0x54, 0x54, 0x18},
    {0x00, 0x08, 0x7E, 0x09, 0x02},
    {0x18, 0xA4, 0xA4, 0x9C, 0x78},
    {0x7F, 0x08, 0x04, 0x04, 0x78},
    {0x00, 0x44, 0x7D, 0x40, 0x00},
    {0x20, 0x40, 0x40, 0x3D, 0x00},
    {0x7F, 0x10, 0x28, 0x44, 0x00},
    {0x00, 0x41, 0x7F, 0x40, 0x00},
    {0x7C, 0x04, 0x78, 0x04, 0x78},
    {0x7C, 0x08, 0x04, 0x04, 0x78},
    {0x38, 0x44, 0x44, 0x44, 0x38},
    {0xFC, 0x18, 0x24, 0x24, 0x18},
    {0x18, 0x24, 0x24, 0x18, 0xFC},
    {0x7C, 0x08, 0x04, 0x04, 0x08},
    {0x48, 0x54, 0x54, 0x54, 0x24},
    {0x04, 0x04, 0x3F, 0x44, 0x24},
    {0x3C, 0x40, 0x40, 0x20, 0x7C},
    {0x1C, 0x20, 0x40, 0x20, 0x1C},
    {0x3C, 0x40, 0x30, 0x40, 0x3C},
    {0x44, 0x28, 0x10, 0x28, 0x44},
    {0x4C, 0x90, 0x90, 0x90, 0x7C},
    {0x44, 0x64, 0x54, 0x4C, 0x44},
    {0x00, 0x08, 0x36, 0x41, 0x00},
    {0x00, 0x00, 0x77, 0x00, 0x00},
    {0x00, 0x41, 0x36, 0x08, 0x00},
    {0x02, 0x01, 0x02, 0x04, 0x02},
    {0x3C, 0x26, 0x23, 0x26, 0x3C},
    {0x1E, 0xA1, 0xA1, 0x61, 0x12},
    {0x3A, 0x40, 0x40, 0x20, 0x7A},
    {0x38, 0x54, 0x54, 0x55, 0x59},
    {0x21, 0x55, 0x55, 0x79, 0x41},
    {0x21, 0x54, 0x54, 0x78, 0x41},
    {0x21, 0x55, 0x54, 0x78, 0x40},
    {0x20, 0x54, 0x55, 0x79, 0x40},
    {0x0C, 0x1E, 0x52, 0x72, 0x12},
    {0x39, 0x55, 0x55, 0x55, 0x59},
    {0x39, 0x54, 0x54, 0x54, 0x59},
    {0x39, 0x55, 0x54, 0x54, 0x58},
    {0x00, 0x00, 0x45, 0x7C, 0x41},
    {0x00, 0x02, 0x45, 0x7D, 0x42},
    {0x00, 0x01, 0x45, 0x7C, 0x40},
    {0xF0, 0x29, 0x24, 0x29, 0xF0},
    {0xF0, 0x28, 0x25, 0x28, 0xF0},
    {0x7C, 0x54, 0x55, 0x45, 0x00},
    {0x20, 0x54, 0x54, 0x7C, 0x54},
    {0x7C, 0x0A, 0x09, 0x7F, 0x49},
    {0x32, 0x49, 0x49, 0x49, 0x32},
    {0x32, 0x48, 0x48, 0x48, 0x32},
    {0x32, 0x4A, 0x48, 0x48, 0x30},
    {0x3A, 0x41, 0x41, 0x21, 0x7A},
    {0x3A, 0x42, 0x40, 0x20, 0x78},
    {0x00, 0x9D, 0xA0, 0xA0, 0x7D},
    {0x39, 0x44, 0x44, 0x44, 0x39},
    {0x3D, 0x40, 0x40, 0x40, 0x3D},
    {0x3C, 0x24, 0xFF, 0x24, 0x24},
    {0x48, 0x7E, 0x49, 0x43, 0x66},
    {0x2B, 0x2F, 0xFC, 0x2F, 0x2B},
    {0xFF, 0x09, 0x29, 0xF6, 0x20},
    {0xC0, 0x88, 0x7E, 0x09, 0x03},
    {0x20, 0x54, 0x54, 0x79, 0x41},
    {0x00, 0x00, 0x44, 0x7D, 0x41},
    {0x30, 0x48, 0x48, 0x4A, 0x32},
    {0x38, 0x40, 0x40, 0x22, 0x7A},
    {0x00, 0x7A, 0x0A, 0x0A, 0x72},
    {0x7D, 0x0D, 0x19, 0x31, 0x7D},
    {0x26, 0x29, 0x29, 0x2F, 0x28},
    {0x26, 0x29, 0x29, 0x29, 0x26},
    {0x30, 0x48, 0x4D, 0x40, 0x20},
    {0x38, 0x08, 0x08, 0x08, 0x08},
    {0x08, 0x08, 0x08, 0x08, 0x38},
    {0x2F, 0x10, 0xC8, 0xAC, 0xBA},
    {0x2F, 0x10, 0x28, 0x34, 0xFA},
    {0x00, 0x00, 0x7B, 0x00, 0x00},
    {0x08, 0x14, 0x2A, 0x14, 0x22},
    {0x22, 0x14, 0x2A, 0x14, 0x08},
    {0xAA, 0x00, 0x55, 0x00, 0xAA},
    {0xAA, 0x55, 0xAA, 0x55, 0xAA},
    {0x00, 0x00, 0x00, 0xFF, 0x00},
    {0x10, 0x10, 0x10, 0xFF, 0x00},
    {0x14, 0x14, 0x14, 0xFF, 0x00},
    {0x10, 0x10, 0xFF, 0x00, 0xFF},
    {0x10, 0x10, 0xF0, 0x10, 0xF0},
    {0x14, 0x14, 0x14, 0xFC, 0x00},
    {0x14, 0x14, 0xF7, 0x00, 0xFF},
    {0x00, 0x00, 0xFF, 0x00, 0xFF},
    {0x14, 0x14, 0xF4, 0x04, 0xFC},
    {0x14, 0x14, 0x17, 0x10, 0x1F},
    {0x10, 0x10, 0x1F, 0x10, 0x1F},
    {0x14, 0x14, 0x14, 0x1F, 0x00},
    {0x10, 0x10, 0x10, 0xF0, 0x00},
    {0x00, 0x00, 0x00, 0x1F, 0x10},
    {0x10, 0x10, 0x10, 0x1F, 0x10},
    {0x10, 0x10, 0x10, 0xF0, 0x10},
    {0x00, 0x00, 0x00, 0xFF, 0x10},
    {0x10, 0x10, 0x10, 0x10, 0x10},
    {0x10, 0x10, 0x10, 0xFF, 0x10},
    {0x00, 0x00, 0x00, 0xFF, 0x14},
    {0x00, 0x00, 0xFF, 0x00, 0xFF},
    {0x00, 0x00, 0x1F, 0x10, 0x17},
    {0x00, 0x00, 0xFC, 0x04, 0xF4},
    {0x14, 0x14, 0x17, 0x10, 0x17},
    {0x14, 0x14, 0xF4, 0x04, 0xF4},
    {0x00, 0x00, 0xFF, 0x00, 0xF7},
    {0x14, 0x14, 0x14, 0x14, 0x14},
    {0x14, 0x14, 0xF7, 0x00, 0xF7},
    {0x14, 0x14, 0x14, 0x17, 0x14},
    {0x10, 0x10, 0x1F, 0x10, 0x1F},
    {0x14, 0x14, 0x14, 0xF4, 0x14},
    {0x10, 0x10, 0xF0, 0x10, 0xF0},
    {0x00, 0x00, 0x1F, 0x10, 0x1F},
    {0x00, 0x00, 0x00, 0x1F, 0x14},
    {0x00, 0x00, 0x00, 0xFC, 0x14},
    {0x00, 0x00, 0xF0, 0x10, 0xF0},
    {0x10, 0x10, 0xFF, 0x10, 0xFF},
    {0x14, 0x14, 0x14, 0xFF, 0x14},
    {0x10, 0x10, 0x10, 0x1F, 0x00},
    {0x00, 0x00, 0x00, 0xF0, 0x10},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xF0, 0xF0, 0xF0, 0xF0, 0xF0},
    {0xFF, 0xFF, 0xFF, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0xFF, 0xFF},
    {0x0F, 0x0F, 0x0F, 0x0F, 0x0F},
    {0x38, 0x44, 0x44, 0x38, 0x44},
    {0x7C, 0x2A, 0x2A, 0x3E, 0x14},
    {0x7E, 0x02, 0x02, 0x06, 0x06},
    {0x02, 0x7E, 0x02, 0x7E, 0x02},
    {0x63, 0x55, 0x49, 0x41, 0x63},
    {0x38, 0x44, 0x44, 0x3C, 0x04},
    {0x40, 0x7E, 0x20, 0x1E, 0x20},
    {0x06, 0x02, 0x7E, 0x02, 0x02},
    {0x99, 0xA5, 0xE7, 0xA5, 0x99},
    {0x1C, 0x2A, 0x49, 0x2A, 0x1C},
    {0x4C, 0x72, 0x01, 0x72, 0x4C},
    {0x30, 0x4A, 0x4D, 0x4D, 0x30},
    {0x30, 0x48, 0x78, 0x48, 0x30},
    {0xBC, 0x62, 0x5A, 0x46, 0x3D},
    {0x3E, 0x49, 0x49, 0x49, 0x00},
    {0x7E, 0x01, 0x01, 0x01, 0x7E},
    {0x2A, 0x2A, 0x2A, 0x2A, 0x2A},
    {0x44, 0x44, 0x5F, 0x44, 0x44},
    {0x40, 0x51, 0x4A, 0x44, 0x40},
    {0x40, 0x44, 0x4A, 0x51, 0x40},
    {0x00, 0x00, 0xFF, 0x01, 0x03},
    {0xE0, 0x80, 0xFF, 0x00, 0x00},
    {0x08, 0x08, 0x6B, 0x6B, 0x08},
    {0x36, 0x12, 0x36, 0x24, 0x36},
    {0x06, 0x0F, 0x09, 0x0F, 0x06},
    {0x00, 0x00, 0x18, 0x18, 0x00},
    {0x00, 0x00, 0x10, 0x10, 0x00},
    {0x30, 0x40, 0xFF, 0x01, 0x01},
    {0x00, 0x1F, 0x01, 0x01, 0x1E},
    {0x00, 0x19, 0x1D, 0x17, 0x12},
    {0x00, 0x3C, 0x3C, 0x3C, 0x3C},
    {0x00, 0x00, 0x00, 0x00, 0x00}
};
/***
const uint8 code BMP1[] =
{
	0x00,0x03,0x05,0x09,0x11,0xFF,0x11,0x89,0x05,0xC3,0x00,0xE0,0x00,0xF0,0x00,0xF8,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0xFF,0x11,0xAA,0x44,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0x01,0x38,0x44,0x82,0x92,
	0x92,0x74,0x01,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x44,0xFF,0x01,0x7D,
	0x7D,0x7D,0x01,0x7D,0x7D,0x7D,0x7D,0x01,0x7D,0x7D,0x7D,0x7D,0x7D,0x01,0xFF,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x03,0x03,
	0xF3,0x13,0x11,0x11,0x11,0x11,0x11,0x11,0x01,0xF1,0x11,0x61,0x81,0x01,0x01,0x01,
	0x81,0x61,0x11,0xF1,0x01,0x01,0x01,0x01,0x41,0x41,0xF1,0x01,0x01,0x01,0x01,0x01,
	0xC1,0x21,0x11,0x11,0x11,0x11,0x21,0xC1,0x01,0x01,0x01,0x01,0x41,0x41,0xF1,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x11,0x11,0x11,0x11,0x11,0xD3,0x33,
	0x03,0x03,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0x00,0x00,
	0x7F,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x7F,0x00,0x00,0x01,0x06,0x18,0x06,
	0x01,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x40,0x40,0x7F,0x40,0x40,0x00,0x00,0x00,
	0x1F,0x20,0x40,0x40,0x40,0x40,0x20,0x1F,0x00,0x00,0x00,0x00,0x40,0x40,0x7F,0x40,
	0x40,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x40,0x30,0x0C,0x03,0x00,0x00,
	0x00,0x00,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x06,0x06,
	0x06,0x06,0x04,0x04,0x04,0x84,0x44,0x44,0x44,0x84,0x04,0x04,0x84,0x44,0x44,0x44,
	0x84,0x04,0x04,0x04,0x84,0xC4,0x04,0x04,0x04,0x04,0x84,0x44,0x44,0x44,0x84,0x04,
	0x04,0x04,0x04,0x04,0x84,0x44,0x44,0x44,0x84,0x04,0x04,0x04,0x04,0x04,0x84,0x44,
	0x44,0x44,0x84,0x04,0x04,0x84,0x44,0x44,0x44,0x84,0x04,0x04,0x04,0x04,0x06,0x06,
	0x06,0x06,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x10,0x18,0x14,0x12,0x11,0x00,0x00,0x0F,0x10,0x10,0x10,
	0x0F,0x00,0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00,0x08,0x10,0x12,0x12,0x0D,0x00,
	0x00,0x18,0x00,0x00,0x0D,0x12,0x12,0x12,0x0D,0x00,0x00,0x18,0x00,0x00,0x10,0x18,
	0x14,0x12,0x11,0x00,0x00,0x10,0x18,0x14,0x12,0x11,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
	0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x7F,0x03,0x0C,0x30,0x0C,0x03,0x7F,0x00,0x00,0x38,0x54,0x54,0x58,0x00,0x00,
	0x7C,0x04,0x04,0x78,0x00,0x00,0x3C,0x40,0x40,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xAA,0xAA,0xAA,
	0x28,0x08,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x03,0x0C,0x30,0x0C,0x03,0x7F,
	0x00,0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00,0x7F,0x02,0x04,0x08,0x10,0x7F,0x00,
};
***/

//========================================================================
// 描述: OLED模块写命令.
// 参数: 写的命令.
// 返回: none.
//========================================================================
static void oled_write_command(uint8 IIC_Command)
{
    hardiic_start();
    hardiic_send_byte(OLED_ADDR);            //Slave address,SA0=0
    hardiic_wait_ack();	
    hardiic_send_byte(0x00);			//write command
	hardiic_wait_ack();	
    hardiic_send_byte(IIC_Command); 
	hardiic_wait_ack();	
    hardiic_stop();
}

//========================================================================
// 描述: OLED模块写数据.
// 参数: 写的数据.
// 返回: none.
//========================================================================
static void oled_write_data(uint8 IIC_Data)
{
    hardiic_start();
    hardiic_send_byte(OLED_ADDR);			//D/C#=0; R/W#=0
	hardiic_wait_ack();	
    hardiic_send_byte(0x40);			//write data
	hardiic_wait_ack();	
    hardiic_send_byte(IIC_Data);
	hardiic_wait_ack();	
    hardiic_stop();
}

//========================================================================
// 描述: OLED模块写一个字节.
// 参数: dat:要写入的字节 ; cmd:写入的字节是数据（1）还是命令（0）
// 返回: none.
//========================================================================
static void oled_wr_byte(uint8 dat,uint8 cmd)
{
    if(cmd)
    {
        oled_write_data(dat);
    }else{
        oled_write_command(dat);
	}
}

//========================================================================
// 描述: 坐标设置
// 参数: x,y:坐标; 
// 返回: none.
//========================================================================
void oled_set_pos(uint8 x, uint8 y) 
{ 	
    oled_wr_byte(0xb0+y,OLED_CMD);		//设置页地址（0-7）
	oled_wr_byte(((x&0xf0)>>4)|0x10,OLED_CMD);	//设置显示位置-列低地址
	oled_wr_byte((x&0x0f),OLED_CMD); 	 //设置显示位置-列高地址   
}

//========================================================================
// 描述: 开启OLED显示
// 参数: none.
// 返回: none.
//========================================================================
void oled_display_on()
{
	oled_wr_byte(0X8D,OLED_CMD);  //SET DCDC命令
	oled_wr_byte(0X14,OLED_CMD);  //DCDC ON
	oled_wr_byte(0XAF,OLED_CMD);  //DISPLAY ON
}

//========================================================================
// 描述: 关闭OLED显示
// 参数: none.
// 返回: none.
//========================================================================
void oled_display_off()
{
	oled_wr_byte(0X8D,OLED_CMD);  //SET DCDC命令
	oled_wr_byte(0X10,OLED_CMD);  //DCDC OFF
	oled_wr_byte(0XAE,OLED_CMD);  //DISPLAY OFF
}

//========================================================================
// 描述: 清屏
// 参数: none.
// 返回: none.
//========================================================================
void oled_clear()  
{  
	uint8 y,x;
	for(y=0;y<4;y++)
	{
		for(x=0;x<128;x++)
		{
			_oled_disbuffer[x][y]=0x00;
		}
	}
}

//========================================================================
// 描述: 更新显示
// 参数: none.
// 返回: none.
//========================================================================
void oled_display()  
{  
    uint8 x,y;
	for(y=0;y<4;y++)  
	{  
		oled_wr_byte (0xb0+y,OLED_CMD);    //设置页地址（0-7）
		oled_wr_byte (0x00,OLED_CMD);      //设置显示位置-列低地址
		oled_wr_byte (0x10,OLED_CMD);      //设置显示位置-列高地址  
		for(x=0;x<128;x++)oled_wr_byte(_oled_disbuffer[x][y],OLED_DATA); 
	} 

}//更新显示

//========================================================================
// 描述: OLED填充
// 参数: dot:
// 返回: none.
//========================================================================
void oled_fill(uint8 dot)  
{  
	uint8 y,x;
	for(y=0;y<4;y++)
	{
		for(x=0;x<128;x++)
		{
			_oled_disbuffer[x][y]=dot;
		}
	}
}

//========================================================================
// 描述: 计算m^n函数
// 参数: m,n:要计算的数值
// 返回: none.
//========================================================================
// static unsigned int oled_pow(uint8 m,uint8 n)
// {
// 	unsigned int result=1;	 
// 	while(n--)result*=m;    
// 	return result;
// }

//========================================================================
// 描述: 在指定位置显示一个点
// 参数: x,y:坐标; pixel:亮或灭
// 返回: none.
//========================================================================
void oled_set_pixel(uint8 x, uint8 y,uint8 pixel) 
{ 
    if (x > OLED_MAX_COLUMN || y > OLED_MAX_ROW) {
        return;
    }
    else
    {
        if (pixel) {
            _oled_disbuffer[x][y / 8] |= (1 << (y % 8));
        }
        else {
            _oled_disbuffer[x][y / 8] &= ~(1 << (y % 8));
        }
    }
}

//========================================================================
// 描述: 在指定位置显示一个字符
// 参数: x,y:起点坐标; chr:要显示的字符;
// 返回: none.
//========================================================================
void oled_show_char(int8 x,int8 y,uint8 chr)
{
	uint8 temp;
	uint8 j,i;
//	chr=chr-' ';						  //得到偏移后的值
	if(x < 0)
	{
		for(j=0;j<5;j++)
		{
			temp=fontx[chr][j];
			for(i=0;i<8;i++)
		    {   
				if(((x + i) >= 0)){
                    if(temp&0x01){
                        oled_set_pixel(x+j,y+i,1);
                    }
                }
				temp>>=1; 
		    }
		}	
	}
	else{
		for(j=0;j<5;j++)
		{
			temp=fontx[chr][j];
			for(i=0;i<8;i++)
		    {      
				if(temp&0x01)
                {
                   oled_set_pixel(x+j,y+i,1);  
                }
                temp>>=1; 
			}
		}			
    }
}


// void oled_show_char(uint8 x,uint8 y,uint8 chr)
// {      	
// 	uint8 c=0,i=0;
// 	uint8 ci=0,x1=0,y1=y;
// 	if(y>4)return;
// 	for(ci=0;ci<5;ci++){
// 		x1 = x+ci+i*5;
// 		if(x1>122){x1=x1-122;y1=y+1;}
// 		_oled_disbuffer[x1][y1]=fontx[chr][ci];
// 	}
// }

	// unsigned char c=0,i=0;	
	// c=chr-' ';//得到偏移后的值		
	// if(x>Max_Column-1){x=0;y=y+2;}
	// if(Char_Size ==16)
	// {
	// 	OLED_Set_Pos(x,y);	
	// 	for(i=0;i<8;i++)
	// 		OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
	// 	OLED_Set_Pos(x,y+1);
	// 	for(i=0;i<8;i++)
	// 		OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
	// 	}else 
	// 	{	
	// 		OLED_Set_Pos(x,y);
	// 		for(i=0;i<6;i++)
	// 			OLED_WR_Byte(F6x8[c][i],OLED_DATA);
    //     }

//========================================================================
// 描述: 显示一个字符串
// 参数: x,y:起点坐标;chr:要显示的字符串
// 返回: none.
//========================================================================
void oled_show_string(int8 x,int8 y,uint8 *chr)
{
	uint8 j=0;
	while (chr[j]!='\0')
	{		
	    oled_show_char(x,y,chr[j]);
		x+=8;
		if(x>120){
		    x=0;
			y+=2;
		}
		j++;
	}
}

// //========================================================================
// // 描述: 显示数字
// // 参数: x,y:起点坐标;num:要显示的数值 len: 数字的位数;
// // 返回: none.
// //========================================================================
// void oled_show_num(uint8 x,uint8 y,uint16 num,uint8 len)
// {         	
// 	uint8 t,temp;
// 	uint8 enshow=0;						   
// 	for(t=0;t<len;t++)
// 	{
// 		temp=(num/oled_pow(10,len-t-1))%10;
// 		if(enshow==0&&t<(len-1))
// 		{
// 			if(temp==0)
// 			{
// 				oled_show_char(x+5*t,y,' ');
// 				continue;
// 			}else enshow=1; 
// 		}
// 	 	oled_show_char(x+5*t,y,temp+'0'); 
// 	}
// } 

//========================================================================
// 描述: 在指定位置显示数字
// 参数: x,y:坐标; num:显示的数字; 
// 返回: none.
//========================================================================
void oled_show_num(int8 x,int8 y,int16 num)
{
	char men[15];
	//char *str = men;
	sprintf(men,"%d",num);
    //_itoa(num,men,10);
	oled_show_string(x,y,men);
} 

/**************************************************************************
//========================================================================
// 描述: 显示小数
// 参数: x,y:起点坐标;num:要显示的数值 len: 数字的位数;  size:字体大小
// 返回: none.
//========================================================================
void oled_showfloat(uint8 x,uint8 y,uint16 num,uint8 len,uint8 size)
{         	
    uint8 temp[10];
    sprintf(temp,"%.3f",num);
    oled_show_string(x,y,(u8 *)temp,size)
} 
*****************************************************************************/

//========================================================================
// 描述: 显示12*12汉字
// 参数: x,y:起点坐标;lenth:要显示的汉字长度;hz:字库数组
// 返回: none.
//========================================================================
void oled_show_font12(uint8 lenth,const uint8* hz,int x,int y)
{      
	int zs;
	uint8 zz,i,j;	    
	if (x < 0)
    {
        zs = (0 - x) / 12;

        for (zz = zs; zz < lenth; zz++)
        {
            for (i = 0; i < 12; i++)
            {
                for (j = 0; j < 12; j++)
                {
                    if ((zz * 12 + j + x - 12) > 127)return;
                    if ((y + i - 12) > 63)return;
                    if (!((zz * 12 + x + j) < 0))
                    if ((hz[zz * 24 + i * 2 + j / 8]) & (0x80 >> (j % 8)))oled_set_pixel(zz * 12 + x + j, y + i, 1);
                }
            }

        }
    }
    else
    {
        for (zz = 0; zz < lenth; zz++) {
            for (i = 0; i < 12; i++)
            {
                for (j = 0; j < 12; j++)
                {
                    if ((zz *12 + j + x - 12) > 127)return;
                    if ((y + i - 12) > 63)return;
                    if ((hz[zz * 24 + i * 2 + j / 8]) & (0x80 >> (j % 8)))oled_set_pixel(zz * 12 + x + j, y + i, 1);
                }
            }
        }
    }			
}

//========================================================================
// 描述: 显示16*16汉字
// 参数: 参数: x,y:起点坐标;lenth:要显示的汉字长度;hz:字库数组
// 返回: none.
//========================================================================
void oled_show_font16(uint8 lenth,const uint8* hz,int x,int y)
{    
	int zs;
	uint8 zz,i,j;
	if (x < 0)
    {
        zs = (0 - x) / 16;
        for (zz = zs; zz < lenth; zz++)
        {
            for (i = 0; i < 16; i++)
            {
                for (j = 0; j < 16; j++)
                {
                    if ((zz * 16 + j + x - 16) > 127)return;
                    if ((y + i - 16) > 63)return;
                    if (!((zz * 16 + x + j) < 0))
                    if ((hz[zz * 32 + i * 2 + j / 8]) & (0x80 >> (j % 8)))oled_set_pixel(zz * 16 + x + j, y + i, 1);
                }
            }
        }
    }
    else {
        for (zz = 0; zz < lenth; zz++) {
            for (i = 0; i < 16; i++)
            {
                for (j = 0; j < 16; j++)
                {
                    if ((zz * 16 + j + x - 16) > 127)return;
                    if ((y + i - 16) > 63)return;
                    if ((hz[zz * 32 + i * 2 + j / 8]) & (0x80 >> (j % 8)))oled_set_pixel(zz * 16 + x + j, y + i, 1);
                }
            }
        }
    }					
}

//========================================================================
// 描述: 显示24*24汉字
// 参数: 参数: x,y:起点坐标;lenth:要显示的汉字长度;hz:字库数组
// 返回: none.
//========================================================================
void oled_show_font24(uint8 lenth,const uint8* hz,int x,int y)
{   
	uint16 zs;
	uint8 zz,i,j;	   			    
	if (x < 0) 
    {
        zs = (0 - x)/24;
        
        for (zz = zs; zz < lenth; zz++)
        {
            for (i = 0; i < 24; i++)
            {
                for (j = 0; j < 24; j++)
                {
                    if ((zz * 24 + j + x - 24) > 127)return;
                    if ((y + i - 24) > 63)return;
                    if(!((zz*24+x+j)<0))
                    if ((hz[zz * 72 + i * 3 + j / 8]) & (0x80 >> (j % 8)))oled_set_pixel(zz * 24 +x+ j, y + i, 1);
                }
            }
        }
    }
    else {
        for (zz = 0; zz < lenth; zz++) {
            for (i = 0; i < 24; i++)
            {
                for (j = 0; j < 24; j++)
                {
                    if ((zz * 24 + j + x-24) > 127)return;
                    if ((y + i-24) > 63)return;
                    if ((hz[zz * 72 + i * 3 + j / 8]) & (0x80 >> (j % 8)))oled_set_pixel(zz * 24 + x + j, y + i, 1);
                }
            }
        }
    }
}
//========================================================================
// 描述: 显示32*32汉字
// 参数: 参数: x,y:起点坐标;lenth:要显示的汉字长度;hz:字库数组
// 返回: none.
//========================================================================
void oled_show_font32(uint8 lenth, const uint8* hz, int x, int y)
{
    uint16 zs;
    uint8 zz, i, j;
    if (x < 0)
    {
        zs = (0 - x) / 32;

        for (zz = zs; zz < lenth; zz++)
        {
            for (i = 0; i < 32; i++)
            {
                for (j = 0; j < 32; j++)
                {
                    if ((zz * 32 + j + x - 32) > 127)return;
                    if ((y + i - 32) > 63)return;
                    if (!((zz * 32 + x + j) < 0))
                        if ((hz[zz * 128 + j * 4 + i / 8]) & (0x80 >> (i % 8)))oled_set_pixel(zz * 32 + x + j, y + i, 1);
                }
            }
        }
    }
    else {
        for (zz = 0; zz < lenth; zz++) {
            for (i = 0; i < 32; i++)
            {
                for (j = 0; j < 32; j++)
                {
                    if ((zz * 32 + j + x - 32) > 127)return;
                    if ((y + i - 32) > 63)return;
                    if ((hz[zz * 128 + j * 4 + i / 8]) & (0x80 >> (i % 8)))oled_set_pixel(zz * 32 + x + j, y + i, 1);
                }
            }
        }
    }
}
//========================================================================
// 描述: 显示BMP图片
// 参数: x0,y0:起点坐标; x1,y1:终点坐标; BMP:要显示的图片
// 返回: none.
//========================================================================
void oled_show_bmp(uint8 x0, uint8 y0,uint8 x1, uint8 y1,uint8* BMP)
{ 	
	uint16 j=0;
	uint8 x,y;
    y1 = y1 / 8;
	if(y1%8==0) y=y1/8;      
	else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		for(x=x0;x<x1;x++)
		{
			_oled_disbuffer[x][y]=BMP[j++];
		}
	}
}

//========================================================================
// 描述: 初始化OLED
// 参数: none.
// 返回: none.
//========================================================================
void oled_init()
{ 	
	hardiic_init();
    delay(100);
    oled_wr_byte(0xAE,OLED_CMD);//关闭显示
	
	oled_wr_byte(0x40,OLED_CMD);//---set low column address
	oled_wr_byte(0xB0,OLED_CMD);//---set high column address

	oled_wr_byte(0xC8,OLED_CMD);//-not offset

	oled_wr_byte(0x81,OLED_CMD);//设置对比度
	oled_wr_byte(0xff,OLED_CMD);

	oled_wr_byte(0xa1,OLED_CMD);//段重定向设置

	oled_wr_byte(0xa6,OLED_CMD);//
	
	oled_wr_byte(0xa8,OLED_CMD);//设置驱动路数
	oled_wr_byte(0x1f,OLED_CMD);
	
	oled_wr_byte(0xd3,OLED_CMD);
	oled_wr_byte(0x00,OLED_CMD);
	
	oled_wr_byte(0xd5,OLED_CMD);
	oled_wr_byte(0xf0,OLED_CMD);
	
	oled_wr_byte(0xd9,OLED_CMD);
	oled_wr_byte(0x22,OLED_CMD);
	
	oled_wr_byte(0xda,OLED_CMD);
	oled_wr_byte(0x02,OLED_CMD);
	
	oled_wr_byte(0xdb,OLED_CMD);
	oled_wr_byte(0x49,OLED_CMD);
	
	oled_wr_byte(0x8d,OLED_CMD);
	oled_wr_byte(0x14,OLED_CMD);
	
	oled_wr_byte(0xaf,OLED_CMD);
	oled_clear();
}
