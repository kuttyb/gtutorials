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
	id<KBNode> value =  [[KBOne alloc] init];
    [value autorelease];
    return value;
}

+ (id<KBNode>) initTwo {
    id<KBNode> value = [[KBTwo alloc] init];
    [value autorelease];
    return value;
}

+ (id<KBNode>) initThree {
    id<KBNode> value = [[KBThree alloc] init];
    [value autorelease];
    return value;
}

@end
