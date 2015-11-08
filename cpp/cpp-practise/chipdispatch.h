//
//  chipdispatch.h
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef chip_h
#define chip_h

struct AcceleratorG4;
struct AcceleratorG5;
struct Channel3DG4;
struct Channel3DG5;

#pragma mark - BRNTable
struct BRNTable {
	const static bool brn1 = false;
	const static bool brn2 = false;
    const static bool brn3 = false;
};

#pragma mark - G4
struct G4 {
    typedef AcceleratorG4 accel;
    typedef Channel3DG4   channel3D;
    
	struct BRN : public BRNTable {
		const static bool brn1 = true;
	};
};

#pragma mark - G5
struct G5 {
    typedef AcceleratorG5 accel;
    typedef Channel3DG5   channel3D;
    
	struct BRN : public BRNTable {
		const static bool brn2 = true;
        const static bool brn3 = true;
	};
};

#endif /* chip_h */
