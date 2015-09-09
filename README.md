Heyzap iOS Example App
===============

This sample app shows the basic functionalities of the Heyzap SDK for iOS. 

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

*This project uses CocoaPods to add dependencies. If you'd rather add the frameworks and libraries yourself, you can remove the Pods from the `podfile` and instead follow the instructions on adding SDKs [here](https://developers.heyzap.com/docs/ios_sdk_setup_and_requirements).*

To install the SDKs for all the 3rd-party networks and Heyzap using Cocoapods, use Terminal and navigate to the top level directory of this repo. Then, run `pod install`. This will download the 3rd-party SDKs and Heyzap and add them to your project.

The latest versions of each pod we've tested are shown below:

	- AdColony (2.5.3)
	- AppLovin (3.1.2)
	- ChartboostSDK (5.5.3)
	- FacebookAudienceNetwork (4.5.1)
	- Google-Mobile-Ads-SDK (7.4.1)
	- Heyzap (9.1.5)
	- HyprMX (36)
	- Leadbolt (5.2)
	- UnityAds (1.4.5)
	- VungleAdvertiserSDK (3.1.2)

The `podfile` is set up to use Heyzap SDK `v9.1.5`, and the above versions of the 3rd-party networks' SDKs that we know are compatible with this version of Heyzap's SDK. As new versions of the Heyzap SDK become available, we will try and keep this list & repo up to date. Feel free to submit a pull request or an email to support@heyzap.com if you see that this is not the case.
