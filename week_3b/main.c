#include "spi_flash.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0xFFFFF, 20 bits
#define FLASH_SIZE 1048576

#define TEST_SETUP() int failures = 0;

#define TEST_REPORT()                                                          \
  if (!failures) {                                                             \
    puts("\nSUCCESS!\n");                                                      \
  } else {                                                                     \
    printf("\nFAIL: %d\n", failures);                                          \
  }

#define TEST(NAME)                                                             \
  switch (NAME##_test()) {                                                     \
  case PASS:                                                                   \
    putchar('.');                                                              \
    break;                                                                     \
  case FAIL:                                                                   \
    failures++;                                                                \
    putchar('F');                                                              \
    break;                                                                     \
  case SKIP:                                                                   \
    putchar('S');                                                              \
    break;                                                                     \
  }

typedef enum result { FAIL, PASS, SKIP } result_t;

// Test 1 - write then read back value from chip
result_t write_read_test() {
  uint8_t input[0xFFFF];
  uint8_t output[0xFFFF];
  memset(input, 0xAA, sizeof(input));

  sFLASH_WriteBuffer(input, 0, sizeof(input)); // write test pattern 0xAA
  sFLASH_ReadBuffer(output, 0, sizeof(output));

  for (int i = 0; i < sizeof(output); i++)
    if (output[i] != 0xAA)
      return FAIL;
  return PASS;
}

// Test 2 - erase sector then read back all 1s in sector
result_t erase_sector_test() {
  uint8_t input[0xFFFF];
  uint8_t output[0xFFFF];
  memset(input, 0xAA, sizeof(input));
  sFLASH_WriteBuffer(input, 0, sizeof(input));

  sFLASH_EraseSector(0);

  sFLASH_ReadBuffer(output, 0, 0xFFFF);
  for (int i = 0; i < 0x1000; i++)
    if (output[i] != 0xFF)
      return FAIL;
  if (output[0x1000] == 0xFF)
    return FAIL;
  return PASS;
}

// Test 3 - erase whole chip
result_t erase_chip_test() {
  uint8_t input[0xFFFF];
  uint8_t output[0xFFFF];
  memset(input, 0xAA, sizeof(input));
  sFLASH_WriteBuffer(input, 0, sizeof(input));

  sFLASH_EraseBulk();

  sFLASH_ReadBuffer(output, 0, 0xFFFF);
  for (int i = 0; i < 0x1000; i++)
    if (output[i] != 0xFF)
      return FAIL;
  return PASS;
}

int main(int argc, char **argv) {
  TEST_SETUP();
  TEST(write_read);
  TEST(erase_sector);
  TEST(erase_chip);
  TEST_REPORT();

  return 0;
}
