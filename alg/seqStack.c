/**************************************************
 * this file implements functions defined in the
 * seqStack.h
 * just to be clear... this stack grows upward!
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqStack.h"


void init_seqStack(
        seqStack_t  *pStack )
{
    pStack->base = (element_t *)malloc(LIST_INIT_SIZE * sizeof(element_t));

    if( pStack->base == NULL ){
        raise(ERROR, "failed to allocate memory while initializing seqStack\n");
        return;
    }
 
    pStack->top = NULL;
    pStack->size = LIST_INIT_SIZE;

    return;
}


void destroy_seqStack(
        seqStack_t  *pStack )
{
    free(pStack->base);

    pStack->top = NULL;
    pStack->size = 0;
    return;
}


void clear_seqStack(
        seqStack_t  *pStack )
{
    pStack->top = NULL;
    return;
}


bool_t is_seqStack_empty(
        seqStack_t  *pStack )
{
    return pStack->top == NULL;
}


int seqStack_length(
        seqStack_t  *pStack )
{
    if( pStack->top == NULL )
        return 0;

    return (pStack->top) - (pStack->base) + 1;
}


element_t get_seqStack_top(
        seqStack_t  *pStack )
{
    if( pStack->top == NULL ){
        raise(WARNING, "stack is empty, no top is available\n");
        return ELEM_INIT_VALUE;
    }

    return *(pStack->top);
}


void push_seqStack(
        seqStack_t  *pStack,
        element_t   elem )
{
#ifdef DEBUG_F
    if(pStack->size == 0){
        raise(ERROR, "cannot push an element into an uninitialized stack");
        return;
    }
#endif

    if( seqStack_length(pStack) == pStack->size ){
        pStack->base = expand_memory( pStack->base, pStack->size );
        pStack->top = pStack->base + pStack->size - 1;// bug #1
        pStack->size *= EXPAND_FACTOR;
    }

    if(pStack->top == NULL){
        pStack->top = pStack->base;
    }
    else{
        (pStack->top)++;
    }

    *(pStack->top) = elem;

    return;
}


element_t pop_seqStack(
        seqStack_t  *pStack )
{
#ifdef DEBUG_F
    if( pStack->size == 0 ){
        raise(ERROR, "cannot pop an element from an uninitialized stack");
        return ELEM_INIT_VALUE;
    }
#endif

    if( LIST_INIT_SIZE < pStack->size &&
            seqStack_length(pStack) <= pStack->size / SHRINK_FACTOR ){
        pStack->base = shrink_memory( pStack->base, pStack->size );
        pStack->top = pStack->base + pStack->size/SHRINK_FACTOR-1;// bug #1
        pStack->size /= EXPAND_FACTOR;
    }

    element_t popElem = get_seqStack_top(pStack);

    if( pStack->top == pStack->base ){
        pStack->top = NULL;
    }
    else{
        (pStack->top)--;
    }

    return popElem;
}


void traverse_seqStack(
        seqStack_t  *pStack )
{
    printf("stack size:\t%d\n", pStack->size);
    printf("stack length:\t%d\n", seqStack_length(pStack));

    if(pStack->size == 0){
        printf("this stack is uninitialized!\n");
        return;
    }
    if( pStack->top == NULL ){
        printf("this stack is empty!\n");
        return;
    }

    int i;
    element_t *pElem;
    for( i = 0, pElem = pStack->base; pElem != pStack->top; i++, pElem++ ){
        if( i%10 == 0 ) printf("\n");
        printf("%d\t", *pElem);
    }
    if( i%10 == 0 ) printf("\n");
    printf("%d\t", *pElem);

    printf("\n\n");

    return;
}


