//
//  TestIterators.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 12/12/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <tuple>
#include <array>
#include <set>
#include <map>

using std::cout;
using std::endl;

#pragma mark - C++

#pragma mark - Test
@interface TestIterators : XCTestCase

@end

@implementation TestIterators

- (void)setUp {
    [super setUp];
    cout << "=============" << endl;
}

- (void)tearDown {
    cout << "=============" << endl;
    [super tearDown];
}

- (void) testTuplesAndPairs {
    std::pair<int, float>  p{2, 3.5};
    std::tuple<int, float> pp{2, 3.5};
    
    for (auto v : {2, 3, 5, 6, 7}) {
        cout << v << endl;
    }
    
    cout << p.first << " " << p.second << endl;
    cout << std::get<0>(p) << " " << std::get<1>(p) << endl;
    cout << std::get<0>(pp) << " " << std::get<1>(pp) << endl;
}

- (void) testArrays {
    std::array<int, 5> a;
    a[2] = 3;
    a[6] = 3;
    for (const auto & v : a) {
        cout << v << endl;
    }
}

- (void) testMultiSet {
    std::multiset<int> a;
    
    /* Insert */
    a.insert(3);
    a.insert(3);
    a.insert(3);
    a.insert(5);
    
    XCTAssert(a.count(3) == 3);
    XCTAssert(a.count(5) == 1);
    XCTAssert(a.size() == 4);
    
    for (const auto &v : a) {
        cout << v << endl;
    }
    
    /* Find */
    a.erase(a.find(5));
    
    XCTAssert(a.size() == 3);
    
    cout << "====" << endl;
    
    for (const auto & v: a) {
        cout << v << endl;
    }

    cout << "size of multiset " << sizeof(a) << endl;
}

- (void) testMultiMap {
    std::multimap<int, float> a;
    
    /* Insert */
    a.insert(std::pair<int, float>{2, 3.5});
    a.insert(std::pair<int, float>(2, 4.5));
    /* This is easier and there is template type inference */
    a.insert(std::make_pair(3, 5.2));
    a.insert(std::make_pair(3, 5.5));
    
    
    /* Iterate */
    for (const auto &v : a) {
        cout << v.first << endl;
        cout << v.second << endl;
    }
    
    /* Iterate manually */
    for (auto _begin = a.begin(), _end = a.end(); _begin != _end; ++_begin) {
        cout << _begin->first << " " << _begin->second << endl;
    }
    
    /* Group By */
    cout << "Doing a group by " << endl;
    auto x = a.equal_range(3);
    for (auto itr = x.first; itr != x.second; ++itr) {
        cout << itr->first << " " << itr->second << endl;
    }
}

@end
