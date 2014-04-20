//
//  TestLonePtr.m
//  cpp-code
//
//  Created by Kutty Banerjee on 4/18/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <vector>
#include <string>
#include "LonePtr.hpp"

@interface TestLonePtr : XCTestCase

@end

template class LonePtr<int>;

@implementation TestLonePtr {
    LonePtr<int> subject;
}

- (void)setUp
{
    [super setUp];
    subject.setIfNotSet(new int(3));
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testOurMoveWorks
{
    LonePtr<int> x;
    subject.moveto(x);
    XCTAssert(*x == 3, "");
}

- (void) testMoveFailsCompile
{
    LonePtr<int> x;
    x.setIfNotSet(new int());
    
    // when enabled this should fail build
    // subject.test(x);
}

using std::cout;
using std::endl;
using std::string;
using std::vector;

// bottomline is that after a move you can still use the string object
// or so it seems. Unless of course we use unique_ptr
- (void) testMoveSemantics
{
    string x("my data");
    cout << x << endl;
    
    vector<string> list;
    list.push_back(x);
    for (auto temp : list) {
        cout << temp << endl;
    }
    XCTAssert(true, "");
    
    cout << x << endl;
}

using std::unique_ptr;
- (void) testMoveSemanticsUniquePtr
{
    unique_ptr<int> x(new int());
    *x = 2;
    
    vector<unique_ptr<int>> list;
    list.push_back(std::move(x));
    
    if (0) cout << *x << endl;
    
    unique_ptr<int> temp;
    for (auto itr = list.begin(); (itr != list.end()) && (temp = std::move(*itr)); itr++) {
        cout << *temp << endl;
    }
}

@end
