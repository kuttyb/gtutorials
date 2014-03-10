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

class Range {
public:
    Range(uint64_t base, uint64_t len) : base_address(base), bytes(len){}
    bool operator<(const Range &other) const;
    void print();
private:
    bool is_in_range(uint64_t input, uint64_t base, uint64_t bytes) const;
    uint64_t base_address;
    uint64_t bytes;
};

void Range::print() {
    printf("print: base_addr 0x%llx bytes 0x%llx\n", base_address, bytes);
}

bool Range::is_in_range(uint64_t input, uint64_t  base, uint64_t bytes) const {
    if ((input >= base) && (input <= base + bytes)) {
        return true;
    } else {
        return false;
    }
}

bool Range::operator<(const Range &other) const {
    if (0) {
        printf("comparator: self  addr 0x%llx bytes 0x%llx\n", base_address, bytes);
        printf("comparator: other addr 0x%llx bytes 0x%llx\n", other.base_address, other.bytes);
    }
    
    // -------------------------------------------------------------
    // Check for overlap and return false (to make them look equal)
    // -------------------------------------------------------------
    // Is the other's head in the range or its tail is in the range ...
    if (is_in_range(other.base_address, base_address, bytes) ||
         is_in_range(other.base_address + bytes, base_address, bytes)) {
        printf("equal_case: self: 0x%llx 0x%llx, other: 0x%llx 0x%llx\n",
               base_address, bytes, other.base_address, other.bytes);
        return false;
    }
    
    if ((base_address + bytes) > other.base_address) {
        return false;
    } else {
        return true;
    }
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
    x.insert(two);
    x.insert(three);
    x.insert(four);
    x.insert(one);
    
    printf("TEST: Making sure overlaps are not added\n");
    x.insert(three);
    x.insert(three_head_overlap);
    x.insert(three_tail_overlap);
    XCTAssert(x.size() == 4, "size expected 2 found %ld", x.size());
    
    for (set<Range>::iterator itr = x.begin(); itr != x.end(); itr++) {
        static_cast<Range>(*itr).print();
    }
}

@end
