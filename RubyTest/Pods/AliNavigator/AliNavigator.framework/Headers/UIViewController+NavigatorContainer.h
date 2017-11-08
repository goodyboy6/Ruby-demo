//
//  UIViewController+NavigatorContainer.h
//  AliNavigator
//
//  Created by 晨燕 on 2017/2/24.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBNavigationType.h"

@interface UIViewController (NavigatorContainer)

- (void)addSubcontroller:(UIViewController*)controller navigateType:(TBNavigationType)type animated:(BOOL)animated;

- (void)removeSubController:(UIViewController *)controller navigateType:(TBNavigationType)type animated:(BOOL)animated;

@end
