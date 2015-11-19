//
//  chipdispatch.h
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef chip_h
#define chip_h

/* [a] Place no includes here
 * [b] Only include this file from Public Hal headers and this should be the last include 
 */

#pragma mark - BRNTable
struct BRNTable {
	const static bool brn1 = false;
	const static bool brn2 = false;
    const static bool brn3 = false;
	const static bool brn4 = false;
};

#pragma mark - G5GC0
struct G4 {
    using	accel		= AccelGen1<G4>;
    using	channelTA	= ChannelGen1<DMTA<G4>, G4>;
	using	channel3D	= ChannelGen1<DM3D<G4>, G4>;
	using	channelCL	= ChannelGen1<DMCL<G4>, G4>;
	using	gart		= GartBase<G4>;
	
	struct BRN : public BRNTable {
		const static bool brn2 = true;
	};
};

#pragma mark - G5
struct G5 {
    using	accel	    = AccelGen1<G5>;
	using	channelTA	= ChannelGen2<DMTA<G5>, G5>;
	using	channel3D	= ChannelGen2<DM3D<G5>, G5>;
	using	channelCL	= ChannelGen2<DMCL<G5>, G5>;
	using	gart		= GartBase<G5>;
	
	struct BRN : public BRNTable {
		const static bool brn1 = true;
	};
};

#pragma mark - G5G
struct G5G {
	using   accel		= AccelGen2<G5G>;
	using	channelTA	= ChannelGen1<DMTA<G5G>, G5G>;
	using	channel3D   = ChannelGen1<DM3D<G5G>, G5G>;
	using	channelCL	= ChannelGen1<DMCL<G5G>, G5G>;
	using	gart		= GartGen1<G5G>;
	
	struct BRN : public BRNTable {
		const static bool brn3 = true;
		const static bool brn4 = true;
	};
};

#pragma mark - G5GC0
struct G5GC0 {
	using accel		 = AccelGen2<G5GC0>;
	using channelTA  = ChannelGen1<DMTA<G5GC0>, G5GC0>;
	using channel3D  = ChannelGen1<DM3D<G5GC0>, G5GC0>;
	using channelCL  = ChannelGen1<DMCL<G5GC0>, G5GC0>;
	using gart		 = GartGen1<G5GC0>;
	
	struct BRN : public BRNTable {
	};
};

#endif /* chip_h */
