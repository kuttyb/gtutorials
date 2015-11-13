//
//  AGXAccel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXAccel_hpp
#define AGXAccel_hpp

#include "chipdispatch.h"
#include "Accel.hpp"

class AGXAccel {
public:
    virtual void init() = 0;
    virtual void close() = 0;
    virtual ~AGXAccel() {}
};

class AGXAccelG4 : public AGXAccel{
    G4::accel accel;
public:
    void init()  override;
    void close() override;
};

class AGXAccelG5 : public AGXAccel {
    G5::accel accel;
public:
    void init()  override;
    void close() override;
};

class AGXAccelG5G : public AGXAccel {
    G5G::accel accel;
public:
    void init()  override;
    void close() override;
};


#endif /* AGXAccel_hpp */
