//
// Created by ge028774 on 12/14/2023.
//

#include "Set.h"

Set::Set(int data, int index) {
    this->data = data;
    this->parent = index;
    depth = 1;
}

int Set::getParent() const {
    return parent;
}

int Set::getDepth() const {
    return depth;
}

Set::Set() {
    depth = 1;
}

void Set::setParent(int _parent) {
    this->parent = _parent;
}

void Set::incrementDepth() {
    depth++;
}