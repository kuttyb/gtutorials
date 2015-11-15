//
//  chipdispatch.h
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef chip_h
#define chip_h

#include "Accel.hpp"
#include "Channel.hpp"
#include "dm.hpp"

#pragma mark - BRNTable
struct BRNTable {
	const static bool brn1 = false;
	const static bool brn2 = false;
    const static bool brn3 = false;
	const static bool brn4 = false;
};

#pragma mark - G5GC0
struct G4 {
    typedef AccelGen1<G4>   accel;
    typedef ChannelGen1<DMTA<G4>, G4> channelTA;
	typedef ChannelGen1<DM3D<G4>, G4> channel3D;
	typedef ChannelGen1<DMCL<G4>, G4> channelCL;
	
	struct BRN : public BRNTable {
		const static bool brn2 = true;
	};
};

#pragma mark - G5
struct G5 {
    typedef AccelGen1<G5>   accel;
	typedef ChannelGen2<DMTA<G5>, G5> channelTA;
	typedef ChannelGen2<DM3D<G5>, G5> channel3D;
	typedef ChannelGen2<DMCL<G5>, G5> channelCL;
	
	struct BRN : public BRNTable {
		const static bool brn1 = true;
	};
};

#pragma mark - G5G
struct G5G {
    typedef AccelGen2<G5G>   accel;
	typedef ChannelGen1<DMTA<G5G>, G5G> channelTA;
	typedef ChannelGen1<DM3D<G5G>, G5G> channel3D;
	typedef ChannelGen1<DMCL<G5G>, G5G> channelCL;

	struct BRN : public BRNTable {
		const static bool brn3 = true;
		const static bool brn4 = true;
	};
};

#pragma mark - G5GC0
struct G5GC0 {
	typedef AccelGen2<G5GC0>   accel;
	typedef ChannelGen1<DMTA<G5GC0>, G5GC0> channelTA;
	typedef ChannelGen1<DM3D<G5GC0>, G5GC0> channel3D;
	typedef ChannelGen1<DMCL<G5GC0>, G5GC0> channelCL;

	struct BRN : public BRNTable {
	};
};

#endif /* chip_h */
