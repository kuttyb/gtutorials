//
//  TypeAssert.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/23/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_TypeAssert_h
#define cpp_cmd_TypeAssert_h

#define ASSERT_TYPE_START private: static const bool x_y =
#define ASSERT_TYPE_INHERITS(U, V)   (static_cast<U*>(NULL) == static_cast<V*>(NULL)) &&
#define ASSERT_TYPE_END    false;

#pragma mark C++ enable_if
template <bool n, typename T = void>
struct enable_if {
};

template <typename T>
struct enable_if <true, T> {
    typedef T type;
};


#endif
