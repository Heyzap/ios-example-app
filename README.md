Heyzap iOS Example App
===============

This sample app, a Cocos2D game, integrates Heyzap's iOS Ads SDK. To sample the ads, download the zip file and open the `.xcworkspace` file. Each time you lose, an ad is shown.

Only 2 files use Heyzap Ads, and both are in the `Lumio/Files Using Heyzap SDK` group in Xcode. (Ctrl+F Heyzap to find the pertinent code).

You can flip between interstitials and video by changing the `useVideo` `BOOL` in `AppDelegate.m`.

<img src="/Lumio/Resources/Screenshots/ScreenShot1.png" width="320" height="480" alt="Screenshot 1">


### Internals

Internally, the project uses CocoaPods to add dependencies, but for your convenience the `Pods/` folder is stored in the repository, so you don't need to use CocoaPods.

### License

Lumio was created by Joanne Dyer and is licensed under a Creative Commons Attribution-Noncommercial-Share Alike license.
