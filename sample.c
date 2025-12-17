#include <math.h>
#include <stdio.h>

struct unary {
    double x;
    double cr_result;
};

struct binary {
    double x, y;
    double cr_result;
};

static const struct unary sin_cases[] = {
    {0x1p2, -0x1.837b9dddc1eaep-1}, // AArch64 macOS
    {0x1p6, 0x1.d70da7230c1d8p-1}, // x86-64 macOS
    {0x1p18, -0x1.58809c5ce39b6p-4}, // x86-64 UCRT
    {0x1p25, -0x1.f3fa130939bafp-1}, // x86-64/AArch64 glibc
    {0x1p54, 0x1.cb6f75f360b74p-1}, // x86-64/AArch64 musl
};
static const struct unary exp_cases[] = {
    {-0x1.36b851eb851ecp+3, 0x1.fcf7cf12139c9p-15}, // x86-64 UCRT
    {-0x1.40a3d70a3d70ap+2, 0x1.b52f2f88ff3ddp-8}, // x86-64 macOS
    {-0x1.3333333333333p-1, 0x1.18fdd6b9604e3p-1}, // x86-64/AArch64 musl
    {0x1.6a3d70a3d70a4p+2, 0x1.0f209b8790d89p+4}, // x86-64/AArch64 glibc
    {0x1.a28f5c28f5c29p+3, 0x1.d4072d3139aefp+18}, // AArch64 macOS
};
static const struct binary pow_cases[] = {
    {0x1.3333333333333p-1, -0x1.999999999999ap-4, 0x1.0d6aba2f6f6a6p+0}, // x86-64/AArch64 glibc
    {0x1.6666666666666p+1, -0x1.999999999999ap-1, 0x1.c156a12e405bp-2}, // x86-64/AArch64 macOS
    {0x1.f333333333333p+1, -0x1.7333333333333p+1, 0x1.3c78537126f53p-6}, // x86-64/AArch64 musl
    {0x1.2cccccccccccdp+2, -0x1.599999999999ap+1, 0x1.f618446e34cf5p-7}, // x86-64 UCRT
};
static const struct unary pow2_cases[] = {
    {0x1.0deb851eb851fp+4, 0x1.1c98ce703afb9p+8}, // x86-64 UCRT
    {0x1.135c28f5c28f6p+4, 0x1.282f212d7731ap+8}, // x86-64/AArch64 macOS
    {0x1.2ca3d70a3d70ap+4, 0x1.611068db8bac7p+8}, // x86-64/AArch64 musl
    {0x1.7fe147ae147aep+6, 0x1.1fd1ed5cfaacdp+13}, // x86-64/AArch64 glibc
};
static const struct unary pow05_cases[] = {
    {0x1.4233333333333p+7, 0x1.96291a6b7bfa9p+3}, // x86-64 UCRT
    {0x1.62ccccccccccdp+6, 0x1.2d60cf9a20ae4p+3}, // x86-64/AArch64 macOS
    {0x1.2eccccccccccdp+6, 0x1.166b1b9eb5f04p+3}, // x86-64/AArch64 musl
    {0x1.80e6666666666p+8, 0x1.39e6e29fa7384p+4}, // x86-64/AArch64 glibc
};

int main(void)
{
    for (size_t i = 0; i < sizeof(sin_cases) / sizeof(sin_cases[0]); ++i) {
        double x = sin_cases[i].x;
        double cr = sin_cases[i].cr_result;
        double y = sin(x);
        printf("sin(%.17g [%a]) = %.17g [%a]", x, x, y, y);
        if (y == cr) {
            puts("");
        } else {
            printf("* (cr: %.17g [%a])\n", cr, cr);
        }
    }
    for (size_t i = 0; i < sizeof(exp_cases) / sizeof(exp_cases[0]); ++i) {
        double x = exp_cases[i].x;
        double cr = exp_cases[i].cr_result;
        double y = exp(x);
        printf("exp(%.17g [%a]) = %.17g [%a]", x, x, y, y);
        if (y == cr) {
            puts("");
        } else {
            printf("* (cr: %.17g [%a])\n", cr, cr);
        }
    }
    for (size_t i = 0; i < sizeof(pow_cases) / sizeof(pow_cases[0]); ++i) {
        double x = pow_cases[i].x;
        double y = pow_cases[i].y;
        double cr = pow_cases[i].cr_result;
        double z = pow(x, y);
        printf("pow(%.17g [%a], %.17g [%a]) = %.17g [%a]", x, x, y, y, z, z);
        if (z == cr) {
            puts("");
        } else {
            printf("* (cr: %.17g [%a])\n", cr, cr);
        }
    }
    for (size_t i = 0; i < sizeof(pow2_cases) / sizeof(pow2_cases[0]); ++i) {
        double x = pow2_cases[i].x;
        double cr = pow2_cases[i].cr_result;
        double y = pow(x, 2.0);
        printf("pow(%.17g [%a], 2.0) = %.17g [%a]", x, x, y, y);
        if (y == cr) {
            puts("");
        } else {
            printf("* (cr: %.17g [%a])\n", cr, cr);
        }
    }
    for (size_t i = 0; i < sizeof(pow05_cases) / sizeof(pow05_cases[0]); ++i) {
        double x = pow05_cases[i].x;
        double cr = pow05_cases[i].cr_result;
        double y = pow(x, 0.5);
        printf("pow(%.17g [%a], 0.5) = %.17g [%a]", x, x, y, y);
        if (y == cr) {
            puts("");
        } else {
            printf("* (cr: %.17g [%a])\n", cr, cr);
        }
    }
}
