//
//  BRN.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

#ifndef _BRN_HPP
#define _BRN_HPP

namespace BRN {
#pragma mark - BRN1
    template <bool val, typename Config>
    struct BRN1 {
        void operator()() {
        }
    };
    
    template <typename Config>
    struct BRN1<true, Config> {
        void operator()() {
            cout << "BRN1 " << endl;
        }
    };
    
#pragma mark - BRN2
    template <bool val, typename Config>
    struct BRN2 {
        void operator()() {
        }
    };
    
    template <typename Config>
    struct BRN2<true, Config> {
        void operator()() {
            cout << "BRN2 " << endl;
        }
    };

#pragma mark - BRN3
    template <bool val, typename Config>
    struct BRN3 {
        void operator ()() {
        }
    };
    
    template <typename Config>
    struct BRN3<true, Config> {
        void operator()() {
            cout << "BRN3 " << endl;
        }
    };
}
#endif //_BRN_HPP
