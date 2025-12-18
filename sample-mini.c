#include <math.h>
#include <stdio.h>

int main(void)
{
    {
        volatile double x = 0x1p2;
        double y = sin(x);
        double cr_result = -0x1.837b9dddc1eaep-1;
        printf("sin(%.17g [%a]) = %.17g [%a]", x, x, y, y);
        if (y == cr_result) {
            puts("");
        } else {
            // AArch64 macOS
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
    {
        volatile double x = -0x1.40a3d70a3d70ap+2;
        double y = exp(x);
        double cr_result = 0x1.b52f2f88ff3ddp-8;
        printf("exp(%.17g [%a]) = %.17g [%a]", x, x, y, y);
        if (y == cr_result) {
            puts("");
        } else {
            // x86-64 macOS
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
    {
        volatile double x = 0x1.2cccccccccccdp+2;
        volatile double y = -0x1.599999999999ap+1;
        double cr_result = 0x1.f618446e34cf5p-7;
        double z = pow(x, y);
        printf("pow(%.17g [%a], %.17g [%a]) = %.17g [%a]", x, x, y, y, z, z);
        if (z == cr_result) {
            puts("");
        } else {
            // x86-64 UCRT
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
    {
        volatile double x = 0x1.3333333333333p-1;
        volatile double y = -0x1.999999999999ap-4;
        double cr_result = 0x1.0d6aba2f6f6a6p+0;
        double z = pow(x, y);
        printf("pow(%.17g [%a], %.17g [%a]) = %.17g [%a]", x, x, y, y, z, z);
        if (z == cr_result) {
            puts("");
        } else {
            // x86-64/AArch64 glibc
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
    {
        volatile double x = 0x1.135c28f5c28f6p+4;
        double cr_result = 0x1.282f212d7731ap+8;
        double y = pow(x, 2.0);
        printf("pow(%.17g [%a], 2.0) = %.17g [%a]", x, x, y, y);
        if (y == cr_result) {
            puts("");
        } else {
            // x86-64/AArch64 macOS
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
    {
        volatile double x = 0x1.7fe147ae147aep+6;
        double cr_result = 0x1.1fd1ed5cfaacdp+13;
        double y = pow(x, 2.0);
        printf("pow(%.17g [%a], 2.0) = %.17g [%a]", x, x, y, y);
        if (y == cr_result) {
            puts("");
        } else {
            // x86-64/AArch64 glibc
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
    {
        volatile double x = 0x1.2eccccccccccdp+6;
        double cr_result = 0x1.166b1b9eb5f04p+3;
        double y = pow(x, 0.5);
        printf("pow(%.17g [%a], 0.5) = %.17g [%a]", x, x, y, y);
        if (y == cr_result) {
            puts("");
        } else {
            // x86-64/AArch64 musl
            printf("* (cr: %.17g [%a])\n", cr_result, cr_result);
        }
    }
}
