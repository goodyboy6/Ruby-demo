//
//  UIViewController+AliNavigator.h
//  AliNavigator
//
//  Created by Dafeng Jin on 2017/2/16.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBNavigationParams.h"

@interface UIViewController (AliNavigator)

@property (nonatomic, strong) TBNavigationParams * pageInNavigationParams;
@property (nonatomic, copy) NSString*       tbNavigationURLString;

@end
