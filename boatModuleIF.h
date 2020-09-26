#ifndef __TESTMODULEIF_H_
#define __TESTMODULEIF_H_
#include "boatModuleIFDefs.h"

enum {
    TYPE_CNC = 0,
    TYPE_BENETEAU,
};

moduleIF_t *init_moduleIF(int type);

#endif // __TESTMODULEIF_H_
