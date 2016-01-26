//
//  enqueue.h
//  graph
//
//  Created by oskimura on 2016/01/18.
//  Copyright (c) 2016年 oskimura. All rights reserved.
//

#ifndef graph_enqueue_h
#define graph_enqueue_h

#include<vector>

using namespace std;

template <class T>
struct queue
{
    vector<T> q;
    
    int tail;
    int head;
public:
    queue()
    {
        
        q.resize(512);
        tail = head = 0;
    }
    void enqueue(T e)
    {
        q[tail] = e;
        tail++;
    }
    T dequeue()
    {
        T x;
        if (head != tail) {
            x = q[head];
            head++;
            
        }
        else {
            head = tail = 0;
            throw "error ";
        }
        return x;        
    }
    bool empty()
    {
        if (tail==head) {
            return true;
        }
        return false;
    }
};


#endif
