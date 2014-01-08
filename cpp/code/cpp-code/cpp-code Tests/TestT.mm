//
//  TestT.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "t.h"

using std::cout;
using std::endl;

@interface TestT : XCTestCase

@end

@implementation TestT

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample
{
    cout << "hi there" << endl;
    
    X<int> a;
    cout<< a.add(3, 4) << endl;
    cout<< a.multiply(3, 4) << endl;
}

@end
