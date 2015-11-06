//
//  TestAGX.mm
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
//#include "Accelerator.hpp"
//#include "Channel3D.hpp"
#include "AGXAccelerator.h"
#include "AGXChannel3D.h"

@interface TestAGX : XCTestCase

@end

@implementation TestAGX {
//	/* Internal */
//	Channel3DG5    * subject;
//    AcceleratorG5  * accel;

	/* HAL */
	AGXAccelerator * hAccel;
	AGXChannel3D   * hChannel;
}

- (void)setUp {
    [super setUp];
//	subject  = new Channel3DG5();
//    accel    = new AcceleratorG5();
	hAccel   = new AGXAcceleratorG5();
	hChannel = new AGXChannel3DG5();
}

- (void)tearDown {
//    delete accel;
//	delete subject;
	delete hAccel;
	delete hChannel;
    [super tearDown];
}

#pragma mark - Test Internal
//- (void) testG4 {
//    /* Channel */
//    Channel3DImpl::init(&subject->base);
//    Channel3DImpl::submit<Channel3DG4, G4>()(&subject->base);
//    
//    /* Accel */
//    AcceleratorImpl::init(&accel->base);
//}
//
//- (void) testG5 {
//    /* Channel */
//    Channel3DImpl::init(subject);
//    Channel3DImpl::submit<Channel3DG5, G5>()(subject);
//    
//    /* Accel */
//    AcceleratorImpl::init(accel);
//    AcceleratorImpl::enumerate<AcceleratorG5, G5>()(accel);
//}

#pragma mark - Test AGX
- (void) testG5HAL {
	hAccel->init();
	hAccel->enumerate();
	
	hChannel->init();
	hChannel->submit();
}

@end
