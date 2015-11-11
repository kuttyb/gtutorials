//
//  AcceleratorG5G.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G5G specializations
template <typename ChipDispatch>
class AcceleratorImpl<G5G::accel, ChipDispatch> {
public:
	static void init(G5G::accel * accel) {
		assert(accel->channel3D);

		/* G5G logic */
		cout << "Accel_init: G5G" << endl;
		
		/* Punt to G4 */
		AcceleratorImpl<G5::accel, ChipDispatch>::init(&accel->base);
		
	}
	
	static void enumerate(G5G::accel * accel) {
		assert(accel->channel3D);
		
		cout << " Enumerate: G5G version" << endl;
		
		AcceleratorImpl<G5::accel, ChipDispatch>::enumerate(&accel->base);
	}
};

