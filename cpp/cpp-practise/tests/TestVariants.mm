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
/* Node Structs */
struct NodeA {
	uint8_t op1;
	uint8_t op2;
	NodeA(uint8_t one, uint8_t two) : op1(one), op2(two) {}
};

struct NodeB {
	uint8_t op1;
	NodeB(uint8_t one) : op1(one){}
};

struct NodeC {
	uint8_t op1;
	NodeC(uint8_t one) : op1(one){}
};

typedef boost::variant<NodeA, NodeB, NodeC> Node;

#pragma mark - Visitors
template <typename CONTEXT>
struct Visitor : public boost::static_visitor<>
{
private:
	CONTEXT * context;
	
public:
	Visitor() = delete;
	Visitor(CONTEXT * input_context) : context(input_context)  {}
	
	void operator()(NodeA & data) const {
		assert(context);
		printf("NodeA: %d %d Context %d\n", data.op1, data.op2, *context);
	}
	
	void operator()(NodeB & data) const {
		assert(context);
		printf("NodeB: %d Context %d\n", data.op1, *context);
	}
	
	void operator()(NodeC & data) const {
		assert(context);
		printf("NodeC: %d Context %d\n", data.op1, *context);
	}
};

//template <typename CONTEXT>
//struct OptimizationPass : public boost::static_visitor<>
//{
//	Visitor<CONTEXT> base;
//};

#pragma mark - Specialize Visitor for voidPtr
template <>
void Visitor<voidPtr>::operator()(NodeA &data) const {
	cout << "NodeA: voidPtr" << endl;
}

template <>
void Visitor<voidPtr>::operator()(NodeB &data) const {
	cout << "NodeA: voidPtr" << endl;
}

template <>
void Visitor<voidPtr>::operator()(NodeC &data) const {
	cout << "NodeA: voidPtr" << endl;
}

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
			VISITOR visitor(context);
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
	boost::apply_visitor(Visitor<voidPtr>(nullptr), data);
}

- (void)testVectorVisitor {
	vector<Node> a;
	a.push_back(NodeB(2));
	a.push_back(NodeC(3));
	a.push_back(NodeA(4, 5));
	
	for (Node & temp : a) {
		boost::apply_visitor(Visitor<voidPtr>(nullptr), temp);
	}
}

- (void) testGraph {
	Graph<Visitor<int>, int> graph;

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
