//
//  Accelerator.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "chip.h"
#include "Accelerator.h"
#include "BRN.hpp"

using std::cout;
using std::endl;

namespace AcceleratorImpl {
#pragma mark - init
    template <typename Accel>
    struct init {
        void operator()(Accel * accel) {
            assert(!"default not implemented");
        }
    };
    
    /* G4 version */
    template <>
    struct init <AcceleratorG4> {
        void operator()(AcceleratorG4 * accel) {
            cout << "Accel_init: G4" << endl;
        }
    };
    
    /* G5 version */
    template <>
    struct init <AcceleratorG5> {
        void operator()(AcceleratorG5 * accel) {
            /* Punt to G4 */
            init<AcceleratorG4>()(&accel->base);
            
            /* G5 logic */
            cout << "Accel_init: G5" << endl;
        }
    };
    
    
#pragma mark - enumerate
    /* Use a function when partial specialization not required.
     * Use a function operator when it is required.
     */
    template <typename Accel, typename Config>
    struct enumerate {
        void operator()(Accel * accel){
            assert(!"default not implemented");
        }
    };
    
    template <typename Config>
    struct enumerate<AcceleratorG4, Config> {
        void operator()(AcceleratorG4 * accel) {
            cout << " Enumerate: G4 version" << endl;
        }
    };
    
    template <typename Config>
    struct enumerate<AcceleratorG5, Config> {
        void operator()(AcceleratorG5 * accel) {
            cout << " Enumerate: G5 version" << endl;
            
            enumerate<AcceleratorG4, Config>()(&accel->base);
        }
    };
}
