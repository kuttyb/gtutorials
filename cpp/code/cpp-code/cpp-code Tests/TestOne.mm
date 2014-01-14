//
//  TestOne.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "ConfigOne.h"

using std::cout;
using std::endl;

@interface TestOne : XCTestCase

@end

@implementation TestOne {
	ConfigOne *factory;
}

- (void)setUp
{
    [super setUp];
	factory = new ConfigOne();
}

- (void)tearDown
{
	delete factory;
    [super tearDown];
}

- (void)testExample
{
    // by value
    {
        One<uint64_t> one = factory->createInteger();
        one.value();
    }
    
    // Array Initialization
    {
        One<float> list[] =
        {
			factory->createFloat(), factory->createFloat(), factory->createFloat(), factory->createFloat()
        };
        cout << "printing array values " << endl;
        
        for (uint32_t i = 0; i < sizeof(list) / sizeof(One<float>); i++)
        {
            cout << list[i].latest_value() << endl;
        }
    }
}

@end
