//
//  PerfVirtualCalls.m
//  cpp-practise
//
//  Created by kuttyb on 12/7/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>
#include <mutex>
#include "benchmark.h"

using std::cout;
using std::endl;
using std::mutex;

#pragma mark - Test Classes

class Third {
private :
    mutex lock;
public:
    virtual int process(int a, int b) {
        int val;
//        lock.lock();
        val = a + b;
//        lock.unlock();
        return val;
    }
};

class Second {
private:
    Third * subject;

public:
    Second(Third * input) : subject(input){}

    virtual int process(int a, int b) {
        return subject->process(subject->process(a, b),
                                subject->process(a, b));
    }
};

class First {
private:
    Second * subject;
    
public:
    First(Second * input): subject(input) {}

    virtual int process(int a, int b) {
        return subject->process(a, b);
    }
};

@interface PerfVirtualCalls : XCTestCase

@end

@implementation PerfVirtualCalls

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testExample {
    const int MAX = 10000000;
    First * first = new First(new Second(new Third()));
    
    int value = 0;
    perf::benchmark<std::chrono::milliseconds>([&value, first](){
        for (int i = 0; i < MAX; ++i) {
            if ((i % 5) == 0) {
                value += first->process(10, 3);
            } else {
                value += first->process(2, 3);
            }
        }
    }, 5);

    cout << "value is " << value << endl;
}

@end
