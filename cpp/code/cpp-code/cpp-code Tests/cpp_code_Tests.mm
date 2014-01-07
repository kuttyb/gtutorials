//
//  cpp_code_Tests.m
//  cpp-code Tests
//
//  Created by Kutty Banerjee on 12/25/13.
//  Copyright (c) 2013 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <assert.h>
#import <iostream>
#import "one.h"

using std::cout;
using std::endl;

@interface cpp_code_Tests : XCTestCase

@end

#if 0
// ---------------------------------------------------------
int test_one(void)
{
	// by value
	cout<<"testing the latest software" << endl;
	{
		One<uint64_t> one(2, 3, 8, 1);
		one.value();
		
	}
	cout << "----------------------------" << endl;
    
	
	// Array Initialization
	{
		One<uint64_t> list[] =
        {
            One<uint64_t>(2, 3, 8, 1), One<uint64_t>(1, 5, 2, 2), One<uint64_t>(1, 1, 1, 3), One<uint64_t>(1, 2, 3, 4)
        };
		cout << "printing array values " << endl;
		
		for (uint32_t i = 0; i < sizeof(list) / sizeof(One<uint64_t>); i++)
		{
			cout << list[i].latest_value() << endl;
		}
	}
	cout << "----------------------------" << endl;
    
	cout <<"tearing down program" << endl;
	
	return 0;
}
#endif

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
