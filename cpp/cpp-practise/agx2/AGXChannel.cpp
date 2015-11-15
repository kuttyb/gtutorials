//
//  AGXChannel.cpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include "AGXChannel.hpp"

using std::cout;
using std::endl;

#pragma mark - G4
void AGXChannelG4::init() {
	channel.init();
}

void AGXChannelG4::close() {
	channel.close();
}

void AGXChannelG4::submit() {
	channel.submit();
}

#pragma mark - G5
void AGXChannelG5::init() {
	channel.init();
}

void AGXChannelG5::close() {
	channel.compute();
	channel.close();
}

void AGXChannelG5::submit() {
	channel.submit();
}

#pragma mark - G5G
void AGXChannelG5G::init() {
	channel.init();
}

void AGXChannelG5G::close() {
	channel.close();
}

void AGXChannelG5G::submit() {
	channel.submit();
}

#pragma mark - G5GC0
void AGXChannelG5GC0::init() {
	channel.init();
}

void AGXChannelG5GC0::close() {
	channel.close();
}

void AGXChannelG5GC0::submit() {
	channel.submit();
}
