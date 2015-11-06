//
//  Channel3D.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "chip.h"
#include "Channel3D.h"
#include "BRN.hpp"

using std::cout;
using std::endl;

#pragma mark - Generic
template <typename Chip, typename Config>
struct Channel3DImpl {

	void init(Channel3D * channel) {
		cout << "common code " << endl;
	}
	
	void submit(Channel3D * channel) {
		assert(!"not implemented");
	}
};

#pragma mark - G4
template <typename Config>
struct Channel3DImpl<G4, Config> {

	void submit(Channel3D * channel) {
		/* This code could get used by non G4 chips, use the BRN appropriately */
		applyBRN1<Config::BRN::BRN1>();

		cout << "Submit : G4" << endl;
	}
};

#pragma mark - G5
template <typename Config>
struct Channel3DImpl<G5, Config> {

	void submit(Channel3D * channel) {
		cout << "Submit : G5" << endl;

		/* Punt back into G4 for some common logic */
		Channel3DImpl<G4, Config>::submit();
		
		applyBRN2<Config::BRN::BRN2>();
	}
};
