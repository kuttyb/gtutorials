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
#include "chipdispatch.h"
#include "Accel.hpp"
#include "AGXChannel.hpp"

class AGXAccel {
public:
    virtual void init() = 0;
    virtual void close() = 0;
    virtual ~AGXAccel() {}
};

class AGXAccelG4 : public AGXAccel{
    G4::accel accel;
public:
	AGXAccelG4(AGXChannel * ch) {
		AGXChannelG4 * channel = dynamic_cast<AGXChannelG4 *>(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
    void init()  override;
    void close() override;
};

class AGXAccelG5 : public AGXAccel {
    G5::accel accel;
public:
	AGXAccelG5(AGXChannel * ch) {
		AGXChannelG5 * channel = dynamic_cast<AGXChannelG5 * >(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
    void init()  override;
    void close() override;
};

class AGXAccelG5G : public AGXAccel {
    G5G::accel accel;
public:
	AGXAccelG5G(AGXChannel * ch) {
		AGXChannelG5G * channel = dynamic_cast<AGXChannelG5G *>(ch);
		assert(channel);
		accel.channel = &channel->channel;
	}
    void init()  override;
    void close() override;
};


#endif /* AGXAccel_hpp */
