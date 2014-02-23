#include <stdio.h>
#include "linkList_plus.h"

linkList_t readin_linkList(FILE *stream)
{
    linkList_t list;
    init_linkList( &list );

    element_t elem = ELEM_INIT_VALUE;
    while( fscanf( stream, "%d", &elem ) != EOF ){
        linkNode_t* pNode = new_linkNode(elem);
        insert_linkNode_after(&list, list.tail, pNode);
        list.tail = pNode;
    }

    return list;
}


void test_linkList()
{
    FILE *fptr = fopen("testData/linkListData.in", "r");

    linkList_t list = readin_linkList(fptr);
    traverse_linkList(list);

    clear_linkList(&list);
    traverse_linkList(list);

    destroy_linkList(&list);

    fclose(fptr);

    return;
}
