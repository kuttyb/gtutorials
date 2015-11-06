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

struct AcceleratorG4 {
    Channel3DG4 * channel3d;
    uintptr_t     base_address;
};

struct AcceleratorG5 {
    AcceleratorG4   base;
    Channel3DG5     * channel3d;
    uintptr_t       patch_address;
};

#endif /* Accelerator_hpp */
