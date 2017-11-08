//
//  TBURLRouter.h
//  AliURLRouter
//
//  Created by Dafeng Jin on 16/4/13.
//  Copyright © 2016年 Taobao lnc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBURLActionRequest.h"
#import "TBURLActionResponse.h"

@interface TBURLRouter : NSObject


/**
 单例

 @return 单例
 */
+ (instancetype)sharedRouter;


/**
 注册URL处理类

 @param handlerClass 处理类名
 @param isSingleton 是否单例
 @param url 指定URL
 */
- (void)registerURLHandler:(NSString *)handlerClass
               isSingleton:(BOOL)isSingleton
                    forURL:(NSString *)url;

/**
 注册URL处理类
 
 @param handlerClass 处理类名
 @param isSingleton 是否单例
 @param url 指定URL
 @param frameworkName 指定framework名，用于动态库
 @param bundleName bundle名，便于埋点区分
 */
- (void)registerURLHandler:(NSString *)handlerClass
               isSingleton:(BOOL)isSingleton
                    forURL:(NSString *)url
             frameworkName:(NSString*)frameworkName
                bundleName:(NSString*)bundleName;

/**
 注册匹配URL的正则表达式的处理类
 
 @param handlerClass 处理类名
 @param isSingleton 是否单例
 @param url 指定URL的正则表达式
 */
- (void)registerURLHandler:(NSString *)handlerClass
               isSingleton:(BOOL)isSingleton
               forURLRegex:(NSString *)urlRegex;


/**
 注册匹配URL的正则表达式的处理类
 
 @param handlerClass 处理类名
 @param isSingleton 是否单例
 @param url 指定URL的正则表达式
 @param frameworkName 指定framework名，用于动态库
 @param bundleName bundle名，便于埋点区分
 */
- (void)registerURLHandler:(NSString *)handlerClass
               isSingleton:(BOOL)isSingleton
               forURLRegex:(NSString *)urlRegex
             frameworkName:(NSString*)frameworkName
                bundleName:(NSString*)bundleName;

/**
 添加路由Request中间件

 @param requestMiddlewareString 中间件类名
 @param isSingleton 是否单例
 */
- (void)addURLActionRequestMiddleware:(NSString *)requestMiddlewareString
                          isSingleton:(BOOL)isSingleton;

/**
 添加路由Request中间件
 
 @param requestMiddlewareString 中间件类名
 @param isSingleton 是否单例
 @param frameworkName 指定framework名，用于动态库
 */
- (void)addURLActionRequestMiddleware:(NSString *)requestMiddlewareString
                          isSingleton:(BOOL)isSingleton
                        frameworkName:(NSString*)frameworkName;

/**
 添加路由Response中间件

 @param responseMiddlewareString 中间件类名
 @param isSingleton 是否单例
 */
- (void)addURLActionResponseMiddleware:(NSString *)responseMiddlewareString
                           isSingleton:(BOOL)isSingleton;


/**
 添加路由Response中间件
 
 @param responseMiddlewareString 中间件类名
 @param isSingleton 是否单例
 @param frameworkName 指定framework名，用于动态库
 */
- (void)addURLActionResponseMiddleware:(NSString *)responseMiddlewareString
                           isSingleton:(BOOL)isSingleton
                         frameworkName:(NSString*)frameworkName;

/**
 路由主处理函数

 @param urlActionRequest 路由Request
 @return 路由Response
 */
- (TBURLActionResponse*)processURLActionRequest:(TBURLActionRequest*)urlActionRequest;

/**
 获取指定URL经过路由处理后的VC
 
 @param url 指定URL
 @return 返回VC
 */
- (UIViewController *)viewControllerForURL:(NSURL *)url;

/**
 获取指定URL经过路由处理后的VC

 @param url 指定URL
 @param query 查询参数
 @param nativeParameters Native参数，解决为了安全等问题，不方便在url中传输入的参数
 @return 返回VC
 */
- (UIViewController*)viewControllerForURL:(NSURL*)url
                                    query:(NSDictionary*)query
                         nativeParameters:(NSDictionary*)nativeParameters;

/**
 路由栅栏验证
 */
- (void)checkDuplicateHandler;


/**
 动态库加载回调

 @param handleLogBlock 回调block
 */
- (void)setLoadFrameworkResultBlock:(void (^)(NSString *frameworkName ,NSError* error))handleLogBlock;

@end
