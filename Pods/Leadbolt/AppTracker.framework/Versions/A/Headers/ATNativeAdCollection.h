//
//  ATNativeAdCollection.h
//
//  Created by Leadbolt
//  Copyright © 2016 LeadBolt. All rights reserved.
//
#import "AppTracker.h"

@interface ATNativeAdCollection : NSObject

@property (readonly) NSArray *ads;

-(void) doAllImpressions;

-(void)setConfig:(NSDictionary *)json withDelegate:(id<ATNativeAdDelegate>)d;

@end
