//
//  AGXAccelerator.cpp
//  cpp-practise
//
//  Created by kutty banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include "AGXAccelerator.h"
#include "Accelerator.hpp"

#define LIST_G4 G4::accel, G4
#define LIST_G5 G5::accel, G5

#pragma mark - G4
void AGXAcceleratorG4::init() {
	AcceleratorImpl<LIST_G4>::init(&accel);
}

void AGXAcceleratorG4::enumerate() {
	AcceleratorImpl<LIST_G4>::enumerate(&accel);
}

#pragma mark - G5
void AGXAcceleratorG5::init() {
	AcceleratorImpl<LIST_G5>::init(&accel);
}

void AGXAcceleratorG5::enumerate() {
	AcceleratorImpl<LIST_G5>::enumerate(&accel);
}

