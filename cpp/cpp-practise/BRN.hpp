//
//  BRN.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

#pragma mark - Generic
template <bool val>
void applyBRN1(void) {}

template <bool val>
void applyBRN2(void) {}

#pragma mark - BRN1
template <>
void applyBRN1<true>(void) {
	cout << "BRN1 " << endl;
}

template <>
void applyBRN2<true>(void) {
	cout << "BRN2 " << endl;
}
