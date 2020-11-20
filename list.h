#pragma once
#include "tpoint.h"
#include <iostream>


class List {
protected:
    struct vertex {
        tFigure *object;
        vertex *ptr_next = nullptr;
    };
    vertex *ptr_root = nullptr;
    vertex *ptr_tail = nullptr;
};


class Queue : public List {
public :
     ~Queue() {
        while (ptr_root->ptr_next != nullptr) {
            vertex *temp = ptr_root->ptr_next;
            delete ptr_root;
            ptr_root = temp;
        }
    }
    void addItem(tFigure* object) {
        if (ptr_root == nullptr) {
            vertex *temp = new vertex;
            temp->object = object;
            ptr_tail = temp;
            ptr_root = temp;
        } else {
            vertex *temp = new vertex;
            temp->object = object;
            ptr_tail->ptr_next = temp;
            ptr_tail = temp;
        }
    }
};

class Stack : public List {
public:
    ~Stack() {
        while (ptr_root->ptr_next != nullptr) {
            vertex *temp = ptr_root->ptr_next;
            delete ptr_root;
            ptr_root = temp;
        }
    }
    void addItem(tFigure* object) {
        if (ptr_root == nullptr) {
            vertex *temp = new vertex;
            temp->object = object;
            ptr_tail = temp;
            ptr_root = temp;
        } else {
            vertex *temp = new vertex;
            temp->object = object;
            vertex *new_temp = ptr_root;
            temp->ptr_next = ptr_root;
            ptr_root = temp;
        }
    }
};