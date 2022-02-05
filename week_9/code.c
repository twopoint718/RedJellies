#include <stdint.h>
#include "greatest.h"

/** This is the first function that I came up with. The idea is to
 * repeatedly right-shift the number while also counting the '1's that
 * appear in the LSB as you do so. This should run for however many
 * bits are in 'n' (here's it's always 32). It should only consume
 * memory for variables 'n' and 'out'.
 *
 */
int number_of_ones_A(uint32_t n) {
  int out = 0;
  while(n) {
    out += n & 0x1;
    n >>= 1;
  }
  return out;
}

/** I had to include a recursive function as well. I tried the naive
 * recursive version, this one keeps a counter on the stack as it
 * calls a further recursive function. When the stock winds back down
 * all the "deferred" additions are performed. At least that's what I
 * thought would happen. When I set the optimization to -O2, GCC was
 * able to transform this into a loop!
 *
 */
int number_of_ones_B(uint32_t n) {
  if (n == 0) return 0;
  return (0x1 & n) + number_of_ones_B(n >> 1);
}

/** Counting bits set, Brian Kernighan's way
 *
 * via http://graphics.stanford.edu/~seander/bithacks.html
 *
 */
int number_of_ones_Kernighan(uint32_t n) {
  unsigned int c; // c accumulates the total bits set in v
  for (c = 0; n; c++) {
    n &= n - 1; // clear the least significant bit set
  }
  return c;
}

typedef int (*testFunc_t)(uint32_t);

////////////////////////////////////////////////////////////////////////////////
// Change this line to select which function to test

testFunc_t functionUnderTest = &number_of_ones_B;

////////////////////////////////////////////////////////////////////////////////

/** Run through all possible (contiguous) bit patterns with n = 1
 * through n = 32. For each of those, repeatedly shift the bits left
 * until they reach the MSB. e.g.
 *
 * 01111111 11111111 11111111 11111111 (0x7FFF FFFF) <- shift left
 * 11111111 11111111 11111111 11111110 (0xFFFF FFFE)
 *
 * Unfortunately, this logic can't be used for checking for zero ones,
 * that is a separate test (but there's only one possibility)
 *  
 */
TEST exhaustive(void) {
  int num_ones = 1;  // the number of ones in the bit pattern
  uint32_t bits = 1; // the bit pattern
  uint32_t n;

  while (num_ones <= 32) {
    n = bits;
    while (1) {
      /* fprintf(stderr, "\nn: (%10x) %10u = %10u", n, number_of_ones(n), num_ones); */
      ASSERT_EQ((*functionUnderTest)(n), num_ones);
      if (n & (1 << 31)) {
	break;
      }
      n <<= 1;
    }
    bits = bits << 1 | 0x1; // add one more '1' to the number
    num_ones++;
  }
  PASS();
}

TEST zero(void) {
  ASSERT_EQ((*functionUnderTest)(0), 0);
  PASS();
}

TEST pattern5(void) {
  ASSERT_EQ((*functionUnderTest)(0x55555555), 16);
  PASS();
}

TEST patternA(void) {
  ASSERT_EQ((*functionUnderTest)(0xAAAAAAAA), 16);
  PASS();
}

TEST patternHiLo(void) {
  ASSERT_EQ((*functionUnderTest)(0x80000001), 2);
  PASS();
}


GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_TEST(zero);
    RUN_TEST(pattern5);
    RUN_TEST(patternA);
    RUN_TEST(patternHiLo);
    RUN_TEST(exhaustive);

    GREATEST_MAIN_END();
}
