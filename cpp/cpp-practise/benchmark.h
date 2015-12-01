//
//  benchmark.h
//  benchmark
//
//  Created by kuttyb on 12/7/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#ifndef benchmark_h
#define benchmark_h

#include <iostream>
#include <chrono>

using namespace std;

#pragma mark - Benchmark
namespace perf {
	template <typename RESOLUTION> static inline std::string time_unit(void);
	template <>  std::string time_unit<std::chrono::nanoseconds>(void)  { return "nanoseconds";}
	template <>  std::string time_unit<std::chrono::milliseconds>(void) { return "milliseconds";}
	template <>  std::string time_unit<std::chrono::microseconds>(void) { return "microseconds";}

    template <typename RESOLUTION>
    struct profile {
        void operator()(std::function<void (void)> code, int warmup_iterations)
        {
            /* Warmup */
            for (uint32_t i = 0; i < warmup_iterations; ++i)
            {
                code();
            }
            
            /* Time the actual code */
            auto start = std::chrono::steady_clock::now();
            code();
            auto end   = std::chrono::steady_clock::now();
            
            /* Tell us about it :-) */
            cout << " Benchmark: Execution time " << std::chrono::duration_cast<RESOLUTION>(end - start).count() << " " << time_unit<RESOLUTION>() << endl;
        }
    };
} // namespace

#endif
