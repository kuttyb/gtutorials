//
//  BRNlogic.hpp
//  cpp-practise
//
//  Created by kutty banerjee on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>

namespace moduletryone {
	using std::cout;
	using std::endl;

#pragma mark - BRN1234
	template <bool val>
	void applyBRN123() { }
	
	template <>
	void applyBRN123<true>() {
		cout << " BRN123 being applied" << endl;
	}
	
#pragma mark - BRN234
	template <bool val>
	void applyBRN234() {}
	
	template <>
	void applyBRN234<true>() {
		cout << "BRN234 being applied" << endl;
	}
	
#pragma mark - BRN789
	template <bool val>
	void applyBRN789() {}
	
	template <>
	void applyBRN789<true>() {
		cout << "BRN789 being applied" << endl;
	}
}
