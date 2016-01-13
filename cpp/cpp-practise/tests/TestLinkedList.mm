//
//  TestLinkedList.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 1/13/16.
//  Copyright © 2016 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "linkedlist.hpp"

using std::cout;
using std::endl;

#pragma mark - C++
struct A {
	int value;

	/* LinkedList Nodes */
	A * listone;
	A * listtwo;

	A(int value) : value(value) {}
	
	void print() {
		cout << "value is " << value << endl;
	}
};

template <> A**		  getNext<A, 0>(A * input) { return &input->listone; }
template <> A**		  getNext<A, 1>(A * input) { return &input->listtwo; }
template <> uint32_t  hashCode<A>(A * input)	  { return input->value; }


#pragma mark - Test
@interface TestLinkedList : XCTestCase

@end

@implementation TestLinkedList

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testExample {
	A a(2);
	A b(3);
	A c(4);
	A d(5);
	List<A, 0> list;

	list.insert(&a);
	list.insert(&b);
	list.insert(&c);
	list.insert(&d);
	XCTAssert(list.size() == 4);
	
	list.traverse();
	
	list.remove();
	list.remove();
	
	cout << "===========" << endl;
	list.traverse();
	list.remove();
	list.remove();
	XCTAssert(list.size() == 0);
	
	cout << "===========" << endl;
	list.traverse();
}

@end
