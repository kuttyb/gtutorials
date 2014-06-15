//
//  TestTypeList.mm
//  cpp-cmd
//
//  Courtesy the Loki Library by Andrei Alexandrescu
//  <Modified how we traverse and store elements>
//  <Also keeping operations on TypeList separate from
//   the TypeList datastructure>
//
//  Created by kuttyb on 6/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

template <typename HEAD, typename TAIL>
struct TypeList {
    typedef HEAD head;
    typedef TAIL tail;
    head first;
    tail last;
};

template <typename H, typename T>
struct Work {
    static void work(TypeList<H, T> input) {
        cout << "Head's value is " << input.first << endl;
        
        // Recurse ...
        Work<typename T::head, typename T::tail>::work(input.last);
    }
};

template <typename H>
struct Work <H, voidPtr> {
    static void work(TypeList<H, voidPtr> input) {
        cout << "Tail's value is " << input.last << endl;
    }
};

@interface TestTypeList : XCTestCase

@end

@implementation TestTypeList

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}


- (void)testExample
{
    TypeList<int, TypeList<int, TypeList<float, TypeList<double*, voidPtr> > > > x;
    
    Work<int, TypeList<int, TypeList<float, TypeList<double*, voidPtr> > > >::work(x);
}

@end
