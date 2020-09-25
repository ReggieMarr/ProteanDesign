#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "boatModuleIFDefs.h"
#include "boatModule.h"
#include "boatModuleDefs.h"

struct moduleIF_CTX {
    uint8_t size;
    uint8_t speed;
};

static void printCfg(moduleIF_CTX_t ctx) {
    printf("speed %d size %d", ctx->speed, ctx->size);
}

moduleIF_t *init_moduleIF() {
    struct moduleIF_CTX * const CTX = calloc(1, sizeof(struct moduleIF_CTX));

    if (&dfltBoatCfg) {
        CTX->size = dfltBoatCfg.size;
        CTX->speed = dfltBoatCfg.speed;
    }

    moduleIF_t * const IF = (moduleIF_t *) calloc(1, sizeof(moduleIF_t));
    IF->ctx = CTX;
    IF->printCfg = printCfg;
    return IF;
}
