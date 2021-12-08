#include "spi_flash.h"
#include <assert.h>
#include <string.h>

#define CHIP_SIZE 1048576U
#define BLOCK_SIZE 65536U
#define SECTOR_SIZE 4096U
#define NOT_IMPLEMENTED()                                                      \
  {                                                                            \
    char *_;                                                                   \
    assert((_ = "This function is not implemented.", 1 == 0));                 \
  }

// The "flash memory"
static uint8_t memory[CHIP_SIZE];

/*------------------------------------------------------------------------------
 * NOTES:
 *
 * There are 16 blocks (each 64K) comprising the memory. Within each block
 * there's 16 sectors (each 4K). Within each 4K sector, there's 16 pages (each
 * 256 bytes)
 *
 * - There's 4096 pages of 256 bytes each (up to 256 bytes can be programmed at
 *   a time)
 * - Pages can be erased in groups of
 *   - 16 (4K sector erase)
 *   - 128 (32K block erase)
 *   - 256 (64K block erase)
 *   - entire chip
 *----------------------------------------------------------------------------*/

/* Actual API ----------------------------------------------------------------*/

/* High layer functions  */
void sFLASH_DeInit(void) { NOT_IMPLEMENTED(); }
void sFLASH_Init(void) { NOT_IMPLEMENTED(); }
void sFLASH_WritePage(uint8_t *pBuffer, uint32_t WriteAddr,
                      uint16_t NumByteToWrite) {
  NOT_IMPLEMENTED();
}

uint32_t sFLASH_ReadID(void) { NOT_IMPLEMENTED() }
void sFLASH_StartReadSequence(uint32_t ReadAddr) { NOT_IMPLEMENTED(); }

/* Low layer functions */
uint8_t sFLASH_ReadByte(void) { NOT_IMPLEMENTED(); }
uint8_t sFLASH_SendByte(uint8_t byte) { NOT_IMPLEMENTED(); }
uint16_t sFLASH_SendHalfWord(uint16_t HalfWord) { NOT_IMPLEMENTED(); }
void sFLASH_WriteEnable(void) { NOT_IMPLEMENTED(); }
void sFLASH_WaitForWriteEnd(void) { NOT_IMPLEMENTED(); }

/* Simulator API -------------------------------------------------------------*/

void sFLASH_EraseSector(uint32_t SectorAddr) {
  memset(memory + SectorAddr, 0xFF, SECTOR_SIZE);
}

void sFLASH_EraseBulk(void) { memset(memory, 0xFF, CHIP_SIZE); }

void sFLASH_ReadBuffer(uint8_t *pBuffer, uint32_t ReadAddr,
                       uint16_t NumByteToRead) {
  memcpy(pBuffer, memory + ReadAddr, NumByteToRead);
}

void sFLASH_WriteBuffer(uint8_t *pBuffer, uint32_t WriteAddr,
                        uint16_t NumByteToWrite) {
  memcpy(memory + WriteAddr, pBuffer, NumByteToWrite);
}
