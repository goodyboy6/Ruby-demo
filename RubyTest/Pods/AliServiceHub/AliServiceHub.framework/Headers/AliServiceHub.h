//
//  AliServiceHub.h
//  AliServiceHub
//
//  Created by 晨燕 on 2017/1/20.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ServiceHub.
FOUNDATION_EXPORT double ServiceHubVersionNumber;

//! Project version string for ServiceHub.
FOUNDATION_EXPORT const unsigned char ServiceHubVersionString[];


// In this header, you should import all the public headers of your framework using statements like #import <ServiceHub/PublicHeader.h>



/**
 服务提供者注册服务
 
 @example AliServiceHubRegisterService(TBAppUIServiceProtocol,TBAppUIService,YES)

 @param serviceProtocol 服务接口Protocol
 @param serviceIMPClass 具体的服务实现类，需要confirm serviceProtocol
 @param isSingleton     服务实现类是否以单例形式存在,YES或NO
 */
#define AliServiceHubRegisterService(serviceProtocol,serviceIMPClass,isSingleton) \
char * k##serviceProtocol##_service __attribute((used, section("__DATA,AliServiceHubSec"))) = ""#serviceProtocol"|"#serviceIMPClass"|"#isSingleton"";


/**
 服务提供者注册服务
 
 @example AliServiceHubRegisterServiceWithName(TBUrlNavigatorService,TBAppUISkeletonNavigator,  YES, url_navigator)

 @param serviceProtocol 服务接口Protocol
 @param serviceIMPClass 具体的服务实现类，需要confirm serviceProtocol
 @param isSingleton     服务实现类是否以单例形式存在,YES或NO
 @param serviceName     服务别名
 */
#define AliServiceHubRegisterServiceWithName(serviceProtocol,serviceIMPClass,isSingleton,serviceName) \
char * k##serviceProtocol##_service __attribute((used, section("__DATA,AliServiceHubSec"))) = ""#serviceProtocol"|"#serviceIMPClass"|"#isSingleton"|"#serviceName"";

#import "AliServiceHubManager.h"
