//
//  Accelerator.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "chip.h"
#include "Accelerator.h"
#include "Channel3D.hpp"
#include "BRN.hpp"

#ifndef _Accelerator_hpp
#define _Accelerator_hpp
using std::cout;
using std::endl;

#pragma mark - G4 specializations
template <typename Config>
class AcceleratorImpl<G4::accel, Config> {
public:
	static void init(G4::accel * accel) {
		cout << "Accel_init: G4" << endl;
	}
	
	static void enumerate(G4::accel * accel) {
        cout << " Enumerate: G4 version" << endl;
	}
};

#pragma mark - G5 specializations
template <typename Config>
class AcceleratorImpl<G5::accel, Config> {
public:
	static void init(G5::accel * accel) {
        assert(accel->channel3D);
        
		/* Punt to G4 */
		AcceleratorImpl<G4::accel, Config>::init(&accel->base);
		
		/* G5 logic */
		cout << "Accel_init: G5" << endl;
	}
	
	static void enumerate(G5::accel * accel) {
        assert(accel->channel3D);
        
		cout << " Enumerate: G5 version" << endl;
		
		AcceleratorImpl<G4::accel, Config>::enumerate(&accel->base);
	}
};

#endif //_Accelerator_hpp
