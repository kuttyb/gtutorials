//
//  TestCRTP.m
//  cpp-code
//
//  Created by kuttyb on 5/14/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "TypeAssert.h"

class BaseEncoder {
public:
    void dump() { std::cout << "\t\tType class" << std::endl; }
};

class EncoderTwo : public BaseEncoder {
public:
    void dump() { std::cout << "\t\tSecondType class" << std::endl; }
};

class X {
public:
    void dump() {}
};

template <typename Subtype, typename Encoder>
class Base {
    ASSERT_TYPE_START
    ASSERT_TYPE_INHERITS(Encoder, BaseEncoder)
    ASSERT_TYPE_END
private:
    Encoder s;
public:
    void print();
};
template <typename Subtype, typename Encoder>
void Base<Subtype, Encoder>::print() {
    std::cout<< std::endl << "Base class" << std::endl;
    s.dump();
    static_cast<Subtype*>(this)->print();
}



template <typename Encoder>
class Derived : public Base<Derived<Encoder>, Encoder> {
public:
    void print();
};

template <typename Encoder>
void Derived<Encoder>::print() {
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
        Base<Derived<BaseEncoder>, BaseEncoder> object;
        object.print();
    }
    
    {
        Base<Derived<EncoderTwo>, EncoderTwo> object;
        object.print();
    }
}

@end
