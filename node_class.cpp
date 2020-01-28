//
// Created by mel on 28.01.2020.
//

#include "node_class.h"
#include <iostream>
using namespace std;
//using doubleLinkedList<T>;

template <typename T>
//class doubleLinkedList {
//public:
//    node <T> *head = nullptr;
//    node <T> *tail = nullptr;
void doubleLinkedList<T>::addItem(T val) {
    if (head == nullptr) {
        head = new node <T>;
        head->data = val;
        tail = head;
    }
    else {
        tail->next = new node <T>;
        tail->next->previous = tail;
        tail = tail->next;
        tail->data = val;
        tail->next = nullptr;
    }
}
//    void print_list() {
//        node <T> *current = head;
//        cout<<"[ ";
//        while (current != nullptr) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout<<"]" << endl;
//    }
//    node<T>* find_value(T val) {
//        node<T> *current = head;
//        while (current != nullptr) {
//            if (current->data == val) {
//                return current;
//            }
//            else {
//                current = current->next;
//            }
//        }
//        return nullptr;
//    }
//    node<T>* find_index (unsigned int idx) {
//        node<T> *current = head;
//        for (int i = 0;; ++i, current = current->next) {  //this (the last statement) is disgusting but written to prove a point.
//            if (current == nullptr) {
//                return nullptr;
//            }
//            if (i == idx) {
//                return current;
//            }
//        }
//    }
//    bool swap_items (unsigned int index_a, unsigned int index_b) {
//        node<T> *item1 = find_index(index_a);
//        node<T> *item2 = find_index(index_b);
//        if (item1 == nullptr || item2 == nullptr) {
//            return false;
//        }
//        std::swap(item1->data, item2->data);
//        return true;
//    }
//    bool remove_item (unsigned int idx) {
//        node<T> *current = find_index(idx);
//        if (current == head) {
//            delete head;
//            head = current->next;
//            head->previous = nullptr;
//            return true;
//        }
//        if (current == tail) {
//            delete tail;
//            tail = current->previous;
//            tail->next = nullptr;
//            return true;
//        }
//        if (current == nullptr) {
//            return false;
//        }
//        node<T> *prev = current->previous;
//        node<T> *nxt = current->next;
//        prev->next = nxt;
//        nxt->previous = prev;
//        delete current;
//        return true;
//    }
//    void move_front(T val) {
//        node <T> *current = find_value(val);
//        if (current == nullptr) {
//            return;
//        }
//        if (current == head) {
//            return;
//        }
//        if (current == tail) {
//            current->next = head;
//            head->previous = current;
//            tail = current->previous;
//            tail->next = nullptr;
//            head = current;
//            current->previous = nullptr;
//        }
//        else {
//            node<T> *prev = current->previous;
//            node<T> *nxt = current->next;
//            prev->next = nxt;
//            nxt->previous = prev;
//            current->next = head;
//            head->previous = current;
//            head = current;
//            current->previous = nullptr;
//        }
//    }
//    void move_back(T val) {
//        node<T> *current = find_value(val);
//        if (current == nullptr) {
//            return;
//        }
//        if (current == tail) {
//            return;
//        }
//        if (current == head) {
//            current->previous = tail;
//            tail = head;
//            head = current->next;
//            head->previous = nullptr;
//            current->next = nullptr;
//        }
//        else {
//            node<T> *prev = current->previous;
//            node<T> *nxt = current->next;
//            prev->next = nxt;
//            nxt->previous = prev;
//            current->previous = tail;
//            tail->next = current;
//            tail = current;
//            current->next = nullptr;
//        }
//    }
//};
