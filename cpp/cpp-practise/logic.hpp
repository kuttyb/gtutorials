//
//  logic.hpp
//  cpp-practise
//
//  Created by kuttyb on 2/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef _cpp_practise_logic_
#define _cpp_practise_logic_

#include <iostream>
#include <assert.h>
#include "data.h"
#include "BRNlogic.hpp"

namespace moduletryone {
	using std::cout;
	using std::endl;
	
	template <typename T, typename CONFIG>
	struct logic {
		static void basic() {
			assert(!"not implemented");
		}
	};
	
#pragma mark - Specialized me
	template <typename CONFIG>
	struct logic <me, CONFIG> {
		static void basic() {
			applyBRN234<CONFIG::BRN::BRN234>();
			cout << "me version" << endl;
			applyBRN123<CONFIG::BRN::BRN123>();
		}
	};
	
#pragma mark - Specialized you
	template <typename CONFIG>
	struct logic <you, CONFIG> {
		static void basic() {
			applyBRN234<CONFIG::BRN::BRN234>();
			cout << "you version" << endl;
			applyBRN123<CONFIG::BRN::BRN123>();
		}
	};
	
#pragma mark - Specialized them
	template <typename CONFIG>
	struct logic <them, CONFIG> {
		static void basic() {
			applyBRN234<CONFIG::BRN::BRN234>();
			cout << "them version" << endl;
			applyBRN123<CONFIG::BRN::BRN123>();
		}
	};
}

#endif /* defined(_cpp_practise_logic_) */
