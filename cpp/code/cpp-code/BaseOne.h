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

// kbb : Boost TTI is what you want, a decent way to find out what types
//       you are willing to accept (best Java wildcards alternative)
#if 0
template <typename T>
constexpr bool IS_TYPE(T input) {
    return false;
}

template <typename T>
constexpr bool IS_TYPE(BaseOne<T> input) {
    return true;
}
#endif

#endif
