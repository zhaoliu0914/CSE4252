#include <iostream>
#include "linkedlist.h"

// Please don't change the main function
// But modify the other linkedlist.h and linkedlist.cpp files
// To make this code compile

int main() {
    LinkedList list1;
    list1.add_tail(1);
    list1.add_tail(2);

    std::cout << list1 << std::endl;
    list1.delete_tail();
    std::cout << "After deletion: " << list1 << std::endl;

    DequeLinkedList list;
    list.add_tail(1);
    list.add_tail(2);
    list.add_head(3);
    list.add_head(4);
    list.add_tail(5);
    std::cout << list << std::endl;

    list.delete_tail();
    list.delete_head();
    std::cout << "After deletion: " << list << std::endl;

    return 0;
}

