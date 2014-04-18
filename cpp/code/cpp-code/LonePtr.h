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
    // Hide copy constructor, assignment operator
    LonePtr(const LonePtr<T>& other);
    LonePtr<T>& operator=(const LonePtr<T>& rhs);
    // Hide move constructor and move operator
    LonePtr(LonePtr<T>&& other);
    LonePtr<T>& operator=(LonePtr<T>&& rhs);
    
public:
    LonePtr(){}
    LonePtr(T *ptr);
    T* get();
    void setIfNotSet(T *ref);
    bool move(LonePtr<T>& other);
};

#endif /* defined(__cpp_code__LonePtr__) */
