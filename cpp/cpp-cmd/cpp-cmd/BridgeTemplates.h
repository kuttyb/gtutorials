//
//  BridgeTemplates.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/23/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_cmd__BridgeTemplates__
#define __cpp_cmd__BridgeTemplates__

class X {
public:
    int print(float f) {return 0;}
    void print_more(double  x) {}
};

class Y {
public:
    int call_value(void) { return 0;}
};

class C :  public Y {
};

class D : public X {
};

class E {
};

#endif /* defined(__cpp_cmd__BridgeTemplates__) */
