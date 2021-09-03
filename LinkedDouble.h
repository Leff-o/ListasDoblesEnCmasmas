//
// Created by Biss on 3/09/2021.
//
#ifndef LINKDOUBLE_LINKEDDOUBLE_H
#define LINKDOUBLE_LINKEDDOUBLE_H

#include <vector>
#include <string>

#include "Node.h"
using namespace std;
template <class T>
class LinkedDouble {

public:
    LinkedDouble();

    bool isEmpty();

    void addNodeFirst( T );

    void addNodeLast( T );

    void addNodeAfterTo(Node<T>*, T);

    void addNodeBeforeTo(Node<T>*, T);

    void addNodeSorted(T);

    T deleteNode(Node<T> *node);

    Node<T>* findNode(std::string);

    T *getObject(int index);

    T* findInfo(std::string);

    std::vector<T> getList(bool);

    virtual ~LinkedDouble();

private:
    Node<T>* head;
    Node<T>* last;
};


#endif //LINKDOUBLE_LINKEDDOUBLE_H