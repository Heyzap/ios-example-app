//
//  HYPRReward.h
//  HyprMX-Framework
//
//  Copyright (c) 2012 HyprMX Mobile LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HYPRReward : NSObject

/**
 * Creates a new HYPRReward with a local image
 *
 * @param rewardId the ID of this reward. Will be returned with the quantity once an offer has been completed.
 * @param value the value in dollars of this reward. Cents may be fractional, for instance 0.015f => $0.015.
 * @param quantity the maximum quantity of this reward to give out. If it's unlimited, you may use NSUIntegerMax
 * @param title the title of this reward.
 * @param localImageName the name of the image tied to this reward in your app bundle. This should return a UIImage when [UIImage imageNamed:localImageName] is called. May be nil.
 *
 * @return HYPRReward an instance of the HYPRReward class containing the reward properties.
 */
+ (HYPRReward *)rewardWithId:(int)rewardId
              valueInDollars:(float)value
                 maxQuantity:(unsigned int)quantity
                       title:(NSString *)title
                   imageName:(NSString *)localImageName __attribute__((deprecated("first deprecated in HyprMX 4.2. Use the rewardWithId:valueInDollars:maxQuantity:title: method instead")));

/** 
 * Creates a new HYPRReward
 *
 * @param rewardId the ID of this reward. Will be returned with the quantity once an offer has been completed.
 * @param value the value in dollars of this reward. Cents may be fractional, for instance 0.015f => $0.015.
 * @param quantity the maximum quantity of this reward to give out. If it's unlimited, you may use NSUIntegerMax
 * @param title the title of this reward.
 *
 * @return HYPRReward an instance of the HYPRReward class containing the reward properties.
 */
+ (HYPRReward *)rewardWithId:(int)rewardId
              valueInDollars:(float)value
                 maxQuantity:(unsigned int)quantity
                       title:(NSString *)title;

@end
