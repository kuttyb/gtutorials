//
//  TestVariants.mm
//  cpp-practise
//
//  Created by kuttyb on 1/27/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <boost/variant.hpp>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#pragma mark - Compiler IR
struct NodeBase {
	bool jump;
	NodeBase() : jump(false){}
};

/* Node Structs */
struct NodeA : public NodeBase {
	uint8_t op1;
	uint8_t op2;
	NodeA(uint8_t one, uint8_t two) : op1(one), op2(two) {}
};


struct NodeB : public NodeBase {
	uint8_t op1;
	NodeB(uint8_t one) : op1(one){}
};

struct NodeC : public NodeBase {
	uint8_t op1;
	NodeC(uint8_t one) : op1(one){}
};


typedef boost::variant<NodeA, NodeB, NodeC> Node;

#pragma mark - Visitors
#define   PROCESS_JUMP(node)  {if (node.jump) return;}
template <typename SUBVISITOR>
struct Visitor : public boost::static_visitor<>
{
	void operator()(NodeA & data) const {
		PROCESS_JUMP(data);
		SUBVISITOR()(data);
	}
	
	void operator()(NodeB & data) const {
		PROCESS_JUMP(data);
		SUBVISITOR()(data);
	}

	void operator()(NodeC & data) const {
		PROCESS_JUMP(data);
		SUBVISITOR()(data);
	}
};

template <typename CONTEXT>
struct MyVisitor : public boost::static_visitor<>
{
	CONTEXT * context;
	
	void operator()(NodeA & data) const {
		*context = *context + 1;
		printf("NodeA: %d %d context %d\n", data.op1, data.op2, *context);
	}
	
	void operator()(NodeB & data) const {
		*context = *context + 1;
		printf("NodeB: %d context %d\n", data.op1, *context);
	}
	
	void operator()(NodeC & data) const {
		*context = *context + 1;
		printf("NodeC: %d context %d\n", data.op1, *context);
	}
};

/*
 * As usual, there are 3 abstractions:
 *  [a] There are Nodes (IR Nodes)
 *  [b] There is a Graph (that contains Nodes)
 *  [c] There are Visitors (Passes & Optimizations)
 */
template <typename VISITOR, typename CONTEXT>
struct Graph {
private:
	std::vector <Node> nodes;
public:
	void addNode(Node a) {
		nodes.push_back(a);
	}
	
	void visit(CONTEXT * context) {
		for (Node & temp : nodes) {
			VISITOR visitor;
			visitor.context = context;
			boost::apply_visitor(visitor, temp);
		}
	}
};

#pragma mark - Test
@interface TestVariants : XCTestCase

@end

@implementation TestVariants

- (void)setUp {
    [super setUp];
	cout << "==================" << endl;
}

- (void)tearDown {
	cout << "==================" << endl;
    [super tearDown];
}

- (void)testBasicVisitor {
	Node data(NodeA(2, 3));
	boost::apply_visitor(Visitor<MyVisitor<int>>(), data);
}

- (void)testVectorVisitor {
	vector<Node> a;
	a.push_back(NodeB(2));
	a.push_back(NodeC(3));
	a.push_back(NodeA(4, 5));
	
	for (Node & temp : a) {
		boost::apply_visitor(Visitor<MyVisitor<int>>(), temp);
	}
}

- (void) testGraph {
	Graph<MyVisitor<int>, int> graph;
	
	graph.addNode(NodeA(2, 3));
	graph.addNode(NodeB(3));
	graph.addNode(NodeC(45));
	
	int a = 10;
	graph.visit(&a);
	printf("\n");
	
	int b = 20;
	graph.visit(&b);
}

@end
