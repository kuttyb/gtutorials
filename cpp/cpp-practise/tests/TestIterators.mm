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
    cout << std::get<0>(pp) << " " << std::get<1>(pp) << endl;
}

@end
