//
//  chipdispatch.h
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef chip_h
#define chip_h

#pragma mark - BRNTable
struct BRNTable {
	const static bool brn1 = false;
	const static bool brn2 = false;
    const static bool brn3 = false;
};

#pragma mark - G4
struct G4 {
	struct BRN : public BRNTable {
		const static bool brn2 = true;
	};
};

#pragma mark - G5
struct G5 {
	struct BRN : public BRNTable {
		const static bool brn1 = true;
	};
};

#pragma mark - G5G
struct G5G {
	struct BRN : public BRNTable {
		const static bool brn3 = true;
	};
};

#endif /* chip_h */
