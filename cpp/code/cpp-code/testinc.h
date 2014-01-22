//
//  testinc.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_code_testinc_h
#define cpp_code_testinc_h

// Just to explain that in Xcode if you goto E.hpp and check "included-by", you will
// see this file. This will happen only if somebody actually includes this file.
// For templated clases, I am leaning towards implementing them in .hpp files that
// are included by the customers of that class. Yep, lets try out non-dll setups,
// but "Force Instantiating" templates is messy!!
#include "E.hpp"

#endif
