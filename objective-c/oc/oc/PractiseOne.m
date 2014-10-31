//
//  PractiseOne.m
//  oc
//
//  Created by Kutty Banerjee on 10/18/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Protocols
@protocol One
-(void) one;
@end

@protocol Two
-(void) two;
@end

#pragma mark - Base class
@interface Base : NSObject
@end

@implementation Base
@end

#pragma mark - Derived Class
@interface Basic : Base<One, Two>

- (id<One>) print:(uint32_t) index  NAME:(NSString *) name;

- (uint32_t) calculate:(uint32_t) first  SECOND:(uint32_t) second;

@end

#pragma mark - Category
@interface Base(FIRST_CATEGORY)
-(void) category_one:(uint32_t) value;
@end

@implementation Basic {
    // Private variables go in here
}

- (id<One>) print:(uint32_t)index NAME:(NSString *)name
{
    NSLog(@"printing the print method %d\n", 5);
    return self;
}

-(uint32_t) calculate:(uint32_t)first SECOND:(uint32_t)second
{
    return first + second;
}

-(void) one
{
}

-(void) two
{
}

-(void) category_one:(uint32_t)value
{
}

@end
