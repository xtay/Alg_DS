#ifndef SEQLIST_H
#define SEQLIST_H

/********************************************************
 * this header defines data structures and functions for
 * manipulating the sequenced list.
 *
 * mainly refer to the data structures in C by Yan Weimin
 * from page 22
 *
 * insert and delete elements from the table involves
 * some memory management, and these two functions
 * refer to CLRS from page 464
********************************************************/

#include "common.h"

#define LIST_INIT_SIZE 32

//actually this increment is not need in CLRS
#define LIST_INCREMENT 10 

//the factor when allocating new memory for insertion or deletion
#define EXPAND_FACTOR 2
#define SHRINK_FACTOR (EXPAND_FACTOR * EXPAND_FACTOR)

typedef struct{
    element_t   *aElem;
    int         length; //num of elements existed in this list;
    int         size;   //maximum num of elements within allocated memory
} seqList_t;

void init_seqList( 
        seqList_t   *pList );

void destroy_seqList(
        seqList_t   *pList );

void clear_seqList( 
        seqList_t   *pList ); 

element_t *expand_memory(
        element_t   *aElem,
        int         curSize );

element_t *shrink_memory(
        element_t   *aElem,
        int         curSize );

void insert_seqList_elem( 
        seqList_t   *pList, 
        int         index, 
        element_t   elem ); 

element_t delete_seqList_elem( 
        seqList_t   *pList, 
        int         index );

int locate_seqList_elem( 
        seqList_t   list, 
        element_t   elem );

void traverse_seqList(
        seqList_t   list );

//these two functions will be implemented later 
//since it needs to sort the list
void merge_seqList( 
        seqList_t   la, 
        seqList_t   lb, 
        seqList_t   *pLc );

void union_seqList( 
        seqList_t   la, 
        seqList_t   lb, 
        seqList_t   *pLc );

#endif
