//
//  MemoryWrapper.m
//  oc
//
//  Created by Kutty Banerjee on 10/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "MemoryWrapper.h"
#import "Memory.h"

@implementation MemoryWrapper {
    Memory * object;
}

-(id) initWithData:(uint32_t) max_elements
{
    self = [super init];
    if (self) {
        object = [[Memory alloc] initWithData:max_elements];
    }
    
    return self;
}

/*
 * I think ARC is silently placing a _post_dealloc method at the bottom which is responsible for calling release
 * on the Member variables and also doing [super deallloc] for you.
 */
-(void) dealloc
{
    printf("MemoryWrapper dealloc\n");
}

-(void) printIndex:(uint32_t) index COUNT:(uint32_t) count
{
    [object printIndex:index COUNT:count];
}

@end
