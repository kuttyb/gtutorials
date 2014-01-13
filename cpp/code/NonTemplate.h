//
//  NonTemplate.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/12/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__NonTemplate__
#define __cpp_code__NonTemplate__

class NonTemplate {
public:
    NonTemplate(int input);
    ~NonTemplate(void);
    void print(void);
private:
    static const int VALUE;
    int _value;
};

#endif /* defined(__cpp_code__NonTemplate__) */
