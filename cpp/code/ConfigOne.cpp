//
//  ConfigOne.cpp
//  cpp-code
//
//  Created by kutty banerjee on 1/13/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "ConfigOne.h"

One<uint64_t> ConfigOne::createInteger(void) {
	return One<uint64_t>::One(2, 3, 4, 1);
}

One<float> ConfigOne::createFloat(void) {
	return One<float>::One(2, 3, 4, 1.2f);
}
