//
//  NumberTemplates.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_NumberTemplates_h
#define cpp_cmd_NumberTemplates_h

#include <iostream>

using std::cout;
using std::endl;

template <typename Subtype>
class DataStore{
private:
    int _array[5];
public:
    void print(void);
};

template <typename Subtype>
void DataStore<Subtype>::print(void) {
    cout <<"Generic: size of the array is " << 5 << endl;
}

class DataStoreSecond : public DataStore<DataStoreSecond> {
};

class DataStoreThird  : public DataStore<DataStoreThird> {
};

#endif
