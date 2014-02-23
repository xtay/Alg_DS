#include "seqList_plus.h"

void test_seqList()
{
    seqList_t   list;
    element_t   elem;
    
    init_seqList( &list );

    int i = 0;
    for( i = 0; i < 100; i++ ){
        insert_seqList_elem( &list, 0, i+1 );
    }

    traverse_seqList( list );
    check_status("");
    
    for( i = 0; i < 84; i++ ){
        elem = delete_seqList_elem( &list, list.length-1 );
    }

    traverse_seqList( list );

    destroy_seqList( &list );

    return;
}
