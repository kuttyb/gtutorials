//
//  TestLambda.mm
//  cpp-practise
//
//  Created by kuttyb on 11/22/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

#pragma mark - C++
void process(function<void ()> code) {
	code();
}

#pragma mark - Objective C
@interface TestLambda : XCTestCase

@end

@implementation TestLambda

- (void)setUp {
    [super setUp];
	cout << "=============" << endl;
}

- (void)tearDown {
	cout << "=============" << endl;
    [super tearDown];
}

- (void)testBasic {
	int a = 2;
	
	process([a](){
		cout << "data " << a <<  endl;
	});
}

@end
