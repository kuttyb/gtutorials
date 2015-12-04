//
//  testgraph.mm
//  cpp-practise
//
//  Created by kuttyb on 12/4/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "graph.hpp"

using std::cout;
using std::endl;

@interface testgraph : XCTestCase

@end

@implementation testgraph

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testBasic {
	Node<int> root(5);
	Node<int> first(2);
	Node<int> second(3);
	root.addChild(&first);
	root.addChild(&second);

	/* DFS */
	bool a = search<int, true>(&root, 8);
	XCTAssert(a == false);
	a = search<int, true>(&root, 3);
	XCTAssert(a == true);
	
	/* BFS */
	a = search<int, false>(&root, 8);
	XCTAssert(a == false);
	a = search<int, false>(&root, 3);
	XCTAssert(a == true);
}

@end
