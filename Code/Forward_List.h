//
// Created by LongXiaJun on 2019/1/13 0013.
//

#include <cstdlib>
#include <iostream>
#include <cstdio>

#ifndef CODE_FORWARD_LIST_H
#define CODE_FORWARD_LIST_H

#endif //CODE_FORWARD_LIST_H

using namespace std;


namespace forward_list {
    // 定义单链表
    typedef struct node {
        int data;
        node *next;
    } node;

    // 面试题1：创建一个单链表
    node *create() {
        int i = 0;  // 链表中数据的个数
        node *head, *p, *q;

        int x = 0;
        head = (node *) malloc(sizeof(node));  // 创建头结点


        while (true) {
            cout << "Please input the data: \n";
            cin >> x;
            if (x == 0) break;

            p = (node *) malloc(sizeof(node));
            p->data = x;
            if (++i == 1) {   //链表只含有一个元素
                head->next = p;  // 连接到head的后面
            } else {
                q->next = p;
            }
            q = p;

        }
        q->next = nullptr;  // 将最后一个结点指向nullptr
        return head;
    }

    //面试题2：编程实现一个单链表的测长
    int length(node *head) {
        int len = 0;
        node *p;
        p = head->next;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }

    // 面试题3：编程实现一个单链表的打印
    void print(node *head) {
        node *p;
        int index = 0;
        if (head->next == nullptr) {  // 链表为空
            cout << "Link is empty!\n";
            return;
        }
        p = head->next;
        while (p != nullptr) {   // 遍历链表
            printf("The %dth node is: %d\n", ++index, p->data);
            p = p->next;
        }
    }

    // 面试题4：编程实现一个单链表节点的查找
    // pos:从0开始，0返回head节点
    node *search_node(node *head, int pos) {
        node *p = head->next;
        if (pos < 0) // pos位置不正确
        {
            printf("incorrect position to search node!\n");
            return nullptr;
        }
        if (pos == 0) {  // 在head位置，返回head
            return head;
        }
        if (p == nullptr) {
            printf("Link is empty!\n"); // 链表为空
            return nullptr;
        }
        while (--pos) {
            if ((p = p->next) == nullptr) {
                printf("incorrect position to search node!\n");
                break;
            }
        }
        return p;
    }

    // 面试题5：编程实现一个单链表节点的插入
    node *insert_node(node *head, int pos, int data) {
        node *item = nullptr;
        node *p;

        item = (node *) malloc(sizeof(node));
        item->data = data;
        if (pos == 0) {  // 插入链表头后面
            item->next = head->next;   // head后面是item
            head->next = item;
            return head;
        }
        p = search_node(head, pos);    // 获得位置pos的节点指针
        if (p != nullptr) {
            item->next = p->next;      // item指向原pos节点的后一个节点
            p->next = item;            // 把item插入到pos的后面
        }
        return head;
    }
}





































