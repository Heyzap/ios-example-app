//
//  ViewController.h
//  SampleApp
//
//  Created by Monroe Ekilah on 7/21/15.
//  Copyright (c) 2015 heyzap.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <HeyzapAds/HeyzapAds.h>

@interface HeyzapSampleAppViewController : UIViewController <HZAdsDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;


/** Updates the scrollView contentSize property to encapsulate all subviews. Subclasses should call this after adding views to the scrollview (typically, at the end of viewDidLoad). */
- (void)updateScrollViewContentSize;

@end

