//
//  TypeCollection.h
//  cpp-cmd
//
//  Created by kuttyb on 6/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef cpp_cmd_TypeCollection_h
#define cpp_cmd_TypeCollection_h

#include <tuple>

#pragma mark Type Container class -
template <typename... T>
struct TypeContainer {
    std::tuple<T*...> args;
    
    TypeContainer(T*... input) {
        args = std::make_tuple(input...);
    }
    
    constexpr size_t size() const {
        return std::tuple_size<std::tuple<T*...> >::value - 1;
    }
};


#pragma mark Type Processor class -
template <size_t N, typename D, typename... T>
class TypeProcessor {
public:
    static void method(D * value, TypeContainer<T...> * input) {
        std::get<N>(input->args)->print(*value);
        
        // Recurse ...
        TypeProcessor<N - 1, D, T...>::method(value, input);
    }
    
    static void factory(TypeContainer<T...> * input) {
        std::get<N>(input->args) =
         std::tuple_element<N, std::tuple<T*...> >::type::create();
        
        // Recurse ...
        TypeProcessor<N - 1, D, T...>::factory(input);
    }
};

// Class Partial Specialization
template <typename D, typename... T>
class TypeProcessor<0, D, T...> {
public:
    static void method(D * value, TypeContainer<T...> * input) {
        std::get<0>(input->args)->print(*value);
    }
    
    static void factory(TypeContainer<T...> * input) {
        std::get<0>(input->args) =
        std::tuple_element<0, std::tuple<T*...> >::type::create();
    }
};


#endif
