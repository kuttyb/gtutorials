//
//  Test.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "Test.h"

@implementation Test

-(void) checkState:(id<KBNode>) input {
	int x = [input add:2 INPUTTWO:3];
	[input dumpState];
	[input compareThree:x TWO:1 THREE:1];
}

@end
