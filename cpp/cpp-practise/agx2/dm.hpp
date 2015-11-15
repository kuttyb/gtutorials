//
//  dm.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/15/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef dm_h
#define dm_h

#include <iostream>

using std::cout;
using std::endl;

template <typename ChipDispatch>
class DM {
public:
	void presubmit() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
	
	void submit() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
	
	void postsubmit() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

template <typename ChipDispatch>
class DMTA : public DM<ChipDispatch> {
public:
	void submit() {
		DM<ChipDispatch>::submit();
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

template <typename ChipDispatch>
class DM3D : public DM<ChipDispatch> {
public:
	void submit() {
		DM<ChipDispatch>::submit();
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

template <typename ChipDispatch>
class DMCL : public DM<ChipDispatch> {
public:
	void submit() {
		DM<ChipDispatch>::submit();
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

#endif /* dm_h */
