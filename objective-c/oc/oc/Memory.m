//
//  Memory.m
//  oc
//
//  Created by Kutty Banerjee on 10/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "Memory.h"

@implementation Memory {
    NSArray * list;
    uint32_t  capacity;
}

#pragma makr - Non Default Constructor
-(id) initWithData:(uint32_t) max_elements
{
    self = [super init];
    if (self)
    {
        capacity = max_elements;
    }
    
    return self;
}

#pragma mark - Static Factory
+(Memory*) newMemory:(uint32_t) max_elements
{
    return [[Memory alloc] initWithData:max_elements];
}

-(void) printIndex:(uint32_t) index COUNT:(uint32_t) count
{
    printf("capacity is %d", capacity);
}

@end
