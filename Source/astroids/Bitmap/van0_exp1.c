////////////////////////////////////////////
/*

Simple Image Conversion Utility

Image Name: van0_exp1.bmp
8 Bit Color Image Array
Width: 48
Height: 48
Pixel Format: Format32bppArgb
*/
///////////////////////////////////////////////////



#include <stdlib.h>
#include "bitmap.h"

static const uint8_t _acvan0_exp1Bmp[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x89, 0x89, 0x89, 0x89, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x69, 0xFD, 0xFC, 0x5B, 0x3B, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69,
0xFE, 0xFC, 0x3C, 0x3C, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFD, 0x49, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD,
0xFD, 0xFD, 0xFD, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0x20, 0xFC, 0x20,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3C, 0x1C,
0x3B, 0x5B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFD, 0xFC, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4B, 0x40, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFC, 0xFC, 0xFC, 0xF3, 0x41, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x4B, 0x6C, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x23, 0x24, 0xB3, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD4, 0xFD, 0xFD,
0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0x00, 0x00, 0x00, 0x00, 0x4A,
0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD, 0xD2, 0x00, 0x00, 0x00,
0x00, 0x6B, 0x24, 0x6D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x3C, 0x3B, 0x3B, 0x7B,
0xBC, 0x9B, 0xBB, 0x00, 0x00, 0x00, 0x00, 0x20, 0x49, 0x49,
0x49, 0x49, 0x89, 0xFC, 0x4A, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x69, 0xFE, 0xFC, 0x3A, 0x3C, 0x1C, 0x15,
0x15, 0x1C, 0x1C, 0x1B, 0x1C, 0x1C, 0x1C, 0x1B, 0x9B, 0x3A,
0xFC, 0xFC, 0xFC, 0xFC, 0xB2, 0x6B, 0x6B, 0x6B, 0x6B, 0x6B,
0x6B, 0xF3, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xD3, 0xFE, 0xFC, 0x6E, 0x55, 0x15, 0x07, 0x0E, 0x07,
0x07, 0x13, 0x1C, 0x14, 0x0D, 0xDB, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xB2, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0xD3,
0x6B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
0x1C, 0x0D, 0x14, 0x14, 0x05, 0x04, 0x1C, 0x14, 0x0E, 0x14,
0x14, 0x1C, 0x07, 0x5B, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFB, 0xF3, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD, 0x1B, 0x1B,
0x1B, 0x1B, 0x1B, 0x1B, 0x1C, 0x0D, 0x0D, 0x05, 0x1B, 0x1C,
0x06, 0x1B, 0x1B, 0x9B, 0x9B, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x01, 0x22, 0x22,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x20, 0xFD, 0xFC, 0xFC, 0x9B, 0xDB,
0xBB, 0xB3, 0x69, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x14, 0x1B,
0x1B, 0xBB, 0x9B, 0xDB, 0xFC, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3,
0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xD4, 0x8D, 0xD5, 0x8A, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x69, 0xFD, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF3,
0x8A, 0x00, 0x00, 0x00, 0x00, 0x1B, 0x9B, 0xBB, 0xFC, 0xDB,
0x41, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x1B, 0x1C, 0x1C, 0x1C,
0x1C, 0x1C, 0x1C, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF3,
0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xAA, 0xFD, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1B, 0x0A, 0x00,
0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x41, 0x00,
0x00, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
0x1B, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xB5, 0xB6, 0xFD, 0xFD,
0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD3, 0xFD,
0xD4, 0xD3, 0xD3, 0xD3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0x20, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3, 0xB3, 0xB3, 0xD3,
0xD3, 0xD3, 0xD3, 0xD3, 0x07, 0x07, 0x27, 0x07, 0x44, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5C, 0x5D, 0x3C, 0x1C,
0x1C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
0x1C, 0x1C, 0x1C, 0x1C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
0x1C, 0x1C, 0x06, 0x0D, 0x07, 0x07, 0x24, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x1B, 0x1B,
0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1C, 0x14, 0x1B, 0x1B,
0x1B, 0x1B, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
0x05, 0x14, 0x06, 0x06, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x12, 0x12, 0x1A, 0x1A, 0x1A,
0x1A, 0x1B, 0x34, 0x1B, 0x06, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A,
0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A,
0x13, 0x05, 0x06, 0x07, 0x07, 0x07, 0x06, 0x1A, 0x1A, 0x1A,
0x0A, 0x03, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5C,
0x5C, 0x3C, 0x00, 0x21, 0x12, 0x1A, 0x12, 0x12, 0x3B, 0x34,
0x34, 0x2E, 0x2F, 0x0C, 0x12, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A,
0x1A, 0x0C, 0x1A, 0x1A, 0x1A, 0x1A, 0x0B, 0x07, 0x07, 0x07,
0x2F, 0x2F, 0x06, 0x04, 0x04, 0x04, 0x09, 0x09, 0x09, 0x09,
0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5C, 0x3B, 0x1A,
0x00, 0x21, 0x21, 0x21, 0x09, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x06, 0x0C, 0x12, 0x12, 0x12, 0x06, 0x07, 0x12,
0x12, 0x12, 0x0B, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07,
0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x2A, 0x21, 0x00, 0x21,
0x00, 0x00, 0x04, 0x07, 0x07, 0x05, 0x04, 0x06, 0x02, 0x02,
0x03, 0x00, 0x00, 0x00, 0x00, 0x12, 0x0B, 0x06, 0x12, 0x0C,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x02, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x4A, 0x21, 0x21, 0x00, 0x00, 0x00, 0x00,
0x06, 0x05, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x00, 0x0B, 0x05, 0x07, 0x06, 0x06, 0x06, 0x06,
0x06, 0x06, 0x06, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
0x00, 0xFF, 0x6B, 0xDE, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
0x06, 0x04, 0x00, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0x00, 0xDE, 0x4F,
0x07, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04,
0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01,
0x00, 0xDE, 0x6B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x6B, 0x21, 0x05, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x21, 0x21,
0x4A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x4A, 0x21, 0x21, 0x06, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4A, 0x07, 0x07,
0x07, 0x07, 0x12, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x6B, 0x21, 0x02, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02,
0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07,
0x12, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x6B, 0x21, 0x21, 0x00, 0x01, 0x09, 0x09, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00,
0x00, 0x00, 0x00, 0x00, 0x21, 0x21, 0x03, 0x07, 0x03, 0x12,
0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,
0x21, 0x00, 0x00, 0x06, 0x04, 0x12, 0x02, 0x00, 0x00, 0x00,
0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00,
0x00, 0x00, 0x94, 0x4A, 0x21, 0x03, 0x06, 0x0B, 0x12, 0x0B,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x21, 0x00,
0x00, 0x06, 0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x4A, 0xFF, 0x4A, 0x21, 0x05, 0x06, 0x06, 0x06, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
0x05, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x94,
0x94, 0x21, 0x01, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04,
0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x6B, 0x4A, 0x21,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x6B, 0x21, 0x00, 0x21, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00};


const ImageData bmvan0_exp1Bmp = {
48, //xSize
48, //ySize
48, //bytesPerLine
8, //bits per pixel
(uint8_t*)_acvan0_exp1Bmp,
};
/////////////////// End of File  ///////////////////////////