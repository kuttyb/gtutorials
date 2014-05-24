//
//  BridgeTemplatesSecond.c
//  cpp-cmd
//
//  Created by kuttyb on 5/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include <iostream>
#include "NumberTemplates.hpp"

template <>
void DataStore<DataStoreSecond>::print(void) {
    cout << "2: size of the array is " << 2 << endl;
}

