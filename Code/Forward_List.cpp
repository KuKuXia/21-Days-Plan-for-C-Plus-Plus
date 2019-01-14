//
// Created by LongXiaJun on 2019/1/13 0013.
//

#include "Forward_List.h"


#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;


namespace forward_list {

    // 面试题1：创建一个单链表
    node *create() {
        int i = 0;  // 链表中数据的个数
        node *head, *p, *q;

        int x = 0;
        head = (node *) malloc(sizeof(node));  // 创建头结点


        while (true) {
            cout << "Please input the data: \n";
            scanf("%d", &x);
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

    // 面试题6：编程实现一个链表节点的删除
    // 删除单链表的pos位置的节点，返回链表头指针
    // pos从1开始计算，1表示删除head后的第一个节点
    node *delete_node(node *head, int pos) {
        node *item = nullptr;
        node *p = head->next;

        if (p == nullptr) {
            printf("Link is empyty!\n");
            return nullptr;
        }
        p = search_node(head, pos);
        if (p != nullptr && p->next != nullptr) {
            item = p->next;
            p->next = item->next;
            delete item;
        }
        return head;
    }

    // 面试题7：实现一个单链表的逆置
    node *reverse(node *head) {
        node *p, *q, *r;
        if (head->next == nullptr) {
            return head;
        }

        p = head->next;
        q = p->next;
        p->next = nullptr;

        while (q != nullptr) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;

        }
        head->next = p;
        return head;
    }

    // 面试题8: 寻找单链表的中间元素
    node *search_middle(node *head) {
        int i = 0;
        int j = 0;

        node *current = nullptr;
        node *middle = nullptr;
        current = middle = head->next;
        while (current != nullptr) {
            if (i / 2 > j) {
                j++;
                middle = middle->next;
            }
            i++;
            current = current->next;
        }
        return middle;
    }

    // 面试题9：单链表的正向排序
    node *InsertSort() {
        int data = 0;
        struct node *head = nullptr, *head1, *New, *Cur, *Pre;
        while (true) {
            printf("please input the data:\n");
            scanf("%d", &data);
            if (data == 0) {
                break;
            }
            New = (struct node *) malloc(sizeof(struct node));
            New->data = data;  // 新分配一个node节点
            New->next = nullptr;
            if (head == nullptr) {
                head = New;  //第一次循环时对头节点赋值
                continue;
            }
            if (New->data <= head->data) {
                //head 之前插入节点
                New->next = head;
                head = New;
                continue;
            }
            Cur = head;
            while (New->data > Cur->data && Cur->next != nullptr) {   // 找到需要插入的位置
                Pre = Cur;
                Cur = Cur->next;
            }
            if (Cur->data >= New->data) {   // 位置在中间
                Pre->next = New;       // 把New节点插入到Pre和Cur之间
                New->next = Cur;
            } else    // 位置在末尾
                Cur->next = New;    // 把new节点插入到Cur之后
        }

        head1->next = head;   //返回头结点哨兵
        return head1;
    }

    // 判断链表是否存在环形链表的问题
    // 如果存在， start存放回环开始的节点
    bool IsLoop(node *head, node **start) {
        node *p1 = head, *p2 = head;
        if (head == nullptr || head->next == nullptr) {
            return false;   // head为null或链表为空是返回false
        }
        do {
            p1 = p1->next;     // p1走一步
            p2 = p2->next->next;  // p2走两步
        } while (p2 && p2->next && p1 != p2);

        if (p1 == p2) {
            *start = p1;
            return true;
        } else
            return false;
    }

    void test_IsLoop() {
        bool bLoop = false;
        node *head = create();   // 创建单链表
        node *start = head->next->next->next;  // 使第四个节点为回环开始位置
        start->next = head->next->next;   //回环连接到第3个节点
//        start->next = nullptr;   //回环连接到第3个节点
        node *loopStart = nullptr;
        bLoop = IsLoop(head, &loopStart);
        printf("bLoop = %d\n", bLoop);
        printf("bLoop == loopStart ? %d\n", (loopStart == start));
    }
}