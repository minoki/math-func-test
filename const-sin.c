#include <math.h>
#include <stdio.h>

int main()
{
    constexpr double a = sin(0x1p938);
    const volatile double x = 0x1p938;
    double b = sin(x);
    printf("sin[compile-time](0x1p938)=%.17g [%a]\n", a, a);
    printf("sin[runtime](0x1p938)=%.17g [%a]\n", b, b);
}
