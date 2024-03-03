#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Please don't change the class Node
class Node {
public:
    int data;
    Node* next;

    Node(int val);
};


class LinkedList {

public:
    LinkedList();

    // Please don't change the function signature add_tail and delete_tail
    // But you may need to add other member variables and/or other member functions

    void add_tail(int val);
    void delete_tail();
    
};

class DequeLinkedList : public LinkedList {
private:
    Node* tail;
public:
    DequeLinkedList();

    // Please don't change the function signature add_head and delete_head
    // But you may need to add other member variables and/or other member functions

    void add_head(int val);
    void delete_head();
    
};



#endif // LINKEDLIST_H

