//
//  AppTracker.h - v6.0
//
//  Created by Leadbolt.
//  Copyright (c) 2015 Leadbolt. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AppModuleDelegate <NSObject>

@optional
-(void) onModuleLoaded:(NSString *)placement;
-(void) onModuleClosed:(NSString *)placement;
-(void) onModuleClicked:(NSString *)placement;
-(void) onModuleCached:(NSString *)placement;
-(void) onModuleFailed:(NSString *)placement error:(NSString *)error cached:(BOOL)iscached;
-(void) onMediaFinished:(BOOL)viewCompleted;

@end

@interface AppTracker : NSObject 


/// Start, close, sync
+(void) startSession:(NSString *)apiKey;
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

typedef enum {
    AdOrientation_AutoDetect=0,
    AdOrientation_Landscape,
    AdOrientation_Portrait
} AdOrientation;

// force Ad Orientation
+(void) fixAdOrientation:(AdOrientation)orientation;

+(void)setAppModuleDelete:(id<AppModuleDelegate>)delegate;

+(BOOL) isAdReady:(NSString *)placement;

//Demographics function
+(void) setAgeRange:(NSString *)range; // accepted values "13-17", "18-25", "26-35", "36-45", "46+"
+(void) setGender:(NSString *)gender; // accepted valued "Male", "Female"

+(void) setFramework:(NSString *)f;


@end
