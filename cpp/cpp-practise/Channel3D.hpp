//
//  Channel3D.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef _Channel3D_hpp
#define _Channel3D_hpp

#include <iostream>
#include <assert.h>
#include "chip.h"
#include "Channel3D.h"
#include "BRN.hpp"

using std::cout;
using std::endl;

namespace Channel3DImpl {
#pragma mark - init
	template <typename Channel>
	struct init {
		void operator()(Channel * channel);
	};
	
	/* G4 version */
	template <>
	struct init<Channel3DG4> {
		void operator()(Channel3DG4 * channel) {
			channel->baseAddr = 0xabcd;
			channel->priority = 0;
			channel->runtime  = 0;
		}
	};
	
	/* G5 version */
	template <>
	struct init<Channel3DG5> {
		void operator()(Channel3DG5 * channel) {
			/* Punt to G4 */
			Channel3DImpl::init<Channel3DG4>()(&channel->base);
			channel->estimate = 20;
			channel->values   = 10;
		}
	};
	
#pragma mark - submit
	template <typename Channel, typename Config>
	struct submit {
		void operator()(Channel * channel);
	};
	
	/* G4 version */
	template <typename Config>
	struct submit <Channel3DG4, Config> {
		void operator()(Channel3DG4 * channel) {
			/* This code could get used by non G4 chips, use the BRN appropriately */
			BRN::BRN1<Config::BRN::brn1, Config>()();
			
			cout << "Submit : G4" << endl;
			
			BRN::BRN2<Config::BRN::brn2, Config>()();
			
			BRN::BRN3<Config::BRN::brn3, Config>()();
		}
	};
	
	/* G5 version */
	template <typename Config>
	struct submit <Channel3DG5, Config> {
		void operator()(Channel3DG5 * channel) {
			cout << "Submit : G5 " << channel->values << endl;
			
			/* Punt back into G4 for some common logic */
			Channel3DImpl::submit<Channel3DG4, Config>()(&channel->base);
			
			BRN::BRN2<Config::BRN::brn2, Config>()();
		}
	};
	
}

#endif //_Channel3D_hpp
