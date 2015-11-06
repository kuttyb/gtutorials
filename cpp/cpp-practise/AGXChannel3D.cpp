//
//  AGXChannel3D.cpp
//  cpp-practise
//
//  Created by kutty banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include "AGXChannel3D.h"
#include "Channel3D.hpp"

#pragma mark - G4
void AGXChannel3DG4::init() {
	Channel3DImpl::init(&channel);
}

void AGXChannel3DG4::submit() {
	Channel3DImpl::submit<G4::channel3D, G4>()(&channel);
}

#pragma mark - G5
void AGXChannel3DG5::init() {
	Channel3DImpl::init(&channel);
}

void AGXChannel3DG5::submit() {
	Channel3DImpl::submit<G5::channel3D, G5>()(&channel);
}
