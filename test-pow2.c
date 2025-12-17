#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct data {
    double x, y, zn, zu, zd;
    const char *quad;
} static const data[] = {
#include "pow2-data.inc"
};

int main(void)
{
    bool all_ok = true;
    for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        double x = data[i].x;
        double y = data[i].y;
        double z = pow(x, y);
        if (z != data[i].zn) {
            all_ok = false;
            puts("---");
            printf("x = %a, y = %a:\n", x, y);
            if (z != data[i].zu && z != data[i].zd) {
                printf("libm: pow(x, y) = %a <not faithful>\n", z);
            } else {
                printf("libm: pow(x, y) = %a\n", z);
            }
            printf("MPFR: pow(x, y) = %a\n", data[i].zn);
            printf("Quad: pow(x, y) = %s\n", data[i].quad);
        }
    }
    if (all_ok) {
        puts("All tests passed for pow()");
    }
}
