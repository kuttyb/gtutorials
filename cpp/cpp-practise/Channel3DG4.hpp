//
//  Channel3DG4.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G4 Specialization
template <typename Config>
class Channel3DImpl<Channel3DG4, Config> {
public:
    static void init(Channel3DG4 * channel) {
        channel->baseAddr = 0xabcd;
        channel->priority = 0;
        channel->runtime  = 0;
    }
    
    static void submit(Channel3DG4 * channel) {
        /* This code could get used by non G4 chips, use the BRN appropriately */
        BRN::BRN1<Config::BRN::brn1, Config>()();
        
        cout << "Submit : G4" << endl;
        
        BRN::BRN2<Config::BRN::brn2, Config>()();
        
        BRN::BRN3<Config::BRN::brn3, Config>()();
    }
};

