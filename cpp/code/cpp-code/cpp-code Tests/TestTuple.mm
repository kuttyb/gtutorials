//
//  TestTuple.m
//  cpp-code
//
//  Created by Kutty Banerjee on 6/6/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <tuple>

using std::cout;
using std::endl;

@interface TestTuple : XCTestCase

@end

@implementation TestTuple

- (void)setUp
{
    [super setUp];
    cout << "-----" << endl;
}

- (void)tearDown
{
    cout << "-----" << endl;
    [super tearDown];
}

- (void)testLearnMakeAndSizeTuple
{
    // declare a tuple
    std::tuple<int, float> x;
    
    // explicitly initialize it
    x = std::make_tuple(3, 2.1f);
    
    // print its size (using type)
    cout <<std::tuple_size<std::tuple<int, float> >::value << endl;
    
    // get each type
    std::tuple_element<0, std::tuple<int, float> >::type   first_val;
    std::tuple_element<1, std::tuple<int, float> >::type   second_val;
    
    // get each type's value
    first_val   = std::get<0>(x);
    second_val  = std::get<1>(x);
    
    cout << "values are " << first_val << " and " << second_val << endl;
}

@end
