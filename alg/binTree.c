#include <stdio.h>
#include "binTree.h"

void init_binTree(biTNode_t *bTree)
{
#ifdef DEBUG_F
    if(bTree != NULL){
        raise(WARNING, "trying to initialize a valid btree\n");
        return;
    }
#endif
    return;
}

void destroy_binTree(biTNode_t *bTree)
{
}

void visit_node(biTNode_t *pNode)
{
#ifdef DEBUG_F
    if(pNode == NULL){
        raise(ERROR, "attempt to access an invalid node pointer");
        return;
    }
#endif
    printf("%d\t", pNode->data);
    return;
} 

void preOrder_traverse_binTree(biTNode_t *bTree)
{
    if(bTree!=NULL)
        visit_node(bTree);

    if(bTree!=NULL && bTree->pLchild != NULL)
        preOrder_traverse_binTree(bTree->pLchild);

    if(bTree!=NULL && bTree->pRchild != NULL)
        preOrder_traverse_binTree(bTree->pRchild);

    return;
}

void inOrder_traverse_binTree(biTNode_t *bTree)
{
    if(bTree!=NULL && bTree->pLchild != NULL)
        preOrder_traverse_binTree(bTree->pLchild);

    if(bTree!=NULL)
        visit_node(bTree);

    if(bTree!=NULL && bTree->pRchild != NULL)
        preOrder_traverse_binTree(bTree->pRchild);

    return;
}

void postOrder_traverse_binTree(biTNode_t *bTree)
{
    if(bTree!=NULL && bTree->pLchild != NULL)
        preOrder_traverse_binTree(bTree->pLchild);

    if(bTree!=NULL && bTree->pRchild != NULL)
        preOrder_traverse_binTree(bTree->pRchild);

    if(bTree!=NULL)
        visit_node(bTree);

    return;
}

void levelOrder_traverse_binTree(biTNode_t *bTree)
{
}
