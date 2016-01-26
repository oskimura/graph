//
//  hash.cpp
//  graph
//
//  Created by oskimura on 2016/01/24.
//  Copyright (c) 2016年 oskimura. All rights reserved.
//

#include "hash.h"
#include "list.h"

template <typename T>
struct hash_table {
    int size;
    int count;
    ::list<T> l;
};

int hash_function(int size, const char*key)
{
    unsigned int val = 0;
    for(;*key!='\0';key++) {
        val = (val<<3) + *key;
    }
    return val % size;
}