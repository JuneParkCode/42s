#include <stdio.h>
#include "array_list.h"

int cmp(int a, int b)
{
    return (a-b);
}

int main(void)
{
    t_arrlist   *lst;

    lst = arrlst_new_list(100);
    // push_pop (BACK) TEST
    printf("PUSH POP BACK TEST\n");
    for (int i = 0; i < 10; ++i)
    {
        arrlst_push_back(lst, i);
        printf("push_back : %d -> %d\n", i, lst -> items[i]);
    }
    while (!arrlst_is_empty(lst))
    {
        printf("%d\n", arrlst_pop_back(lst));
    }
    // push_pop (FRONT) TEST
    printf("PUSH POP FRONT TEST\n");
    for (int i = 0; i < 10; ++i)
    {
        arrlst_push_front(lst, i);
        printf("push_front : %d -> %d\n", i, lst -> items[i]);
    }
    while (!arrlst_is_empty(lst))
    {
        printf("%d\n", arrlst_pop_back(lst));
    }
    // get_size test
    printf("GET SIZE TEST\n");
    for (int i = 0; i < 10; ++i)
    {
        arrlst_push_front(lst, i);
        printf("push_front : %d -> %d\n", i, lst -> items[i]);
        printf("SIZE : %d\n", arrlst_get_size(lst));
    }
    
    t_arrlist   *testList;
    testList = arrlst_new_list(10);
    printf("is Empty? %d\n", arrlst_is_empty(testList));
    printf("is FULL? %d\n", arrlst_is_full(testList));
    for (int i = 0; i < 10; ++i)
    {
        arrlst_push_front(testList, i);
        printf("push_front : %d -> %d\n", i, testList -> items[i]);
        printf("SIZE : %d\n", arrlst_get_size(testList));
    }

    printf("is Empty? %d\n", arrlst_is_empty(testList));
    printf("is FULL? %d\n", arrlst_is_full(testList));
    for (int i = 0; i < 3; ++i)
    {
        printf("POP_FRONT %d\n", arrlst_pop_front(testList));
        if (i != 2)
            arrlst_push_back(testList, i);
    }
    arrlst_push_front(testList, 13);
    printf(" idx is %d\n", arrlst_find_item(testList, 2, cmp));
}