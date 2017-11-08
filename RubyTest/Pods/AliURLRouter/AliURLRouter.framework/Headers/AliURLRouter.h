//
//  AliURLRouter.h
//  AliURLRouter
//
//  Created by Dafeng Jin on 16/4/11.
//  Copyright © 2016年 Taobao lnc. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for AliURLRouter.
FOUNDATION_EXPORT double AliURLRouterVersionNumber;

//! Project version string for AliURLRouter.
FOUNDATION_EXPORT const unsigned char AliURLRouterVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AliURLRouter/PublicHeader.h>

#define AliURLRouterDATA(sectname) __attribute((used, section("__DATA,"#sectname" ")))


/**
 注册路由URL处理类

 @param handlerClass URL处理类
 @param isSingleton 是否单例，YES或NO
 @param bundleName bundle名
 @param urls 能处理的url，用单引号包围，多个url用" | "分割，示例：'main/first | main/second'
 @param urlRegexes 能处理的url匹配正则，规则通urls，示例：'^.*taobao | ^.*tbcdn'
 */
#define AliURLRouterRegisterURLHandler(handlerClass,isSingleton,bundleName,urls,urlRegexes) \
char * k##handlerClass##_router AliURLRouterDATA(AliURLRouterSec) = "{ \"handler\" : \""#handlerClass"\", \"singleton\" : \""#isSingleton"\", \"bundle\" : \""#bundleName"\", \"urls\" : \""#urls"\", \"urlRegexes\" : \""#urlRegexes"\", \"type\" : \"URLHandler\"}";


/**
 添加Request路由中间件

 @param requestMiddleClass Request中间件类
 @param isSingleton 是否单例，YES或NO
 */
#define AliURLRouterAddRequestMiddleware(requestMiddleClass,isSingleton) \
char * k##requestMiddleClass##_request AliURLRouterDATA(AliURLRouterSec) = "{ \"middleware\" : \""#requestMiddleClass"\", \"singleton\" : \""#isSingleton"\", \"type\" : \"RequestMiddleware\"}";

/**
 添加Response路由中间件
 
 @param responseMiddleClass Response中间件类
 @param isSingleton 是否单例，YES或NO
 */
#define AliURLRouterAddResponseMiddleware(responseMiddleClass,isSingleton) \
char * k##responseMiddleClass##_response AliURLRouterDATA(AliURLRouterSec) = "{ \"middleware\" : \""#responseMiddleClass"\", \"singleton\" : \""#isSingleton"\", \"type\" : \"ResponseMiddleware\"}";



#import "TBURLRouter.h"
#import "TBURLActionRequest.h"
#import "TBURLActionResponse.h"
#import "TBURLActionHandler.h"
#import "TBURLActionRequestMiddleware.h"
#import "TBURLActionResponseMiddleware.h"

#import "UIViewControllerTBNavigator.h"
#import "UIViewController+AliURLRouter.h"


