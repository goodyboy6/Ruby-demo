//
//  TBNavigationParams.h
//  Taobao2013
//
//  Created by 晨燕 on 13-2-5.
//  Copyright (c) 2013年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBNavigationType.h"

#define kTBNavigationParamsKey      @"_navigation_params"
#define kNavigatorBehaviorBackUrl @"backurl"
#define kNavigatorBehaviorBackAppName @"appname"
#define kNavigatorBehaviorBackAlertTitle @"backalerttitle"


@interface TBNavigationParams : NSObject

//是否需要动画，默认YES
@property (nonatomic, assign) BOOL                      animated;

//是否需要navigationController包装，默认NO
@property (nonatomic, assign) BOOL                      needNavigationCtrl;

//是否需要把当前页面present出来的controller dismiss掉，默认NO
@property (nonatomic, assign) BOOL                      needDissmiss;

//当navigationType为TBNavigationTypeTabbarSelect需要切换tab时，可以指定是否pop到RootViewController，默认NO
@property (nonatomic, assign) BOOL                      needPopToRootViewController;

//默认push
@property (nonatomic, copy) TBNavigationType          navigationType;

//默认为空,切换tab时对应的url
@property (nonatomic, copy) NSString*                   target;
/**
 *	点击返回时,触发弹窗,如果点击确定后则open此URL
 */
@property (nonatomic, copy) NSString*                   backUrl;

/**
 * 跳进来的源app名称
 */
@property (nonatomic, copy) NSString*                   backAppName;
/**
 *	点击返回时,触发弹窗,提示内容
 */
@property (nonatomic, copy) NSString*                   backAlertTitle;



- (NSString *)stringofNavigationParams;
+ (TBNavigationParams *)navigationParamsofDictionary:(NSDictionary *)dic;

@end
