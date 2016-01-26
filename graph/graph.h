//
//  graph.h
//  graph
//
//  Created by oskimura on 2016/01/18.
//  Copyright (c) 2016年 oskimura. All rights reserved.
//

#ifndef __graph__graph__
#define __graph__graph__

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

#include "list.h"
#include "enqueue.h"

template <typename T1,typename T2>
struct pair {
    T1 fst;
    T2 snd;
    pair(T1 f,T2 s) {
        fst = f;
        snd = s;
    }
};

typedef enum {
    WHITE,
    GRAY,
    BLACK
} Color;

template<typename T>
class Vertex {
public:
    Color color;
    int d;
    T val;
    Vertex *p;
    bool operator== (Vertex<T> v) {
        return this->val == v.val;
    }
    bool operator!=(Vertex<T>v){
        return this->val != v.val;
    }
};

using namespace  std;
template<typename T>
class graph {
    std::map<T,Vertex<T>* > vertex;
    std::map<T, std::vector<Vertex<T>* > > adj;
public:
    graph(std::vector<T>v,std::vector<::pair<T, T> > e){
        for (typename std::vector<T>::iterator iter = v.begin(); iter!=v.end(); iter++) {
            Vertex<T> *x = new Vertex<T>();
            x->val = *iter;
            printf("%c:%p\n",*iter,x);
            
            vertex[*iter] = x;
        }
        printf("\n");
        for (typename std::vector<::pair<T, T> >::iterator ite = e.begin(); ite!=e.end(); ite++) {
            (adj[ite->fst]).push_back(vertex[ite->snd]);
            printf("%c:%p\n",ite->snd,vertex[ite->snd]);
        }
    }
   
    void bfs(T start) {
        queue<Vertex<T>* > q;
        
        for (typename decltype(vertex)::iterator ite = vertex.begin();ite!=vertex.end();ite++) {
                ite->second->color = WHITE;
                ite->second->d = INT16_MAX;
                ite->second->p = NULL;

        }
        vertex[start]->color = GRAY;
        vertex[start]->d = 0;
        vertex[start]->p = NULL;
        q.enqueue(vertex[start]);

        
        
        while (!q.empty()) {
            Vertex<T>* u = q.dequeue();
            
            for(typename std::vector<Vertex<T>* >::iterator ite = adj[u->val].begin();ite!=adj[u->val].end();ite++) {
                Vertex<T>* v  = *ite;
                if(v->color == WHITE) {
                    v->color = GRAY;
                    v->d = u->d+1;
                    v->p = u;
                    q.enqueue(v);
                }
                
            }
            u->color = BLACK;
        }
        
    }
    
    
    
    
};



#endif /* defined(__graph__graph__) */
