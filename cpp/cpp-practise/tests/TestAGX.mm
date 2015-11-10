//
//  TestAGX.mm
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#import <XCTest/XCTest.h>
#include "AGXAccelerator.h"
#include "AGXChannel3D.h"

using std::cout;
using std::endl;

#pragma mark - C++
/* Unspecialized version consumes 1 byte and is a noop */
template <bool val> struct Data {
	void apply() {}
};

template <> struct Data<true> {
	int a;
	int b;
	void apply() {
		cout << "getting work done " << endl << endl;
	}
};

#pragma mark - Test
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
    hAccel->setChannel(hChannel);
    
	hAccel->init();
	hAccel->enumerate();
	
	hChannel->init();
	hChannel->submit();
}

-(void) testG4HAL {
	hAccel   = new AGXAcceleratorG4();
	hChannel = new AGXChannel3DG4();
    hAccel->setChannel(hChannel);
    
	hAccel->init();
	hAccel->enumerate();
	
	hChannel->init();
	hChannel->submit();
}

-(void) testData {
	Data<false> first;
	first.apply();
	
	Data<true> second;
	second.apply();
	
	cout << "sizes false: " << sizeof(first) << " true: " << sizeof(second) << endl;
}

@end
