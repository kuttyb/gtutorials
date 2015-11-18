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
#include "nested.hpp"

using std::cout;
using std::endl;

@interface testagx2 : XCTestCase

@end

@implementation testagx2 {
    AGXAccel * accel;
	AGXChannel * channel;
}

- (void)setUp {
    [super setUp];
    cout << "==============" << endl;
}

- (void)tearDown {
	delete channel;
    delete accel;
    [super tearDown];
    cout << "==============" << endl << endl;
}

- (void)testG4 {
	channel = new AGXChannelG4();
    accel = new AGXAccelG4(channel);
	
    accel->init();
    accel->close();
}

- (void)testG5 {
	channel = new AGXChannelG5();
    accel = new AGXAccelG5(channel);
	
    accel->init();
    accel->close();
	
	channel->close();
}

- (void)testG5G {
	channel = new AGXChannelG5G();
    accel = new AGXAccelG5G(channel);
	
    accel->init();
    accel->close();
}

- (void)testG5GC0 {
	channel = new AGXChannelG5GC0();
	accel   = new AGXAccelG5GC0(channel);
	
	accel->init();
	channel->submit();
	accel->close();
}

- (void) testExport {
	Nested<int> a;
	a.init();
}

@end
