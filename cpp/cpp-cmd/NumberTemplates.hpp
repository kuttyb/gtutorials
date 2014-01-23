//
//  NumberTemplates.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_NumberTemplates_h
#define cpp_cmd_NumberTemplates_h

template <int T>
class DataStore{
private:
    int _array[T];
public:
    void print(void);
};

template <int T>
void DataStore<T>::print(void) {
    cout <<"size of the array is " << T << endl;
}

int num_main(void)
{
    DataStore<3> x;
    x.print();
    DataStore<5> y;
    y.print();
    
    return 0;
}


#endif
