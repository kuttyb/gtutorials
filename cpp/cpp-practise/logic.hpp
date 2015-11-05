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
	
#pragma mark - Unspecialized version
	template <typename T>
	void basic() {
		assert(!"not implemented");
	}

#pragma mark - Specialized me
	template <>
	void basic<me>() {
		cout << "me version" << endl;
	}
	
#pragma mark - Specialized you
	template <>
	void basic<you>() {
		cout << "you version" << endl;
	}
	
#pragma mark - Specialized them
	template <>
	void basic<them>() {
		cout << "them version" << endl;
	}	
}

#endif /* defined(_cpp_practise_logic_) */
