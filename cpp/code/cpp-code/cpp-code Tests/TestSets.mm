//
//  TestSets.m
//  cpp-code
//
//  Created by Kutty Banerjee on 3/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <set>
#include <iostream>
#include "Range.h"

using std::set;

@interface TestSets : XCTestCase

@end

@implementation TestSets {
    set<int> *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new set<int>();
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}


- (void)testBasicOps
{
    subject->insert(2);
    subject->insert(3);
    subject->insert(5);
    XCTAssert(subject->size() == 3, "size is %lu instead", subject->size());
    XCTAssert(subject->find(3) != subject->end(), "element 3 not found");
    subject->erase(subject->find(3));
}

-(void) test_elements:(const set<int>*)input EXPECTED:(const int*)expected ELEMENTS:(const int)elements
{
    int i = 0;
    for (set<int>::iterator x = input->begin(); x != input->end(); x++, i++) {
        XCTAssert(i < elements, "Expected %d elements found an element at index %d", elements, i);
        XCTAssert(*x == expected[i], "Expected %d found %d", expected[i], *x);
    }
}

- (void)testIteration
{
    subject->insert(3);
    subject->insert(5);
    subject->insert(1);
    
    {
        const int table[] = {1, 3, 5};
        const int size = sizeof(table) / sizeof(table[0]);
        [self test_elements:subject EXPECTED:table ELEMENTS:size];
    }
    
    {
        const int table[] = {1, 5};
        const int size = sizeof(table) / sizeof(table[0]);
        subject->erase(subject->find(3));
        [self test_elements:subject EXPECTED:table ELEMENTS:size];
    }
    
    XCTAssert(subject->find(3) == subject->end(), "erase did not work");
}


- (void) testUserDefinedElement
{
    Range one(0x10, 4);
    Range two(0x40, 4);
    Range three(0x60, 4);
    Range four(0x80, 4);
    
    Range three_head_overlap(0x61, 0x10);
    Range three_tail_overlap(0x55, 0x10);
    
    set<Range> x;
    XCTAssert(x.insert(two).second == true, "insert failed");
    XCTAssert(x.insert(three).second == true, "insert failed");
    XCTAssert(x.insert(four).second == true, "insert failed");
    XCTAssert(x.insert(one).second == true, "insert failed");
    
    XCTAssert(x.insert(three).second == false, "inserting an overlap should not succeed");
    XCTAssert(x.insert(three_head_overlap).second == false, "inserting an overlap should not succeed");
    XCTAssert(x.insert(three_tail_overlap).second == false, "inserting an overlap should not succeed");

    XCTAssert(x.size() == 4, "size expected 2 found %ld", x.size());
    
    for (set<Range>::iterator itr = x.begin(); itr != x.end(); itr++) {
        static_cast<Range>(*itr).print();
    }
}

@end
