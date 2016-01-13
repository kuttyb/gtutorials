//
//  TestLinkedList.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 1/13/16.
//  Copyright © 2016 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
#pragma mark - List Interface
/* Any data structure that wishes to use List has to specialize the following methods */
template <typename T, int val> T** getNext(T * input);
template <typename T> uint32_t hashCode(T * input);

template <typename T, int Next>
struct List {
	T * head;
	T * tail;
	uint32_t elements;
	
	List() : head(nullptr), tail(nullptr), elements(0) {}
	
	void insert(T * data) {
		if (!head) {
			head = data;
			tail = data;
		} else {
			*getNext<T, Next>(head) = data;
			head = data;
		}
		++elements;
	}
	
	T * remove() {
		T * temp = tail;
		if (temp) {
			tail = *getNext<T, Next>(temp);
			elements--;
			return temp;
		} else {
			return nullptr;
		}
	}
	
	uint32_t size() {
		return elements;
	}
	
	void traverse() {
		T * itr = tail;
		while (itr) {
			cout << hashCode<T>(itr) << endl;
			itr = *getNext<T, Next>(itr);
		}
	}
};


struct A {
	int value;
	
	/* To abide by the List Interface */
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
