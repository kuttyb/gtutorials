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
    XCTAssert(true, "");
}

@end
