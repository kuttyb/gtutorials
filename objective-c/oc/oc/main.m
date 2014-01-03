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
		NSDate *now = [NSDate date];
	    NSLog(@"This NSDate object lives at %p", now);
		NSLog(@"The date is %@", now);
		
		double seconds = [now timeIntervalSince1970];
		NSLog(@"time elapsed %f", seconds);
		
		// kbb: Notice how multiple arguments are sent
		//      Key point here being, the selector is NOT of the type method(arg1, arg2)
		//		Instead, it is of the type  "method - arg1 - arg2"
		//		The entire method-arg combination decides what message is being sent to the
		//		object. Best to think in terms of Message sending rather than method calling :)
		NSCalendar *cal = [NSCalendar currentCalendar];
		unsigned long day = [cal ordinalityOfUnit:NSDayCalendarUnit inUnit:NSMonthCalendarUnit forDate:now];
		NSLog(@"This is day %lu of the month", day);
	}
	
    return 0;
}

