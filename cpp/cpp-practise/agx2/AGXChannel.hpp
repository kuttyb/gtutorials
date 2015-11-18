//
//  AGXChannel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXChannel_hpp
#define AGXChannel_hpp

#include "Accel.hpp"
#include "Channel.hpp"
#include "chipdispatch.h"

class AGXChannel {
public:
    virtual void init()  = 0;
    virtual void close() = 0;
	virtual void submit() = 0;
	virtual ~AGXChannel() {}
};

class AGXChannelG4 : public AGXChannel {
public:
	G4::channelTA channel;
	
	void init()  override;
	void submit() override;
    void close() override;
};

class AGXChannelG5 : public AGXChannel {
public:
	G5::channelTA channel;

	void init()  override;
	void submit() override;
	void close() override;
};

class AGXChannelG5G : public AGXChannel {
public:
	G5G::channelTA channel;

	void init()  override;
	void submit() override;
	void close() override;
};

class AGXChannelG5GC0 : public AGXChannel {
public:
	G5GC0::channelTA channel;
	
	void init()  override;
	void submit() override;
	void close() override;
};

#endif /* AGXChannel_hpp */
