//
//  testagx2.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "AGXAccel.hpp"
#include <iostream>

using std::cout;
using std::endl;

@interface testagx2 : XCTestCase

@end

@implementation testagx2 {
    AGXAccel * accel;
}

- (void)setUp {
    [super setUp];
    cout << "==============" << endl;
}

- (void)tearDown {
    delete accel;
    [super tearDown];
    cout << "==============" << endl << endl;
}

- (void)testG4 {
    accel = new AGXAccelG4();
    accel->init();
    accel->close();
}

- (void)testG5 {
    accel = new AGXAccelG5();
    accel->init();
    accel->close();
}

@end
