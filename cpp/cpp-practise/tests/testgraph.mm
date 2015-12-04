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

	XCTAssert(dfs(&root, 8) == false);
	XCTAssert(dfs(&root, 3) == true);
}

@end
