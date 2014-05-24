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
    DataStore<DataStoreThird> x;
    x.print();
    DataStore<DataStoreSecond> y;
    y.print();
    DataStore<void> z;
    z.print();
    
    DataStoreFourth fourth;
    fourth.print();
    
    return 0;
}

int main(void) {
    
    num_main();
    
    return 0;
}
