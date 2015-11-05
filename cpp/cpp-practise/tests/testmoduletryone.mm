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

@implementation testmoduletryone {
	ModuleOne * subject;
}

- (void)setUp {
    [super setUp];
	subject = new ModuleOneG4();
}

- (void)tearDown {
	delete subject;
    [super tearDown];
}

- (void)testBasic {
	subject->stop_tryone();
	subject->stop_tryone();
}

@end
