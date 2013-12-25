//
//  cpp_code_Tests.m
//  cpp-code Tests
//
//  Created by Kutty Banerjee on 12/25/13.
//  Copyright (c) 2013 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <assert.h>


@interface cpp_code_Tests : XCTestCase

@end

@implementation cpp_code_Tests

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
    XCTAssert(1, "");
}

- (void)testExample2
{
    printf("second test passing");
    XCTAssertTrue(1 == 1, "values did not match. input was %d", 5);
}

@end
