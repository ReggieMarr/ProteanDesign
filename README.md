# The Generated module interface

## Summary

This repo aims to explore ways of creating an interface which can have components swapped out and a flexible configuration.

## Example

The sample can be run by the following:

 ``` shell
 make -B //Must use -B to ensure that all components are recompiled
 ./getBoatCfg 0
 ```

The executable can be run with the arguments 0 or 1 to get one of two configurations.

## Background

This is achieved by utlizing a couple neat C tricks:

### Opaque Pointers
Opaque pointers are used to share pointers of some typedef which we want to remain private in one scope but passed as an argument in another (e.g. context pointers)

This is done using the following

In boatModuleIFDefs.h
``` c++
//Incomplete definition context in the header
typedef struct moduleIF_CTX *moduleIF_CTX_t;

```

In boatModule.c
``` c++
//Full Definition in the source

struct moduleIF_CTX {
    uint8_t size;
    uint8_t speed;
};

//Note callocing for this type is slightly different
struct moduleIF_CTX * const CTX = calloc(1, sizeof(struct moduleIF_CTX));

```

### Weak Symbols
Weak symbols are used where we have some symbol which may or may not be defined. This is useful when we want to use a variable as a proxy for determining if some source file is included in our build (at runtime). Or when we have some sort of generic context that contains members that may be applicable in some instances and not in others.

Example Given:

In boatModuleDefs.h
``` c++
//Some config that may or may not be needed in creating an instance of a generic interface
//We declare the symbol but do not define it. The weak attribute allows this to compile regardless of if its defined
__attribute__((weak)) extern boatCfg_t dfltBoatCfg;
```

In cnc.c
``` c++
#include "boatModuleDefs.h"

//We would define it in some file 
boatCfg_t dfltBoatCfg = {
    .size = 10,
    .speed= 10,
};

```

In boatModule.c
``` c++
//If we did not compile/link with cnc.c then this global would not be defined and
//would have no memory address allocated for it.
if (&dfltBoatCfg) {
    CTX->size = dfltBoatCfg.size;
    CTX->speed = dfltBoatCfg.speed;
}
```
