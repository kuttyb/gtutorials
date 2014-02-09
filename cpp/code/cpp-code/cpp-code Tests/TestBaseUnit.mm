//
//  TestBaseUnit.m
//  cpp-code
//
//  Created by Kutty Banerjee on 2/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "BaseUnit.h"

@interface TestBaseUnit : XCTestCase

@end

@implementation TestBaseUnit

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
    Base<2, 4, 8> x;
    x.print();
    
    Base<1, 2, 1> y;
    y.print();
    
    // Pick from the fully specialized classes
    Base<1, 2, 3> a;
    a.print();
    
    Base<2, 1, 3> b;
    b.print();

}

@end
