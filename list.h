#pragma once
#include "tpoint.h"
#include <iostream>

class List {
protected:
    struct vertex {
        tFigure *object{};
        vertex *ptr_next = nullptr;
    };
    vertex *ptr_root = nullptr;
    vertex *ptr_tail = nullptr;
};

class Queue : public List {
public :
    void addItem(tFigure* object) {
        auto *temp = new vertex;
        temp->object = object;
        if (ptr_root == nullptr) {
            ptr_tail = temp;
            ptr_root = temp;
        } else {
            ptr_tail->ptr_next = temp;
            ptr_tail = temp;
        }
    }
    ~Queue() {
        while (ptr_root->ptr_next != nullptr) {
            vertex *temp = ptr_root->ptr_next;
            delete ptr_root;
            ptr_root = temp;
        }
    }
};

class Stack : public List {
public:
    void addItem(tFigure* object) {
        auto *temp = new vertex;
        temp->object = object;
        if (ptr_root == nullptr) {
            ptr_tail = temp;
            ptr_root = temp;
        } else {
            vertex *new_temp = ptr_root;
            temp->ptr_next = new_temp;
            ptr_root = temp;
        }
    }
    ~Stack() {
        while (ptr_root->ptr_next != nullptr) {
            vertex *temp = ptr_root->ptr_next;
            delete ptr_root;
            ptr_root = temp;
        }
    }
};