//
//  More.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/13/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__More__
#define __cpp_code__More__

template <typename T>
class More {
private:
    struct _pvt;
    int localvar;
    const int localconst;

public:
    More(void);
    void print(T data);
    // all sorts of variables :)
    static void printClass(void);
    static int classVar;
    static const int classConstant;
};

#endif /* defined(__cpp_code__More__) */
