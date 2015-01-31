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
#include <bitset>

using std::cout;
using std::endl;
using std::vector;
using std::bitset;

#pragma mark - Compiler IR
/* Node Structs */
struct AbstractNode {
	bool jump;
	bool noop;
};

struct NodeA : public AbstractNode {
	uint8_t op1;
	uint8_t op2;
	NodeA(uint8_t one, uint8_t two) : op1(one), op2(two) {}
};

struct NodeB : public AbstractNode  {
	uint8_t op1;
	NodeB(uint8_t one) : op1(one){}
};

struct NodeC : public AbstractNode {
	uint8_t op1;
	NodeC(uint8_t one) : op1(one){}
};

typedef boost::variant<NodeA, NodeB, NodeC> Node;

#pragma mark - BitVector Operations on the IR Graph

struct NodeResult {
    enum {
        SUCCESS, DELETENODE, SETANCHOR, RESETANCHOR, VISITANCHOR, REPLAYANCHOR, TOTALOPS
    } NODEOPS;

public:
    std::bitset<TOTALOPS> status_bits;
    /* Builder Pattern (some status bits cannot coexist with others, ensure valid usage via wrappers) */
    void success()        { status_bits.reset(); status_bits[SUCCESS] = 1;                    }
    void deletenode()     { status_bits.reset(); status_bits[DELETENODE] = 1;                 }
    void setanchor()      { assert(!status_bits[DELETENODE]); status_bits[SETANCHOR] = 1;     }
    void resetanchor()    { assert(!status_bits[DELETENODE]); status_bits[RESETANCHOR] = 1;   }
    void visitanchor()    { assert(!status_bits[DELETENODE]); status_bits[VISITANCHOR] = 1;   }
    void replayanchor()   { assert(!status_bits[DELETENODE]); status_bits[REPLAYANCHOR] = 1;  }
};

#pragma mark - Visitors
template <typename CONTEXT>
struct Visitor : public boost::static_visitor<NodeResult>
{
private:
	CONTEXT * context;
	
public:
	Visitor() = delete;
	Visitor(CONTEXT * input_context) : context(input_context)  {}
	
	NodeResult operator()(NodeA & data) const {
		assert(context);
		printf("NodeA: %d %d Context %d\n", data.op1, data.op2, *context);
        
        NodeResult result;
        result.success();
        return result;
	}
	
	NodeResult operator()(NodeB & data) const {
		assert(context);
		printf("NodeB: %d Context %d\n", data.op1, *context);

        NodeResult result;
        result.success();
        return result;
	}
	
	NodeResult operator()(NodeC & data) const {
		assert(context);
		printf("NodeC: %d Context %d\n", data.op1, *context);
        
        NodeResult result;
        result.success();
        return result;	}
};

/* Here is how you build on top of existing Passes (NO INHERITANCE, ONLY COMPOSITION) */
template <typename CONTEXT>
struct OptimizationPass : public boost::static_visitor<NodeResult>
{
	Visitor<CONTEXT> base;
	CONTEXT * context;
	OptimizationPass() = delete;
	
	OptimizationPass(CONTEXT * input_context) : base(input_context), context(input_context) {}

	NodeResult operator()(NodeA & data) const {
		base(data);
		printf("OPT: NodeA: %d %d Context %d\n", data.op1, data.op2, *context);
        
        NodeResult result;
        result.success();
        return result;	}
	
	NodeResult operator()(NodeB & data) const {
		base(data);
		printf("OPT: NodeB: %d Context %d\n", data.op1, *context);
        
        NodeResult result;
        result.success();
        return result;	}
	
	NodeResult operator()(NodeC & data) const {
		base(data);
		printf("OPT: NodeC: %d Context %d\n", data.op1, *context);
        
        NodeResult result;
        result.deletenode();
        return result;	}
};

#pragma mark - Specialize Visitor for voidPtr
template <>
NodeResult Visitor<voidPtr>::operator()(NodeA &data) const {
	cout << "NodeA: voidPtr" << endl;
    
    NodeResult result;
    result.success();
    return result;
}

template <>
NodeResult Visitor<voidPtr>::operator()(NodeB &data) const {
	cout << "NodeA: voidPtr" << endl;
    
    NodeResult result;
    result.success();
    return result;
}

template <>
NodeResult Visitor<voidPtr>::operator()(NodeC &data) const {
	cout << "NodeA: voidPtr" << endl;
    
    NodeResult result;
    result.deletenode();
    return result;
}

typedef enum { NOOP, LOOKUP, PROCESS } PreProcessorStatus;
struct PreProcessor : public boost::static_visitor<PreProcessorStatus>
{
	PreProcessorStatus common(AbstractNode & node) const {
		if (node.jump) return PreProcessorStatus::LOOKUP;
		if (node.noop) return PreProcessorStatus::NOOP;
		return PreProcessorStatus::PROCESS;
	}
	
	PreProcessorStatus operator()(NodeA & data) const {
		return common(data);
	}

	PreProcessorStatus operator()(NodeB & data) const {
		return common(data);
	}

	PreProcessorStatus operator()(NodeC & data) const {
		return common(data);
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
			VISITOR visitor(context);
			/* Do we really need to process this Node or ... ? */
			PreProcessorStatus status = boost::apply_visitor(PreProcessor(), temp);
			if (status == PreProcessorStatus::PROCESS)
			{
				NodeResult result = boost::apply_visitor(visitor, temp);
				/* TODO: Handle all the cases */
				if (!result.status_bits[NodeResult::SUCCESS]) {
					printf("result was not successful\n");
				}
			} else if (status == PreProcessorStatus::NOOP) {
				continue;
			} else if (status == PreProcessorStatus::LOOKUP) {
				/* TODO: Do a hash table look up to find the new vector offset to use */
			};
			
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

- (void) testOptimizationPass {
	Graph<OptimizationPass<int>, int> graph;
	
	graph.addNode(NodeA(2, 3));
	graph.addNode(NodeB(3));
	graph.addNode(NodeC(45));
	
	int a = 10;
	graph.visit(&a);
	printf("\n");
	
	int b = 20;
	graph.visit(&b);
}

- (void) testBitSet {
    bitset<NodeResult::TOTALOPS> retvalue;
	retvalue[NodeResult::SUCCESS] = 1;
	retvalue[NodeResult::SETANCHOR] = 1;
	
	if (retvalue[NodeResult::SUCCESS])    printf("success\n");
	if (retvalue[NodeResult::SETANCHOR])  printf("setanchor\n");
	if (!retvalue[NodeResult::REPLAYANCHOR]) printf("!replayanchor\n");
}

@end
