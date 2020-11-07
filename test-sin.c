#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct data {
    double x, yn, yu, yd;
    const char *quad;
} static const data[] = {
#include "sin-data.inc"
};

int main(void)
{
    bool all_ok = true;
    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        double x = data[i].x;
        double y = sin(x);
        if (y != data[i].yn) {
            all_ok = false;
            puts("---");
            printf("x = %a:\n", x);
            if (y != data[i].yu && y != data[i].yd) {
                printf("libm: sin(x) = %a <more than 1 ulp away>\n", y);
            } else {
                printf("libm: sin(x) = %a\n", y);
            }
            printf("MPFR: sin(x) = %a\n", data[i].yn);
            printf("Quad: sin(x) = %s\n", data[i].quad);
        }
    }
    if (all_ok) {
        puts("All tests passed for sin()");
    }
}
