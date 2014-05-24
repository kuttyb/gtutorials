//
//  IA.h
//  cpp-code
//
//  Created by Kutty Banerjee on 5/24/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_code_IA_h
#define cpp_code_IA_h

/* Pure Interface(Java) or Protocol(Objective-C) */
template <typename SUBTYPE>
class IA {
public :
    void print(void);
    int  add(int a, int b);
    int  multiply(int a, int b);
};

/* Interface Inheritance, pure and simplel */
class One : public IA<One> {
};

class Two : public IA<Two> {
};

class Twenty : public IA<Twenty> {
};
#endif
