//
//  Derived.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_cmd__Derived__
#define __cpp_cmd__Derived__

class Derived : public Base<Derived> {
public:
    void start(void);
};

#endif /* defined(__cpp_cmd__Derived__) */
