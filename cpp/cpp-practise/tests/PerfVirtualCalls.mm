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
        return subject->process(a, b);
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
    const int MAX = 1000000000;
    First * first = new First(new Second(new Third()));
    
    int value = 0;
    cout << "first is " << first << endl;
    benchmark<std::chrono::milliseconds>([&value, first](){
        cout << "first inside is " << first << endl;
        
        for (int i = 0; i < MAX; ++i) {
            if ((i % 5) == 0) {
                value += first->process(10, 3);
            } else {
                value += first->process(2, 3);
            }
        }
    });

    cout << "value is " << value << endl;
}

@end
