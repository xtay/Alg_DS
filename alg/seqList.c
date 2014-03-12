/**************************************************
 * this file implements functions defined in the
 * seqList.h
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "seqList.h"


void init_seqList( 

        seqList_t *pList )
{
    pList->aElem = (element_t *)malloc(LIST_INIT_SIZE * sizeof(element_t));

    if( pList->aElem == NULL ){
        raise(ERROR, "failed to allocate memory when initialize seqlist\n");
        return;
    }

    pList->length = 0;
    pList->size   = LIST_INIT_SIZE;

    return;
}


void destroy_seqList( 
        
        seqList_t   *pList )
{
    free(pList->aElem);
    //set length to ILLEGAL_LENGTH so that any attempt to
    //reuse this list will not work.
    pList->length = ILLEGAL_LENGTH;
    pList->size   = ILLEGAL_LENGTH;

    return;
}


void clear_seqList( 

        seqList_t   *pList )
{
    pList->length = 0;
    //uncomment the line below if nessecery...
    //memset(pList->aElem, '\0', pList->size * sizeof(element_t));

    return;
}

element_t *expand_memory(
        element_t   *aElem,
        int         curSize )
{
    element_t *result;
    result = (element_t*) malloc( EXPAND_FACTOR * curSize * sizeof(element_t) );

    if( aElem == NULL ){
        raise(ERROR, "failed to allocate memory when insert new element\n");
        return NULL;
    } 

    //bug #2, fixed
    memcpy(result, aElem, curSize * sizeof(element_t));

    free(aElem);

    return result;
}

element_t *shrink_memory(
        element_t   *aElem,
        int         curSize )
{
    element_t *result;
    result = (element_t*) malloc( curSize / EXPAND_FACTOR * sizeof(element_t) );

    if( aElem == NULL ){
        raise(ERROR, "failed to allocate memory when delete an element\n");
        return NULL;
    } 

    //bug #2, fixed
    memcpy(result, aElem, curSize / SHRINK_FACTOR * sizeof(element_t));

    free(aElem);

    return result;
}

void insert_seqList_elem( 

        seqList_t   *pList,
        int         index, 
        element_t   elem )
{

#ifdef DEBUG_F
    //check if the seqlist is still available to use
    //bug #1, fixed
    if( pList->length < 0 || pList->size <= 0 ){
        raise(ERROR, "seqlist is not initialized\n");
        return;
    }

    //check if the index is in range
    if( index < 0 || index > pList->length ){
        raise(ERROR, "insert index is out of range!\n");
        return;
    }
#endif
    
    //allocate new memory space if necessary
    //better performance could be achieved.
    element_t *pOldElems = NULL;

    if( pList->length == pList->size ){
        pList->aElem = expand_memory( pList->aElem, pList->size );
        pList->size *= EXPAND_FACTOR;
    }

    //insert new element finally
    int i = 0;
    element_t *aElem = pList->aElem;

    for( i = pList->length; i > index ; i-- ){
        aElem[i] = aElem[i-1];
    }

    aElem[index] = elem;

    pList->length += 1;

    return;
}


element_t delete_seqList_elem( 

        seqList_t   *pList, 
        int         index )
{

    element_t result = ELEM_INIT_VALUE;

#ifdef DEBUG_F
    //check if the seqlist is still available to use
    //bug #1, fixed, length is legal to be 0
    if( pList->length < 0 || pList->size <= 0 ){ 
        raise(ERROR, "seqlist is not initialized\n");
        return result;
    }

    //check if the index is in range
    if( index < 0 || index > pList->length ){
        raise(ERROR, "insert index is out of range!\n");
        return result;
    }
#endif

    //allocate new memory space if necessary
    //better performance could be achieved.
    element_t *pOldElems = NULL;

    if( pList->length <= pList->size / SHRINK_FACTOR ){
        pList->aElem = shrink_memory( pList->aElem, pList->size );
        pList->size /= EXPAND_FACTOR;
    }

    //delete new element finally
    int i = 0;
    element_t *aElem = pList->aElem;

    result = aElem[index];

    for( i = index; i < pList->length - 1 ; i++ ){
        aElem[i] = aElem[i+1];
    }

    pList->length -= 1;

    return result;
}


int locate_seqList_elem( 

        seqList_t   list, 
        element_t   e )
{
    int i = 0;

    return 0;
}


void traverse_seqList(
        seqList_t   list )
{
    int i = 0;

    printf("this list has %d elements\n", list.length);
    printf("%lu*%d memory has been allocated for this list\n",
            sizeof(element_t),
            list.size);

    for( i = 0; i < list.length; i++ ){
        if( i%10 == 0 ) printf("\n");
        printf("%d\t", list.aElem[i]);
    }

    printf("\n\n");

    return;
}

//these two functions will be implemented later 
//since it needs to sort the list
void merge_seqList( 

        seqList_t   la, 
        seqList_t   lb, 
        seqList_t   *pLc )
{
    return;
}


void union_seqList( 

        seqList_t   la, 
        seqList_t   lb, 
        seqList_t   *pLc )
{
    return;
}

