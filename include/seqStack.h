#ifndef STACK_H
#define STACK_H

/********************************************************
 * this header defines data structures and functions for
 * manipulating a stack.
 *
 * mainly refer to the data structures in C by Yan Weimin
 * from page 44
********************************************************/

//include seqList.h to use the memory management functions
#include "seqList.h"
#include "common.h"

typedef struct{
    element_t   *base;
    element_t   *top;
    int         size;   //maximum num of elements within allocated memory
} seqStack_t;

void init_seqStack(
        seqStack_t  *sStack );

void destroy_seqStack(
        seqStack_t  *sStack );

void clear_seqStack(
        seqStack_t  *sStack );

bool_t is_seqStack_empty(
        seqStack_t  *sStack );

int seqStack_length(
        seqStack_t  *sStack );

element_t get_seqStack_top(
        seqStack_t  *sStack );

void push_seqStack(
        seqStack_t  *sStack,
        element_t   elem );

element_t pop_seqStack(
        seqStack_t  *sStack );

void traverse_seqStack(
        seqStack_t  *sStack );

#endif
