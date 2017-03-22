//
//  ATNativeAd.h
//
//  Created by Leadbolt
//  Copyright © 2016 LeadBolt. All rights reserved.
//

typedef void(^completion)(NSError *);
typedef enum {
    ATNativeAdErrorNoConnection=0,
    ATNativeAdErrorNoFill
} ATNativeAdError;

typedef enum {
    ATNativeAdTrackStart=0,
    ATNativeAdTrackProgress25,
    ATNativeAdTrackProgress50,
    ATNativeAdTrackProgress75,
    ATNativeAdTrackEnd,
    ATNativeAdTrackMute,
    ATNativeAdTrackUnmute,
    ATNativeAdTrackPause,
    ATNativeAdTrackResume,
    ATNativeAdTrackReplay,
    ATNativeAdTrackFullscreen,
    ATNativeAdTrackExitFullscreen,
    ATNativeAdTrackAcceptInvitation,
    ATNativeAdTrackSkip
} ATNativeAdTrackEvent;

typedef enum {
    ATNativeAdOptionMediaTypeImage=0,
    ATNativeAdOptionMediaTypeVideo
} ATNativeAdOptionMediaType;


@interface ATNativeAd : NSObject

@property (readonly) NSString *title;
@property (readonly) NSString *adDescription;
@property (readonly) NSString *callToAction;
@property (readonly) NSString *mediaUrl;
@property (readonly) ATNativeAdOptionMediaType mediaType;
@property (readonly) NSString *iconUrl;

@property (readonly) float duration;
@property (readonly) NSString *imageUrlLandscape;
@property (readonly) NSString *imageUrlPortrait;


-(void) doImpression;
-(void) setConfig:(NSDictionary *)json;
-(void) doClickFromViewController:(UIViewController *)m withStoreKitDelegate:(id<SKStoreProductViewControllerDelegate>)d completion:(completion)block;

-(void) doTrackEvent:(ATNativeAdTrackEvent)event;

@end