//
//  BaseOne.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_code_BaseOne_h
#define cpp_code_BaseOne_h

template <typename T>
class BaseOne {
public:
    void start(T *input);
};

template <typename T>
constexpr bool IS_TYPE(T input) {
    return false;
}

template <typename T>
constexpr bool IS_TYPE(BaseOne<T> input) {
    return true;
}
#endif

