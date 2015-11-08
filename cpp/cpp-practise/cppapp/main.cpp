//
//  main.cpp
//  cppapp
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include "AGXChannel3D.h"
#include "AGXAccelerator.h"

int main(int argc, const char * argv[]) {
    AGXAccelerator * hAccel   = new AGXAcceleratorG5();
    AGXChannel3D   * hChannel = new AGXChannel3DG5();

    hAccel->setChannel(hChannel);
    
    hAccel->init();
    hAccel->enumerate();
    
    hChannel->init();
    hChannel->submit();
    
    delete hChannel;
    delete hAccel;
    
    return 0;
}
