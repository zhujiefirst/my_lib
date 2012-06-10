#ifndef JK_COMMON_H
#define JK_COMMON_H

/*
 * type define
 */
typedef		char				jk_int8;
typedef		unsigned char		jk_uint8;
typedef     short				jk_int16;
typedef		unsigned short		jk_uint16;
typedef		int					jk_int32;
typedef		unsigned int		jk_uint32;
/*
#define jk_int8				char
#define jk_uint8			unsigned char 
#define jk_int16			short
#define jk_uint16			unsigned short
#define jk_int32			int
#define jk_uint32			unsigned int 
*/

/*
 * define the maximum and minimum macro of 8, 16, 32-bits intger
 */
#define JK_INT8_MIN			(-128)			// CHAR_MIN
#define JK_INT8_MAX			(127)			// CHAR_MAX
#define JK_UINT8_MIN		(0)
#define JK_UINT8_MAX		(255)			// UCHAR_MAX
#define JK_INT16_MIN		(-32768)        // SHORT_MIN
#define JK_INT16_MAX		(32767)			// SHORT_MAX
#define JK_UINT16_MIN		(0)
#define JK_UINT16_MAX		(0xffff)		// USHORT_MAX
#define JK_INT32_MIN		(-2147483648)	// INT_MIN
#define JK_INT32_MAX		(2147483647)	// INT_MAX
#define JK_UINT32_MIN		(0)
#define JK_UINT32_MAX		(0xffffffff)    // UINT32_MAX

/*
 * define return macro
 */
#define JK_SUCCESS			0
#define JK_ERROR            -1

#endif