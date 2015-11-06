//
//  AGXAccelerator.h
//  cpp-practise
//
//  Created by kutty banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXAccelerator_h
#define AGXAccelerator_h

#include "Accelerator.h"
#include "chip.h"

class AGXAccelerator {
public:
	virtual void init()      = 0;
	virtual void enumerate() = 0;
	virtual ~AGXAccelerator() {}
};

class AGXAcceleratorG4 : public AGXAccelerator {
private:
	G4::accel accel;
public:
	void init() override;
	void enumerate() override;
};

class AGXAcceleratorG5 : public AGXAccelerator {
private:
	G5::accel accel;
public:
	void init() override;
	void enumerate() override;
};

#endif /* AGXAccelerator_h */
