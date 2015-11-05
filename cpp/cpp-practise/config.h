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

namespace moduletryone {
#pragma mark - Properties
	struct BRNTable {
		const static bool BRN123 = false;
		const static bool BRN234 = false;
		const static bool BRN789 = false;
	};
	
	struct ConfigHigher {
		typedef you  Major;
		typedef them Minor;
		
		struct BRN : public BRNTable {
			const static bool BRN123 = true;
		};
	};
	
	struct ConfigLower {
		typedef them Major;
		typedef you  Minor;
		
		struct BRN : public BRNTable {
			const static bool BRN234 = true;
			const static bool BRN789 = true;
		};
	};
}

#endif /* defined(_cpp_practise_config_) */
