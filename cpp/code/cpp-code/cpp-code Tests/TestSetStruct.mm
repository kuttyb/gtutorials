//
//  TestSetStruct.m
//  cpp-code
//
//  Created by Kutty Banerjee on 5/11/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <set>
#include <iostream>

@interface TestSetStruct : XCTestCase

@end

class Event {
private:
    uint64_t m_type;
    uint64_t m_timestamp;
    uint64_t m_arg0;
    uint64_t m_arg1;
    uint64_t m_arg2;
public:
    Event(uint64_t type, uint64_t timestamp, uint64_t arg0, uint64_t arg1, uint64_t arg2) {
        m_type      = type;
        m_timestamp = timestamp;
        m_arg0      = arg0;
        m_arg1      = arg1;
        m_arg2      = arg2;
    }
    bool operator<(const Event & other) const;
};

bool Event::operator<(const Event & other) const {
    if (other.m_timestamp > m_timestamp)
        return true;
    else
        return false;
}

using std::set;

@implementation TestSetStruct {
    set<Event> *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new set<Event>();
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testBasic
{

}

@end
