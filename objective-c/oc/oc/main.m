//
//  main.m
//  oc
//
//  Created by kutty banerjee on 1/3/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KBTwo.h"
#import "KBNode.h"
#import "KBThree.h"

// Non-Class/Instance methods can have C-syntax
static id<KBNode> factory(void) {
	return [[KBOne alloc]init];
}

int main(int argc, const char * argv[])
{
	@autoreleasepool {
		id<KBNode> one = factory();
		NSLog(@"return value is %d", [one add:3 INPUTTWO:5]);
//		NSLog(@"property value is %d", [one localProp]);
//		NSLog(@"public var is %d", one->pubVar);
		[one dumpState];
		[one compareThree:20 TWO:10 THREE:3];
		[one dumpState];
	}
	
    return 0;
}

