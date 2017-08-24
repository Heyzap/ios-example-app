//
//  ATNativeAd.h
//
//  Created by Leadbolt
//  Copyright © 2016 LeadBolt. All rights reserved.
//

@protocol ATNativeAdDelegate;
@class ATNativeAdCollection;

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

typedef enum {
    ATNativeAdImageTypeCover=0,
    ATNativeAdImageTypeIcon
} ATNativeAdImageType;


@interface ATNativeAd : NSObject <SKStoreProductViewControllerDelegate>

@property (readonly) NSString *title;
@property (readonly) NSString *adDescription;
@property (readonly) NSString *callToAction;
@property (readonly) ATNativeAdOptionMediaType mediaType;

@property (readonly) float duration;
@property (readonly) NSString *imageUrlLandscape;
@property (readonly) NSString *imageUrlPortrait;


-(void) downloadImage:(ATNativeAdImageType)type withBlock:(nullable void (^) (UIImage * __nullable image)) block;
-(void) registerViewForInteraction:(UIView * _Nonnull)view withViewController:(UIViewController * _Nonnull)viewController;
-(void) unregisterView;

-(void) setConfig:(NSDictionary * __nullable)json withDelegate:(id<ATNativeAdDelegate>)d;
-(void) doTrackEvent:(ATNativeAdTrackEvent)event;

@end

@protocol ATNativeAdDelegate <NSObject>

@optional
-(void) onAdsLoaded:(ATNativeAdCollection *)collection;
-(void) onAdsFailed:(ATNativeAdError)error;
-(void) onAdClicked:(ATNativeAd *)ad;

@end
