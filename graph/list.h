//
//  list.h
//  graph
//
//  Created by oskimura on 2016/01/18.
//  Copyright (c) 2016年 oskimura. All rights reserved.
//

#ifndef graph_list_h
#define graph_list_h

#include <stdio.h>

template  <typename T>
class list
{
    struct node {
        node *next;
        node *prev;
        T val;
    };
    node* head;
    
public:
    list()
    {
        head = NULL;
    };
    void insert(T e)
    {
        node* n = new node();
        n->val = e;
        n->next = head;
        if (head!=NULL) {
            head->prev = n;
        }
        n->prev=NULL;
        head = n;
    };
    
    void del(T e)
    {
        node *x = head;
        while (x) {
            if (e == x->val) {
                if (x->next!=NULL) {
                    x->next->prev = x->prev;
                }
                if (x->prev!=NULL) {
                    x->prev->next = x->next;
                    
                }
                else {
                    head = x->next;
                }
            }
            x = x->next;
        }
    }
    node* find(T e)
    {
        node* x = head;
        while (x) {
            if (e==x->val) {
                return x;
            }
            x = x->next;
        }
        return NULL;
    }
    void print() 
    {
        node *x = head;
        while(x) {
            printf("%d",x->val);
            x = x->next;
        }
    }
};
//
//int main() {
//    list<char> l;
//    l.insert('a');  
//    l.print();
//    l.del('a');
//    l.print();
//    l.insert('a');  
//    l.print();
//    l.insert('b');  
//    l.print();
//    l.del('a');
//    return 0;
//}

#endif
