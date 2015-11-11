//
//  TestInheritance.mm
//  cpp-practise
//
//  Created by kutty banerjee on 11/10/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
template <bool enable, typename Dispatch>
struct brn {
	void apply() {}
};

template <typename Dispatch>
struct brn  <true, Dispatch> {
	int a;
	int b;
	void apply() {
		cout << "BRN being applied " << endl;
	}
};

#pragma mark - Config
struct ConfigG4 {
	/* BRN Table */
	static const bool brn1Enabled = false;
	typedef brn<brn1Enabled, ConfigG4>   brn1;
	
	/* Deletegate objects */
	static brn1 obj;
};

struct ConfigG5 : public ConfigG4 {
	/* BRN Table */
	static const bool brn1Enabled = true;
	typedef brn<brn1Enabled, ConfigG5> brn1;
	
	/* Deletegate objects */
	static brn1 obj;
};

struct ConfigG9 {
	/* BRN Table */
	static const bool brn1Enabled = true;
	typedef brn<brn1Enabled, ConfigG9> brn1;
	
	/* Deletegate objects */
	static brn1 obj;
};

template <typename Target, typename Dispatch>
struct toplevel {
	void operator()();
};

template <typename Dispatch>
struct toplevel<ConfigG4, Dispatch> {
	void operator()() {
		cout << "toplevel : ConfigG4" << endl;
		Dispatch::obj.apply();
	}
};

template <typename Dispatch>
struct toplevel<ConfigG5, Dispatch> {
	void operator()() {
		cout << "toplevel : ConfigG5" << endl;
		/* Punt to G4 */
		toplevel<ConfigG4, Dispatch>()();
	}
};

template <typename Dispatch>
struct toplevel<ConfigG9, Dispatch> {
	void operator()() {
		cout << "toplevel : ConfigG9" << endl;
		/* Punt to G5 */
		toplevel<ConfigG5, Dispatch>()();
	}
};

#pragma mark - Test
@interface TestInheritance : XCTestCase

@end

@implementation TestInheritance

- (void)setUp {
	[super setUp];
}

- (void)tearDown {
	[super tearDown];
}

- (void)testBasic {
	toplevel<ConfigG9, ConfigG9>()();
	
	cout << endl << "sizeof: G4 " << sizeof(ConfigG4::obj) << " G5: " << sizeof(ConfigG5::obj) << " G9: " << sizeof(ConfigG9::obj) << endl;
}

@end
