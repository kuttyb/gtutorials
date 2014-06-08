//
//  typevector.h
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
struct typevector {
    std::tuple<T*...> args;
    
    typevector(T*... input) {
        args = std::make_tuple(input...);
    }
    
    constexpr size_t size() const {
        return std::tuple_size<std::tuple<T*...> >::value - 1;
    }
};


#pragma mark Type Processor class -
template <size_t N, typename D, typename... T>
class foreach_type {
public:
    static void method(D * value, typevector<T...> * input) {
        std::get<N>(input->args)->print(*value);
        
        // Recurse ...
        foreach_type<N - 1, D, T...>::method(value, input);
    }
    
    static void factory(typevector<T...> * input) {
        typename std::tuple_element<N, std::tuple<T...> >::type * l;
        int x = 3; void *ptr = &x;
        l = (typename std::tuple_element<N, std::tuple<T...> >::type * )ptr;
        // Calling a static method so just need a non-null pointer to beat the type system
        // TODO: This will blow up if ::create uses static data in its Type Class
        //       Goal is to find out how to do tuple_element<N, ....>::type::static_method()
        std::get<N>(input->args) = l->create();
        
        // Recurse ...
        foreach_type<N - 1, D, T...>::factory(input);
    }
};

// Class Partial Specialization
template <typename D, typename... T>
class foreach_type<0, D, T...> {
public:
    static void method(D * value, typevector<T...> * input) {
        std::get<0>(input->args)->print(*value);
    }
    
    static void factory(typevector<T...> * input) {
        typename std::tuple_element<0, std::tuple<T...> >::type * l;
        int x = 3; void *ptr = &x;
        l = (typename std::tuple_element<0, std::tuple<T...> >::type * )ptr;
        std::get<0>(input->args) = l->create();
    }
};


#endif
