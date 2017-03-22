AdColony iOS SDK
==================================
Modified: December 9, 2016  
SDK Version: 3.1.0

iOS 10
----------------------------------
iOS 10 has introduced one change that will affect your integration of our SDK. Please refer to our [integration instructions](https://github.com/AdColony/AdColony-iOS-SDK-3/wiki/Xcode-Project-Setup) for details.

Download:
----------------------------------
The simplest way to obtain the AdColony iOS SDK is to click the "Clone or download" button located on the upper, right-hand side of the Github repository page.

Contains:
----------------------------------
* AdColony.framework (iOS)
* Sample Apps (Swift and ObjC)
  * AdColonyBasic
  * AdColonyV4VC
  * AdColonyInstantFeed

Getting Started with AdColony:
----------------------------------
Our Aurora SDK contains huge leaps forward in our capabilities, with benefits for both publishers and advertisers. We would also like to highlight the addition of AdColony Compass™ to our suite of products. AdColony Compass provides publishers with intuitive marketing tools to maximize the value of users throughout your app economy, like creating rewards, achievements, push notifications and in-app messaging. Please note that updating from our AdColony 2.x SDK is not a drag and drop update, but rather includes breaking API and process changes. Please review our [documentation](https://github.com/AdColony/AdColony-iOS-SDK-3/wiki) to get a better idea on what changes will be necessary in your app.

AdColony Compass™ provides the tools to increase user engagement through targeted user communications, achievements and rewards.

Combined with AdColony’s award-winning Instant-Play™ HD video ads, Compass™ features can also stimulate monetization within apps. Compass™ tools allow publishers to incentivize desired user behaviors and improve KPI's for apps without heavy development work or altering carefully balanced in-app economies.

The Compass™ early access program has ended, and we are no longer accepting new partners for Compass™ access. Publishers who are currently using AdColony Compass™ services should email compass@adcolony.com for more details.

*All* users should review our [documentation](https://github.com/AdColony/AdColony-iOS-SDK-3/wiki).

3.1.0 Change Log:
----------------------------------
- Capability to retrieve the net CPM bid value for a zone's next ad
- MOAT viewability support
- Internal viewable impression metrics
- Support for dashboard's play frequency zone setting
- Developers no longer required to pause/resume native ads
- AdColonyCompass library no longer available in public build
- Decreased compiled size of SDK
- Fix for crash causing JavaScriptCore to run out of memory
- Misc bugfixes

3.0.6 Change Log:
----------------------------------
* Reduced performance impact of JSON operations
* Reduced energy impact from internal update loop
* Misc bugfixes

3.0.5 Change Log:
----------------------------------
* Click event handler in AdColonyInterstitial
* User-left-application handler in AdColonyInterstitial
* Misc bugfixes

3.0.4 Change Log:
----------------------------------
* General Availability (GA) release
* Misc bugfixes

3.0.3 Change Log:
----------------------------------
* Vertical ads
* Flexible ad-orientation controls
* Updated Swift syntax in sample apps (requires Xcode 8)
* Increased deployment target to iOS 6.0
* Misc bugfixes

3.0.2 Change Log:
----------------------------------
* AdColony Compass™
* Native Ad Unit (InstantFeed™)
* In-app Purchase Promo (IAPP) ads
* Custom Messaging
* InstantFeed demo app
* Swift-based sample apps
* Misc bugfixes

3.0.1 Change Log:
----------------------------------
* Increased required Xcode version to 7.0
* Asynchronous API for making ad requests
* Delegate protocols replaced with block-based handlers
* Replaced usage of NSURLConnection with NSURLSession
* Optimized ad server communication protocols
* Video-playing APIs now take a reference to presenting view controller
* New APIs for option setting and configuring user metadata

Legal Requirements:
----------------------------------
By downloading the AdColony SDK, you are granted a limited, non-commercial license to use and review the SDK solely for evaluation purposes.  If you wish to integrate the SDK into any commercial applications, you must register an account with AdColony and accept the terms and conditions on the AdColony website.

Note that U.S. based companies will need to complete the W-9 form and send it to us before publisher payments can be issued.


Contact Us:
----------------------------------
For more information, please visit AdColony.com. For questions or assistance, please email us at support@adcolony.com.
