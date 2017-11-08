//
//  TBURLAction.h
//  Taobao4iPad
//
//  Created by Tim Cao on 12-4-24.
//  Copyright (c) 2012年 Taobao.com. All rights reserved.
//
//  !!!请不要新增依赖此文件了，后续会被去掉!!!请只依赖service文件

#import <UIKit/UIKit.h>
#import "TBNavigationType.h"

@class TBNavigationParams;

@interface TBURLAction : NSObject
@property (nonatomic, copy) NSString*                 urlPath;
@property (nonatomic, readonly) UIViewController*         sourceController;
//导航相关的参数，比如是否需要动画等
@property (nonatomic, readonly) TBNavigationParams*       navigationParams;
/**
 *  OpenURL中传递的nativeParams
 *  通常用于传递native的参数。比如block的传递，对象的传递，
 *  也可以用于导航功能的扩展，自定义参数
 */
@property (nonatomic, readonly) NSDictionary*             nativeParams;

+ (id)actionWithURLPath:(NSString*)urlPath sourceController:(UIViewController*)sourceViewController;
+ (id)actionWithURLPath:(NSString*)urlPath sourceController:(UIViewController*)sourceViewController navgationParams:(TBNavigationParams *)navigationParams nativeParams:(NSDictionary*)nativeParams;

- (id)initWithURLPath:(NSString*)urlPath sourceController:(UIViewController*)sourceViewController;
- (id)initWithURLPath:(NSString*)urlPath sourceController:(UIViewController*)sourceViewController navgationParams:(TBNavigationParams *)navigationParams nativeParams:(NSDictionary*)nativeParams;


- (void)rewriteNavigationParams:(NSDictionary*)newNavigationParams;

@end
