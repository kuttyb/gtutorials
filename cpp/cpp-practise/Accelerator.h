//
//  Accelerator.h
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef Accelerator_hpp
#define Accelerator_hpp

#include "Channel3D.h"
#include "chip.h"

struct AcceleratorG4 {
	G4::channel3D * channel3D;
    uintptr_t     base_address;
};

struct AcceleratorG5 {
    AcceleratorG4   base;
	G5::channel3D * channel3D;
    uintptr_t       patch_address;
};

#endif /* Accelerator_hpp */
