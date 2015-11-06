//
//  TestAGX.mm
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Channel3D.hpp"

@interface TestAGX : XCTestCase

@end

@implementation TestAGX {
	Channel3DG5 * subject;
}

- (void)setUp {
    [super setUp];
	subject = new Channel3DG5();
}

- (void)tearDown {
	delete subject;
    [super tearDown];
}

- (void) testG4 {
    Channel3DImpl::init<Channel3DG4>()(&subject->base);
    Channel3DImpl::submit<Channel3DG4, G4>()(&subject->base);
}

- (void) testG5 {
    Channel3DImpl::init<Channel3DG5>()(subject);
    Channel3DImpl::submit<Channel3DG5, G5>()(subject);
}

@end
