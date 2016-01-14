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

	A(int value) : value(value), nextone(nullptr), nexttwo(nullptr), prevone(nullptr), prevtwo(nullptr) {}
};

template <> A**		  getNext<A, 0>(A * input) { return &input->nextone; }
template <> A**		  getPrev<A, 0>(A * input) { return &input->prevone; }
template <> A**		  getNext<A, 1>(A * input) { return &input->nexttwo; }
template <> A**		  getPrev<A, 1>(A * input) { return &input->prevtwo; }

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
	
	auto p = [](A& ref){
		cout << ref.value << endl;
	};
	
	listb.insert(&a);
	listb.insert(&d);

	list.insert(&a);
	list.insert(&b);
	list.insert(&c);
	list.insert(&d);
	XCTAssert(list.size() == 4);
	list.traverse(p);
	list.remove();
	list.remove();
	list.traverse(p);
	list.remove();
	list.remove();
	XCTAssert(list.size() == 0);
	list.traverse(p);

	XCTAssert(listb.size() == 2);
	listb.traverse(p);
	
	listb.remove();
	listb.remove();
	XCTAssert(listb.size() == 0);
	listb.traverse(p);
}

- (void)testDoubleLinkedList {
	A a(2);
	A b(3);
	A c(4);
	A d(5);
	DList<A, 0> list;
	DList<A, 1> listb;
	
	auto p = [](A& ref){
		cout << ref.value << endl;
	};
	
	/* Populate List 1 */
	list.insert(&a);
	list.insert(&b);
	list.insert(&c);
	list.insert(&d);
	
	/* Populate List 2 */
	listb.insert(&a);
	listb.insert(&c);
	listb.traverseBack(p);
	XCTAssert(listb.size() == 2);
	
	
	list.traverseBack(p);
	XCTAssert(list.size() == 4);
	
	listb.remove();
	listb.remove();
	cout << "area of interest" << endl;
	XCTAssert(listb.size() == 0);
	listb.insert(&b);
	listb.insert(&c);
	listb.traverseBack(p);

	list.traverseFront(p);
	
	listb.remove();
	listb.remove();
	XCTAssert(listb.size() == 0);
	
	list.remove();
	list.remove();
	list.traverseBack(p);
	
	list.insert(&a);
	list.insert(&b);
	list.traverseBack(p);
	list.traverseFront(p);
}

@end
