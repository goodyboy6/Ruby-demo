//
//  TBURLActionResponse.h
//  TBAppUISkeleton
//
//  Created by Tim Cao on 14-3-20.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

typedef enum {
    //TBURLActionResponseTypeInterrupt
    TBURLActionResponseTypeNone = 1, /**< 告诉容器不用做处理。（如触发了某个事件，但不需页面跳转） */
    TBURLActionResponseTypeViewController, /**< 返回ViewController */
    TBURLActionResponseTypeObject, /**< 返回一个用户自定义的对象 */
    TBURLActionResponseTypeRedirect, /**< url重定向,注意不要引起死循环.场景:重定向给其他bundle来处理URL,自己bundle能处理不应该用重定向 */
    TBURLActionResponseTypeAsync, /**< 异步response */
    //alert,view,object,往下添加
} TBURLActionResponseType;

//    TBURLActionResponseTypeError, /**< 是由我来处理的，但是发生了异常情况 */
//    TBURLActionResponseTypePopback, /**< 需要UI骨架popViewController */

@interface TBURLActionResponse : NSObject
/**
 *	重定向到此URL
 */
@property (nonatomic, strong) NSURL *redirectURL;

/**
 *	若responseType=TBURLActionResponseTypeViewController，那么需返回viewController
 */
@property (nonatomic, strong) UIViewController *viewController;

/**
 *	若responseType=TBURLActionResponseTypeObject，那么需返回object
 */
@property (nonatomic, strong) id object;

/**
 *	UI导航展示的行为修改，见TBAppUISkeleton中的TBNavigatorBehaviorConst.h
 */
@property (nonatomic, strong) NSDictionary *modifiedNavigatorBehavior;

/**
 *	响应类型
 */
@property (nonatomic, assign) TBURLActionResponseType responseType;

/**
 *  响应此response的bundle的名称. 埋点用
 */
@property (nonatomic, strong) NSString *bundleName;

/**
 *  响应此response的handler的名称(用string,避免强引用). 埋点用
 */
@property (nonatomic, strong) NSString *handlerName;

- (id)initWithViewController:(UIViewController*)viewController;

@end
