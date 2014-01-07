//
//  KBFactory.h
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KBNode.h"

@interface KBFactory : NSObject

+ (id<KBNode>) initOne;
+ (id<KBNode>) initTwo;
+ (id<KBNode>) initThree;

@end
