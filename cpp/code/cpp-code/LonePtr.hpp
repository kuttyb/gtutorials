//
//  LonePtr.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 4/18/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <assert.h>
#include "LonePtr.h"

using std::cout;
using std::endl;

template <typename T>
LonePtr<T>::LonePtr(T *ptr) {
    m_ptr = ptr;
}

template <typename T>
T* LonePtr<T>::get() {
    return m_ptr;
}


template <typename T>
LonePtr<T>::~LonePtr() {
    if (m_ptr) {
        delete m_ptr;
    }
}


template <typename T>
void LonePtr<T>::setIfNotSet(T *ptr) {
    if (!m_ptr) {
        m_ptr = ptr;
    }
}

template <typename T>
void LonePtr<T>::test(LonePtr<T> input) {
    assert(input.get());
}

template <typename T>
bool LonePtr<T>::move(LonePtr<T>& other) {
    if (m_ptr && !other.m_ptr) {
        other.m_ptr = m_ptr;
        m_ptr = NULL;
        return true;
    } else {
        return false;
    }
}
