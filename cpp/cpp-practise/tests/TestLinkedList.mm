//
//  TestLinkedList.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 1/13/16.
//  Copyright © 2016 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

#define ASSERT 1
#include "dlinkedlist.hpp"

using std::cout;
using std::endl;

#pragma mark - C++
struct A {
	int value;

	/* LinkedList Nodes */
	A * nextone;
	A * prevone;
	
	A * nexttwo;
	A * prevtwo;

	A(int value) : value(value), nextone(nullptr), nexttwo(nullptr) {}
};

template <> A**		  getNext<A, 0>(A * input) { return &input->nextone; }
template <> A**		  getPrev<A, 0>(A * input) { return &input->prevone; }
template <> A**		  getNext<A, 1>(A * input) { return &input->nexttwo; }
template <> A**		  getPrev<A, 1>(A * input) { return &input->prevtwo; }
template <> uint32_t  hashCode<A>(A * input)   { return input->value;	 }

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

- (void)testSingleLinkedList {
	A a(2);
	A b(3);
	A c(4);
	A d(5);
	List<A, 0> list;
	List<A, 1> listb;
	
	listb.insert(&a);
	listb.insert(&d);

	list.insert(&a);
	list.insert(&b);
	list.insert(&c);
	list.insert(&d);
	XCTAssert(list.size() == 4);
	cout << "=========== List ===========" << endl;
	list.traverse();
	list.remove();
	list.remove();
	cout << "=========== List ===========" << endl;
	list.traverse();
	list.remove();
	list.remove();
	XCTAssert(list.size() == 0);
	cout << "=========== List ===========" << endl;
	list.traverse();

	cout << "=========== ListB ===========" << endl;
	XCTAssert(listb.size() == 2);
	listb.traverse();
	
	listb.remove();
	listb.remove();
	XCTAssert(listb.size() == 0);
	listb.traverse();
}

- (void)testDoubleLinkedList {
	A a(2);
	A b(3);
	A c(4);
	A d(5);
	DList<A, 0> list;
	
	list.insert(&a);
	list.insert(&b);
	list.insert(&c);
	list.insert(&d);
	
	list.traverseBack();
	XCTAssert(list.size() == 4);
	
	cout << "===========" << endl;
	list.remove();
	list.remove();
	list.traverseBack();

	cout << "===========" << endl;
	list.traverseFront();
}

@end
