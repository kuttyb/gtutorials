//
//  testagx2.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "AGXAccel.hpp"
#include "AGXGart.hpp"
#include <iostream>
#include "nested.hpp"

using std::cout;
using std::endl;

@interface testagx2 : XCTestCase

@end

@implementation testagx2 {
    AGXAccel   * accel;
	AGXChannel * channel;
	AGXGart	   * gart;
}

- (void)setUp {
    [super setUp];
    cout << "==============" << endl;
}

- (void)tearDown {
	delete gart;
	delete channel;
    delete accel;
    [super tearDown];
    cout << "==============" << endl << endl;
}

- (void)testG4 {
	channel = new AGXChannelG4();
    accel = new AGXAccelG4(channel);
	gart = new AGXGartG4(accel);
	
    accel->init();
    accel->close();
	gart->setup();
}

- (void)testG5 {
	channel = new AGXChannelG5();
    accel = new AGXAccelG5(channel);
	gart = new AGXGartG5(accel);
	
    accel->init();
    accel->close();
	gart->setup();
	
	channel->close();
}

- (void)testG5G {
	channel = new AGXChannelG5G();
    accel = new AGXAccelG5G(channel);
	gart = new AGXGartG5G(accel);
	
    accel->init();
    accel->close();
	gart->setup();
}

- (void)testG5GC0 {
	channel = new AGXChannelG5GC0();
	accel   = new AGXAccelG5GC0(channel);
	gart	= new AGXGartG5GC0(accel);
	
	accel->init();
	channel->submit();
	accel->close();
	gart->setup();
}

- (void) testExport {
	Nested<int> a;
	a.init();
}

@end
