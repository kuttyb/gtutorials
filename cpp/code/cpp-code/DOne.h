//
//  DOne.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__DOne__
#define __cpp_code__DOne__

#include "BaseOne.h"

class DOne : public BaseOne<DOne> {
private:
    DOne *ref;
public:
    void start(DOne *input);
};

#endif /* defined(__cpp_code__DOne__) */
