#include <iostream>
#include <functional>
#include "benchmark.h"

using std::cout;
using std::endl;

#define LOOPITERATIONS (1000)

#pragma mark - Using Functors
template <typename Policy>
int processF() {
	int sum = 0;
	for (int i = 0; i < LOOPITERATIONS; ++i) {
		sum += Policy()(i, i + 1);
	}
	return sum;
}

#pragma mark - Using Lambdas
int processL(std::function<int(int, int)> func) {
	int sum = 0;
	for (int i = 0; i < LOOPITERATIONS; ++i) {
		sum += func(i, i + 1);
	}
	return sum;
}

template <typename T>
int process(T fn) {
	int sum = 0;
	for (int i = 0; i < LOOPITERATIONS; ++i) {
		sum += fn(i, i + 1);
	}
	return sum;
}

int main(int argc, const char * argv[]) {
	cout << "hi there" << endl;
	
	/* Test Policy (inlining) */
	{
		struct Policy {
			int operator()(int arg1, int arg2) {
				return arg1 + arg2;
			}
		};
		
		int value = 0;
		perf::profile<std::chrono::microseconds>()([&value]() {
			
			value = processF<Policy>();
			
		}, 10);
		cout << " Policy returned value is " << value << endl << endl;
	}
	
	/* Test Lambda (no inlining with std::function) */
	{
		int value = 0;
		perf::profile<std::chrono::microseconds>()([&value]() {
			
			value = processL([](int arg1, int arg2){return arg1 + arg2;});
			
		}, 10);
		cout << " Lambda returned value is " << value << endl << endl;
	}
	
	/* Test Lambda (as a template paramter - with inlining) */
	{
		int value = 0;
		perf::profile<std::chrono::microseconds>()([&value]() {

			value = process([](int arg1, int arg2) {return arg1 + arg2;});
			
		}, 10);
		cout << " Lambda (template) returned value is " << value << endl << endl;
	}
	
    return 0;
}
