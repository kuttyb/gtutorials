//
//  Type.cpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/21/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#include <stdlib.h>
#include "moduletryone.h"
#include "config.h"
#include "logic.hpp"

using namespace moduletryone;

#pragma mark - ModuleOneG4
void ModuleOneG4::start_tryone(void) {
	logic<ConfigHigher::Major, ConfigHigher>::basic();
	logic<ConfigHigher::Minor, ConfigHigher>::basic();
}

void ModuleOneG4::stop_tryone(void) {
	logic<ConfigHigher::Minor, ConfigLower>::basic();
}

#pragma mark - ModuleOneG5
void ModuleOneG5::start_tryone(void) {
	logic<ConfigLower::Major, ConfigLower>::basic();
	logic<ConfigLower::Minor, ConfigLower>::basic();
}

void ModuleOneG5::stop_tryone(void) {
	logic<ConfigLower::Minor, ConfigLower>::basic();
}

