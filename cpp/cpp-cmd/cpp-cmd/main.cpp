//
//  main.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <assert.h>
#include <iostream>
#include "NumberTemplates.hpp"

int num_main(void)
{
    DataStore<3> x;
    x.print();
    DataStore<2> y;
    y.print();
    DataStore<5> z;
    z.print();
    
    return 0;
}

int main(void) {
    
    num_main();
    
    return 0;
}
