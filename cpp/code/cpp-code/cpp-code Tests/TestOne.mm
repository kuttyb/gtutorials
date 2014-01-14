//
//  TestOne.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "one.h"

using std::cout;
using std::endl;

@interface TestOne : XCTestCase

@end

@implementation TestOne

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
    // by value
    cout<<"testing the latest software" << endl;
    {
        One<uint64_t> one = One<uint64_t>::createInteger(2, 3, 8, 1);
        one.value();
        
    }
    cout << "----------------------------" << endl;
    
    
    // Array Initialization
    {
        One<uint64_t> list[] =
        {
            One<uint64_t>::createInteger(2, 3, 8, 1), One<uint64_t>::createInteger(1, 5, 2, 2), One<uint64_t>::createInteger(1, 1, 1, 3), One<uint64_t>::createInteger(1, 2, 3, 4)
        };
        cout << "printing array values " << endl;
        
        for (uint32_t i = 0; i < sizeof(list) / sizeof(One<uint64_t>); i++)
        {
            cout << list[i].latest_value() << endl;
        }
    }
    cout << "----------------------------" << endl;
    
    cout <<"tearing down program" << endl;
}

@end
