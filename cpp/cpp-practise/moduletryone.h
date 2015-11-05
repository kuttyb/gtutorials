//
//  moduletryone.h
//  cpp-practise
//
//  Created by kuttyb on 2/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef _cpp_practise_moduletryone_
#define _cpp_practise_moduletryone_

class ModuleOne {
public :
	virtual void start_tryone() = 0;
	virtual void stop_tryone() = 0;
	virtual ~ModuleOne() {}
};

class ModuleOneG4 : public ModuleOne {
public:
	void start_tryone() override;
	void stop_tryone()  override;
};

class ModuleOneG5 : public ModuleOne {
public:
	void start_tryone() override;
	void stop_tryone()  override;
};

#endif /* defined(_cpp_practise_moduletryone_) */
