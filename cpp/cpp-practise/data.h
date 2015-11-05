//
//  data.h
//  cpp-practise
//
//  Created by kuttyb on 2/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef _cpp_practise_data_
#define _cpp_practise_data_

namespace moduletryone {
	struct me {
		int   first;
		float second;
		me(int a, float b) : first(a), second(b) {}
	};
	
	struct you {
		int one;
		you(int data) : one(data) {}
	};
	
	struct them {
		float data;
		them(float more) : data(more) {}
	};
}
#endif /* defined(_cpp_practise_data_) */
