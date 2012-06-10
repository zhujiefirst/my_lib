#include <stdio.h>
#include <assert.h>
#include "jk_common.h"
#include "jk_debug_utils.h"

void jk_parseBits8(void* pValue)
{	
	assert(pValue);

	jk_uint16 mask = 0x0080;
	jk_uint8 value = *(jk_uint8*)pValue;

	while (mask) {
		printf("%d ", (value & mask) ? 1 : 0);
		mask >>= 1;
	}
	printf("\n");
}

void jk_parseBits16(void* pValue)
{
	assert(pValue);

	jk_uint32 mask = 0x00008000;
	jk_uint16 value = *(jk_uint16*)pValue;

	while (mask) {
		printf("%d ", (value & mask) ? 1 : 0);
		mask >>= 1;
	}
	printf("\n");
}

void jk_parseBits32(void* pValue)
{
	assert(pValue);

	jk_uint32 mask = 0x80000000;
	jk_uint32 value = *(jk_uint32*)pValue;

	while (mask) {
		printf("%d ", (value & mask) ? 1 : 0);
		mask = 0x7fffffff & (mask >> 1);
	}
	printf("\n");
}

/*
int main(int argc, char** argv)
{
#if 0		// test < jk_parseBit8 >
	jk_int8 signedValue = JK_INT8_MIN;
	jk_uint8 unsignedValue = 0;
	jk_uint16 countNum = 0;
	printf("\nnow, test < jk_parseBit8 >:\n");
	for (; countNum < (JK_UINT8_MAX + 1); ++signedValue, ++countNum) {
		jk_parseBits8(&signedValue);
	}
 	printf("\n-------------------------------\n");
	for (countNum = 0; countNum < (JK_UINT8_MAX + 1); ++unsignedValue, ++countNum) {
		jk_parseBits8(&unsignedValue);
	}
	printf("\ntest is over!\n");
#endif

#if 0		// test < jk_parseBit16 >
	jk_int16 signedValue = JK_INT16_MIN;
	jk_uint16 unsignedValue = 0;
	jk_uint32 countNum = 0;
	printf("\nnow, test < jk_parseBit16 >:\n");
	for (; countNum < (JK_UINT16_MAX + 1); ++signedValue, ++countNum) {
		jk_parseBits16(&signedValue);
	}
	printf("\n-------------------------------\n");
	for (countNum = 0; countNum < (JK_UINT16_MAX + 1); ++unsignedValue, ++countNum) {
		jk_parseBits16(&unsignedValue);
	}
	printf("\ntest is over!\n");
#endif

#if 0		// test < jk_parseBit32 >
	jk_int32 signedValue = JK_INT32_MIN;
	jk_uint32 unsignedValue = 0;
	jk_uint32 countNum = 0;
	printf("\nnow, test < jk_parseBit16 >:\n");
	for (; countNum <= JK_UINT32_MAX ; ++signedValue, ++countNum) {
		jk_parseBits32(&signedValue);
	}
	printf("\n-------------------------------\n");
	for (countNum = 0; countNum <= JK_UINT32_MAX; ++unsignedValue, ++countNum) {
		jk_parseBits32(&unsignedValue);
	}
	printf("\ntest is over!\n");
#endif

	return 0;
}
*/