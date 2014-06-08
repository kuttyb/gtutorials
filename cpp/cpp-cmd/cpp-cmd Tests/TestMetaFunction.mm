//
//  TestMetaFunction.mm
//  cpp-cmd
//
//  Created by kuttyb on 6/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

// template parameters are your function arguments and the static const part is the return value.
// any computation required in its value calculation is the body
template <unsigned int  n>
struct factorial {
    static const unsigned int value = n * factorial<n-1>::value;
    
    static constexpr unsigned int fact() {
        return n * factorial<n-1>::fact();
    }
};

template <>
struct factorial<0> {
    static const unsigned int value = 1;
    
    static constexpr unsigned int fact() {
        return 1;
    }
};

@interface TestMetaFunction : XCTestCase

@end

@implementation TestMetaFunction

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
    factorial<3> x;
    cout << "factorial is " << x.value << endl;
    
    cout << "factorial is " << x.fact() << endl;
}


@end
