#ifndef BINTREE_H
#define BINTREE_H

#include "common.h"

typedef struct biTNode{
    element_t       data;
    struct biTNode   *pLchild, *pRchild;
} biTNode_t;

void init_binTree(biTNode_t *bTree);

void destroy_binTree(biTNode_t *bTree);

void preOrder_traverse_binTree(biTNode_t *bTree);

void inOrder_traverse_binTree(biTNode_t *bTree);

void postOrder_traverse_binTree(biTNode_t *bTree);

void levelOrder_traverse_binTree(biTNode_t *bTree);

#endif
