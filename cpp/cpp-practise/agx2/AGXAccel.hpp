//
//  AGXAccel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXAccel_hpp
#define AGXAccel_hpp

#include <assert.h>
#include "Accel.hpp"
#include "AGXChannel.hpp"
#include "Gart.hpp"
#include "chipdispatch.h"

class AGXAccel {
public:
    virtual void init() = 0;
    virtual void close() = 0;
    virtual ~AGXAccel() {}
};

class AGXAccelG4 : public AGXAccel{
public:
	G4::accel accel;

	AGXAccelG4(AGXChannel * ch) {
		AGXChannelG4 * channel = dynamic_cast<AGXChannelG4 *>(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
    void init()  override;
    void close() override;
};

class AGXAccelG5 : public AGXAccel {
public:
	G5::accel accel;

	AGXAccelG5(AGXChannel * ch) {
		AGXChannelG5 * channel = dynamic_cast<AGXChannelG5 * >(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
    void init()  override;
    void close() override;
};

class AGXAccelG5G : public AGXAccel {
public:
	G5G::accel accel;

	AGXAccelG5G(AGXChannel * ch) {
		AGXChannelG5G * channel = dynamic_cast<AGXChannelG5G *>(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
    void init()  override;
    void close() override;
};

class AGXAccelG5GC0 : public AGXAccel {
public:
	G5GC0::accel accel;

	AGXAccelG5GC0(AGXChannel * ch) {
		AGXChannelG5GC0 * channel = dynamic_cast<AGXChannelG5GC0 *>(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
	void init()  override;
	void close() override;
};

#endif /* AGXAccel_hpp */
