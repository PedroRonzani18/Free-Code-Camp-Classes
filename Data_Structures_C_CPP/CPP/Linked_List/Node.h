#pragma once
#include <cstddef>

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node(T data):
        data(data),
        next(NULL)
    {}
};

