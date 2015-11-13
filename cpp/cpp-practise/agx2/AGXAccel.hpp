//
//  AGXAccel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXAccel_hpp
#define AGXAccel_hpp

#include "Accel.hpp"

class AGXAccel {
public:
    virtual void init() = 0;
    virtual void close() = 0;
    virtual ~AGXAccel() {}
};

class AGXAccelG4 : public AGXAccel{
    AccelGen1<G4> accel;
public:
    void init()  override;
    void close() override;
};

class AGXAccelG5 : public AGXAccel {
    AccelGen1<G5> accel;
public:
    void init()  override;
    void close() override;
};

class AGXAccelG5G : public AGXAccel {
    AccelGen2<G5G> accel;
public:
    void init()  override;
    void close() override;
};


#endif /* AGXAccel_hpp */
