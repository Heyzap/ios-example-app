# Fyber FairBid iOS Example App

This sample app demonstrates the basic functionalities of the Fyber FairBid SDK for iOS. 

## Features

* You can fetch and show Interstitial, Video, Incentivized, and Banner ads from the main screen by selecting one of them and pressing the fetch and show buttons.
* All fetches and shows on the main screen will use the ad tag entered in the ad tag text field, or the default tag if no tag is entered.
* The Mediation Test Suite can be opened, which allows you to test ads and debug settings for each network.
* A console view prints callbacks, NSNotifications, and more information from the Fyber FairBid SDK.
* As callbacks/notifications/etc come in, the show button will change colors to reflect ad availability. The availability can also be checked manually with the `isAvailable?` button, which will also change the color of the show button.

## Installation

The sample app relies on CocoaPods as the dependency manager. To install the dependencies, run the following command:

```bash
pod install --repo-update
```

After that, open the file SampleApp.xcworkspace on XCode.

### Setup

In order to utilize the test app with your own settings on your Fyber FairBid dashboards, you'll need to change a couple of things:

* Your Bundle ID
  * Change the bundle ID in Xcode to your game's bundle ID in the target settings.
* Your Publisher ID
  * Change the publisher ID string set in `AppDelegate.m` from `ENTER_YOUR_PUBLISHER_ID_HERE` to your own publisher ID.

If you do not do these things, 3rd-party networks may not be available in the test app.

### Cocoapods

*This project uses CocoaPods to add dependencies. If you'd rather add the frameworks and libraries yourself, you can remove some/all Pods from the `Podfile`, run `pod install` in this repo's top directory to remove the frameworks and libraries, and instead follow the instructions on adding SDKs [here](https://developers.heyzap.com/docs/ios_sdk_setup_and_requirements).*

The latest versions of each pod we've tested are shown in the `Podfile.lock` file.

The `podfile` is set up to use the latest versions of the 3rd-party networks' SDKs.
