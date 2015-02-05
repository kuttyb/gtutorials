//
//  Type.cpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/21/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#include "logic.hpp"
#include "config.h"

void start() {
	{
		basic<ConfigHigher::Major>();
		basic<ConfigHigher::Minor>();
	}
	
	{
		basic<ConfigLower::Minor>();
	}
	
	{
		basic<ConfigLower::Major>();
	}
}
