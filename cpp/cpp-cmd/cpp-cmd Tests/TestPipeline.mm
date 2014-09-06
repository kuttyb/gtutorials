//
//  TestPipeline.mm
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <string>
#include "Header.h"

using std::cout;
using std::endl;
using std::string;

#pragma mark C++ Data Classes
struct PipelineFirst {
    int m_data;
    int m_moredata;
    float m_fdata;
    PipelineFirst(int data, int moredata, float fdata) :
    m_data(data), m_moredata(moredata), m_fdata(fdata){}
};

struct PipelineSecond {
    string & m_input;
    PipelineSecond(std::string & input) : m_input(input) {}
};

#pragma mark PipelineFirst
template <>
void Pipeline<PipelineFirst>::createContext(PipelineFirst & input) {
    cout << "Creating PipelineFirst" << endl;
}

template<>
void Pipeline<PipelineFirst>::destroyContext(PipelineFirst &input) {
    cout << "Destroying PipelineFirst" << endl;
}

#pragma mark PipelineSecond
template <>
void Pipeline<PipelineSecond>::createContext(PipelineSecond &input) {
    cout << "Creating PipelineSecond" << endl;
}

template <>
void Pipeline<PipelineSecond>::destroyContext(PipelineSecond &input) {
    cout << "Destroying PipelineSecond" << endl;
}

#pragma mark LongPipeline
template <typename T>
void LongPipeline<T>::createContext(T & input) {
    cout << "Generic : LongPipeline: createContext" << endl;
    Pipeline<T>::createContext(input);
}

template <typename T>
void LongPipeline<T>::destroyContext(T & input) {
    cout << "Generic: LongPipeline: destroyContext" << endl;
    Pipeline<T>::destroyContext(input);
}


#pragma mark Client Class
template <typename T>
void operate(Pipeline<T> & pipeline, T & input) {
    pipeline.createContext(input);
    pipeline.destroyContext(input);
}

template <typename T>
void longoperate(LongPipeline<T> & pipeline, T & input) {
    pipeline.createContext(input);
    pipeline.destroyContext(input);
}

@interface TestPipeline : XCTestCase

@end

@implementation TestPipeline

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
    PipelineFirst first(2, 3, 4.8f);
    //    Pipeline<PipelineFirst> x;
    LongPipeline<PipelineFirst> x;
    
    longoperate(x, first);
}

@end
