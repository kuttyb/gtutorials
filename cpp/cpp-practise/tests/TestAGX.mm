//
//  TestAGX.mm
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "AGXAccelerator.h"
#include "AGXChannel3D.h"

@interface TestAGX : XCTestCase

@end

@implementation TestAGX {
	AGXAccelerator * hAccel;
	AGXChannel3D   * hChannel;
}

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
	delete hAccel;
	delete hChannel;
    [super tearDown];
}


#pragma mark - Test AGX
- (void) testG5HAL {
	hAccel   = new AGXAcceleratorG5();
	hChannel = new AGXChannel3DG5();

	hAccel->init();
	hAccel->enumerate();
	
	hChannel->init();
	hChannel->submit();
}

-(void) testG4HAL {
	hAccel   = new AGXAcceleratorG4();
	hChannel = new AGXChannel3DG4();
	
	hAccel->init();
	hAccel->enumerate();
	
	hChannel->init();
	hChannel->submit();
}

@end
