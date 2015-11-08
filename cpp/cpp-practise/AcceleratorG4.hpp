//
//  AcceleratorG4.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G4 specializations
template <typename ChipDispatch>
class AcceleratorImpl<G4::accel, ChipDispatch> {
public:
    static void init(G4::accel * accel) {
        assert(accel->channel3D);
        
        cout << "Accel_init: G4" << endl;
    }
    
    static void enumerate(G4::accel * accel) {
        assert(accel->channel3D);
        
        cout << " Enumerate: G4 version" << endl;
    }
};
