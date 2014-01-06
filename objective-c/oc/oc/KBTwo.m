//
//  KBTwo.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "KBTwo.h"

@implementation KBTwo

-(void) dumpState {
	NSLog(@"Dumping State for KBTwo");
	NSLog(@"\tprotVar = %d", protVar);
	[super dumpState];
}

@end
