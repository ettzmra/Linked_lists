//
// Created by mel on 28.01.2020.
//

#ifndef LINKED_LISTS_NODE_CLASS_H
#define LINKED_LISTS_NODE_CLASS_H

template <typename T>
struct node {
    T data; // at class scope, variable templates need to be declared static.
    node *next;
    node *previous;
};

template <typename T>

class doubleLinkedList {
public:
    node<T> *head;
    node<T> *tail;
    void addItem (T val);

};
//template <typename T>
//class doubleLinkedList {
//public:
//    node<T> *head = nullptr;
//    node<T> *tail = nullptr;
//};

#endif //LINKED_LISTS_NODE_CLASS_H
