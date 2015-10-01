//
//  TestCollections.mm
//  cpp-practise
//
//  Created by kuttyb on 1/27/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

struct A  {
	int x;
	int y;
	A(int _x, int _y) : x(_x), y(_y) {}
	
	/* NOTE: Its always (this operator input) */
	bool operator<(const A & input) const {
        cout << "using the operator" << endl;
		return (x + y) < (input.x + input.y);
	}
	
    /* Copy ctor and assignment operator */
	A(const A &) = delete;
	A& operator=(const A &) = delete;
};

/* For Collections with Pointers, you need to explicitly provide the operator */
struct APtr {
    bool operator()(const A* lhs, const A* rhs) const {
        cout << "special operator" << endl;
        return (lhs->x + lhs->y) < (rhs->x + rhs->y);
    }
};

@interface TestCollections : XCTestCase

@end

@implementation TestCollections

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testSet {
	A a(3, 5);
	A b(200, 300);
	
    if (a < b) cout << "done" << endl;
    
	set<A*, APtr> x;
	x.insert(&a);
	x.insert(&b);
	x.insert(&a);
	
	cout << "Regular foreach" << endl;
	for (const A * temp : x) {
		cout << temp->x << " " << temp->y << endl;
	}
	
	cout << "Regular Set iterator" << endl;
	for (auto itr = x.begin(); itr != x.end(); itr++) {
		cout << (*itr)->x << " " << (*itr)->y << endl;
	}

	/* Note how we use collection.rbegin / collection.rend */
	cout << "Reverse Set iterator" << endl;
	for (auto itr = x.rbegin(); itr != x.rend(); itr++) {
		cout << (*itr)->x << " " << (*itr)->y << endl;
	}
}

- (void) testEraseSet {
	A a(3, 5);
	A b(200, 300);
	A c(500, 600);
	
	set<A*> x;
	x.insert(&a);
	x.insert(&b);
	x.insert(&c);
	
	/* Erasure works like you would erase from an array once you have its index. The iterator works
	 * exactly like the index from an API perspective
	 */
	for (auto itr = x.begin(); itr != x.end(); ) {
		if ((*itr)->x == 200) {
			auto temp = itr;
			++itr;
			x.erase(temp);
		} else {
			++itr;
		}
	}
	
	/* Now loop over it again */
	for (const A * temp : x) {
		cout << temp->x << " " << temp->y << endl;
	}
}

@end
