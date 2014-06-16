//
//  conditional.h
//  cpp-cmd
//
//  Created by kuttyb on 6/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_conditional_h
#define cpp_cmd_conditional_h

template <bool n, typename INPUT>
struct _if {
    static void _do(std::function<void (INPUT input)> func, INPUT args) {
        return func(args);
    }
};

template <typename INPUT>
struct _if<false, INPUT> {
    // Do nothing
    static void _do(std::function<void (INPUT input)> func, INPUT args) {
    }
};


#endif
