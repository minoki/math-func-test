#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpfr.h>
#include <gmp.h>

static void to_normalized_hex(char *buf, mpfr_t a, int mant)
{
    // assume a is positive
    mpz_t z;
    mpz_init(z);
    mpfr_exp_t e = mpfr_get_z_2exp(z, a);
    mpz_abs(z, z);
    size_t size_in_base_2 = mpz_sizeinbase(z, 2);
    // 2^(mant+k-1) <= 1XXXXXX(in hex) < 2^(mant+k), 0 <= k < 4
    // (mant+k-1) is a multiple of 4
    // k === 1-mant mod 4
    int k = (1 + 3 * mant) % 4;
    mpz_mul_2exp(z, z, mant + k - size_in_base_2);
    char buf2[(mant + 2) / 4 + 3];
    mpz_get_str(buf2, 16, z);
    // buf2: z * 2^(mant + k - size_in_base_2)
    // z * 2^(mant + k - size_in_base_2) * 2^(mant-1-k)
    if (mpfr_signbit(a) != 0) {
        *buf++ = '-'; // negative
    }
    sprintf(buf, "0x%c.%sp%+d", buf2[0] /* 0 */, buf2+1, (int)e + mant - 1);
    mpz_clear(z);
}

static void to_hex_str(char *buf, mpfr_t x)
{
    int prec = mpfr_get_prec(x);
    to_normalized_hex(buf, x, prec);
}

int main(void)
{
    FILE *f = fopen("pow-data.inc", "w");
    if (f == NULL) {
        fputs("Failed to open sin-data.inc", stderr);
        abort();
    }
    for (int m = 1; m < 50; m++) {
        for (int n = -40; n <= 40; n++) {
            double x = (double)m / 10.0;
            double y = (double)n / 10.0;
            mpfr_t xm, ym, zm, zu, zd, zp;
            mpfr_init2(xm, 53);
            mpfr_init2(ym, 53);
            mpfr_init2(zm, 53);
            mpfr_init2(zu, 53);
            mpfr_init2(zd, 53);
            mpfr_init2(zp, 113);
            int r = mpfr_set_d(xm, x, MPFR_RNDN);
            if (r != 0) {
                fprintf(stderr, "mpfr_set_d was inexact on %a!\n", x);
                abort();
            }
            r = mpfr_set_d(ym, y, MPFR_RNDN);
            if (r != 0) {
                fprintf(stderr, "mpfr_set_d was inexact on %a!\n", y);
                abort();
            }
            mpfr_pow(zm, xm, ym, MPFR_RNDN);
            mpfr_pow(zu, xm, ym, MPFR_RNDU);
            mpfr_pow(zd, xm, ym, MPFR_RNDD);
            mpfr_pow(zp, xm, ym, MPFR_RNDN);
            char buf[1024];
            to_hex_str(buf, zp);
            fprintf(f, "    {%a, %a, %a, %a, %a, \"%s\"},\n", x, y, mpfr_get_d(zm, MPFR_RNDN), mpfr_get_d(zu, MPFR_RNDN), mpfr_get_d(zd, MPFR_RNDN), buf);
            mpfr_clear(xm);
            mpfr_clear(zm);
            mpfr_clear(zu);
            mpfr_clear(zd);
            mpfr_clear(zp);
        }
    }
    fclose(f);
}
