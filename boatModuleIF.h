#ifndef __TESTMODULEIF_H_
#define __TESTMODULEIF_H_

enum {
    TYPE_CNC = 0,
    TYPE_BENETEAU,
};

typedef struct moduleIF_CTX *moduleIF_CTX_t;

typedef struct {
    void (*printCfg)(moduleIF_CTX_t ctx);

    moduleIF_CTX_t ctx;
} moduleIF_t;

moduleIF_t *init_moduleIF(int type);

#endif // __TESTMODULEIF_H_
