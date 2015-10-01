//
//  testmoduletryone.mm
//  cpp-practise
//
//  Created by kuttyb on 2/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include "moduletryone.h"

@interface testmoduletryone : XCTestCase

@end

@implementation testmoduletryone

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testBasic {
	start_tryone();
	stop_tryone();
}

@end
