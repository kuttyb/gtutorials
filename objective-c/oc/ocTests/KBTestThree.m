//
//  KBTestThree.m
//  oc
//
//  Created by Kutty Banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "KBFactory.h"
#import "KBNode.h"
#import "KBTest.h"

@interface KBTestThree : XCTestCase

@property(nonatomic, strong) id <KBNode> subject;
@end

@implementation KBTestThree

- (void)setUp
{
    [super setUp];
    self.subject = [KBFactory initThree];
}

//
// NSMutableArray - addObject, count, removeLastObject, replaceObjectAtIndex, array[index]
//
// NSNumber       - numberWithType (to create)
//                - typeValue      (to extract)
//
// NSLog          - @"format %@"   @ before any string and %@ to print the objects internals
//                - Use @"%@" to print out NSString as well
//
- (void)testArray
{
    // Create a mutable array and add some numbers into it
    NSArray * data = [[NSMutableArray alloc]init];
    [data addObject:[NSNumber numberWithInt:3]];
    [data addObject:[NSNumber numberWithInt:31]];
    [data addObject:[NSNumber numberWithInt:22]];
    [data addObject:@"random number"];
    
    XCTAssert([data count] == 4);
    
    // Insert object
    [data replaceObjectAtIndex:1 withObject:[NSNumber numberWithInt:50]];
    XCTAssert([data count] == 4);
    
    XCTAssert([data[2] integerValue] == 22);
    
    // Iterate over it
    for (NSObject * temp in data)
    {
        NSLog(@"contents are %@", temp);
        NSLog(@"description is %@", [temp description]);
        NSLog(@"-----");
    }
    
    // Good now remove 2 objects
    [data removeLastObject];
    XCTAssert([data count] == 3);
    
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    [KBTest test_body:self.subject];
}

@end
