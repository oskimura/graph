//
//  main.cpp
//  graph
//
//  Created by oskimura on 2016/01/18.
//  Copyright (c) 2016年 oskimura. All rights reserved.
//

#include <iostream>

#include "string.h"
#include "graph.h"
#include "list.h"
#include "enqueue.h"
#define GTEST_HAS_TR1_TUPLE 0

int main(int argc, const char * argv[]) {
    // insert code here...
    queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    int d = q.dequeue();
    printf("%d¥n",d);
    
    //std::string v("rstuvwxy");
    std::vector< ::pair<char,char> > e;
    //r
    e.push_back(::pair<char,char>('r','s'));
    e.push_back(::pair<char,char>('r','v'));
    
    
    //s
    e.push_back(::pair<char,char>('s','r'));
    e.push_back(::pair<char,char>('s','w'));
    
    //t
    e.push_back(::pair<char,char>('t','u'));
    e.push_back(::pair<char,char>('t','w'));
    e.push_back(::pair<char,char>('t','x'));
    
    //u
    e.push_back(::pair<char,char>('u','t'));
    e.push_back(::pair<char,char>('u','x'));
    e.push_back(::pair<char,char>('u','y'));
    
    //v
    e.push_back(::pair<char,char>('v','r'));
                
    
    //w
    e.push_back(::pair<char,char>('w','s'));
    e.push_back(::pair<char,char>('w','x'));
    e.push_back(::pair<char,char>('w','t'));
    
    //x
    e.push_back(::pair<char,char>('x','t'));
    e.push_back(::pair<char,char>('x','u'));
    e.push_back(::pair<char,char>('x','w'));
    e.push_back(::pair<char,char>('x','y'));
    
    //y
    e.push_back(::pair<char,char>('y','u'));
    e.push_back(::pair<char,char>('y','x'));
    
    string text = "rstuvwxy";
    std::vector<char> v;
    for(typename decltype(text)::iterator c = text.begin(); c!=text.end(); c++ ) {
        v.push_back(*c);
    }
    
    graph<char> g(v,e);

    Vertex<char> s;
    //s.val = 's';
    g.bfs('s');
    std::cout << "Hello, World!\n";
    return 0;
}
