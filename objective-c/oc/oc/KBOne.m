//
//  KBOne.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "KBOne.h"

@implementation KBOne {
	// private and protected goes in here
@private int privVar;
@protected int protVar;
}

-(int) add:(int)inputOne INPUTTWO:(int)inputTwo {
	// accessing protected variables is easy, just access them
	pubVar = inputOne + inputTwo;
	
	// properties can use the . notification or setProperty message
	self.localProp = pubVar;
	[self setLocalProp: pubVar];
	
	// Set private and protected values
	privVar = self.localProp;
	protVar = self.localProp;
	
	return pubVar;
}

-(void) dumpState {
	NSLog(@"Dumping State");
	NSLog(@"\tprotVar = %d", protVar);
	NSLog(@"\tprivVar = %d", privVar);
}

@end
