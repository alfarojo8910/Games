///////////////////////////////////////////////////
/*
Simple Wave File Conversion Utility

Dana Olcott
Feb, 2018
www.danasboatshop.com
Generate sound input files for use in
firmware on memory constrained devices

To Use:
Configure a timer to interrupt at sampleRate
Configure a DAC with bit size bitDepth
On timer interrupt, write soundData[] to DAC
Define the following struct somewhere in the firmware:

typedef struct
{
	uint8_t* soundData
	uint32_t length
	uint8_t bitDepth
	uint32_t sampleRate
}SoundData;

Source: EnemyExplode.wav
Target: wavEnemyExplode.c
Input:
Sample Rate (hz): 44100
Bit Depth: 16
Length(bytes): 36210
Duration (ms): 410.544

Output:
SoundData Struct Name: sound_enemyExplode
Sample Rate (hz): 11000
Bit Depth: 8
Length(bytes): 4526
Duration (ms): 410.544

*/
////////////////////////////////////////////////////

#include "Sound.h"

static const uint8_t soundData[] = 
{
	0x00, 0x0f, 0x60, 0x60, 0xc7, 0xc7, 0xcc, 0xd5, 
	0x5b, 0x36, 0xb7, 0x4e, 0x4e, 0xbf, 0x2f, 0x37, 
	0x30, 0x46, 0xc4, 0xc4, 0x60, 0x39, 0xae, 0x4a, 
	0x4d, 0x60, 0x60, 0x9f, 0xb9, 0x56, 0x42, 0x41, 
	0x9f, 0x9f, 0xcc, 0xda, 0x18, 0xa9, 0xa0, 0xa0, 
	0xa0, 0x13, 0x13, 0xa4, 0xa3, 0xa0, 0xa6, 0xa6, 
	0x30, 0x30, 0xc8, 0xc8, 0xb7, 0x27, 0x57, 0xcc, 
	0xcc, 0xc0, 0xc0, 0x1a, 0x1a, 0xaa, 0xa6, 0xa1, 
	0x28, 0x28, 0xa1, 0xa1, 0xcb, 0xc4, 0xcb, 0xcb, 
	0xb7, 0x36, 0x36, 0xa2, 0xa2, 0xb7, 0xc1, 0xdc, 
	0xaa, 0xa5, 0xa2, 0xa2, 0x41, 0x41, 0x52, 0x52, 
	0xcf, 0xe4, 0xd9, 0x25, 0x25, 0x1c, 0x1c, 0xd8, 
	0xd8, 0xa3, 0xa3, 0xbf, 0x41, 0x5b, 0xca, 0xca, 
	0x3d, 0x3d, 0x39, 0x39, 0x23, 0x23, 0x44, 0xde, 
	0xa4, 0xa4, 0xa4, 0xe9, 0x38, 0xa5, 0xa5, 0xbe, 
	0xbe, 0x38, 0x38, 0xa5, 0xae, 0x5a, 0xc5, 0xb4, 
	0xb3, 0xb3, 0x3a, 0x3a, 0xf0, 0xf0, 0xbf, 0xbb, 
	0xcd, 0x27, 0xb1, 0xac, 0xbe, 0x37, 0x37, 0xa6, 
	0xa6, 0x4b, 0x4b, 0xe9, 0xe9, 0x20, 0x58, 0x4f, 
	0xe5, 0xd1, 0x4f, 0x49, 0xc0, 0xba, 0xc0, 0xc0, 
	0xa9, 0xa9, 0xa7, 0xa8, 0xd7, 0xd7, 0xae, 0xae, 
	0xa8, 0xb7, 0x52, 0x48, 0x48, 0x4b, 0x42, 0x57, 
	0x4e, 0x53, 0x56, 0x52, 0x50, 0x48, 0x4e, 0x4c, 
	0x4c, 0xbf, 0xbf, 0xf2, 0xf2, 0x56, 0x56, 0xfa, 
	0xef, 0xaa, 0xb9, 0x41, 0x47, 0x55, 0x26, 0xaa, 
	0xb0, 0x1e, 0x55, 0x55, 0xdf, 0xe2, 0x33, 0x0d, 
	0x3a, 0x36, 0x2b, 0x29, 0x24, 0x24, 0x43, 0x43, 
	0x36, 0x36, 0xc6, 0xc6, 0x54, 0x54, 0x53, 0x53, 
	0x1f, 0x1f, 0x53, 0x53, 0x4e, 0x4e, 0x53, 0x53, 
	0x53, 0x53, 0x43, 0x43, 0x52, 0x52, 0x15, 0x15, 
	0x49, 0x49, 0x52, 0x52, 0xad, 0xad, 0x52, 0x52, 
	0x4b, 0x4b, 0xae, 0xae, 0xd2, 0xd3, 0x20, 0x05, 
	0xc0, 0xbd, 0xae, 0xae, 0x2d, 0x34, 0x49, 0x45, 
	0xaf, 0xb6, 0x50, 0x50, 0x50, 0x50, 0xe5, 0x19, 
	0xd1, 0xd1, 0x4e, 0x4e, 0x32, 0x2a, 0xb0, 0xb0, 
	0x0f, 0x44, 0xd6, 0xc7, 0xb0, 0xc2, 0x3b, 0xcf, 
	0xc1, 0x2d, 0x49, 0xca, 0xb1, 0xb1, 0xc6, 0x49, 
	0xcb, 0xbe, 0xba, 0xbe, 0x0b, 0x48, 0x4a, 0x3d, 
	0x34, 0x3a, 0x36, 0x40, 0x4d, 0x4d, 0x4d, 0x4b, 
	0x37, 0x4d, 0x21, 0x11, 0x36, 0xf7, 0x27, 0xba, 
	0xc0, 0xd8, 0xc3, 0xd0, 0x3f, 0x43, 0x4c, 0x47, 
	0xc7, 0xbc, 0x30, 0x45, 0x4b, 0x3d, 0xb8, 0xb4, 
	0xcc, 0xd4, 0xc0, 0xd7, 0xc9, 0xb4, 0xb4, 0x0c, 
	0x31, 0x35, 0x2b, 0xd5, 0xbd, 0x31, 0xde, 0xe3, 
	0x2a, 0xdd, 0xec, 0xc3, 0x15, 0x34, 0x2a, 0x11, 
	0x1d, 0xcf, 0x2a, 0x36, 0x10, 0xc0, 0xb6, 0x39, 
	0x42, 0x2f, 0xb7, 0xb7, 0xce, 0x48, 0x48, 0x20, 
	0xbb, 0x2c, 0xf0, 0x31, 0x47, 0x3f, 0x29, 0xd6, 
	0xc5, 0xc1, 0x2d, 0x34, 0xda, 0x42, 0x3e, 0xb9, 
	0xb9, 0xe8, 0x46, 0x46, 0x46, 0xc3, 0xc5, 0x3e, 
	0x37, 0x21, 0xc4, 0xc6, 0xd3, 0x2c, 0x29, 0xdf, 
	0xba, 0x11, 0x45, 0x45, 0x3a, 0x3a, 0x44, 0x44, 
	0x30, 0x30, 0x24, 0x23, 0xe8, 0xbb, 0xbb, 0xdb, 
	0xd9, 0xce, 0xc1, 0xd3, 0x43, 0x39, 0x0c, 0x0c, 
	0xe6, 0x24, 0xd8, 0xbb, 0xc6, 0xd7, 0xd7, 0xbb, 
	0xbb, 0xd1, 0x31, 0x30, 0xca, 0xca, 0xc2, 0x2e, 
	0x19, 0x0d, 0x26, 0xe6, 0xef, 0x20, 0x1d, 0xbc, 
	0xbf, 0x25, 0x3f, 0x30, 0xbc, 0xbc, 0x0e, 0x36, 
	0x3b, 0x18, 0x14, 0x35, 0x35, 0x41, 0x41, 0x2b, 
	0x29, 0x43, 0x43, 0x43, 0xdb, 0xdb, 0xf3, 0x3f, 
	0x36, 0xca, 0xca, 0x38, 0x38, 0x3b, 0x2d, 0x1f, 
	0x32, 0x32, 0x31, 0x32, 0x40, 0xf1, 0xf1, 0xf3, 
	0xf3, 0xda, 0x16, 0x16, 0x18, 0x18, 0xe6, 0xd8, 
	0xdd, 0xf4, 0xf4, 0x0f, 0x0b, 0x1e, 0x38, 0x38, 
	0xd1, 0xd1, 0x2e, 0x43, 0x43, 0xd7, 0xd7, 0xca, 
	0x36, 0x36, 0x43, 0x43, 0x38, 0x23, 0x23, 0x43, 
	0x43, 0x26, 0x10, 0x3b, 0x43, 0x43, 0xf4, 0xf4, 
	0x32, 0x43, 0x43, 0x1b, 0x1b, 0x13, 0x36, 0x36, 
	0x29, 0x29, 0x3c, 0x3b, 0x38, 0x3c, 0x3c, 0x43, 
	0x43, 0x43, 0x38, 0x38, 0xcb, 0xcb, 0xcf, 0x28, 
	0x28, 0xf6, 0xf6, 0xf6, 0xeb, 0xeb, 0xdf, 0xf6, 
	0xf6, 0x0e, 0x0e, 0xd7, 0xc4, 0xc4, 0x19, 0x19, 
	0x26, 0x2b, 0x2b, 0xbf, 0xbf, 0xbf, 0x36, 0x36, 
	0xc8, 0xc8, 0xc8, 0xcf, 0xcf, 0xcf, 0xcc, 0xcc, 
	0xd6, 0xd6, 0xd6, 0xbf, 0xbf, 0xca, 0xe6, 0xe6, 
	0xc1, 0xc1, 0xc1, 0x27, 0x27, 0xbf, 0xbd, 0xbd, 
	0x03, 0x03, 0x3d, 0x25, 0x25, 0xbd, 0xbd, 0xbd, 
	0x3c, 0x3c, 0xc6, 0xc6, 0xc6, 0xdb, 0xdb, 0xda, 
	0xd7, 0xd7, 0xf4, 0xf4, 0xf4, 0x33, 0x33, 0x36, 
	0x36, 0x36, 0x42, 0x42, 0x42, 0x30, 0x30, 0x10, 
	0xe7, 0xe7, 0x3c, 0x3b, 0x3b, 0xd7, 0xd7, 0x2b, 
	0x35, 0x35, 0xcf, 0xcf, 0xcf, 0xde, 0xde, 0xda, 
	0xbd, 0xbd, 0xc0, 0x0e, 0x0e, 0xca, 0xca, 0xca, 
	0x14, 0x14, 0x14, 0x3d, 0x3d, 0x39, 0xbd, 0xbd, 
	0xde, 0xea, 0xea, 0xbd, 0xd3, 0xd3, 0xbd, 0xbd, 
	0xbd, 0x42, 0x42, 0x42, 0xbd, 0xbd, 0xbd, 0xe6, 
	0xe6, 0xd0, 0xd8, 0xd8, 0xc1, 0xbe, 0xbe, 0x2d, 
	0x2d, 0x2d, 0xca, 0xca, 0xca, 0x42, 0x42, 0x2a, 
	0xbe, 0xbe, 0x1d, 0x1b, 0x1b, 0xbe, 0xbe, 0xbe, 
	0xbe, 0xbe, 0xbe, 0xe7, 0xe7, 0xfd, 0xd3, 0xd3, 
	0x41, 0xed, 0xed, 0xda, 0x26, 0x26, 0xbe, 0xbe, 
	0xbe, 0x20, 0x20, 0x20, 0x1d, 0x1d, 0x1d, 0x34, 
	0x34, 0x3a, 0x3b, 0x3b, 0x33, 0x2f, 0x2f, 0x1e, 
	0x39, 0x39, 0x3c, 0x27, 0x27, 0x3d, 0x35, 0x35, 
	0x22, 0x15, 0x15, 0xe2, 0x30, 0x30, 0x30, 0x31, 
	0x31, 0x39, 0x41, 0x3d, 0x3d, 0x3b, 0xed, 0xed, 
	0xcc, 0x28, 0x28, 0xca, 0x1b, 0x1b, 0x41, 0x18, 
	0x18, 0x3e, 0x41, 0x41, 0x3b, 0x17, 0xe5, 0x2c, 
	0x28, 0x25, 0x25, 0x2d, 0x2d, 0x2d, 0xbe, 0xbe, 
	0xbe, 0x41, 0x41, 0x41, 0xbe, 0xbe, 0xbe, 0x31, 
	0x32, 0x2c, 0xe6, 0x17, 0x17, 0x2a, 0x32, 0x32, 
	0x41, 0xd2, 0xd2, 0xe1, 0x41, 0x41, 0xf4, 0xbe, 
	0xbe, 0x2e, 0x3f, 0x3f, 0xd6, 0x27, 0x27, 0x3a, 
	0xdc, 0xdc, 0x2c, 0x29, 0x23, 0xe6, 0xc5, 0xcc, 
	0xcc, 0xc6, 0xc7, 0xc7, 0xcf, 0x25, 0x25, 0x26, 
	0x23, 0x1c, 0x36, 0x40, 0xe3, 0xe3, 0xd9, 0x3a, 
	0x3a, 0xd8, 0xe3, 0x0b, 0x40, 0x40, 0xd9, 0xd9, 
	0x10, 0x40, 0x40, 0x1c, 0x1c, 0xd8, 0x35, 0x40, 
	0x30, 0x30, 0x09, 0xee, 0xe3, 0xc2, 0xc2, 0xbf, 
	0xbf, 0xbf, 0xc4, 0xda, 0xd5, 0xd5, 0xbf, 0xbf, 
	0xcd, 0xcd, 0xce, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
	0xcb, 0xf6, 0xee, 0xed, 0x16, 0x16, 0x40, 0x40, 
	0x40, 0x40, 0x26, 0x26, 0x26, 0x26, 0x40, 0x3f, 
	0xdf, 0xbf, 0xbf, 0xd2, 0x37, 0x3c, 0xd5, 0xd5, 
	0xca, 0xd1, 0x36, 0xf1, 0xf1, 0xda, 0xda, 0x3b, 
	0x24, 0x16, 0xc2, 0xc2, 0x20, 0x20, 0x40, 0x18, 
	0x18, 0x25, 0x25, 0x40, 0x40, 0xf1, 0x1b, 0x1b, 
	0x23, 0x23, 0xc0, 0xc0, 0xbf, 0xbf, 0xbf, 0xbf, 
	0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 
	0xc4, 0xc4, 0xc6, 0xcd, 0xc1, 0xc1, 0xd8, 0xd8, 
	0xea, 0xea, 0xc6, 0xd4, 0xe1, 0xe1, 0x28, 0xd8, 
	0xd8, 0xd8, 0xc4, 0xdb, 0xdb, 0x20, 0x3f, 0x31, 
	0x31, 0x2e, 0x2d, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x25, 0x1f, 0xed, 0xed, 0x3f, 0x3b, 0x25, 
	0x25, 0xd0, 0x1f, 0x3e, 0x3e, 0x37, 0x28, 0xe4, 
	0xe4, 0xdf, 0xda, 0xce, 0xce, 0xc3, 0xc3, 0xc0, 
	0xc0, 0x17, 0xe1, 0xe1, 0xe1, 0xe1, 0x3e, 0x3e, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xd6, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xc0, 0xc0, 0xc0, 0xd8, 0xeb, 0xeb, 0xd4, 
	0xc6, 0x26, 0x26, 0xee, 0xee, 0xc7, 0xc7, 0xf2, 
	0xe3, 0xd5, 0xd5, 0xf7, 0x30, 0x36, 0x36, 0x23, 
	0x33, 0x35, 0x35, 0x1c, 0xdd, 0xdd, 0xdd, 0x29, 
	0xe8, 0xe8, 0xe8, 0x30, 0x3f, 0x3f, 0x3f, 0x38, 
	0x31, 0x3f, 0x3f, 0x3f, 0x3f, 0x1e, 0x1e, 0x1e, 
	0xfd, 0x12, 0x12, 0x12, 0x3e, 0x3b, 0x3b, 0x3b, 
	0xdb, 0x36, 0x36, 0x36, 0x36, 0xe9, 0xc5, 0xc5, 
	0xc5, 0x26, 0xef, 0xef, 0xef, 0xc1, 0xd6, 0xd6, 
	0xd6, 0xd6, 0x30, 0xc2, 0xc2, 0xc2, 0xc3, 0x12, 
	0x12, 0x12, 0x12, 0x15, 0x19, 0x19, 0x19, 0xe3, 
	0xcb, 0xcb, 0xcb, 0xcb, 0xd1, 0xc1, 0xc1, 0xc1, 
	0xc1, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xde, 0xde, 
	0xde, 0xde, 0xef, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 
	0xc5, 0xc5, 0xc5, 0xc9, 0xd7, 0xd8, 0xd8, 0xd8, 
	0x2a, 0x36, 0x36, 0x36, 0x3c, 0x3e, 0x3e, 0x3e, 
	0xf5, 0x1e, 0x1e, 0x1e, 0x1e, 0xd7, 0xc1, 0xc1, 
	0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xd5, 0x0e, 0x0e, 
	0x0e, 0x0e, 0xe8, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 
	0x3e, 0x3e, 0x3e, 0x38, 0x3e, 0x3e, 0x3e, 0x3e, 
	0xdc, 0xdc, 0xdc, 0xdc, 0x28, 0x1d, 0x1d, 0x1d, 
	0x1d, 0xc1, 0xd9, 0xd9, 0xd9, 0xd9, 0xc2, 0xc2, 
	0xc2, 0xc2, 0xc2, 0x08, 0x08, 0x08, 0x08, 0x08, 
	0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0xe7, 0xe7, 0xe7, 
	0xe7, 0xe7, 0xc2, 0xc2, 0xc2, 0xc2, 0xc2, 0xc2, 
	0xc2, 0xc2, 0xc2, 0xc2, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0xcf, 0xca, 
	0xca, 0xca, 0xca, 0xc2, 0xc2, 0xc2, 0xc2, 0xc2, 
	0xc2, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xd3, 0xfb, 
	0xfb, 0xfb, 0xfb, 0xfb, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xc2, 0xc2, 0xc2, 0xc2, 0xc2, 0xc2, 0xc2, 
	0xca, 0xca, 0xca, 0xca, 0xca, 0xcc, 0xc6, 0xc6, 
	0xc6, 0xc6, 0xc2, 0xca, 0xca, 0xca, 0xca, 0xca, 
	0xe4, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x22, 0x36, 
	0x3b, 0x3b, 0x3b, 0x3b, 0x23, 0xe3, 0xe3, 0xe3, 
	0xe3, 0xe2, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0x3d, 
	0x3d, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 
	0x3c, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xc3, 0xe6, 
	0xe6, 0xe6, 0xe6, 0xe6, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0xd5, 0xc6, 0xc6, 0xc7, 0xc7, 0xc4, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x3c, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0xd6, 0xd9, 0xd9, 0xd9, 0xd9, 0xdc, 
	0x31, 0x31, 0x31, 0x31, 0x31, 0x3c, 0x3c, 0x3c, 
	0x3c, 0x3c, 0x3c, 0x31, 0xee, 0xee, 0xee, 0xee, 
	0xee, 0xca, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xf4, 
	0xcf, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 
	0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 
	0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 
	0xc3, 0xd4, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xe4, 
	0xe4, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xc8, 0xc8, 
	0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc4, 
	0xc4, 0xc4, 0xc4, 0xc4, 0xc4, 0xc4, 0xc5, 0xc5, 
	0xc5, 0xc5, 0xc5, 0xd1, 0xd1, 0xc7, 0xc7, 0xc7, 
	0xc7, 0xc7, 0xc4, 0xc4, 0xc4, 0xc8, 0xc8, 0xc8, 
	0xc8, 0xc8, 0xd4, 0xd4, 0xc6, 0xc4, 0xc4, 0xc4, 
	0xc4, 0xc4, 0xc4, 0xc4, 0xd5, 0xd5, 0xd5, 0xd5, 
	0xd5, 0x34, 0x34, 0x34, 0x3b, 0x3b, 0x3b, 0x3b, 
	0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 
	0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0xe9, 0xe9, 0xe9, 
	0xe9, 0xe9, 0xc4, 0xc4, 0xc4, 0xd4, 0xd4, 0xd4, 
	0xd4, 0xd4, 0x34, 0x34, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x2c, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 0x2b, 
	0x2b, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 
	0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xc8, 0xc8, 0xc4, 
	0xc4, 0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0x0e, 0x0e, 0xc7, 0xc7, 0xc7, 
	0xc7, 0xc7, 0xc5, 0xc5, 0xc5, 0xd6, 0xd6, 0xd6, 
	0xd6, 0xeb, 0x39, 0x39, 0xda, 0xda, 0xda, 0xda, 
	0xda, 0xc5, 0xc5, 0xc5, 0xc5, 0xc5, 0xc5, 0xc5, 
	0xc5, 0xc5, 0xc5, 0xc5, 0xe9, 0xe9, 0xe9, 0xe9, 
	0x0c, 0x3a, 0x3a, 0x3a, 0xdb, 0xdb, 0xdb, 0xdb, 
	0xdb, 0xc5, 0xc5, 0xc5, 0xc8, 0xc8, 0xc8, 0xc8, 
	0xc8, 0x15, 0x15, 0x15, 0x25, 0x25, 0x25, 0x25, 
	0x25, 0x30, 0x30, 0x30, 0x30, 0xea, 0xea, 0xea, 
	0xea, 0xea, 0xc9, 0xc9, 0xc9, 0xc9, 0xdd, 0xdd, 
	0xdd, 0xdd, 0xdd, 0x1f, 0x1f, 0x1f, 0x1f, 0xe1, 
	0xe1, 0xe1, 0xe1, 0xe1, 0xcd, 0xcd, 0xcd, 0xcd, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc6, 
	0xc6, 0xc6, 0xc6, 0xc6, 0xc9, 0xc9, 0xc9, 0xc9, 
	0xc9, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0x12, 0x12, 
	0x12, 0x12, 0x12, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
	0x29, 0xe3, 0xe3, 0xe3, 0xe3, 0xde, 0xc6, 0xc6, 
	0xc6, 0xc6, 0xc6, 0xc9, 0x11, 0x11, 0x11, 0x11, 
	0x1c, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 
	0x39, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 
	0x32, 0x32, 0x39, 0x39, 0x39, 0x39, 0x38, 0x38, 
	0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 
	0x28, 0x16, 0x15, 0x15, 0x15, 0xc7, 0xc7, 0xc7, 
	0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc9, 
	0x18, 0x18, 0x18, 0x18, 0x29, 0x38, 0x38, 0x38, 
	0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 
	0x38, 0x38, 0x38, 0x38, 0x38, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 
	0x38, 0x38, 0x38, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x18, 0x27, 0x27, 0x27, 0x27, 0x27, 
	0xda, 0xda, 0xda, 0xda, 0xda, 0xc7, 0xc7, 0xc7, 
	0xc7, 0xc7, 0xc7, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xe1, 
	0xe1, 0xe1, 0xe2, 0xe0, 0xd6, 0xd6, 0xd6, 0xd6, 
	0xd6, 0xd6, 0x20, 0x2a, 0x2a, 0x2a, 0x2a, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x24, 
	0x24, 0x24, 0x24, 0x1c, 0xcb, 0xcb, 0xcb, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 
	0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 
	0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xc8, 0xca, 0xca, 
	0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xe8, 0xe9, 0xe9, 0xe9, 0xe9, 0xe9, 
	0xe9, 0xe9, 0xe9, 0xe9, 0xf2, 0x2d, 0x2d, 0x2d, 
	0x2d, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 
	0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 
	0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 
	0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0xc9, 0xc9, 0xc9, 0xc9, 0xc9, 
	0xc9, 0xc9, 0xc9, 0xc9, 0xc9, 0xc9, 0xc9, 0xc9, 
	0xc9, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 
	0x15, 0x15, 0x15, 0x15, 0x15, 0x0c, 0x0c, 0x0c, 
	0x0c, 0x0a, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 
	0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 
	0xf1, 0xf1, 0xe0, 0xd6, 0xd6, 0xd6, 0xd6, 0xc9, 
	0xc9, 0xc9, 0xc9, 0xc9, 0xca, 0xca, 0xca, 0xca, 
	0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 
	0xca, 0xca, 0xdd, 0x20, 0x20, 0x20, 0x20, 0x35, 
	0x35, 0x35, 0x35, 0x35, 0x35, 0x35, 0x35, 0x35, 
	0x35, 0x35, 0x35, 0x35, 0x35, 0x35, 0x35, 0x35, 
	0x35, 0x35, 0x35, 0x35, 0x35, 0x30, 0x1c, 0x1c, 
	0x1c, 0x1c, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 
	0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 
	0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 0xca, 
	0xca, 0xca, 0xca, 0xca, 0xcb, 0xd2, 0xd2, 0xd2, 
	0xd2, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
	0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
	0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
	0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 
	0xe8, 0xf1, 0x2d, 0x2d, 0x2d, 0x2d, 0x33, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 
	0x34, 0x34, 0x15, 0x15, 0x15, 0x15, 0x15, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 0xcb, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
	0xcc, 0xd3, 0xd6, 0xd6, 0xd6, 0xd8, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0xda, 
	0xd7, 0xd7, 0xd7, 0xd3, 0xce, 0xce, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 
	0xce, 0xce, 0xce, 0xce, 0xce, 0xcf, 0xcf, 0xcf, 
	0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 
	0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 
	0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 
	0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 
	0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 
	0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xd0, 0x13, 
	0x13, 0x13, 0x13, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x28, 0x28, 0x28, 0x28, 0x0c, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 0xeb, 
	0xeb, 0xd8, 0xd8, 0xd8, 0xd8, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 0xd1, 
	0xd1, 0xd1, 0xd1, 0xd1, 0x18, 0x18, 0x18, 0x18, 
	0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2d, 
	0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
	0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
	0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
	0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
	0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 
	0x2d, 0x2d, 0x2d, 0x2d, 0x1b, 0x1b, 0x1b, 0x1b, 
	0xea, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 
	0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 
	0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 
	0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 
	0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 
	0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 0xd3, 
	0xd3, 0xd3, 0xd3, 0xdd, 0xdd, 0xdd, 0xdd, 0xe5, 
	0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 
	0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 
	0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 
	0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 
	0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 
	0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 
	0xf4, 0x0a, 0x0a, 0x0a, 0x0a, 0x0c, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xde, 
	0xde, 0xde, 0xde, 0xde, 0xd4, 0xd4, 0xd4, 0xd4, 
	0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 
	0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 
	0xd4, 0xd4, 0xd4, 0xd4, 0xd4, 0xd5, 0xd5, 0xd5, 
	0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 
	0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 
	0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0xd5, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 
	0x2a, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 
	0x23, 0x12, 0x12, 0x12, 0x12, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 
	0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 
	0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 
	0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 
	0xd8, 0xd8, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x08, 0x08, 0x08, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 
	0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xe6, 0xe3, 0xe3, 
	0xe3, 0xe3, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
	0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
	0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
	0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
	0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 
	0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0xdc, 0x15, 
	0x15, 0x15, 0x15, 0x20, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x21, 
	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 
	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 
	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 
	0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 
	0x21, 0x11, 0x11, 0x11, 0x11, 0xde, 0xde, 0xde, 
	0xde, 0xde, 0xde, 0xde, 0xde, 0xde, 0xde, 0xde, 
	0xde, 0xde, 0xde, 0xde, 0xde, 0xde, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xe0, 0xe0, 0xe0, 
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
	0xe0, 0xe0, 0xe3, 0xe5, 0xe5, 0xe5, 0xe5, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 0xf2, 
	0xf2, 0xf2, 0xf2, 0xf2, 0x19, 0x19, 0x19, 0x19, 
	0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 
	0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 
	0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 
	0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c, 
	0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
	0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
	0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
	0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
	0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
	0x1c, 0x1c, 0x1c, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 
	0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 
	0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x0b, 0x0b, 
	0x0b, 0x0b, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 
	0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 
	0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe4, 0xe5, 
	0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 
	0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 
	0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 
	0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 
	0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 0xe5, 
	0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 
	0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 
	0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 
	0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xe6, 0xeb, 
	0xeb, 0xeb, 0xeb, 0xeb, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x0e, 0x0e, 0x0e, 0x0e, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 
	0x13, 0x13, 0x13, 0x13, 0x12, 0x12, 0x12, 0x12, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
	0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0xf1, 0xf1, 0xf1, 0xf1, 0xec, 
	0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 
	0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 
	0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 
	0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 
	0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 0xed, 
	0xed, 0xed, 0xed, 0xee, 0xee, 0xee, 0xee, 0xee, 
	0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 
	0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 
	0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xef, 0xef, 
	0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 
	0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 
	0xef, 0xef, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0, 
	0xf1, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 
	0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 
	0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
	0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
	0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
	0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
	0xf8, 0xf8, 0xf8, 0xf8, 0xf9, 0xf9, 0xf9, 0xf9, 
	0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 
	0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 
	0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 
	0xf9, 0xf9, 0xf9, 0xfa, 0xfa, 0xfa, 0x03, 0x03, 
	0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
	0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 
	0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x02, 0x02, 0x02, 0x01, 0x01, 0x01
};

const SoundData sound_enemyExplode = 
{
	(uint8_t*)soundData,	//pointer to data
	4526,	//length of data array
	8,	//bits per sample
	11000	//sample rate (hz)
};

////////////////////////////////////////////////////

