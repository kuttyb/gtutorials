//
//  KBOne.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "KBOne.h"

@implementation KBOne

-(int) add:(int)inputOne INPUTTWO:(int)inputTwo {
	// accessing protected variables is easy, just access them
	pubVar = inputOne + inputTwo;
	
	// properties can use the . notification or setProperty message
	self.localProp = pubVar;
	[self setLocalProp: pubVar];
	
	return pubVar;
}
@end
