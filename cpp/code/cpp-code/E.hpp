//
//  E.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__E__
#define __cpp_code__E__

template <typename Derived>
class E {
public:
    void start(Derived data) {
        return static_cast<Derived*>(this)->start(data);
    }
};

#endif /* defined(__cpp_code__E__) */
