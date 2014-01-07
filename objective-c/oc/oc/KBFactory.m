//
//  KBFactory.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "KBFactory.h"
#import "KBOne.h"
#import "KBTwo.h"
#import "KBThree.h"

@implementation KBFactory

+ (id<KBNode>) initOne {
	return [[KBOne alloc] init];
}

+ (id<KBNode>) initTwo {
	return [[KBTwo alloc] init];
}

+ (id<KBNode>) initThree {
	return [[KBThree alloc] init];
}

@end
