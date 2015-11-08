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
#include "chipdispatch.h"
#include "AGXChannel3D.h"

class AGXAccelerator {
public:
	virtual void init()      = 0;
	virtual void enumerate() = 0;
	virtual ~AGXAccelerator() {}
    /* Setters */
    virtual void setChannel(AGXChannel3D * channel) = 0;
};

class AGXAcceleratorG4 : public AGXAccelerator {
private:
	G4::accel accel;
public:
	void init() override;
	void enumerate() override;
    void setChannel(AGXChannel3D * channel) override {
        accel.channel3D = &((AGXChannel3DG4 *)channel)->channel;
    }
};

class AGXAcceleratorG5 : public AGXAccelerator {
private:
	G5::accel accel;
public:
	void init() override;
	void enumerate() override;
    void setChannel(AGXChannel3D * channel) override {
        accel.channel3D = &((AGXChannel3DG5 *) channel)->channel;
        accel.base.channel3D = &((AGXChannel3DG5 *) channel)->channel.base;
    }
};

#endif /* AGXAccelerator_h */
