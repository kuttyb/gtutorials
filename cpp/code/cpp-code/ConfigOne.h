//
//  ConfigOne.h
//  cpp-code
//
//  Created by kutty banerjee on 1/13/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_code_ConfigOne_h
#define cpp_code_ConfigOne_h

#include "one.h"

class ConfigOne {
public:
	One<uint64_t> createInteger(void);
	One<float> createFloat(void);
};

#endif
