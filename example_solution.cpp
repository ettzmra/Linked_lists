#include <iostream>

using std::cout;
using std::endl;

template <typename T>
struct node {
  node<T> *next;
  node<T> *previous;
  T data;
};

template <typename T>
class DoubleList {
public:
  DoubleList() {
    head = nullptr;
    tail = nullptr;
  }
  
  void push_front(T data) {
    if (head == nullptr) {
      initList(data);
    } else {
      cout << "Regular push front: " << data << endl;
      node<T> *newNode = initNode(data);
      newNode->next = head;
      newNode->previous = newNode;
      head->previous = newNode;
      head = newNode;
    }
  }
  void push_back(T data) {
    if (tail == nullptr) {
      initList(data);
    } else {
      cout << "Regular push back: " << data << endl;
      node<T> *newNode = initNode(data);
      newNode->next = newNode;
      newNode->previous = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  bool pop_front() {
    if (head == nullptr) {
      cout << "Cannot pop front on empty list" << endl;
      return false;
    } else if (head == tail) {
      cout << "Pop front to empty queue: " << head->data << endl;
      delete head;
      head = nullptr;
      tail = nullptr;
      return true;
    } else {
      cout << "Pop front: " << head->data << endl;
      node<T> *nextNode = head->next;
      nextNode->previous = nextNode;
      delete head;
      head = nextNode;
      return true;
    }
  }

  bool pop_back() {
    if (tail == nullptr) {
      cout << "Cannot pop back on empty list" << endl;
      return false;
    } else if (tail == head) {
      return pop_front();
    } else {
      cout << "Pop back: " << tail->data << endl;
      node<T> *prevNode = tail->previous;
      prevNode->next = prevNode;
      delete tail;
      tail = prevNode;
      return true;
    }
  }

  bool getItem(unsigned int index, T &item) {
    node<T> *targetNode = findNodebyIndex(index);

    if (targetNode == nullptr) {
      cout << "No such index: " << index;
      return false;
    } else {
      item = targetNode->data;
      return true;
    }
  }

  bool getFront(T &item) {
    if (head == nullptr) {
      return false;
    } else {
      item = head->data;
      return true;
    }
  }
  
  bool getBack(T &item) {
    if (tail == nullptr) {
      return false;
    } else {
      item = tail->data;
      return true;
    }
  }
  
  bool deleteItem(unsigned int index) {
    ol getItem(unsigned int index, T &item) {
    node<T> *targetNode = findNodebyIndex(index);

    if (targetNode == nullptr) {
      cout << "No such index: " << index;
      return false;
    } else {
      cout << "Deleting " << index << endl;
      if (targetNode == head && targetNode == tail) {
	
      } else if (targetNode == head) {
	pop_front();
      } else if (targetNode == tail) {
	pop_back();
      } else {
	node<T> *prev = targetNode->previous;
	node<T> *next = targetNode->next;
	prev->next = next;
	next->previous = prev;
	delete targetNode;
      }
      return true;
    }
  }
  
  unsigned int count();
  
  void print() {
    cout << "[";
    node<T> *currentNode = head;
    while(currentNode != nullptr) {
      cout << currentNode->data;
      if (currentNode == tail) {
	break;
      } else {
	cout << " ";
	currentNode = currentNode->next;
      }
    }
    cout << "]" << endl;
  }
  void clear();
private:
  node<T>* initNode(T data) {
    node<T> *newNode = new node<T>();
    newNode->data = data;
    return newNode;
  }

  void initList(T data) {
    cout << "New List, Initalizing single node: " << data << endl;
    node<T> *newNode = initNode(data);
    newNode->next = newNode;
    newNode->previous = newNode;
    head = newNode;
    tail = newNode;
  }

  node<T>* findNodebyIndex(unsigned int index) {
    node<T> *currentNode = head;
    unsigned int currentIndex = 0;
    while(currentNode != nullptr) {
      if (currentNode == tail) {
	return nullptr;
      } else if (currentIndex == index) {
	return currentNode;
      } else {
	currentNode = currentNode->next;
	++currentIndex;
      }
    }
    return nullptr;
  }


  
  node<T> *head;
  node<T> *tail;
};

int main()
{
  DoubleList<int> list;
  list.push_front(3);
  list.push_front(2);
  list.push_front(1);

  list.push_back(4);
  list.push_back(5);
  list.push_back(6);
  
  list.print();

  int i = 0;
  list.getFront(i);
  cout << "Front = " << i << endl;
  list.getBack(i);
  cout << "Back = " << i << endl;

  list.getItem(3, i);
  cout << "list[3] == " << i << endl;

  list.deleteItem(3);
  list.print();
  
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.print();

  list.getItem(3, i);
  cout << "list[3] == " << i << endl;
  
  return 0;
}
