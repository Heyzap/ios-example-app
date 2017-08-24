//
//  AppTracker.h - v8.2
//
//  Created by Leadbolt.
//  Copyright (c) 2017 Leadbolt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "ATNativeAd.h"
#import "ATNativeAdOptions.h"
#import "ATNativeAdCollection.h"

@protocol AppModuleDelegate <NSObject>

@optional
-(void) onModuleLoaded:(NSString *)placement;
-(void) onModuleClosed:(NSString *)placement reward:(BOOL)reward;
-(void) onModuleClicked:(NSString *)placement;
-(void) onModuleCached:(NSString *)placement;
-(void) onModuleFailed:(NSString *)placement error:(NSString *)error cached:(BOOL)iscached;

@end

@interface AppTracker : NSObject

typedef enum {
    AppTrackerDisableAutoCache=0,
    AppTrackerEnableAutoCache
} AdCacheOption;


/// Start, close, sync
+(void) startSession:(NSString *)apiKey;
+(void) startSession:(NSString *)apiKey withOption:(AdCacheOption) option;
+(void) closeSession;

// Module functions
+(void) loadModule:(NSString*) placement viewController:(UIViewController*)viewController;
+(void) loadModule:(NSString*) placement viewController:(UIViewController*)viewController withUserData:(NSString*)userData;
+(void) loadModuleToCache:(NSString*) placement;
+(void) loadModuleToCache:(NSString*) placement withUserData:(NSString*)userData;
+(void) destroyModule;

// Crash Reporting
+(void)setCrashHandlerStatus:(BOOL)enable;
//+(void)crashWithName:(NSString*)crashName description:(NSString*)description;


typedef enum {
    AdOrientation_AutoDetect=0,
    AdOrientation_Landscape,
    AdOrientation_Portrait
} AdOrientation;

// force Ad Orientation
+(void) fixAdOrientation:(AdOrientation)orientation;

+(void)setAppModuleDelegate:(id<AppModuleDelegate>)delegate;

+(BOOL) isAdReady:(NSString *)placement;

//Demographics function
+(void) setAgeRange:(NSString *)range; // accepted values "13-17", "18-25", "26-35", "36-45", "46+"
+(void) setGender:(NSString *)gender; // accepted valued "Male", "Female"


// Native Ad methods
+(void) loadNativeAds:(ATNativeAdOptions *)options;
+(void) setNativeAdDelegate:(id<ATNativeAdDelegate>)delegate;

+(void) setFramework:(NSString *)framework;


@end
