//
//  ATNativeAdCollection.h
//
//  Created by Leadbolt
//  Copyright © 2016 LeadBolt. All rights reserved.
//

@interface ATNativeAdCollection : NSObject

@property (readonly) NSArray *ads;

-(void) doAllImpressions;

-(void)setConfig:(NSDictionary *)json;

@end