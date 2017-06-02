//
//  HYPRErrorType.h
//  HyprMX
//
//  Created on 3/1/12.
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//

typedef NS_ENUM(NSInteger, HYPRErrorType) {
    
    /** 
     * VAST Errors  
     * 020 - 039
     */
    HYPRErrorTypeVASTPlayerError                   = 20,
    HYPRErrorTypeVASTParsingTagError               = 21,
    HYPRErrorTypeVASTDownloadingError              = 22,
    HYPRErrorTypeVASTCachingAssetError             = 23,
    HYPRErrorTypeVASTAssetDownloadError            = 24,
    HYPRErrorTypeVASTDownloadingTagError           = 25,
    HYPRErrorTypeVASTNoSuitableMediaError          = 26,
    HYPRErrorTypeVASTPrepareForPlaybackError       = 27,
    HYPRErrorTypeVASTRewardNotDeliveredError       = 28,
    
    // VAST Errors: Player Catalog Frame Errors
    HYPRErrorTypeVASTPlayerDidNotReceiveThankYouURL     = 30,
    HYPRErrorTypeVASTPlayerCatalogFrameError            = 31,
    
    // VAST Errors: Parser Internal Errors
    HYPRErrorTypeNSXMLParseError                        = 32,
    HYPRErrorTypeNSXMLValidationError                   = 33,
    HYPRErrorTypeParsingStatusFailedWithNoData          = 34,
    HYPRErrorTypeParsingWrapperLoopDetected             = 35,
    
    // VAST Errors: XML XSD Validation Errors
    HYPRErrorTypeVASTDocumentConversionError = 36,

    /**
     * General Web View Errors
     * 040-059
     */
    HYPRErrorTypeWebViewEmptyJavaScriptError = 40,
    HYPRErrorTypeWebViewJavaScriptPOSTError = 41,
    HYPRErrorTypeGeneralOfferPageReadyError = 42,
    
    // HYPROfferViewController App Store Errors
    HYPRErrorTypeAppStoreLoadingError       = 43,
    
    // HYPROfferViewController Payout Errors
    HYPRErrorTypePayoutCompleteJavaScriptError = 44,
    
    // Post Offer Questions Error
    HYPRErrorTypePostOfferQuestionsNotSupported = 45,
    
    /**
     * Web Traffic Errors
     * 060-079
     */
    HYPRErrorTypeWebTrafficPageReadyError                 = 60,
    HYPRErrorTypeWebTrafficSessionTaskError               = 61,
    HYPRErrorTypeWebTrafficJSONContentsError              = 62,
    HYPRErrorTypeWebTrafficOfferValidationError           = 63,
    HYPRErrorTypeWebTrafficReadyStateJavaScriptError      = 64,
    HYPRErrorTypeWebTrafficJSONContentValidationError     = 65,
    HYPRErrorTypeWebTrafficPageLoadScriptsJavaScriptError = 66,
    HYPRErrorTypeWebTrafficJavaScriptPOSTError            = 67,
    
    /**
     * HYPRDownloadJob Errors
     * 080-099
     */
    HYPRErrorTypeDownloadJobCopyFileError                   = 80,
    HYPRErrorTypeDownloadJobNSDataCopyError                 = 81,
    HYPRErrorTypeDownloadJobAssetValidationError            = 82,
    HYPRErrorTypeDownloadJobNotEnoughDiskSpaceError         = 83,
    HYPRErrorTypeDownloadJobNSURLSessionTaskFailureDelegate = 84,
    HYPRErrorTypeDownloadJobReceived404ResponseError        = 85,

    /**
     * Offers Available Errors
     * 100-119
     */
    HYPRErrorTypeOfferAvailableFailed                   = 100,
    
    /**
     * Image Errors
     * 120-139
     */
    HYPRErrorTypeImageLoadingError   = 120,
    HYPRErrorTypeImageParameterError = 121,
    
    /**
     * HYPROfferViewController Audio Session Errors
     * 140-159
     */
    HYPRErrorTypeAudioSessionFailureToSetCategory                  = 140,
    HYPRErrorTypeAudioSessionFailureToSetSettings                  = 141,
    HYPRErrorTypeAudioSessionFailureToSetPlaybackToActiveSession   = 142,
    HYPRErrorTypeAudioSessionFailureToSetPlaybackToOriginalSession = 143,
    
    /**
     * NSURL Error
     * 160-179
     */
    HYPRErrorTypeStringToNSURLConversionError = 160,
    
    /**
     * HYPRObjectMappingQueue Errors
     * 180-199
     */
    HYPRErrorTypeObjectMappingQueueNilJSONObject = 180,
    HYPRErrorTypeObjectMappingQueueJSONParsingFailure = 181,
    
    /**
     * HYPRMRAIDDeviceSupportHandler Errors
     * 200-219
     */
    HYPRErrorTypeNonStringPhotosUsageDescriptionPlistValue = 200,
    HYPRErrorTypeEmptyStringPhotosUsageDescriptionPlistValue = 201,
    HYPRErrorTypeNonStringCalendarsUsageDescriptionPlistValue = 202,
    HYPRErrorTypeEmptyStringCalendarsUsageDescriptionPlistValue = 203,
    
    /**
     * Unspecified Error (Used in Unit Tests)
     * 0
     */
    HYPRErrorTypeUnspecified = 0
    
};

//
// static list of error messages for types
//
static NSString * const HYPRErrorMessages[] = {
    
    [HYPRErrorTypeVASTPlayerError] = @"An error occurred while playing a VAST video",
    [HYPRErrorTypeVASTParsingTagError] = @"An error occurred while parsing the VAST tag",
    [HYPRErrorTypeVASTDownloadingError] = @"Could not load VAST offer(s) from the specified URL",
    [HYPRErrorTypeVASTCachingAssetError] = @"An error occurred while caching VAST asset",
    [HYPRErrorTypeVASTAssetDownloadError] = @"An error occurred while downloading VAST asset",
    [HYPRErrorTypeVASTDownloadingTagError] = @"An error occurred while downloading VAST tag",
    [HYPRErrorTypeVASTNoSuitableMediaError] = @"No suitable media was found for VAST tag",
    [HYPRErrorTypeVASTPrepareForPlaybackError] = @"An error occurred while the VAST asset was being prepared for playback",
    [HYPRErrorTypeVASTRewardNotDeliveredError] = @"The Offer completed, however, the reward was never delivered",
    
    [HYPRErrorTypeVASTPlayerDidNotReceiveThankYouURL] = @"The Thank You URL was not received before video finished playback",
    [HYPRErrorTypeVASTPlayerCatalogFrameError] = @"An error was thrown by the Catalog Frame response",
    [HYPRErrorTypeNSXMLParseError] = @"A Parsing error was thrown by the NSXML Vast Parser",
    [HYPRErrorTypeNSXMLValidationError] = @"A Validation error was thrown by the NSXML Vast Parser",
    [HYPRErrorTypeParsingStatusFailedWithNoData] = @"A VAST Parser failed with No Data Reported",
    [HYPRErrorTypeParsingWrapperLoopDetected] = @"A VAST Parser failed with Wrapper URL Loop detected",
    
    [HYPRErrorTypeVASTDocumentConversionError] = @"An error ocurred when converting the VAST XML data into an XML document",
    
    [HYPRErrorTypeWebViewEmptyJavaScriptError] = @"Web View empty string JavaScript evaluation error occurred",
    [HYPRErrorTypeWebViewJavaScriptPOSTError] = @"The Web View failed to evaluate the JavaScript POST",
    [HYPRErrorTypeDownloadJobReceived404ResponseError] = @"Download Job Received 404 Response from Server",
    [HYPRErrorTypeDownloadJobCopyFileError] = @"Failed to copy the file",
    [HYPRErrorTypeDownloadJobNSDataCopyError] = @"NSURLSession data copy to new NSData object exception occurred",
    [HYPRErrorTypeDownloadJobAssetValidationError] = @"Asset validation error",
    [HYPRErrorTypeDownloadJobNSURLSessionTaskFailureDelegate] = @"URLSession:task:didCompleteWithError: was invoked",
    [HYPRErrorTypeAudioSessionFailureToSetSettings] = @"Audio Session failed to set the settings",
    [HYPRErrorTypeAudioSessionFailureToSetCategory] = @"Audio Session failed to set the category to AVAudioSessionCategoryPlayback",
    [HYPRErrorTypeAudioSessionFailureToSetPlaybackToActiveSession] = @"Audio Session failed to set the playback to active setting",
    [HYPRErrorTypeAudioSessionFailureToSetPlaybackToOriginalSession] = @"Audio Session failed to set the playback to original setting",
    [HYPRErrorTypeDownloadJobNotEnoughDiskSpaceError] = @"Not enough Disk Space exists for the file being downloaded",
    [HYPRErrorTypeImageParameterError] = @"Image URL is required to download an image",
    
    [HYPRErrorTypeImageLoadingError] = @"Could not load image from the specified URL",
    
    [HYPRErrorTypeOfferAvailableFailed] = @"Offers Available Request Failed",
    
    [HYPRErrorTypeUnspecified] = @"Unspecified Error Type",
    [HYPRErrorTypeAppStoreLoadingError] = @"An error occurred while loading the native App Store modal view",
    [HYPRErrorTypeStringToNSURLConversionError] = @"An error occurred while converting an NSString to a NSURL object",
    [HYPRErrorTypePostOfferQuestionsNotSupported] = @"Post Offer Questions are not supported by the iOS SDK",
    [HYPRErrorTypePayoutCompleteJavaScriptError] = @"payoutComplete JavaScript evaluation error occurred",
    [HYPRErrorTypeWebTrafficPageReadyError] = @"Web Traffic Offer page did not receive pageReady message. Close button attached to Navigation",
    [HYPRErrorTypeWebTrafficSessionTaskError] = @"Web Traffic NSURLSession Data Task initialization error occurred",
    [HYPRErrorTypeWebTrafficJSONContentsError] = @"Web Traffic Offer contents JSON String returned empty",
    [HYPRErrorTypeWebTrafficOfferValidationError] = @"Web Traffic Offer failed validation",
    [HYPRErrorTypeWebTrafficReadyStateJavaScriptError] = @"Web Traffic readyState JavaScript evaluation error occurred",
    [HYPRErrorTypeWebTrafficJSONContentValidationError] = @"Web Traffic Offer contents failed validation",
    [HYPRErrorTypeWebTrafficPageLoadScriptsJavaScriptError] = @"Web Traffic Page Load Scripts evaluation error occured",
    [HYPRErrorTypeWebTrafficJavaScriptPOSTError] = @"The Web Traffic failed to evaluate the JavaScript POST",
    
    [HYPRErrorTypeGeneralOfferPageReadyError] = @"General Offer page did not receive pageReady message. Close button attached to Navigation",
    
    [HYPRErrorTypeObjectMappingQueueNilJSONObject] = @"The JSON object failed to decode into a valid string",
    [HYPRErrorTypeObjectMappingQueueJSONParsingFailure] = @"Error Parsing the JSON object",
    
    [HYPRErrorTypeNonStringPhotosUsageDescriptionPlistValue] = @"NSPhotoLibraryUsageDescription is not a string",
    [HYPRErrorTypeEmptyStringPhotosUsageDescriptionPlistValue] = @"NSPhotoLibraryUsageDescription is an empty string",
    [HYPRErrorTypeNonStringCalendarsUsageDescriptionPlistValue] = @"NSCalendarsUsageDescription is not a string",
    [HYPRErrorTypeEmptyStringCalendarsUsageDescriptionPlistValue] = @"NSCalendarsUsageDescription is an empty string"
};
