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
#include <map>
#include <tuple>

using std::cout;
using std::endl;
using std::set;
using std::map;

struct A  {
	int x;
	int y;
	A(int _x, int _y) : x(_x), y(_y) {}
	
	/* NOTE: Its always (this operator input) */
	bool operator<(const A & input) const {
        cout << "using the operator" << endl;
        return (input.x + input.y) < (x + y);
	}
	
    /* Copy ctor and assignment operator */
	A(const A &) = delete;
	A& operator=(const A &) = delete;
};

/* For Collections with Pointers, you need to explicitly provide the operator */
struct APtr {
    bool operator()(const A* lhs, const A* rhs) const {
        //cout << "special operator" << endl;
        return (lhs->x + lhs->y) < (rhs->x + rhs->y);
    }
};

@interface TestCollections : XCTestCase

@end

@implementation TestCollections

- (void)setUp {
	cout << "======================" << endl;
    [super setUp];
}

- (void)tearDown {
	cout << "======================" << endl;
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
	for (auto itr = x.begin(); itr != x.end(); ++itr) {
		cout << (*itr)->x << " " << (*itr)->y << endl;
	}

	/* Note how we use collection.rbegin / collection.rend */
	cout << "Reverse Set iterator" << endl;
	for (auto itr = x.rbegin(); itr != x.rend(); ++itr) {
		cout << (*itr)->x << " " << (*itr)->y << endl;
	}
}

- (void) testMap {
	A a(3, 5);
	A b(200, 300);
	A c(500, 600);
	
	/* Insert */
	map<A*, int> m;
	m[&a] = 2;
	m[&b] = 3;
	m[&c] = 4;
	
	/* Iterate (note how a std::pair is returned by the iterator */
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << "key " << std::get<0>(*itr)->x << " " << std::get<0>(*itr)->y << " value: " << std::get<1>(*itr) << endl;
	}
	
	/* Erase */
	m.erase(&a);
	cout << " Post Erase " << endl;
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << "key " << std::get<0>(*itr)->x << " " << std::get<0>(*itr)->y << " value: " << std::get<1>(*itr) << endl;
	}
	
	/* size */
	cout << "size is " << m.size() << endl;
}

- (void) testMultiMap {
    A a(3, 5);
    A b(200, 300);
    A c(500, 600);

    /* Insert */
    std::multimap<A*, int, APtr> map;
    map.insert(std::make_pair(&a, 2));
    
    map.insert(std::make_pair(&b, 3));
    map.insert(std::make_pair(&b, 8));
    map.insert(std::make_pair(&b, 9));
    
    map.insert(std::make_pair(&c, 4));
    XCTAssert(map.size() == 5);
    
    /* Find */
    {
        auto x = map.find(&a);
        XCTAssert(x->second == 2);
        XCTAssert(map.size() == 5);
    }
    
    /* Iterate */
    cout << "foreach iteration" << endl;
    for (const auto &v : map) {
        cout << v.first->x << " " << v.second << endl;
    }
    
    /* Group by individual key */
    {
        cout << "Group By" << endl;
        auto x = map.equal_range(&b);
        for (auto itr = x.first; itr != x.second; ++itr) {
            cout << itr->first->x << " " << itr->second << endl;
        }
    }
    
    /* Group by all keys */
    {
        for (auto itr = map.begin(); itr != map.end(); ) {
            A* key = itr->first;
            auto m = map.equal_range(key);
            cout << "Using Key " << key->x << endl;
            auto inner_itr = m.first;
            for (; inner_itr != m.second; ++inner_itr) {
                cout << " " << inner_itr->second << endl;
            }
            itr = inner_itr;
        }
    }

    /* Erase */
    {
        map.erase(map.find(&b));
        XCTAssert(map.size() == 4);
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
