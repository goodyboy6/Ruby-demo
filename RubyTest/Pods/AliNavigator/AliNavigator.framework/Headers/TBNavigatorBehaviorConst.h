//
//  TBNavigatorBehaviorConst.h
//  TBAppUISkeleton
//
//  Created by junzhan on 14-4-1.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//  response里可以设置behavior
// 使用如[dict setObject:kNavigatorBehaviorPresent forKey:kNavigatorBehaviorNavigationType]
// [dict setObject:@"1" forKey:kNavigatorBehaviorNeedLogin]

/**
 *	0或1，是否启用动画,默认YES
 */
#define kNavigatorBehaviorAnimated @"animated"

/**
 *	0或1，是否需要navigationController包装,默认NO
 */
#define kNavigatorBehaviorNeedNavigationCtrl @"neednavigationctrl"

/**
 *	0或1，默认NO
 */
#define kNavigatorBehaviorNeedLogin @"needlogin"

/**
 *	是否需要安全码，默认NO
 */
#define kNavigatorBehaviorNeedSafeCode @"needsafecode"

/**
 *	是否需要把当前页面present出来的controller dismiss掉，默认YES
 */
#define kNavigatorBehaviorNeedDissmiss @"needdismiss"


#pragma mark 页面进入方式及附带动作

/**
 *	页面进入动画类型，默认push.
 *  value可以指定：kNavigatorBehavior(Push|Present|TabbarSelect)
 */
#define kNavigatorBehaviorNavigationType @"navigationtype"

/**
 *	当kNavigatorBehaviorNavigationType为kNavigatorBehaviorTypeTabbarSelect需要切换tab时，可以指定是否pop到RootViewController，默认NO
 */
#define kNavigatorBehaviorNeedPopToRootViewController @"needpoptoroot"

/**
 *	当kNavigatorBehaviorNavigationType为kNavigatorBehaviorTypeTabbarSelect需要切换tab时,需要指定对应tab的url（如：taobao://home/root）
 */
#define kNavigatorBehaviorTabTargetUrl @"tabtargeturl"


#pragma mark 页面进入动作

/**
 *	kNavigatorBehaviorNavigationType时pushViewController动作
 */
#define kNavigatorBehaviorTypePush @"push"

/**
 *	kNavigatorBehaviorNavigationType时presentViewController动作
 */
#define kNavigatorBehaviorTypePresent @"present"

/**
 *	kNavigatorBehaviorNavigationType时做tab切换动作
 */
#define kNavigatorBehaviorTypeTabbarSelect @"tabbarSelect"


//反向操作，外部暂不开放
#define kNavigatorBehaviorTypeDismiss @"dismiss"
#define kNavigatorBehaviorTypePop @"pop"
