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

@implementation TestSets

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}


- (void)testBasicOps
{
    set<int> a;
    a.insert(2);
    a.insert(3);
    a.insert(5);
    XCTAssert(a.size() == 3, "size is %lu instead", a.size());
    XCTAssert(a.find(3) != a.end(), "element 3 not found");
    a.erase(a.find(3));
}

static bool test_elements(const set<int> *input, const int *expected, const int elements) {
    int i = 0;
    for (set<int>::iterator x = input->begin(); x != input->end(); x++, ++i) {
        if (i >= elements) return false;
        if (expected[i] != *x) return false;
    }
    return true;
}

- (void)testIteration
{
    set<int> x;
    x.insert(3);
    x.insert(5);
    x.insert(1);
    
    {
        const int table[] = {1, 3, 5};
        const int size = sizeof(table) / sizeof(table[0]);
        XCTAssert(test_elements(&x, table, size), "mismatch");
    }
    
    {
        const int table[] = {1, 5};
        const int size = sizeof(table) / sizeof(table[0]);
        x.erase(x.find(3));
        XCTAssert(test_elements(&x, table, size), "mismatch");
    }
    
    XCTAssert(x.find(3) == x.end(), "erase did not work");
}

@end
