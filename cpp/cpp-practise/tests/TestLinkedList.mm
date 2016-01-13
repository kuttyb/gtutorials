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
using std::end;

#pragma mark - C++
template <typename Data>
struct Node {
    Data data;
    Node * next;
};

template <typename Data>
struct List {
    Node<Data> * head;
    Node<Data> * tail;
};

template <typename Data, typename Linkable>
void insertList(Linkable & node) {
    
}

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
}

@end
