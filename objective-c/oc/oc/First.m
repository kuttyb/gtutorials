//
//  First.m
//  oc
//
//  Created by kuttyb on 5/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import "First.h"

@interface First ()

- (void) protectedMethod;

@end

@implementation First

-(void) printValues {
    NSLog(@"printing First#printvalues\n%@", self);
    [self protectedMethod];
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
