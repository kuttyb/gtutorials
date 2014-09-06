//
//  Pipe.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_Pipe_h
#define cpp_cmd_Pipe_h

#include <iostream>
#include <array>
#include <tuple>

template <typename T, size_t fifo_depth, typename... M>
class Pipe {
private:
    std::array<T, fifo_depth> queue;
    uint64_t  lock_mask;
public:
    // Individual run of the Pipeline (synchronous and inside one thread)
    void execute(T & input, uint32_t context_id);
    // Queue work for future execution
    void enqueue(T input, uint32_t context_id);
    // Pick a ready Pipeline instance and launch execute on it
    void run();
    // Understand what kind of locking would be required by the individual
    // modules
    void setup_locks();
};


#endif
