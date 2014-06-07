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

@implementation TestTuple {
    std::tuple<int, float> x;
}

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testLearnMakeAndSizeTuple
{
    x = std::make_tuple(3, 2.1f);
    cout <<std::tuple_size<std::tuple<int, float> >::value << endl;
}

@end
