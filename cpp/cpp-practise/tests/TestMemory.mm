//
//  TestMemory.mm
//  cpp-practise
//
//  Created by kuttyb on 12/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;

#pragma mark - C++
class A {
public:
	int a ;
	int b;
	explicit A(int one, int two) : a(one), b(two) {}
};

#pragma mark - Test
@interface TestMemory : XCTestCase

@end

@implementation TestMemory

- (void)setUp {
    [super setUp];
	cout << "=============" << endl;
}

- (void)tearDown {
	cout << "=============" << endl;
    [super tearDown];
}

void print(const A& input) {
	cout << "A: " << input.a << " " << input.b << endl;
}

- (void)testBasic {
	shared_ptr<A> a = std::make_shared<A>(2, 3);
	print(*a);
}

@end
