//
//  NumberTemplatesThird.c
//  cpp-cmd
//
//  Created by kuttyb on 5/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include <iostream>
#include "NumberTemplates.hpp"

template <>
void DataStore<3>::print(void) {
    cout << "3: array of size 3" << endl;
}

