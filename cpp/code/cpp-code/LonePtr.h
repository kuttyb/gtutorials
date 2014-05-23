//
//  LonePtr.h
//  cpp-code
//
//  Created by Kutty Banerjee on 4/18/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__LonePtr__
#define __cpp_code__LonePtr__

#include <iostream>

template <typename T>
class LonePtr {
private:
    T* m_ptr;
    // Get rid of the copy and hide ctor/operators
    LonePtr(const LonePtr<T>& other) = delete;
    LonePtr<T>& operator=(const LonePtr<T>& rhs) = delete;

    LonePtr(LonePtr<T>&& other)  = delete;
    LonePtr<T>& operator=(LonePtr<T>&& rhs) = delete;
    
public:
    LonePtr(){}
    ~LonePtr();
    LonePtr(T *ptr);
    void setIfNotSet(T *ref);
    bool moveto(LonePtr<T>& other);
    
    // Overloaded dereference and member access operators
    T operator*() const;
    T* operator->() const;
};

#endif /* defined(__cpp_code__LonePtr__) */
