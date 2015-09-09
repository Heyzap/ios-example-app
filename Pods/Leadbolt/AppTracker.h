//
//  AppTracker.h - v5.2
//
//  Created by Leadbolt.
//  Copyright (c) 2015 Leadbolt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppTracker : NSObject 


/// Start, close, sync
+(void) startSession:(NSString *)apiKey;
+(void) startSession:(NSString *)apikey view:(UIView *)view __deprecated;
+(void) closeSession;

+(void) setSyncDataPeriodInSecond:(int)periodInSecond;
+(void) sync;

// Basic Event Functions
+(void) event:(NSString*) name;
+(void) event:(NSString*) name instant:(BOOL)instant;

// Event with Float Values
+(void) event:(NSString*) name value:(float)floatValue;
+(void) event:(NSString*) name value:(float)floatValue instant:(BOOL)instant;
+(void) event:(NSString*) name value:(float)floatValue ref:(NSString*)ref;
+(void) event:(NSString*) name value:(float)floatValue ref:(NSString*)ref instant:(BOOL)instant;

/// Event with String Values
+(void) event:(NSString*) name stringValue:(NSString*) value;
+(void) event:(NSString*) name stringValue:(NSString*) value instant:(BOOL)instant;
+(void) event:(NSString*) name stringValue:(NSString*) value ref:(NSString *)ref;
+(void) event:(NSString*) name stringValue:(NSString*) value ref:(NSString*)ref instant:(BOOL)instant;

// Event with int Values
+(void) event:(NSString*) name intValue:(int)intValue;
+(void) event:(NSString*) name intValue:(int)intValue instant:(BOOL)instant;
+(void) event:(NSString*) name intValue:(int)intValue ref:(NSString *)ref;
+(void) event:(NSString*) name intValue:(int)intValue ref:(NSString *)ref instant:(BOOL)instant;

// Transaction Events
+(void) transaction:(NSString*) name value:(float)floatValue currencyCode:(NSString*)currencyCode;
+(void) transaction:(NSString*) name value:(float)floatValue currencyCode:(NSString*)currencyCode instant:(BOOL)instant;
+(void) transaction:(NSString*) name value:(float)floatValue currencyCode:(NSString*)currencyCode ref:(NSString*)ref;
+(void) transaction:(NSString*) name value:(float)floatValue currencyCode:(NSString*)currencyCode ref:(NSString*)ref instant:(BOOL)instant;

// Module functions
+(void) loadModule:(NSString*) placement viewController:(UIViewController*)viewController;
+(void) loadModule:(NSString*) placement viewController:(UIViewController*)viewController withUserData:(NSString*)userData;
+(void) loadModuleToCache:(NSString*) placement;
+(void) loadModuleToCache:(NSString*) placement withUserData:(NSString*)userData;
+(void) destroyModule;

// Crash Reporting
+(void)setCrashHandlerStatus:(BOOL)enable;
+(void)crashWithName:(NSString*)crashName description:(NSString*)description;

// Landscape Mode
+(void) setLandscapeMode:(BOOL)mode __deprecated;

typedef enum {
    AdOrientation_AutoDetect=0,
    AdOrientation_Landscape,
    AdOrientation_Portrait
} AdOrientation;

// force Ad Orientation
+(void) fixAdOrientation:(AdOrientation)orientation;

@end
