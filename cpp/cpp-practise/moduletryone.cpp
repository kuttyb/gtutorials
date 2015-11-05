//
//  Type.cpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/21/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#include <stdlib.h>
#include "config.h"
#include "logic.hpp"

using namespace moduletryone;

void start_tryone() {
	/* Do an external probe and select an Object Graph */
	if (rand() % 2)
	{
		logic<ConfigHigher::Major, ConfigHigher>::basic();
		logic<ConfigHigher::Minor, ConfigHigher>::basic();
	}
	else
	{
		logic<ConfigLower::Minor, ConfigLower>::basic();
	}
}

void stop_tryone() {
	{
		logic<ConfigLower::Minor, ConfigLower>::basic();
	}
}
