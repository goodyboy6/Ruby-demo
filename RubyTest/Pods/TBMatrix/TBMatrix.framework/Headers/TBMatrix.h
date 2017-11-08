//
//  TBMatrix.h
//  TBMatrix
//
//  Created by 晨燕 on 13-12-31.
//  Copyright (c) 2013年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "TBMContainer+UrlBus.h"
#import "TBMContainer+ServiceBus.h"
#import "TBMMessageReceiver.h"


/**
 plist注册接口
 只适用于静态库注册，动态库请走配置文件
 
 @param bundleName 该Bundle或SDK的唯一标识，全app唯一，如果有重复，编译整包时报错，duplicateSymbol
 @param configFile 该Bundle或SDK的service及url处理的plist配置文件名字

 @example TBRegisterBundleNameAndConfigFile(TBWangwang, TBWangwang.bundle/wangwang.plist)
 @example TBRegisterBundleNameAndConfigFile(TBAppEnvironment, app_environment_bundle.plist)
 */
#define TBRegisterBundleNameAndConfigFile(bundleName,configFile) \
char * k##bundleName##_bundlePlist __attribute((used, section("__DATA,TBContainerSec"))) = ""#configFile"";


