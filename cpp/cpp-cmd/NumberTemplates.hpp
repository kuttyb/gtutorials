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

template <int T>
class DataStore{
private:
    int _array[T];
public:
    void print(void);
};

template <int T>
void DataStore<T>::print(void) {
    cout <<"Generic: size of the array is " << T << endl;
}


#endif
