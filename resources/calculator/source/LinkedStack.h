//
// Created by Sino on 2018/2/8.
//

#ifndef CALCULATOR_LINKEDSTACK_H
#define CALCULATOR_LINKEDSTACK_H

#include <iostream>

template<class T>
class LinkedStack {
    struct Node {
        T value;
        Node *next;
    };
public:
    LinkedStack();

    ~LinkedStack();

    void push(T value);

    T pop();

    T getTop();

    int getLen();

    bool isEmpty();

private:
    Node *top;
    int len;
};

template<class T>
LinkedStack<T>::LinkedStack() {
    top = NULL;
    len = 0;
}

template<class T>
LinkedStack<T>::~LinkedStack() {
    Node *next = top;
    while (next) {
        Node *deleteMe = next;
        next = next->next;
        delete deleteMe;
    }
    len = 0;
}

template<class T>
void LinkedStack<T>::push(T value) {
    Node *n = new Node();
    n->value = value;
    n->next = top;
    top = n;
    len++;
}

template<class T>
T LinkedStack<T>::pop() {
    if (len > 0) {
        Node *n = top;
        T ret = n->value;
        top = top->next;
        len--;
        delete n;
        return ret;
    }
    return NULL;
}

template<class T>
T LinkedStack<T>::getTop() {
    if (len > 0)
        return top->value;
    return NULL;
}

template<class T>
int LinkedStack<T>::getLen() {
    return len;
}

template<class T>
bool LinkedStack<T>::isEmpty() {
    return len <= 0;
}

#endif //CALCULATOR_LINKEDSTACK_H
