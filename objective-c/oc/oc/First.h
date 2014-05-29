//
//  First.h
//  oc
//
//  Created by kuttyb on 5/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface First : NSObject

-(void) printValues;

-(int)  addNumbers : (int) one SECOND : (int) second;

@end


@interface Second : First

@end
