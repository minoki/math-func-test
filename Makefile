all: sample test-sin test-exp test-pow test-pow2 test-pow05

sample: sample.c
	$(CC) -o $@ $< -lm

const-sin: const-sin.c
	gcc -std=c2x -o $@ $< -lm

test-sin: test-sin.c sin-data.inc
	$(CC) -o $@ $< -lm

test-exp: test-exp.c exp-data.inc
	$(CC) -o $@ $< -lm

test-pow: test-pow.c pow-data.inc
	$(CC) -o $@ $< -lm

test-pow2: test-pow2.c pow2-data.inc
	$(CC) -o $@ $< -lm

test-pow05: test-pow05.c pow05-data.inc
	$(CC) -o $@ $< -lm

gen-sin: gen-sin.c
	$(CC) -o $@ $< `pkg-config --cflags --libs mpfr`

sin-data.inc: gen-sin
	./gen-sin

gen-exp: gen-exp.c
	$(CC) -o $@ $< `pkg-config --cflags --libs mpfr`

exp-data.inc: gen-exp
	./gen-exp

gen-pow: gen-pow.c
	$(CC) -o $@ $< `pkg-config --cflags --libs mpfr`

pow-data.inc: gen-pow
	./gen-pow

gen-pow2: gen-pow2.c
	$(CC) -o $@ $< `pkg-config --cflags --libs mpfr`

pow2-data.inc: gen-pow2
	./gen-pow2

gen-pow05: gen-pow05.c
	$(CC) -o $@ $< `pkg-config --cflags --libs mpfr`

pow05-data.inc: gen-pow05
	./gen-pow05
