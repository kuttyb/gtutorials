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

#pragma mark - BRNTable
struct BRNTable {
	const static bool brn1 = false;
	const static bool brn2 = false;
    const static bool brn3 = false;
};

#pragma mark - G4
struct G4 {
    typedef AccelGen1<G4>   accel;
    typedef ChannelGen1<G4> channel;
    
	struct BRN : public BRNTable {
		const static bool brn2 = true;
	};
};

#pragma mark - G5
struct G5 {
    typedef AccelGen1<G5>   accel;
    typedef ChannelGen2<G5> channel;
    
	struct BRN : public BRNTable {
		const static bool brn1 = true;
	};
};

#pragma mark - G5G
struct G5G {
    typedef AccelGen2<G5G>   accel;
    typedef ChannelGen1<G5G> channel;
    
	struct BRN : public BRNTable {
		const static bool brn3 = true;
	};
};

#endif /* chip_h */
