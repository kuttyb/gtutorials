//
//  AGXAccelerator.cpp
//  cpp-practise
//
//  Created by kutty banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include "AGXAccelerator.h"
#include "Accelerator.hpp"

#pragma mark - G4
void AGXAcceleratorG4::init() {
	AcceleratorImpl<G4::accel, G4>::init(&accel);
}

void AGXAcceleratorG4::enumerate() {
	AcceleratorImpl<G4::accel, G4>::enumerate(&accel);
}

#pragma mark - G5
void AGXAcceleratorG5::init() {
	AcceleratorImpl<G5::accel, G5>::init(&accel);
}

void AGXAcceleratorG5::enumerate() {
	AcceleratorImpl<G5::accel, G5>::enumerate(&accel);
}

