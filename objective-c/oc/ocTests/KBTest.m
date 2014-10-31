//
//  KBTest.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "KBTest.h"

@implementation KBTest

+ (void)test_body : (id<KBNode>) subject
{
	@autoreleasepool {
		[subject dumpState];
		[subject compareThree:20 TWO:10 THREE:3];
		[subject dumpState];
	}
    // Testing
}

@end
