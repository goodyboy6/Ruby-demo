//
//  TBURLActionViewController.h
//  AliURLRouter
//
//  Created by Dafeng Jin on 2017/2/6.
//  Copyright © 2017年 Taobao lnc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UIViewControllerTBNavigator <NSObject>

@optional


/**
 VC遵循的路由初始化接口

 @param URL 指定URL
 @param query 查询参数
 @return VC
 */
- (id)initWithNavigatorURL:(NSURL*)URL query:(NSDictionary*)query;

// 预留Native参数，解决为了安全等问题，不方便在url中传输入的参数
- (id)initWithNavigatorURL:(NSURL*)URL query:(NSDictionary*)query nativeParams:(NSDictionary *)nativeParams;

@end
