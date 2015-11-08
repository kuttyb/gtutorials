//
//  AcceleratorG5.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G5 specializations
template <typename Config>
class AcceleratorImpl<G5::accel, Config> {
public:
    static void init(G5::accel * accel) {
        assert(accel->channel3D);
        
        /* Punt to G4 */
        AcceleratorImpl<G4::accel, Config>::init(&accel->base);
        
        /* G5 logic */
        cout << "Accel_init: G5" << endl;
    }
    
    static void enumerate(G5::accel * accel) {
        assert(accel->channel3D);
        
        cout << " Enumerate: G5 version" << endl;
        
        AcceleratorImpl<G4::accel, Config>::enumerate(&accel->base);
    }
};

