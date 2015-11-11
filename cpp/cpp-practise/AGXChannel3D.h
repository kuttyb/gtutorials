//
//  AGXChannel3D.h
//  cpp-practise
//
//  Created by kutty banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef AGXChannel3D_h
#define AGXChannel3D_h

#include "Channel3D.h"
#include "chipdispatch.h"

class AGXChannel3D {
public:
	virtual void init()   = 0;
	virtual void submit() = 0;
	virtual ~AGXChannel3D() {}
};

class AGXChannel3DG4 : public AGXChannel3D {
public:
    G4::channel3D channel;
	void init() override;
	void submit() override;
};

class AGXChannel3DG5 : public AGXChannel3D {
public:
    G5::channel3D channel;
	void init() override;
	void submit() override;
};

class AGXChannel3DG5G : public AGXChannel3D {
public:
	G5G::channel3D channel;
	void init()   override;
	void submit() override;
};

#endif /* AGXChannel3D_h */
