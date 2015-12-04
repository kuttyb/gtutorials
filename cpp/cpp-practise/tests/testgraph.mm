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
	cout << "===============" << endl;
    [super setUp];
}

- (void)tearDown {
	cout << "===============" << endl;
    [super tearDown];
}

- (void)testSearch {
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

- (void)testTraversal {
	Node<int> root(1);
	Node<int> first(12);
	Node<int> second(13);
	Node<int> third(123);
	Node<int> fourth(1234);
	Node<int> fifth(135);

	root.addChild(&first);
	root.addChild(&second);
	
	first.addChild(&third);
	
	third.addChild(&fourth);
	
	second.addChild(&fifth);

	printNodes<int, false>(&root);
	cout << "=====" << endl;
	printNodes<int, true>(&root);
}

@end
