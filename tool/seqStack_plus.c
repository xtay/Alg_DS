#include "seqStack_plus.h"

void test_seqStack()
{
    seqStack_t   stack;
    element_t   elem;
    
    init_seqStack( &stack );

    int i = 0;
    for( i = 0; i < 33; i++ ){
        push_seqStack( &stack, i+1 );
    }

    traverse_seqStack( &stack );
    check_status("");
    
    for( i = 0; i < 28; i++ ){
        elem = pop_seqStack( &stack );
    }

    traverse_seqStack( &stack );

    destroy_seqStack( &stack );

    return;
}
