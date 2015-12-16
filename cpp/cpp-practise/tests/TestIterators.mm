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
    std::array<int, 5> a = {0, 1, 2, 3, 4};
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
    a.insert(std::make_pair(4, 2.2));
    a.insert(std::make_pair(3, 5.5));
    a.insert(std::make_pair(4, 3.1));
    a.insert(std::make_pair(3, 5.2));
    
    
    /* Iterate */
    cout << "foreach iteration" << endl;
    for (const auto &v : a) {
        cout << v.first << endl;
        cout << v.second << endl;
    }
    
    /* Iterate manually */
    cout << "Manual iteration" << endl;
    for (auto _begin = a.begin(), _end = a.end(); _begin != _end; ++_begin) {
        cout << _begin->first << " " << _begin->second << endl;
    }
    
    /* Group By a single key */
    cout << "Doing a group by " << endl;
    auto x = a.equal_range(3);
    for (auto itr = x.first; itr != x.second; ++itr) {
        cout << itr->first << " " << itr->second << endl;
    }
    
    /* Group By the entire collection */
    {
        cout << "===============" << endl;
        for (auto itr = a.begin(); itr != a.end(); ) {
            int key = itr->first;
            cout << "using key : " << key << endl;
            
            auto m = a.equal_range(key);
            auto inner_itr = m.first;
            for (; inner_itr != m.second; ++inner_itr) {
                cout << "\t " << inner_itr->second << endl;
            }
            itr = inner_itr;
        }
        cout << "===============" << endl;
    }
    
    /* Find */
    auto b = a.find(2);
    
    /* Erase */
    cout << "size before " << a.size() << endl;

    a.erase(b); /* This will erase the first occurence of 2, not all 2s */
    a.erase(2); /* This will erase all occurrences of 2 */
    
    /* And this is of course totally range based */
    auto y = a.equal_range(4);
    a.erase(y.first, y.second);
    
    cout << "size after " << a.size() << endl;
    /* Ensure erase worked */
    for (auto _begin = a.begin(), _end = a.end(); _begin != _end; ++_begin) {
        cout << _begin->first << " " << _begin->second << endl;
    }
    
    cout << "sizeof multimap is " << sizeof(a) << endl;
}

@end
