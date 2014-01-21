//
//  DBase.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__DBase__
#define __cpp_code__DBase__

template <typename T>
class DBasex {
public:
    void start(void);
};

class DDerived : public DBasex<DDerived> {
};

#endif /* defined(__cpp_code__DBase__) */
