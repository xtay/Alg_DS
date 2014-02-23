#ifndef LINKLIST_H
#define LINKLIST_H

/********************************************************
 * this header defines data structures and functions for
 * manipulating the link list.
 *
 * refer to the data structures in C by Yan Weimin
 * from page 28
********************************************************/

#include "common.h"

typedef struct lNode{
    element_t       data;
    struct lNode    *next;
} linkNode_t;

typedef struct {
    linkNode_t  *head;
    linkNode_t  *tail;
    int length;
} linkList_t;


//warning: this function will call malloc to allocate space for a linkNode.
linkNode_t* new_linkNode(
        element_t   elem );

//note: this function is for make_linkNode().
void free_linkNode(
        linkNode_t  *pNode );

void init_linkList( 
        linkList_t  *pList );

linkNode_t* prior_linkNode_pos(
        linkList_t  *pList,
        linkNode_t  *pNode );

linkNode_t* next_linkNode_pos(
        linkNode_t  *pNode );

void insert_linkNode_after(
        linkList_t  *pList,
        linkNode_t  *pRef,
        linkNode_t  *pNew );

void insert_linkNode_before(
        linkList_t  *pList,
        linkNode_t  *pRef,
        linkNode_t  *pNew );

void remove_linkNode(
        linkList_t  *pList,
        linkNode_t  *pNode );

void clear_linkList(
        linkList_t  *pList );

void destroy_linkList(
        linkList_t  *pList );

linkNode_t* locate_linkNode(
        linkList_t  *pList, 
        int         index );

void traverse_linkList(
        linkList_t list);

linkNode_t* locate_linkList_elem(
        linkList_t  *pList,
        element_t   elem );


#endif
