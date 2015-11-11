//
//  Channel3DG5.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G5 Specialization
template <typename ChipDispatch>
class Channel3DImpl<G5::channel3D, ChipDispatch> {
public:
    static void init(Channel3DG5 * channel) {
        /* Punt to G4 */
        Channel3DImpl<G4::channel3D, ChipDispatch>::init(&channel->base);
        
        channel->estimate = 20;
        channel->values   = 10;
    }
    
    static void submit(Channel3DG5 * channel, brn1Data * data, brn2Data * data2, brn3Data * data3) {
        cout << "Submit : G5 " << channel->values << endl;
        
        /* Punt back into G4 for some common logic */
        Channel3DImpl<G4::channel3D, G4>::submit(&channel->base, data, data2, data3);
        
		brn2<ChipDispatch::BRN::brn2, ChipDispatch>::apply(data2);
    }
};


