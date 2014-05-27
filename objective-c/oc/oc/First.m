//
//  First.m
//  oc
//
//  Created by kuttyb on 5/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "First.h"
#import "FirstDisplay.h"

/** Class Extension : Use it to place your Protected fields and properties */
/** Place Private Fields and fields within the @implementation */
@interface First ()

- (void) protectedMethod;

@property (readwrite) int protectedField;

@end


@implementation First {
    int privateField;
}

/** Private methods are damn simple, just place them inside the body and nobody will know */
-(void) privateMethod {
    NSLog(@"private method First class\n");
}

-(void) printValues {
    NSLog(@"printing First#printvalues\n%@", self);
    [self protectedMethod];
    [self crazyLastMinuteAddition];
}

-(int)  addNumbers : (int) one SECOND : (int) second {
    return one + second;
}

- (void) protectedMethod {
    NSLog(@"protected method in First speaking");
}

@end


@implementation Second

-(void) printValues {
    NSLog(@"printing Second#printvalues\n%@", self);
    [self protectedMethod];
}

@end
