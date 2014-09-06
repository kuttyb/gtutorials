//
//  Pipe.hpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/6/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "Pipe.h"
#include "typevector.h"

using std::cout;
using std::endl;
using std::array;

using std::cout;
using std::endl;

template <typename I, typename T, size_t fifo_depth, typename... M>
void Pipe<I, T, fifo_depth, M...>::execute(PipeEntry<T, I> * entry) {
    cout << "Pipe execute" << endl;
    foreach_type<std::tuple_size<std::tuple<M...> >::value - 1, PipeEntry<T, I>, M...>::executemodule(entry);
}

template <typename I, typename T, size_t fifo_depth, typename... M>
void Pipe<I, T, fifo_depth, M...>::enqueue(I input, uint32_t context_id) {
    
}

template <typename I, typename T, size_t fifo_depth, typename... M>
void Pipe<I, T, fifo_depth, M...>::run(void) {
    
}

template <typename I, typename T, size_t fifo_depth, typename... M>
void Pipe<I, T, fifo_depth, M...>::setup_locks(void) {
    cout << "Initializing locks" << endl;
    PipeEntry<uint64_t, uint8_t> lock_mask(0, 0, 0);
    foreach_type<std::tuple_size<std::tuple<M...> >::value - 1, PipeEntry<uint64_t, uint8_t>, M...>::executemodule(&lock_mask);
}

