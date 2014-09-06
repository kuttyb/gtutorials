//
//  functionalderivation.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_functionalderivation_h
#define cpp_cmd_functionalderivation_h

#pragma mark Functional Classes (Behaviour only - extend using composition)
template <typename T>
class Base {
public:
    void common(T & input);
};

template <typename T>
class Derived {
private:
    Base<T> composite;
public:
    void common(T & input);
};


#pragma mark Data Classes (no Behaviour - extend using Inheritance)
//
// We could have used Composition for this too but then
// Base<T>::common(T & input) would have had to do input.compositevar
// which would have prevented it from working with G4P
//
// So Data Inheritance, Functional Composition (Higher order functions)
//
struct G4P {
    int x;
    int y;
    G4P (int one, int two) : x(one), y(two) {}
};

struct G4G : public G4P {
    float m;
    G4G(float input, int one, int two) : m(input), G4P(one, two) {}
};

#endif
