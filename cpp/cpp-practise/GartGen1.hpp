//
//  GartGen1.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/19/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef GartGen1_h
#define GartGen1_h

#pragma mark - Gen1
template <typename ChipDispatch>
class GartGen1 : public GartBase<ChipDispatch> {
public:
	void init() {
		cout << __PRETTY_FUNCTION__ << endl;
		GartBase<ChipDispatch>::setup();
	}
};

#endif /* GartGen1_h */
