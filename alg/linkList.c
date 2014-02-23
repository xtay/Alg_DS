/**************************************************
 * this file implements functions defined in the
 * seqList.h
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linkList.h"


//warning: this function will call malloc to allocate space for a linkNode.
linkNode_t* new_linkNode(
        element_t   elem )
{
    linkNode_t *pNode = (linkNode_t *)malloc(sizeof(linkNode_t));

    if( pNode == NULL ){
        raise(ERROR, "failed to allocate memory for a single linkNode\n");
        return NULL;
    }

    pNode->data = elem;
    pNode->next = NULL;

    return pNode;
}


//warning: this function is for make_linkNode().
//and this function would NOT set pNode NULL...
void free_linkNode(
        linkNode_t  *pNode )
{
    free(pNode);

    return;
}


void init_linkList( 
        linkList_t  *pList )
{
    //make a header node, which will not be used to hold DATA
    linkNode_t* pHeader = new_linkNode(ELEM_INIT_VALUE);

    pList->head   = pHeader;
    pList->tail   = pHeader;
    pList->length = 0;

    return;
}


linkNode_t* prior_linkNode_pos(
        linkList_t  *pList,
        linkNode_t  *pNode )
{
    linkNode_t* p = NULL;

#ifdef DEBUG_F
    //actually, this is a good way to find the TAIL of the list.
    if( pNode == NULL ){
        raise(ERROR, "pNode is NULL! unable to find it's prior...\n");
        return NULL;
    }
    if( pNode == pList->head ){
        raise(ERROR, "pNode is the list header! it has no prior!\n");
        return NULL;
    }
#endif

    p = pList->head;
    while( p != NULL && p->next != pNode ){
        p = p->next;
    }

    return p;
}


linkNode_t* next_linkNode_pos(
        linkNode_t  *pNode )
{
#ifdef DEBUG_F
    if( pNode == NULL ){
        raise(ERROR, "pNode is NULL! unable to find it's next...\n");
        return NULL;
    }
#endif

    linkNode_t* p = pNode->next;

    return p;
}


void insert_linkNode_after(
        linkList_t  *pList,
        linkNode_t  *pRef,
        linkNode_t  *pNew )
{
#ifdef DEBUG_F
    //note that this check would significantly slow down the performance
    linkNode_t *p = NULL;
    if( pRef != pList->head ){
        //verify that pRef is in the pList by finding its prior node
        p = prior_linkNode_pos(pList, pRef);
        if( p == NULL ){
            raise(ERROR, "pRef is not in the pList in which you wanna insert.\n");
            return;
        }
    }
#endif

    pNew->next = pRef->next;
    pRef->next = pNew;

    pList->length++;
    if( pNew->next == NULL )
        pList->tail = pNew;

    return;
}


void insert_linkNode_before(
        linkList_t  *pList,
        linkNode_t  *pRef,
        linkNode_t  *pNew )
{
#ifdef DEBUG_F
    if( pRef == pList->head ){
        raise(ERROR, "you cannot insert a node before the list header!\n");
        return;
    }
#endif

    linkNode_t *pRefPrior = prior_linkNode_pos(pList, pRef);

    insert_linkNode_after(pList, pRefPrior, pNew);

    return;
}


//as to the insert_linkNode function doesn't allocate memory, this
//function doesn't free the node, one should call the free_linkNode...
//to free the linkNode explicitly and manually.
void remove_linkNode(
        linkList_t  *pList,
        linkNode_t  *pNode )
{
    linkNode_t* pNodePrior = prior_linkNode_pos(pList, pNode);

#ifdef DEBUG_F
    if( pNodePrior == NULL ){
        raise(ERROR, "could not remove the node, since it has no prior...\n");
        return;
    }
#endif
    
    pNodePrior->next = pNode->next;

    pList->length--;
    if( pNodePrior->next == NULL )
        pList->tail = pNodePrior;

    return;
}


void clear_linkList(
        linkList_t  *pList )
{
    linkNode_t  *pFirst = pList->head->next;

#ifdef DEBUG_F
    if( pList->head == NULL || pList->length == 0 ){
        raise(WARNING, "this list has nothing to clear!");
        return;
    }
#endif

    while( pList->length > 0 ){
        pFirst = pList->head->next;
        remove_linkNode(pList, pFirst);
        free_linkNode(pFirst);
    }

    return;
}


void destroy_linkList(
        linkList_t  *pList )
{
    clear_linkList(pList);

    free_linkNode(pList->head);

    pList->head     = NULL;
    pList->tail     = NULL;
    pList->length   = ILLEGAL_LENGTH;

    return;
}


void traverse_linkList(
        linkList_t list)
{
    int i = 0;
    linkNode_t *p = list.head;

    printf("this list has %d elements\n", list.length);

    for( i = 0; i < list.length; i++ ){
        if( i%10 == 0 ) printf("\n");
        p = p->next;
        printf("%d\t", p->data);
    }

    printf("\n\n");

    return;
}


linkNode_t* locate_linkNode(
        linkList_t  *pList, 
        int         index )
{
    linkNode_t *nodePos = NULL;

    return nodePos;
}


linkNode_t* locate_linkList_elem(
        linkList_t  *pList,
        element_t   elem )
{
    linkNode_t *nodePos = NULL;

    return nodePos;
}


