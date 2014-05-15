//
//  TestCRTP.m
//  cpp-code
//
//  Created by kuttyb on 5/14/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

class Type {
public:
    void dump() { std::cout << "\t\tType class" << std::endl; }
};

class SecondType {
public:
    void dump() { std::cout << "\t\tSecondType class" << std::endl; }
};



template <typename SelfType, typename Strategy>
class Base {
private:
    Strategy s;
public:
    void print();
};
template <typename SelfType, typename Strategy>
void Base<SelfType, Strategy>::print() {
    std::cout<< std::endl << "Base class" << std::endl;
    s.dump();
    static_cast<SelfType*>(this)->print();
}



template <typename Strategy>
class Derived : public Base<Derived<Strategy>, Strategy> {
public:
    void print();
};

template <typename Strategy>
void Derived<Strategy>::print() {
    std::cout<< "Derived class" << std::endl << std::endl;
}




@interface TestCRTP : XCTestCase

@end

@implementation TestCRTP

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    {
        Base<Derived<Type>, Type> object;
        object.print();
    }
    
    {
        Base<Derived<SecondType>, SecondType> object;
        object.print();
    }
}

@end
