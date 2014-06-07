//
//  TestTuple.m
//  cpp-code
//
//  Created by Kutty Banerjee on 6/6/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <tuple>

using std::cout;
using std::endl;

template <typename T, typename... Ts>
void printer(const T& t, const Ts&... ts) {
    // Duck Typing
    t.print();
    
    if (sizeof...(ts) == 0) return;
    
    printer(ts...);   // not recursion!
}

@interface TestTuple : XCTestCase

@end

@implementation TestTuple

- (void)setUp
{
    [super setUp];
    cout << "-----" << endl;
}

- (void)tearDown
{
    cout << "-----" << endl;
    [super tearDown];
}

//
// We are going to learn the following here
//      [a] std::tuple
//      [b] std::make_tuple
//      [c] std::tuple_size
//      [d] std::tuple_element
//      [e] std::get<N>(tuple_var)
//
- (void)testLearnMakeAndSizeTuple
{
    // declare a tuple
    std::tuple<int, float> x;
    
    // explicitly initialize it
    x = std::make_tuple(3, 2.1f);
    
    // print its size (using type)
    size_t n = std::tuple_size<std::tuple<int, float> >::value;
    XCTAssert(n == 2);
    
    // get each type
    std::tuple_element<0, std::tuple<int, float> >::type   first_val;
    std::tuple_element<1, std::tuple<int, float> >::type   second_val;
    
    // get each type's value
    first_val   = std::get<0>(x);
    second_val  = std::get<1>(x);
    
    XCTAssert(first_val == 3);
    XCTAssert(second_val == 2.1f);
}

@end
