#include "linkedlist.h"

// You may need to define the constructor for LinkedList and DequeLinkedList

Node::Node(int val) {
    this->data = val;
    this->next = nullptr;
}

/**
 * Constructor of LinkedList
 */
LinkedList::LinkedList() {
    this->head = nullptr;
    this->type = "LinkedList";
}

void LinkedList::add_tail(int val) {
    Node *node = new Node(val);

    if (this->head == nullptr) {
        this->head = node;

    } else {
        bool isContinue = true;
        Node *currentNode = this->head;

        while (isContinue) {
            if (currentNode->next == nullptr) {
                isContinue = false;
            } else {
                currentNode = currentNode->next;
            }
        }

        currentNode->next = node;
    }
}

void LinkedList::delete_tail() {
    if (this->head != nullptr) {
        if (this->head->next == nullptr) {
            this->head = nullptr;
        } else {
            bool isContinue = true;
            Node *currentNode = this->head;

            while (isContinue) {
                if (currentNode->next->next == nullptr) {
                    isContinue = false;
                } else {
                    currentNode = currentNode->next;
                }
            }

            delete currentNode->next;

            currentNode->next = nullptr;
        }
    }

}

/**
 * Overloading operator "<<" for LinkedList
 *
 * @param os
 * @param list
 * @return
 */
std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
    os << list.type << ": ";

    if (list.head != nullptr) {
        bool isContinue = true;

        os << list.head->data;

        Node *currentNode = list.head->next;

        while (isContinue) {
            if (currentNode == nullptr) {
                isContinue = false;
            }else{
                os << "->" << currentNode->data;

                currentNode = currentNode->next;
            }
        }
    }
    return os;
}


/**
 * Constructor of DequeLinkedList
 */
DequeLinkedList::DequeLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->type = "DequeLinkedList";
}

void DequeLinkedList::add_head(int val) {
    Node *node = new Node(val);

    if (this->head == nullptr) {
        node->next = nullptr;
    } else {
        node->next = this->head;
    }

    this->head = node;
}

void DequeLinkedList::delete_head() {
    if (this->head != nullptr) {
        this->head = this->head->next;
    }
}

// You may need to add other functions to overload the <<

