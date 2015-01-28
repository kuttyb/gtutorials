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
#include <vector>

using std::cout;
using std::endl;
using std::vector;

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
	
	void operator()(std::vector<int> & data) const
	{
		
	}
};

typedef boost::variant<int, std::string, std::vector<int>> Node;


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

- (void)testBasicVisitor {
	Node data("hello");
	boost::apply_visitor(Visitor(), data);
}

- (void)testVectorVisitor {
	vector<Node> a;
	a.push_back(3);
	a.push_back("fine");
	a.push_back(4);
	
	for (Node & temp : a) {
		boost::apply_visitor(Visitor(), temp);
	}
}

@end
