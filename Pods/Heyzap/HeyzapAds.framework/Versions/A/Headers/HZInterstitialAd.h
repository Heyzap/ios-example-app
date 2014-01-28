/*
 * Copyright (c) 2014, Smart Balloon, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of 'Smart Balloon, Inc.' nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

@protocol HZAdsDelegate;

/** Controller class for showing Heyzap's Interstitial Ads. Typical users will only need to call the `show` method. */
@interface HZInterstitialAd : NSObject

#pragma mark - Showing Ads

/** Shows an interstitial ad. */
+ (void) show;

/** Shows an interstitial ad.
 
 @param tag A string identifying the context in which the ad was shown, e.g. "After level 1". In the future, Heyzap will breakdown ads data based on this value. */
+ (void) showForTag: (NSString *) tag;

/** Shows an interstitial ad.
 
 @param tag A string identifying the context in which the ad was shown, e.g. "After level 1". In the future, Heyzap will breakdown ads data based on this value.
 @param completion Completion block
 `result` `YES` if there was an ad to show, otherwise `NO`.
 `error` `nil` if there was an ad to show. Otherwise, the error's `userInfo` dictionary will contain an explanation under the `NSLocalizedDescriptionKey`.
 */
+ (void) showForTag:(NSString *)tag completion:(void (^)(BOOL result, NSError *error))completion;

#pragma mark - Callbacks

/** Sets the delegate to receive the messages listed in the `HZAdsDelegate` protocol.
 
 @param delegate The object to receive the callbacks. 
 */
+ (void) setDelegate: (id<HZAdsDelegate>) delegate;

#pragma mark - Manual Control of Ads

// Typical users of the SDK won't need to call these methods. However, you may use them to achieve more fine-tuned control, especially if you are using multiple ad networks and want to minimize unnecessary server requests.

/** Fetches a new ad from Heyzap.  */
+ (void) fetch;

/** Fetches a new ad from Heyzap with an optional completion handler */
+ (void) fetchWithCompletion: (void (^)(BOOL result, NSError *error))completion;

/** Fetches a new ad for a tag from Heyzap */
+ (void) fetchForTag: (NSString *) tag;

/** Fetches a new ad for a tag from Heyzap with an optional completion handler */
+ (void) fetchForTag:(NSString *)tag withCompletion: (void (^)(BOOL result, NSError *error))completion;

/** Whether or not an ad is available to show. */
+ (BOOL) isAvailable;

/** Whether or not an ad with the particular tag is available to show. */
+ (BOOL) isAvailableForTag: (NSString *) tag;

/** Dismisses the current ad, if visible. If an ad has been fetched from the server, clears all data about that ad from memory. If auto-prefetching has not been turned off, this method also fetches a new ad. */
+ (void) hide;


#pragma mark - Private methods

+ (void) setCreativeID:(int)creativeID;

/** Private method
 @param options private
 */
+ (void)showAdWithOptions:(NSDictionary *)options;

@end
