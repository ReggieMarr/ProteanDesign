#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "boatModuleIFDefs.h"
#include "boatModuleIF.h"
#include "boatModuleDefs.h"

struct moduleIF_CTX {
    uint8_t size;
    uint8_t speed;
};

static void printCfg(moduleIF_CTX_t ctx) {
    printf("speed %d size %d", ctx->speed, ctx->size);
}

moduleIF_t *init_moduleIF(int type) {
    struct moduleIF_CTX * const CTX = calloc(1, sizeof(struct moduleIF_CTX));

    /* Note that cases need to be made for every type of cfg * every type of instance */
    switch (type) {
        case TYPE_CNC:
            if (&dfltBoatCfg_CNC) {
                CTX->size = dfltBoatCfg_CNC.size;
                CTX->speed = dfltBoatCfg_CNC.speed;
            }
            break;
        case TYPE_BENETEAU:
            if (&dfltBoatCfg_Beneteau) {
                CTX->size = dfltBoatCfg_Beneteau.size;
                CTX->speed = dfltBoatCfg_Beneteau.speed;
            }
            break;
        default:
            return 0;
    }

    moduleIF_t * const IF = (moduleIF_t *) calloc(1, sizeof(moduleIF_t));
    IF->ctx = CTX;
    IF->printCfg = printCfg;
    return IF;
}
