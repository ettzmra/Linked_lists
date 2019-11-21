#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct node {
    T data; // at class scope, variable templates need to be declared static.
    node *next = nullptr;
    node *previous = nullptr;
};

template <typename T>
class doubleLinkedList {
    public:
        node <T> *head = nullptr;
        node <T> *tail = nullptr;
        void addItem(T val) {
            if (head == nullptr) {head = new node <T>; tail = head; head->data = val;}
            else {tail->next = new node <T>; tail->next->previous = tail; tail = tail->next; tail->data = val;}
        }
        void push_front(T val) {
            node <T> *current = head->next;
            while (current != nullptr){
            if (current->data == val) {
                if (current == head->next) {
                    current->next = head;
                    head = current;
                    current->previous = nullptr;
                }
                else {
                    current->next = current->previous;
                    current->previous = current->previous->previous;
                }
            }
            else {current = current->next;}
            }
        }
        void push_back(T val) {
            node <T> *current = head;
            while (current->next != nullptr) {
                node <T> *previous_node = current->previous;
                node <T> *next_node = current->next;
                if (current->data == val) {
                    if (current == head) {
                        current->previous = next_node;
                        head = next_node;
                        current->next = next_node->next;
                    }
                    else {
                        previous_node->next = current;
                        previous_node->previous = current->previous;
                        current->previous = next_node;
                        current->next = next_node->next;
                        /*if (current->next->next == nullptr) {
                            tail->previous = current->next;
                            current->next = nullptr;
                            tail = current;}
                        else{current->next = current->previous->next; current->previous->next = current;}*/
                        //current->previous = current->next;
                    }
                } else { current = current->next; }
            }
        }
};

int main() {
    doubleLinkedList <int> firstlist;
    firstlist.addItem(1);
    firstlist.addItem(2);
    firstlist.addItem(3);
    cout<< firstlist.head->data << "\n" << firstlist.head->next->data << "\n" << firstlist.tail->data << "\n";
    //firstlist.push_front(2);
    firstlist.push_back(2);
    cout<< firstlist.head->data << "\n" << firstlist.head->next->data << "\n" << firstlist.tail->data;
    //string food = "pizza"; string* meal = &food; cout << meal << "\n" << &meal << "\n" << food << "\n" << &food << "\n";
    //meal = "hamburger"; cout << food;
    return 0;
}