//
//  AGXAccel.cpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include "AGXAccel.hpp"

using std::cout;
using std::endl;

#pragma mark - G4
void AGXAccelG4::init() {
    accel.init();
}

void AGXAccelG4::close() {
    accel.close();
}

#pragma mark - G5
void AGXAccelG5::init() {
    accel.init();
}

void AGXAccelG5::close() {
    accel.close();
}

#pragma mark - G5G
void AGXAccelG5G::init() {
    accel.init();
}

void AGXAccelG5G::close() {
    accel.close();
}

#pragma mark - G5GC0
void AGXAccelG5GC0::init() {
	accel.init();
}

void AGXAccelG5GC0::close() {
	accel.close();
}
