//
//  Channel3DG4.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G4 Specialization
template <typename ChipDispatch>
class Channel3DImpl<G4::channel3D, ChipDispatch> {
public:
    static void init(Channel3DG4 * channel) {
        channel->baseAddr = 0xabcd;
        channel->priority = 0;
        channel->runtime  = 0;
    }
    
    static void submit(Channel3DG4 * channel) {
        /* This code could get used by non G4 chips, use the BRN appropriately */
        brn1<ChipDispatch::BRN::brn1, ChipDispatch>()();
        
        cout << "Submit : G4" << endl;
        
        brn2<ChipDispatch::BRN::brn2, ChipDispatch>()();
        
        brn3<ChipDispatch::BRN::brn3, ChipDispatch>()();
    }
};

