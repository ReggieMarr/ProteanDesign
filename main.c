#include <stdio.h>
#include <stdlib.h>
#include "boatModuleIFDefs.h"
#include "boatModuleIF.h"

int main(int argc, char *argv[]) {

    char *type = argv[1];
    int typeNum = atoi(type);

    moduleIF_t *IF = init_moduleIF(typeNum);

    if (IF) {
        IF->printCfg(IF->ctx);
    }
    else {
        printf("Failed to init module");
    }


    return 0;
}
