#pragma once
#include "tpoint.h"
#include <iostream>

struct vertex {
    tFigure *object{};
    vertex *ptr_next = nullptr;
};

class List {
protected:
    vertex *ptr_root = nullptr;
    vertex *ptr_tail = nullptr;
    static int qtyLists;
    int m_qty;

public:
    List() {
        m_qty = ++qtyLists;
    }
    virtual vertex *getHead() = 0;
    int getQTY() const {
        return m_qty;
    }
};

class Queue : public List {
public:
    void addItem(tFigure *object) {
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
    vertex *getHead() override {
        return this->ptr_root;
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
    void addItem(tFigure *object) {
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
    vertex *getHead() override {
        return this->ptr_root;
    }
    ~Stack() {
        while (ptr_root->ptr_next != nullptr) {
            vertex *temp = ptr_root->ptr_next;
            delete ptr_root;
            ptr_root = temp;
        }
    }
};