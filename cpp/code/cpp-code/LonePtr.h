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
    // Hide copy constructor
    LonePtr(const LonePtr<T>& other);
    LonePtr<T>& operator=(const LonePtr<T>& rhs);
    
public:
    LonePtr(){}
    LonePtr(T *ptr);
    T* get();
    void set(T *ref);
    void reset();
};

#endif /* defined(__cpp_code__LonePtr__) */
