//
//
// Copyright (c) 2017 Fyber. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import "FYBOffer.h"
#import "FYBInterstitialCreativeType.h"

@interface FYBInterstitialOffer : NSObject <FYBOffer>

@property (nonatomic, copy, readonly) NSString *tpnPlacementId;
@property (nonatomic, assign, readonly) FYBInterstitialCreativeType creativeType;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end
