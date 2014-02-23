#ifndef BINTREE_H
#define BINTREE_H

#include "common.h"

typedef struct bTNode{
    element_t       data;
    struct bTNode   *pLchild, *pRchild;
} binTNode;

#endif
