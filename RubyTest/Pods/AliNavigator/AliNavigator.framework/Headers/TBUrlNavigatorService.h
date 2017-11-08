//
//  TBUrlNavigatorService
//  AliNavigator
//
//  Created by 尹 峥伟 on 14-3-15.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - TBURLNavigatorService
@class TBURLActionResponse,TBURLActionRequest;
@class TBURLAction, TBNavigationParams;

#define kUrlNavigatorServiceName @"url_navigator"

@protocol TBUrlNavigatorService <NSObject>

- (BOOL)openURLAction:(TBURLAction*)action;

- (BOOL)backURLAction:(TBURLAction*)action;

- (void)finshURLActionAsyncResponse:(TBURLActionResponse *)urlActionResponse urlActionRequest:(TBURLActionRequest *)urlActionRequest;
@end


#pragma mark - Public Method


BOOL TBOpenURLFromTarget(NSString* urlPath, id target);

BOOL TBOpenURLFromSourceAndParams(NSString* urlPath, id target, NSDictionary* extraInfo);

BOOL TBOpenURLFromTargetWithNativeParams(NSString* urlPath, id target, NSDictionary* extraInfo, NSDictionary *nativeParams);

//原来extraInfo中为nil的，可以使用这个接口
BOOL TBOpenURLFromTargetWithParams(NSString* urlPath, id target, TBNavigationParams *navParams, NSDictionary *nativeParams);

//完成异步response,若不能处理此URL则urlActionResponse需传入nil,UI骨架将打开webview
void TBFinshAsyncURLAction(TBURLActionResponse *urlActionResponse, TBURLActionRequest *urlActionRequest);

BOOL TBBackFromTarget(id target);

#pragma mark - Depcrated Method

BOOL TBOpenURLFromView(NSString* urlPath, UIView* view);// __attribute__ ((deprecated("这个方法已经废弃，请改用TBOpenURLFromTarget")));
// __attribute__ ((deprecated("这个方法已经废弃，请改用TBOpenURLFromTargetWithParams,extraInfo中的参数，请合并至nativeParams")));
BOOL TBBackFromView(UIView* view);// __attribute__ ((deprecated("这个方法已经废弃，请改用TBBackFromTarget")));


