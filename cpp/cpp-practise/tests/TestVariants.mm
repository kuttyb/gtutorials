//
//  TestVariants.mm
//  cpp-practise
//
//  Created by kuttyb on 1/27/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <boost/variant.hpp>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
struct Visitor : public boost::static_visitor<>
{
	void operator()(int i) const
	{
		cout << "int: input is " << i << endl;
	}
	
	void operator()(std::string & data) const
	{
		cout << "string: input is " << data << endl;
	}
};

#pragma mark - Test
@interface TestVariants : XCTestCase

@end

@implementation TestVariants

- (void)setUp {
    [super setUp];
	cout << "==================" << endl;
}

- (void)tearDown {
	cout << "==================" << endl;
    [super tearDown];
}

- (void)testExample {
	boost::variant<int, std::string> data ("hello");
	boost::apply_visitor(Visitor(), data);
}

@end
