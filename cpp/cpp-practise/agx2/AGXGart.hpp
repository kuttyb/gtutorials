//
//  AGXGart.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/18/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXGart_hpp
#define AGXGart_hpp

#include <assert.h>
#include "Accel.hpp"
#include "AGXAccel.hpp"
#include "chipdispatch.h"

class AGXGart {
public:
	virtual void setup()  = 0;
	virtual ~AGXGart() {}
};

class AGXGartG4 : public AGXGart {
	G4::gart gart;
public:
	AGXGartG4(AGXAccel * accel) {
		AGXAccelG4 * g4Accel = dynamic_cast<AGXAccelG4 *>(accel);
		assert(g4Accel);
		gart.accel = &g4Accel->accel;
	}
	void setup();
};

class AGXGartG5 : public AGXGart {
	G5::gart gart;
public:
	AGXGartG5(AGXAccel * accel) {
		AGXAccelG5 * g5Accel = dynamic_cast<AGXAccelG5 *>(accel);
		assert(g5Accel);
		gart.accel = &g5Accel->accel;
	}
	void setup();
};

class AGXGartG5G : public AGXGart {
	G5G::gart gart;
public:
	AGXGartG5G(AGXAccel * accel) {
		AGXAccelG5G * g5gAccel = dynamic_cast<AGXAccelG5G *>(accel);
		assert(g5gAccel);
		gart.accel = &g5gAccel->accel;
	}
	void setup();
};

class AGXGartG5GC0 : public AGXGart {
	G5GC0::gart gart;
public:
	AGXGartG5GC0(AGXAccel * accel) {
		AGXAccelG5GC0 * g5Accel = dynamic_cast<AGXAccelG5GC0 *>(accel);
		assert(g5Accel);
		gart.accel = &g5Accel->accel;
	}
	void setup();
};

#endif /* AGXGart_hpp */
