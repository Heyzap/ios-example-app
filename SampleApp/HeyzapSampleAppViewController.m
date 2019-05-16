
//
//  ViewController.m
//  SampleApp
//
//  Created by Monroe Ekilah on 7/21/15.
//  Copyright (c) 2015 heyzap.com. All rights reserved.
//

#import "HeyzapSampleAppViewController.h"
#import <MessageUI/MessageUI.h>
#import <HeyzapAds/HeyzapAds.h>
typedef enum {
    kAdUnitSegmentInterstitial,
    kAdUnitSegmentVideo,
    kAdUnitSegmentIncentivized,
    kAdUnitSegmentBanner,
    kAdUnitSegmentOfferWall,
} kAdUnitSegment;


@interface HeyzapSampleAppViewController ()<HZAdsDelegate,UITextFieldDelegate, HZIncentivizedAdDelegate, HZBannerAdDelegate, HZFyberVirtualCurrencyClientDelegate>

@property (nonatomic, strong) UISegmentedControl *adUnitSegmentedControl;
@property (nonatomic, strong) UITextView *consoleTextView;

@property (nonatomic) UIButton *fetchButton;
@property (nonatomic) UIButton *showButton;

@property (nonatomic) UITextField *adTagField;
@property (nonatomic) UITextField *currencyIdField;

@property (nonatomic) UIButton *showBannerButton;
@property (nonatomic) UIButton *hideBannerButton;
@property (nonatomic, strong) HZBannerAd *currentBannerAd;

@property (nonatomic) NSArray *bannerControls;
@property (nonatomic) NSArray *offerWallControls;
@property (nonatomic) NSArray *standardControls;


@end

#define ButtonWidth 80
#define ButtonHeight 40
#define ButtonXSpacing 15
#define ButtonYSpacing 10

#define LOG_METHOD_NAME_TO_CONSOLE [self logToConsole:NSStringFromSelector(_cmd)]
#define LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(str) [self logToConsole:[NSString stringWithFormat:@"%@ %@", NSStringFromSelector(_cmd), str]]


@implementation HeyzapSampleAppViewController


#pragma mark - UI

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor lightGrayColor];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds]; // Set contentSize later dynamically
    self.scrollView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:self.scrollView];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil];
    
    // Dismisses first responder (keyboard)
    [self.view addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTapped:)]];
    
    // setup Heyzap callbacks
    [HZInterstitialAd setDelegate:self];
    [HZVideoAd setDelegate:self];
    [HZIncentivizedAd setDelegate:self];
    [HZOfferWallAd setDelegate:self];
    [[HZFyberVirtualCurrencyClient sharedClient] setDelegate:self];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(remoteDataRefreshed:) name:HZRemoteDataRefreshedNotification object:nil];
    
    // Setup buttons
    
    UIButton *testActivityButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    testActivityButton.frame = CGRectMake(ButtonXSpacing, 40.0, ButtonWidth*2 + ButtonXSpacing, ButtonHeight);
    testActivityButton.layer.cornerRadius = 4.0;
    testActivityButton.backgroundColor = [UIColor lightTextColor];
    [testActivityButton setTitle:@"Mediation Test Suite" forState:UIControlStateNormal];
    [testActivityButton addTarget:self action:@selector(showTestActivity) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollView addSubview:testActivityButton];
    
    self.fetchButton = [UIButton buttonWithType: UIButtonTypeRoundedRect];
    self.fetchButton.frame = CGRectMake(ButtonXSpacing, CGRectGetMaxY(testActivityButton.frame)+ButtonYSpacing, ButtonWidth, ButtonHeight);
    self.fetchButton.backgroundColor = [UIColor lightTextColor];
    self.fetchButton.layer.cornerRadius = 4.0;
    [self.fetchButton setTitle: @"Fetch" forState: UIControlStateNormal];
    self.fetchButton.accessibilityLabel = @"fetch";
    [self.fetchButton setTitleColor: [UIColor whiteColor] forState: UIControlStateNormal];
    [self.fetchButton addTarget: self action: @selector(fetchAd:) forControlEvents: UIControlEventTouchUpInside];
    [self.scrollView addSubview: self.fetchButton];
    
    self.showButton = [UIButton buttonWithType: UIButtonTypeRoundedRect];
    self.showButton.frame = CGRectMake(CGRectGetMaxX(self.fetchButton.frame) + ButtonXSpacing, CGRectGetMinY(self.fetchButton.frame), ButtonWidth, ButtonHeight);
    self.showButton.backgroundColor = [UIColor redColor];
    self.showButton.layer.cornerRadius = 4.0;
    [self.showButton setTitle: @"Show" forState: UIControlStateNormal];
    self.showButton.accessibilityLabel = @"show";
    [self.showButton setTitleColor: [UIColor whiteColor] forState: UIControlStateNormal];
    [self.showButton addTarget: self action: @selector(showAd:) forControlEvents: UIControlEventTouchUpInside];
    [self.scrollView addSubview: self.showButton];
    
    self.adTagField = ({
        UITextField *text = [[UITextField alloc] initWithFrame:CGRectMake(CGRectGetMaxX(self.showButton.frame) + ButtonXSpacing, CGRectGetMinY(self.fetchButton.frame), ButtonWidth*2, ButtonHeight)];
        text.delegate = self;
        text.borderStyle = UITextBorderStyleRoundedRect;
        text.keyboardType = UIKeyboardTypeDefault;
        text.placeholder = @"Ad Tag";
        text.textAlignment = NSTextAlignmentLeft;
        text.accessibilityLabel = @"ad tag";
        text.autocapitalizationType = UITextAutocapitalizationTypeNone;
        [text addTarget:self action:@selector(adTagEditingChanged:) forControlEvents:UIControlEventEditingChanged];
        text;
    });
    [self.scrollView addSubview:self.adTagField];
    
    self.hideBannerButton = [UIButton buttonWithType: UIButtonTypeRoundedRect];
    self.hideBannerButton.frame = self.fetchButton.frame;
    self.hideBannerButton.backgroundColor = [UIColor darkGrayColor];
    self.hideBannerButton.layer.cornerRadius = 4.0;
    [self.hideBannerButton setTitle: @"Hide" forState: UIControlStateNormal];
    self.hideBannerButton.accessibilityLabel = @"hide";
    [self.hideBannerButton setTitleColor: [UIColor whiteColor] forState: UIControlStateNormal];
    [self.hideBannerButton setTitleColor: [UIColor lightGrayColor] forState: UIControlStateDisabled];
    [self.hideBannerButton addTarget: self action: @selector(hideBannerButtonPressed:) forControlEvents: UIControlEventTouchUpInside];
    self.hideBannerButton.enabled = NO;
    [self.scrollView addSubview: self.hideBannerButton];
    
    self.showBannerButton = [UIButton buttonWithType: UIButtonTypeRoundedRect];
    self.showBannerButton.frame = self.showButton.frame;
    self.showBannerButton.backgroundColor = [UIColor greenColor];
    [self.showBannerButton setTitleColor: [UIColor whiteColor] forState: UIControlStateNormal];
    [self.showBannerButton setTitleColor: [UIColor lightGrayColor] forState: UIControlStateDisabled];
    self.showBannerButton.layer.cornerRadius = 4.0;
    [self.showBannerButton setTitle: @"Show" forState: UIControlStateNormal];
    self.showBannerButton.accessibilityLabel = @"show";
    [self.showBannerButton addTarget: self action: @selector(showBannerButtonPressed:) forControlEvents: UIControlEventTouchUpInside];
    [self.scrollView addSubview: self.showBannerButton];
    
    UIButton *availableButton = ({
        UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        button.frame = CGRectMake(ButtonXSpacing, CGRectGetMaxY(self.fetchButton.frame) + ButtonYSpacing, ButtonWidth, ButtonHeight);
        button.backgroundColor = [UIColor lightTextColor];
        button.layer.cornerRadius = 4.0;
        [button setTitle: @"Available?" forState: UIControlStateNormal];
        [button addTarget: self action: @selector(checkAvailability) forControlEvents: UIControlEventTouchUpInside];
        button;
    });
    [self.scrollView addSubview:availableButton];
    
    UIButton *vcsRequestButton = ({
        UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        button.frame = CGRectMake(CGRectGetMaxX(availableButton.frame) + ButtonXSpacing, CGRectGetMaxY(self.fetchButton.frame) + ButtonYSpacing, ButtonWidth*1.5, ButtonHeight);
        button.backgroundColor = [UIColor lightTextColor];
        button.layer.cornerRadius = 4.0;
        [button setTitle: @"VCS Request" forState: UIControlStateNormal];
        [button addTarget: self action: @selector(vcsRequest) forControlEvents: UIControlEventTouchUpInside];
        button;
    });
    [self.scrollView addSubview:vcsRequestButton];
    
    self.currencyIdField = ({
        UITextField *text = [[UITextField alloc] initWithFrame:CGRectMake(CGRectGetMaxX(vcsRequestButton.frame) + ButtonXSpacing, CGRectGetMinY(vcsRequestButton.frame), ButtonWidth*1.5, ButtonHeight)];
        text.delegate = self;
        text.borderStyle = UITextBorderStyleRoundedRect;
        text.keyboardType = UIKeyboardTypeDefault;
        text.placeholder = @"Currency ID";
        text.textAlignment = NSTextAlignmentLeft;
        text.accessibilityLabel = @"currency ID";
        text.autocapitalizationType = UITextAutocapitalizationTypeNone;
        text;
    });
    [self.scrollView addSubview:self.currencyIdField];
    
    self.adTagField = ({
        UITextField *text = [[UITextField alloc] initWithFrame:CGRectMake(CGRectGetMaxX(self.showButton.frame) + ButtonXSpacing, CGRectGetMinY(self.fetchButton.frame), ButtonWidth*2, ButtonHeight)];
        text.delegate = self;
        text.borderStyle = UITextBorderStyleRoundedRect;
        text.keyboardType = UIKeyboardTypeDefault;
        text.placeholder = @"Ad Tag";
        text.textAlignment = NSTextAlignmentLeft;
        text.accessibilityLabel = @"ad tag";
        [text addTarget:self
                 action:@selector(adTagEditingChanged:)
       forControlEvents:UIControlEventEditingChanged];
        text;
    });
    [self.scrollView addSubview:self.adTagField];
    
    self.adUnitSegmentedControl = [[UISegmentedControl alloc] initWithItems: @[@"Interstitial", @"Video", @"Incentivized", @"Banner", @"OfferWall"]];
    self.adUnitSegmentedControl.frame = CGRectMake(ButtonXSpacing, CGRectGetMaxY(availableButton.frame)+ButtonYSpacing, self.view.frame.size.width - ButtonXSpacing*2, ButtonHeight);
    self.adUnitSegmentedControl.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [self.adUnitSegmentedControl setSelectedSegmentIndex: 0];
    [self.adUnitSegmentedControl addTarget:self
                                    action:@selector(changeColorOfShowButton)
                          forControlEvents:UIControlEventValueChanged];
    [self.scrollView addSubview: self.adUnitSegmentedControl];

    self.consoleTextView = [[UITextView alloc] initWithFrame:CGRectMake(0.0, CGRectGetMaxY(self.adUnitSegmentedControl.frame)+10, self.view.frame.size.width, self.view.frame.size.height * 0.4)];
    self.consoleTextView.editable = NO;
    self.consoleTextView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [self.consoleTextView setFont: [UIFont fontWithName: @"Courier" size: 12.0]];
    [self.scrollView addSubview:self.consoleTextView];
    
    UIButton *emailConsoleButton = [self buttonWithRect:CGRectMake(ButtonXSpacing, CGRectGetMaxY(self.consoleTextView.frame) + 5, 88, 25) text:@"Email Text"];
    [emailConsoleButton addTarget:self action:@selector(emailConsoleButton) forControlEvents:UIControlEventTouchUpInside];
    emailConsoleButton.autoresizingMask = UIViewAutoresizingFlexibleRightMargin;
    [self.scrollView addSubview:emailConsoleButton];
    
    int clearWidth = 50, topWidth = 38, bottomWidth = 63;
    UIButton *clearButton = [self buttonWithRect:CGRectMake(CGRectGetMaxX(self.consoleTextView.frame)-clearWidth, CGRectGetMaxY(self.consoleTextView.frame) + 5, clearWidth, 25) text:@"Clear"];
    [clearButton addTarget:self action:@selector(clearButton) forControlEvents:UIControlEventTouchUpInside];
    clearButton.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    [self.scrollView addSubview:clearButton];
    
    UIButton *bottomButton = [self buttonWithRect:CGRectMake(CGRectGetMinX(clearButton.frame)-bottomWidth-5, CGRectGetMinY(clearButton.frame), bottomWidth, 25) text:@"Bottom"];
    [bottomButton addTarget:self action:@selector(bottomButton) forControlEvents:UIControlEventTouchUpInside];
    bottomButton.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    [self.scrollView addSubview:bottomButton];
    
    UIButton *topButton = [self buttonWithRect:CGRectMake(CGRectGetMinX(bottomButton.frame)-topWidth-5, CGRectGetMinY(clearButton.frame), topWidth, 25) text:@"Top"];
    [topButton addTarget:self action:@selector(topButton) forControlEvents:UIControlEventTouchUpInside];
    topButton.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    [self.scrollView addSubview:topButton];

    
    self.bannerControls = @[self.showBannerButton,self.hideBannerButton];
    self.standardControls = @[self.showButton, self.fetchButton, availableButton];
    self.offerWallControls = @[vcsRequestButton, self.currencyIdField];
    [self.bannerControls setValue:@YES forKey:@"hidden"];
    [self.offerWallControls setValue:@YES forKey:@"hidden"];
    
    // This approach avoids constant manual adjustment
    CGRect subviewContainingRect = CGRectZero;
    for (UIView *view in self.scrollView.subviews) {
        subviewContainingRect = CGRectUnion(subviewContainingRect, view.frame);
    }
    self.scrollView.contentSize = (CGSize) { subviewContainingRect.size.width, subviewContainingRect.size.height + 80 };
    
}

- (UIButton *)buttonWithRect:(CGRect)rect text:(NSString *)text{
    UIButton * button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [button setTitle:text forState:UIControlStateNormal];
    button.frame = rect;
    [button setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];
    button.titleEdgeInsets = UIEdgeInsetsMake(0, 5, 0, 0);
    return button;
}

- (void)viewTapped:(UITapGestureRecognizer *)sender{
    [sender.view endEditing:YES];
}

- (void)logToConsole:(NSString *)consoleString {
    NSDateFormatter * format = [[NSDateFormatter alloc]init];
    [format setDateFormat:@"[h:mm:ss a]"];
    self.consoleTextView.text = [self.consoleTextView.text stringByAppendingFormat:@"\n\n%@ %@",[format stringFromDate:[NSDate date]],consoleString];
    
    // get around weird bug in iOS 9 - text view scrolling has issues when done directly after updating the text
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self bottomButton];
    });
}

- (void)adTagEditingChanged:(UITextField *)sender {
    [self changeColorOfShowButton];
}

- (NSString *)adTagText {
    NSString *text = [[self.adTagField text] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if ([text isEqualToString:@""]) {
        return nil;
    }
    
    return text;
}

- (NSString *)currencyIdText {
    NSString *text = [[self.currencyIdField text] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if ([text isEqualToString:@""]) {
        return nil;
    }
    
    return text;
}

- (void)changeColorOfShowButton {
    [self.bannerControls setValue:@(self.adUnitSegmentedControl.selectedSegmentIndex != kAdUnitSegmentBanner) forKey:@"hidden"];
    [self.offerWallControls setValue:@(self.adUnitSegmentedControl.selectedSegmentIndex != kAdUnitSegmentOfferWall) forKey:@"hidden"];
    [self.standardControls setValue:@(self.adUnitSegmentedControl.selectedSegmentIndex == kAdUnitSegmentBanner) forKey:@"hidden"];
    
    NSString * adTag = [self adTagText];
    
    switch (self.adUnitSegmentedControl.selectedSegmentIndex) {
        case kAdUnitSegmentInterstitial:
            [self setShowButtonOn:[HZInterstitialAd isAvailableForTag:adTag]];
            break;
        case kAdUnitSegmentVideo:
            [self setShowButtonOn:[HZVideoAd isAvailableForTag:adTag]];
            break;
        case kAdUnitSegmentIncentivized:
            [self setShowButtonOn:[HZIncentivizedAd isAvailableForTag:adTag]];
            break;
        case kAdUnitSegmentOfferWall:
            [self setShowButtonOn:[HZOfferWallAd isAvailableForTag:adTag]];
            break;
    }
}

- (void)setShowButtonOn:(BOOL)on {
    self.showButton.backgroundColor = (on ? [UIColor greenColor] : [UIColor redColor]);
}


#pragma mark - Button handlers

- (void)fetchAd:(id)sender {
    NSString *adTag = [self adTagText];
    if (adTag) {
        [self logToConsole:[NSString stringWithFormat:@"Fetching for tag: %@", adTag]];
    } else {
        [self logToConsole:@"Fetching for default tag"];
        adTag = nil;
    }
    
    void (^completionBlock)(BOOL, NSError *) = ^void(BOOL result, NSError *err) {
        [self logToConsole:[NSString stringWithFormat:@"Fetch successful? %@ error: %@", result ? @"yes" : @"no", err]];
    };
    
    switch (self.adUnitSegmentedControl.selectedSegmentIndex) {
        case kAdUnitSegmentInterstitial:
            [HZInterstitialAd fetchForTag:adTag withCompletion:completionBlock];
            break;
        case kAdUnitSegmentVideo:
            [HZVideoAd fetchForTag:adTag withCompletion:completionBlock];
            break;
        case kAdUnitSegmentIncentivized:
            [HZIncentivizedAd fetchForTag:adTag withCompletion:completionBlock];
            break;
        case kAdUnitSegmentOfferWall:
            [HZOfferWallAd fetchForTag:adTag withCompletion:completionBlock];
        default:
            break;
    }
}

- (void)showAd:(id)sender {
    [self.view endEditing:YES];
    NSString *adTag = [self adTagText];
    if (adTag) {
        [self logToConsole:[NSString stringWithFormat:@"Showing for tag: %@", adTag]];
    } else {
        [self logToConsole:@"Showing for default tag"];
        adTag = nil;
    }
    
    switch (self.adUnitSegmentedControl.selectedSegmentIndex) {
        case kAdUnitSegmentInterstitial:
            NSLog(@"Showing Interstitial");
            [HZInterstitialAd showForTag:adTag];
            break;
        case kAdUnitSegmentVideo:
            NSLog(@"Showing Video");
            [HZVideoAd showForTag:adTag];
            break;
        case kAdUnitSegmentIncentivized:
            NSLog(@"Showing Incentivized");
            [HZIncentivizedAd showForTag:adTag];
            break;
        case kAdUnitSegmentOfferWall:
            NSLog(@"Showing OfferWall");
            [HZOfferWallAd showForTag:adTag];
        default:
            break;
    }
}

- (void)showBannerButtonPressed:(UIControl *)sender {
    self.showBannerButton.enabled = NO;
    
    [self.view endEditing:YES];
    
    HZBannerAdOptions *opts = [[HZBannerAdOptions alloc] init];
    opts.presentingViewController = self;
    opts.tag = [self adTagText];
    
    if (UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)) {
        opts.admobBannerSize = HZAdMobBannerSizeFlexibleWidthLandscape;
    }
    
    [HZBannerAd placeBannerInView:self.view
                         position:HZBannerPositionBottom
                          options:opts
                          success:^(HZBannerAd *banner) {
                              banner.delegate = self;
                              self.hideBannerButton.enabled = YES;
                              self.currentBannerAd = banner;
                          } failure:^(NSError *error) {
                              self.showBannerButton.enabled = YES;
                              [self logToConsole:[NSString stringWithFormat:@"Failed to place banner ad. Error: %@", error]];
                          }];
}

- (void)hideBannerButtonPressed:(id)sender {
    [self.view endEditing:YES];
    [self.currentBannerAd removeFromSuperview];
    self.currentBannerAd = nil;
    
    self.hideBannerButton.enabled = NO;
    self.showBannerButton.enabled = YES;
}

- (void)clearButton{
    self.consoleTextView.text = @"";
}

- (void)topButton{
    [self.consoleTextView scrollRectToVisible:CGRectMake(0, 0, 1, 1) animated:NO];
}

- (void)bottomButton{
    CGRect rect = CGRectMake(0, self.consoleTextView.contentSize.height -1, self.consoleTextView.frame.size.width, self.consoleTextView.contentSize.height);
    [self.consoleTextView scrollRectToVisible:rect animated:NO];
}

- (void)emailConsoleButton{
    if ([MFMailComposeViewController canSendMail]) {
        MFMailComposeViewController *mail = [[MFMailComposeViewController alloc] init];
        [mail setSubject:@"Heyzap SDK Sample App log"];
        
        [mail addAttachmentData:[self.consoleTextView.text dataUsingEncoding:NSUTF8StringEncoding]
                       mimeType:@"text/plain"
                       fileName:@"consoleLog.txt"];
        [self presentViewController:mail animated:YES completion:nil];
        
    } else {
        [[[UIAlertView alloc] initWithTitle:@"Can't send email"
                                    message:@"This device is not setup to deliver email."
                                   delegate:nil
                          cancelButtonTitle:@"Ok"
                          otherButtonTitles:nil, nil] show];
    }
}

- (void)showTestActivity {
    [HeyzapAds presentMediationDebugViewController];
}

- (void)checkAvailability {
    NSString * adTag = [self adTagText];
    NSString *adType;
    BOOL available = NO;
    
    switch (self.adUnitSegmentedControl.selectedSegmentIndex) {
        case kAdUnitSegmentInterstitial:
            available = [HZInterstitialAd isAvailableForTag:adTag];
            adType = @"An interstitial";
            break;
        case kAdUnitSegmentVideo:
            available = [HZVideoAd isAvailableForTag:adTag];
            adType = @"A video";
            break;
        case kAdUnitSegmentIncentivized:
            available = [HZIncentivizedAd isAvailableForTag:adTag];
            adType = @"An incentivized";
            break;
        case kAdUnitSegmentOfferWall:
            available = [HZOfferWallAd isAvailableForTag:adTag];
            adType = @"An offer wall";
            break;
    }
    
    if (adType) {
        [self setShowButtonOn:available];
        [self logToConsole:[NSString stringWithFormat:@"%@ ad %@ available for tag: `%@`.", adType, (available ? @"is" : @"is not"), adTag]];
    }
}

- (void)vcsRequest {
    [[HZFyberVirtualCurrencyClient sharedClient] requestDeltaOfCurrency:[self currencyIdText]];
}

#pragma mark - Callbacks

- (void)didReceiveAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
    
    [self changeColorOfShowButton];
}
- (void)didShowAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
    
    [self changeColorOfShowButton];
}
- (void)didClickAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
}
- (void)didHideAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
    [self changeColorOfShowButton];
}
- (void)didFailToReceiveAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
}

- (void)didFailToShowAdWithTag:(NSString *)tag andError:(NSError *)error {
    [self logToConsole:[NSString stringWithFormat:@"%@ tag: %@ error: %@",NSStringFromSelector(_cmd),tag, error]];
}

- (void)willStartAudio {
    LOG_METHOD_NAME_TO_CONSOLE;
}
- (void)didFinishAudio {
    LOG_METHOD_NAME_TO_CONSOLE;
}

- (void)didCompleteAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
}

- (void)didFailToCompleteAdWithTag:(NSString *)tag {
    LOG_METHOD_NAME_TO_CONSOLE_WITH_STRING(tag);
}

- (void)didReceiveVirtualCurrencyResponse:(HZFyberVirtualCurrencyResponse *)response {
    [self logToConsole:[NSString stringWithFormat:@"VCS response: %@", response]];
}

- (void)didFailToReceiveVirtualCurrencyResponse:(NSError *)error {
    [self logToConsole:[NSString stringWithFormat:@"VCS error: %@", error]];
}

#pragma mark - NSNotifications

- (void) remoteDataRefreshed: (NSNotification *)notification {
    if([notification.userInfo count] > 0) {
        [self logToConsole: [NSString stringWithFormat:@"Remote data refreshed. Data: %@", notification.userInfo]];
    } else {
        [self logToConsole: [NSString stringWithFormat:@"Remote data refreshed (empty)"]];
    }
}


#pragma mark - UI Management

- (void)keyboardWillShow:(NSNotification *)notification {
    // If we're not onscreen, ignore this notification
    if (self.view.superview == nil) {
        return;
    }
    NSTimeInterval animationDuration = [[notification.userInfo objectForKey:UIKeyboardAnimationDurationUserInfoKey] floatValue];
    UIViewAnimationOptions keyboardCurve = [[notification.userInfo objectForKey:UIKeyboardAnimationCurveUserInfoKey] unsignedIntegerValue];
    
    CGRect keyboardFrameInWindow = [[notification.userInfo objectForKey:UIKeyboardFrameEndUserInfoKey] CGRectValue];
    CGRect keyboardFrameInLocalCoordinates = [self.view convertRect:keyboardFrameInWindow fromView:nil];
    
    [UIView animateWithDuration:animationDuration delay:0 options:keyboardCurve animations:^{
        self.scrollView.frame = CGRectMake(self.scrollView.frame.origin.x, self.scrollView.frame.origin.y, self.scrollView.frame.size.width, CGRectGetMinY(keyboardFrameInLocalCoordinates));
    }completion:nil];
}
- (void)keyboardWillHide:(NSNotification *)notification {
    // If we're not onscreen, ignore this notification
    if (self.view.superview == nil) {
        return;
    }
    NSTimeInterval animationDuration = [[notification.userInfo objectForKey:UIKeyboardAnimationDurationUserInfoKey] floatValue];
    UIViewAnimationOptions keyboardCurve = [[notification.userInfo objectForKey:UIKeyboardAnimationCurveUserInfoKey] unsignedIntegerValue];
    
    CGRect keyboardFrameInWindow = [[notification.userInfo objectForKey:UIKeyboardFrameEndUserInfoKey] CGRectValue];
    CGRect keyboardFrameInLocalCoordinates = [self.view convertRect:keyboardFrameInWindow fromView:nil];
    
    [UIView animateWithDuration:animationDuration delay:0 options:keyboardCurve animations:^{
        self.scrollView.frame = CGRectMake(self.scrollView.frame.origin.x, self.scrollView.frame.origin.y, self.scrollView.frame.size.width, CGRectGetMinY(keyboardFrameInLocalCoordinates));
    }completion:nil];
}

- (void)updateScrollViewContentSize {
    // This approach avoids constant manual adjustment
    CGRect subviewContainingRect = CGRectZero;
    for (UIView *view in self.scrollView.subviews) {
        subviewContainingRect = CGRectUnion(subviewContainingRect, view.frame);
    }
    self.scrollView.contentSize = (CGSize) { CGRectGetWidth(self.view.frame), subviewContainingRect.size.height + 80 };
}

#if __IPHONE_OS_VERSION_MAX_ALLOWED < 90000
- (NSUInteger)supportedInterfaceOrientations
#else
- (UIInterfaceOrientationMask)supportedInterfaceOrientations
#endif
{
    return UIInterfaceOrientationMaskAll;
}

@end
