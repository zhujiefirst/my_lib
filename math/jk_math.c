#include "stdio.h"
#include "jk_math.h"

/*
 * http://en.wikipedia.org/wiki/Fast_inverse_square_root
 */
float jk_quickSqrt(float number)
{
	jk_int32 i;
	float x2, y;
	const float threehalfs = 1.5f;

	x2 = number * 0.5f;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	// i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	i  = 0x5f375a86 - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration 
	//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return 1.0f / y;
}

jk_uint16 jk_sqrtInt32(jk_uint32 number)
{
	jk_uint32 remain = 0;	
	jk_uint16 root = 0;			// the result
	jk_uint32 divisor = 0;

	for (jk_uint8 i = 0; i < 16; ++i) {
		remain = (remain << 2) + (number >> 30);
		number <<= 2;			// update the number
		root <<= 1;
		divisor = (root << 1) + 1;
		if (divisor <= remain) {
			remain -= divisor;
			++root;
		}
	}
	
	return root;
}

/*
int main(int argc, char** argv)
{
#if 0			// test jk_quickSqrt
	printf("%f\n", jk_quickSqrt(0.25));
#endif

#if 0			// test jk_sqrtInt32
	printf("%d\n", jk_sqrtInt32(121));
#endif

	return 0;
}
*/