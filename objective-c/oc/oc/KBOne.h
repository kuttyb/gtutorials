//
//  KBOne.h
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KBOne : NSObject {
	// protected variables here (default is protected) you can change it with @public, @protected, @private
	// General rule of thumb seemes to be to keep protected and private in the .m file instead and keep the
	// interface clean for public consumption.
	@public int pubVar;
}

@property (nonatomic) int localProp;

-(int) add:(int) inputOne INPUTTWO:(int) inputTwo;

-(void) dumpState;

@end


