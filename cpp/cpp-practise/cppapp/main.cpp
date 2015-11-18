//
//  main.cpp
//  cppapp
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include "AGXAccel.hpp"

int main(int argc, const char * argv[]) {
	AGXAccel * accel;
	AGXChannel * channel;
	
	
	channel = new AGXChannelG5GC0();
	accel   = new AGXAccelG5GC0(channel);
	
	accel->init();
	channel->submit();
	accel->close();

	delete channel;
	delete accel;
	
    return 0;
}
