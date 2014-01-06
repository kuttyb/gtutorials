//
//  KBNode.h
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KBNode <NSObject>

-(int) add:(int) inputOne INPUTTWO:(int) inputTwo;

-(void) dumpState;

-(BOOL) compareThree:(int) one TWO:(int) two THREE:(int)three;

@end
