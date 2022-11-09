#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gmp.h>

#define MPZ_CMP(A, OP, B) mpz_cmp((A), (B)) OP 0
#define MPZ_CMP_UI(A, OP, B) mpz_cmp_ui((A), (B)) OP 0

static void fib(mpz_t n, mpz_t out) {
    mpz_t first;
    mpz_t second;
    mpz_t tmp;
    mpz_t i;

    mpz_init(first);
    mpz_init(second);
    mpz_init(tmp);
    mpz_init(i);

    mpz_set_ui(first, 0);
    mpz_set_ui(second, 1);

    for (mpz_set_ui(i, 0); (mpz_cmp(i, n) < 0); mpz_add_ui(i, i, 1)) {
        mpz_add(tmp, first, second);
        mpz_set(first, second);
        mpz_set(second, tmp);
    }
    mpz_set(out, first);

    mpz_clear(first);
    mpz_clear(second);
    mpz_clear(tmp);
    mpz_clear(i);
}

int main(void) {
    mpz_t n;
    mpz_t result;

    mpz_init(n);
    mpz_init(result);
    for (;;) {
        mpz_inp_str(n, stdin, 10);
        if (MPZ_CMP_UI(n, ==, 0)) {
            break;
        }
        fib(n, result);
        mpz_out_str(stdout, 10, result);
        puts("");
        mpz_set_ui(n, 0);
    }
    mpz_clear(n);
    mpz_clear(result);
    return 0;
}
