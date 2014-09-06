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
#include <tuple>

/*
 TODO:
 =====
 [a] Add a std::map and store pointer to queue entries and its context_id
     enqueue adds into it and run searches it for the correct context_id.
 
 [b] Add a Fifo wrapper around queue that enqueue adds into. Should have 
     Basic Fifo behaviour and later add thread blocking behaviour using a
     Condition Variable.
 
 [c] After this spend your time in getting Locking correct. Keep in mind
     some Modules may have the same lock for all context_ids so create a
     PipeLock struct and in addition to the Module Lock mask, place a bit
     to capture this information.
 */
template <typename T, typename I>
struct PipeEntry {
    T   pipe_intermediate_data;
    I   pipe_input;
    uint32_t context_id;
    PipeEntry(T intermed, I input, uint32_t cid) :
    pipe_intermediate_data(intermed),
    pipe_input(input), context_id(cid) {}
    PipeEntry() {}
};

template <typename I, typename T, size_t fifo_depth, typename... M>
class Pipe {
private:
    PipeEntry<T, I> queue[fifo_depth];
    uint64_t  lock_mask;
public:
    Pipe() {}
    // Individual run of the Pipeline (synchronous and inside one thread)
    void execute(PipeEntry<T, I> * entry);
    // Queue work for future execution
    void enqueue(I input, uint32_t context_id);
    // Pick a ready Pipeline instance and launch execute on it
    void run(uint32_t context_id);
    // Understand what kind of locking would be required by the individual
    // modules
    void setup_locks();
};


#endif
