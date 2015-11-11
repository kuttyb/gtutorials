//
//  AGXChannel3D.cpp
//  cpp-practise
//
//  Created by kutty banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include "AGXChannel3D.h"
#include "Channel3D.hpp"

#define LIST_G4  G4::channel3D, G4
#define LIST_G5  G5::channel3D, G5
#define LIST_G5G G5G::channel3D, G5G

#pragma mark - G4
void AGXChannel3DG4::init() {
	Channel3DImpl<LIST_G4>::init(&channel);
}

void AGXChannel3DG4::submit() {
	Channel3DImpl<LIST_G4>::submit(&channel, &channel.b1Data, nullptr, nullptr);
}

#if 1
#pragma mark - G5
void AGXChannel3DG5::init() {
	Channel3DImpl<LIST_G5>::init(&channel);
}

void AGXChannel3DG5::submit() {
	Channel3DImpl<LIST_G5>::submit(&channel, nullptr, &channel.b2Data, &channel.b3Data);
}
#endif

#pragma mark - G5G
void AGXChannel3DG5G::init() {
	Channel3DImpl<LIST_G5G>::init(&channel);
}

void AGXChannel3DG5G::submit() {
	Channel3DImpl<LIST_G5G>::submit(&channel, nullptr, nullptr, &channel.b3Data);
}
