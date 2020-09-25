#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "boatModuleIFDefs.h"
#include "boatModuleIF.h"

moduleIF_t *init_moduleIF(int type) {
    switch (type) {
        case TYPE_CNC:
            if (init_moduleIF_CNC) {
                return init_moduleIF_CNC();
            }
            else {
                printf("failed cnc");
                return 0;
            }
            break;
        case TYPE_BENETEAU:
            if (init_moduleIF_Beneteau) {
                return init_moduleIF_Beneteau();
            }
            else {
                printf("failed ben");
                return 0;
            }
            break;
        default:
            return 0;
    }
}
