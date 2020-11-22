#ifndef bc
#define bc

#ifndef standard
#define standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regle.h"
#endif

typedef struct elemRegle{
    Regle rgl;
    struct elemRegle* suiv;
}ElemRegle;

typedef ElemRegle* BC;

#endif