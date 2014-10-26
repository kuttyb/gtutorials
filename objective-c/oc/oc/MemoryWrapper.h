//
//  MemoryWrapper.h
//  oc
//
//  Created by Kutty Banerjee on 10/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Memory.h"

@interface MemoryWrapper : NSObject

-(id) initWithData:(uint32_t) max_elements;

-(void) printIndex:(uint32_t) index COUNT:(uint32_t) count;

@property (nonatomic, strong) Memory * delegate;

@end
