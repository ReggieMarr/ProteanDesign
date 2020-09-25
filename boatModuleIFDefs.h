#ifndef __MODULEIFDEFS_H_
#define __MODULEIFDEFS_H_

typedef struct moduleIF_CTX *moduleIF_CTX_t;

typedef struct {
    void (*printCfg)(moduleIF_CTX_t ctx);

    moduleIF_CTX_t ctx;
} moduleIF_t;

__attribute__((weak)) extern moduleIF_t *init_moduleIF_CNC();
__attribute__((weak)) extern moduleIF_t *init_moduleIF_Beneteau();

#endif // __MODULEIFDEFS_H_
