//
// Created by LongXiaJun on 2019/1/13 0013.
//
#ifndef CODE_FORWARD_LIST_H
#define CODE_FORWARD_LIST_H

#endif //CODE_FORWARD_LIST_H

namespace forward_list {
    // 定义单链表
    typedef struct node {
        int data;
        node *next;
    } node;

    node *delete_node(node *head, int pos);

    node *create();

    int length(node *head);

    void print(node *head);

    node *insert_node(node *head, int pos, int data);

    node *search_node(node *head, int pos);

    node *reverse(node *head);

    node *search_middle(node *head);

    node *InsertSort();

    void test_IsLoop();
}





































