#include "stdio.h"
#include "jk_common.h"
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
 
        return 1.0 / y;
}

int main(int argc, char** argv)
{
#if 1
	printf("%f\n", jk_quickSqrt(0.25));
#endif

	return 0;
}