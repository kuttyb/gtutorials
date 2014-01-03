//
//  main.m
//  oc
//
//  Created by kutty banerjee on 1/3/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{

	@autoreleasepool {
	    // insert code here...
		NSDate *now = [[NSDate alloc] init];
	    NSLog(@"This NSDate object lives at %p", now);
		NSLog(@"The date is %@", now);
		NSLog(@"time elapsed %f", [now timeIntervalSince1970]);
		
		// multiple arguments in message sending
		NSLog(@"This is day %lu of the month", [[NSCalendar currentCalendar] ordinalityOfUnit:NSDayCalendarUnit inUnit:NSMonthCalendarUnit forDate:now]);
	}
	
    return 0;
}

