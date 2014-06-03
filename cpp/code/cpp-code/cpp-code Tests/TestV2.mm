//
//  TestV2.mm
//  cpp-code
//
//  Created by Kutty Banerjee on 5/24/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>
#include <utility>
#include "IA.h"

using std::cout;
using std::endl;
using std::vector;

class B {
public:
	void print() { cout << "b" << endl;}
};

class D1  {
public:
	void print() { cout << "d1" << endl; }
};

class D2 : public D1 {
};

template <size_t ARGS, typename... PARAMS>
class Value {
private:
    std::tuple<PARAMS...> args;
public:
	void parseargs() {
		std::get<ARGS - 1>(args).print();
		if (ARGS <= 1) return;
		
//		Value<ARGS - 1, std::forward<PARAMS>(args)...> y;
//		y.parseargs();
    }
	
};

template <typename T>
void addback(vector<IA<T> > & vec, IA<T> & input) {
    vec.push_back(input);
}

#pragma mark Client (delegates IA)
template <typename IA_FIELD, typename IA_METHOD>
class Client {
private:
    IA_FIELD subject;
    
public:
    void setup(IA<IA_METHOD> input);
};

template <typename IA_FIELD, typename IA_METHOD>
void Client<IA_FIELD, IA_METHOD>::setup(IA<IA_METHOD> input) {
    cout << "member function " << endl;
    input.add(5, 1);
    input.print();
    
    cout << "private field " << endl;
    subject.print();
}


void test_client(void) {
    IA<One> one;
    one.print();
    
    IA<Two> two;
    two.print();
}

void test_class(void) {
    IA<One> input;
    
    Client<Two, One> a;
    a.setup(input);
}


// =================================================================
@interface TestV2 : XCTestCase

@end

@implementation TestV2

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testClient
{
    test_client();
}

- (void)testClass
{
    test_class();
}

- (void)testImplInheritance
{
    Twenty twenty;
    
    Client<One, Twenty> client;
    client.setup(twenty);
}

- (void)testVector
{
    vector<IA<One> > a;
    One x;
    x.print();
    addback(a, x);
    
    IA<One> z = a.at(0);
    z.print();
    addback(a, z);
}

- (void)testVariadicTemplates
{
#if 1
	Value<2, B, D1> x;
	x.parseargs();
#endif
}

@end

