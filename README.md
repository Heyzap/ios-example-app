Heyzap iOS Example App
===============

This sample app demonstrates the basic functionalities of the Heyzap SDK for iOS. 

### Features:
* You can fetch and show Interstitial, Video, Incentivized, and Banner ads from the main screen by selecting one of them and pressing the fetch and show buttons.
* All fetches and shows on the main screen will use the ad tag entered in the ad tag text field, or the default tag if no tag is entered.
* The Mediation Test Suite can be opened, which allows you to test ads and debug settings for each network.
* A console view prints callbacks, NSNotifications, and more information from the Heyzap SDK.
* As callbacks/notifications/etc come in, the show button will change colors to reflect ad availability. The availability can also be checked manually with the `isAvailable?` button, which will also change the color of the show button.


### Setup

In order to utilize the test app with your own settings on your Heyzap dashboards, you'll need to change a couple of things:
* Your Bundle ID
	* Change the bundle ID in Xcode from `com.heyzap.ios.sampleapp` to your game's bundle ID in the target settings.
* Your Publisher ID
	* Change the publisher ID string set in `AppDelegate.m` from `ENTER_YOUR_PUBLISHER_ID_HERE` to your own publisher ID.

If you do not do these things, 3rd-party networks will not be available in the test app.

### Cocoapods

*This project uses CocoaPods to add dependencies. If you'd rather add the frameworks and libraries yourself, you can remove some/all Pods from the `podfile`, run `pod install` in this repo's top directory to remove the frameworks and libraries, and instead follow the instructions on adding SDKs [here](https://developers.heyzap.com/docs/ios_sdk_setup_and_requirements).*

All the pods are included in this repo. You should not need Cocoapods installed on your machine, and the app should run from Xcode without any other configuration or downloads.

The latest versions of each pod we've tested & included in this repo are shown below:

	- AdColony (2.6.2)
	- AppLovin (3.4.0)
	- ChartboostSDK (6.4.7)
	- FBAudienceNetwork (4.14.0)
	- Google-Mobile-Ads-SDK (7.9.1)
	- Heyzap (9.6.3)
	- HyprMX (68)
	- HZInMobi (5.3.1)
	- Leadbolt (6.0)
	- UnityAds (1.5.6)
	- VungleSDK-iOS (3.2.2)

The `podfile` is set up to use the latest versions of the 3rd-party networks' SDKs. Feel free to send an email to support@heyzap.com if you find that one of the updates to a third-party SDK seems to be incompatible with the latest Heyzap SDK.


### Known issues
- Leadbolt 6.0 (`libAppTracker.a`) will produce warnings that are caused by [this bug](https://openradar.appspot.com/radar?id=5051031360634880).
