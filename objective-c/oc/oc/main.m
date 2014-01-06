//
//  main.m
//  oc
//
//  Created by kutty banerjee on 1/3/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KBOne.h"

int main(int argc, const char * argv[])
{

	@autoreleasepool {
		KBOne *one = [[KBOne alloc] init];
		NSLog(@"return value is %d", [one add:3 INPUTTWO:5]);
		NSLog(@"property value is %d", [one localProp]);
		NSLog(@"public var is %d", one->pubVar);
	}
	
    return 0;
}

