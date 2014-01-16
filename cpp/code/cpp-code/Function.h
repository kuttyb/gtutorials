//
//  Function.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__Function__
#define __cpp_code__Function__

template <typename T> T func(T input);
template <int> int func(int input);

// Type-Traits
template <typename T>
bool is_type_valid(T input) {
    return false;
}

template <>
bool is_type_valid(int input) {
    return true;
}

template <>
bool is_type_valid(float input) {
    return false;
}

template <>
bool is_type_valid(char input) {
    return true;
}

constexpr int get_area(int input, int two) {
    return input + two;
}

#endif /* defined(__cpp_code__Function__) */
