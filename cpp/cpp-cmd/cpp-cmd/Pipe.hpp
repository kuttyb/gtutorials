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

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::execute(T & input, uint32_t context_id) {
    cout << "Pipe execute" << endl;
    foreach_type<std::tuple_size<std::tuple<M...> >::value - 1, T, M...>::executemodule(&input, context_id);
}

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::enqueue(T input, uint32_t context_id) {
    
}

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::run(void) {
    
}

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::setup_locks(void) {
    cout << "Initializing locks" << endl;
    foreach_type<std::tuple_size<std::tuple<M...> >::value - 1, uint64_t, M...>::executemodule(&lock_mask, 0);
}

