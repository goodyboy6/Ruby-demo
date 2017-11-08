//
//  AliAppLifeCycle.h
//  AliAppLifeCycle
//
//  Created by 晨燕 on 2017/2/6.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for AppLifeManager.
FOUNDATION_EXPORT double AppLifeManagerVersionNumber;

//! Project version string for AppLifeManager.
FOUNDATION_EXPORT const unsigned char AppLifeManagerVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AppLifeManager/PublicHeader.h>

#import "AliAppLifeCycleEventProtocol.h"
#import "AliAppLifeCycleMessageProtocol.h"
#import "AliAppLifeCycleManager.h"
#import "AliAppLifeCycleAppDelegate.h"


// 注意：以下注册方式只在Debug下生效，Release不生效，是为了方便业务开发期测试开发接口，后续要集成时还是要走配置文件

/**
 注解注册事件处理器
 @example
 AliAppLifeCycleRegisterEvent(DetailEventHandler, 'applicationDidBecomeActive:,applicationWillResignActive:,applicationDidEnterBackground:', YES)

 @param eventHandler 处理event的Class
 @param eventList 想要处理的event,如果一个handler处理多个event，用“,”分隔，整体用“‘”包括
 @param isSingleton 是否单例
 */
#define AliAppLifeCycleRegisterEvent(eventHandler,eventList,isSingleton) \
char * k##eventHandler##_appLifeCycleEvent __attribute((used, section("__DATA,AppLifeCycleSec"))) = "event|"#eventHandler"|"#eventList"|"#isSingleton"";


/**
 注解注册消息接收
 @example AliAppLifeCycleRegisterMessage(DetailMessageHandler, 'UIApplicationDidFinishLaunchingNotification,UIApplicationDidBecomeActiveNotification', YES)

 @param messageHandler 想要监听消息的Class
 @param messageList 想要监听的消息名，如果一个handler处理多个message，用“,”分隔，整体用“‘”包括
 @param isSingleton 是否单例
 */
#define AliAppLifeCycleRegisterMessage(messageHandler,messageList,isSingleton) \
char * k##messageHandler##_appLifeCycleMessage __attribute((used, section("__DATA,AppLifeCycleSec"))) = "message|"#messageHandler"|"#messageList"|"#isSingleton"";
