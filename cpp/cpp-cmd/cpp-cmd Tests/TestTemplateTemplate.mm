//
//  TestTemplateTemplate.mm
//  cpp-cmd
//
//  Created by Kutty Banerjee on 6/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class First {
public:
    void print() {
        cout << "value is " << endl;
    }
};

template <template <typename> class F, typename T>
class Second {
public:
    // You cannot do F<T> unless F is declared as Template Template Parameter
    void use(F<T> local) {
        cout << "Generic version speaking" << endl;
        local.print();
    }
};

// Nothing fancy about the partial specialization as you can see, its just
// regular<F, int>
template <template <typename> class F>
class Second <F, int> {
public:
    void use(F<int> local) {
        cout << "int version speaking" << endl;
        local.print();
    }
};

@interface TestTemplateTemplate : XCTestCase

@end

@implementation TestTemplateTemplate

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
    // This will use the Generic version
    {
        First<float> a;
        Second<First, float> b;
        b.use(a);
    }

    cout << "-------------------" << endl;

    // This will use the Partially specialized version for int
    {
        First<int> a;
        Second<First, int> b;
        b.use(a);
    }
}

@end
