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
	Channel3D * subject;
}

- (void)setUp {
    [super setUp];
	subject = new Channel3D();
}

- (void)tearDown {
	delete subject;
    [super tearDown];
}

- (void)testG4 {
	Channel3DImpl<G4,G4>::init(subject);
	Channel3DImpl<G4, G4>::submit(subject);
}

- (void)testG5 {
	Channel3DImpl<G5, G5>::init(subject);
	Channel3DImpl<G5, G5>::submit(subject);
}

@end
