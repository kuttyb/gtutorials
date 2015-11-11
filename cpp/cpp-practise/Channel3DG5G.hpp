//
//  Channel3DG5G.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/8/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#pragma mark - G5 Specialization
template <typename ChipDispatch>
class Channel3DImpl<G5G::channel3D, ChipDispatch> {
public:
	static void init(G5G::channel3D * channel) {
		/* Punt to G4 */
		Channel3DImpl<G5::channel3D, ChipDispatch>::init(&channel->base);

		channel->local_value = 0;
	}
	
	static void submit(G5G::channel3D * channel, brn1Data * data, brn2Data * data2, brn3Data * data3) {
		cout << "Submit : G5 " << channel->local_value << endl;
		
		/* Punt back into G4 for some common logic */
		Channel3DImpl<G5::channel3D, ChipDispatch>::submit(&channel->base, data, data2, data3);

		/* TODO: Add an extra BRN here */
	}
};
