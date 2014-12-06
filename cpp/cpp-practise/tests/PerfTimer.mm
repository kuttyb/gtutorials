//
//  PerfTimer.m
//  cpp-practise
//
//  Created by kuttyb on 12/6/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>
#include <functional>
#include <string>
#include <chrono>

using namespace std;

#pragma mark - Benchmark
template <typename RESOLUTION> std::string time_unit(void) { assert(!"must specialize RESOLUTION"); }
template <> std::string time_unit<std::chrono::nanoseconds>(void)  { return "nanoseconds";}
template <> std::string time_unit<std::chrono::milliseconds>(void) { return "milliseconds";}
template <> std::string time_unit<std::chrono::microseconds>(void) { return "microseconds";}
template <typename RESOLUTION>
void benchmark(std::function<void (void)> code)
{
    auto start = std::chrono::steady_clock::now();
    code();
    auto end   = std::chrono::steady_clock::now();
    cout << " ============ " << endl;
    cout << " Benchmark: Execution time " << std::chrono::duration_cast<RESOLUTION>(end - start).count() << " " << time_unit<RESOLUTION>() << endl;
    cout << " ============ " << endl;
}


@interface PerfTimer : XCTestCase

@end

@implementation PerfTimer

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
    int x = 10;
    benchmark<std::chrono::microseconds>([&x](void) {
        cout << "first line of text" << x << " that is the value" << endl;
    });
}

@end
