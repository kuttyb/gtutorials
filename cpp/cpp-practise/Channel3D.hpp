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

	static void init(Channel3D * channel) {
		assert(!"not implemented");
	}
	
	static void submit(Channel3D * channel) {
		assert(!"not implemented");
	}
};

#pragma mark - G4
template <typename Config>
struct Channel3DImpl<G4, Config> {

	static void init(Channel3D * channel) {
		cout << "Common code" << endl;
		cout << "==========" << endl;
	}
	
	static void submit(Channel3D * channel) {
		/* This code could get used by non G4 chips, use the BRN appropriately */
		applyBRN1<Config::BRN::brn1>();

		cout << "Submit : G4" << endl;

		applyBRN2<Config::BRN::brn2>();
	}
};

#pragma mark - G5
template <typename Config>
struct Channel3DImpl<G5, Config> {

	static void init(Channel3D * channel) {
		Channel3DImpl<G4, Config>::init(channel);
	}
	
	static void submit(Channel3D * channel) {
		cout << "Submit : G5" << endl;

		/* Punt back into G4 for some common logic */
		Channel3DImpl<G4, Config>::submit(channel);
		
		applyBRN2<Config::BRN::brn2>();
	}
};
