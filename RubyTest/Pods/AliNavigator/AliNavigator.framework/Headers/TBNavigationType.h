//
//  TBNavigationType.h
//  Taobao2013
//
//  Created by 晨燕 on 13-2-5.
//  Copyright (c) 2013年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TBNavigatorBehaviorConst.h"

typedef NSString* TBNavigationType;
/*
 这里定义一些常见的、通用的导航类型，App可以根据自己的需要，自定义扩展，只需要在SkeleHandler里自己去处理即可
 */
extern TBNavigationType const TBNavigationTypePush;
extern TBNavigationType const TBNavigationTypePop;
extern TBNavigationType const TBNavigationTypePresent;
extern TBNavigationType const TBNavigationTypeDismiss;
extern TBNavigationType const TBNavigationTypeTabbarSelect;
extern TBNavigationType const TBNavigationTypeUnKnown;

