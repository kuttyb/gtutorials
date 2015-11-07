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
	Channel3DImpl<G4::channel3D, G4>::init(&channel);
}

void AGXChannel3DG4::submit() {
	Channel3DImpl<G4::channel3D, G4>::submit(&channel);
}

#pragma mark - G5
void AGXChannel3DG5::init() {
	Channel3DImpl<G5::channel3D, G5>::init(&channel);
}

void AGXChannel3DG5::submit() {
	Channel3DImpl<G5::channel3D, G5>::submit(&channel);
}
