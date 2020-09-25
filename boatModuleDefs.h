#ifndef __TESTMTRDEFS_H_
#define __TESTMTRDEFS_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint8_t  size;
    uint8_t  speed;
} boatCfg_t;

__attribute__((weak)) extern boatCfg_t dfltBoatCfg;

#endif // __TESTMTRDEFS_H_
