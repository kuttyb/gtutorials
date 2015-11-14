//
//  ChannelGen1.h
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/14/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef ChannelGen1_h
#define ChannelGen1_h

#pragma mark - Gen1
template <typename ChipDispatch>
class ChannelGen1 : public ChannelBase<ChipDispatch> {
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        ChannelBase<ChipDispatch>::init();
    }
};

#endif /* ChannelGen1_h */
