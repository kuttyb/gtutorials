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
	AcceleratorImpl::init(&accel);
}

void AGXAcceleratorG4::enumerate() {
	AcceleratorImpl::enumerate<G4::accel, G4>()(&accel);
}

#pragma mark - G5
void AGXAcceleratorG5::init() {
	AcceleratorImpl::init(&accel);
}

void AGXAcceleratorG5::enumerate() {
	AcceleratorImpl::enumerate<G5::accel, G5>()(&accel);
}

