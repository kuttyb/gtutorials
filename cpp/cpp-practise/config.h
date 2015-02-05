//
//  config.h
//  cpp-practise
//
//  Created by kuttyb on 2/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef _cpp_practise_config_
#define _cpp_practise_config_

#include "data.h"

namespace {
	struct ConfigHigher {
		typedef you  Major;
		typedef them Minor;
	};
	
	struct ConfigLower {
		typedef them Major;
		typedef you  Minor;
	};
}

#endif /* defined(_cpp_practise_config_) */
