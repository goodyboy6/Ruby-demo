//
//  AliServiceHubManager.h
//  AliServiceHub
//
//  Created by 晨燕 on 2017/1/18.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AliServiceHubManager : NSObject

+ (instancetype)sharedInstance;

#pragma mark - Service Register

/**
 *  服务提供者注册服务。
 *
 *  @param serviceProtocol  服务接口协议
 *  @param serviceIMPClass  服务接口具体实现
 */
- (void)registerServiceProtocol:(NSString *)serviceProtocol
                       IMPClass:(NSString *)serviceIMPClass;

/**
 *   服务提供者注册服务。
 *
 *  @param serviceProtocol  服务接口协议
 *  @param serviceIMPClass  服务接口具体实现
 *  @param frameworkName 服务所在的动态库名字
 */
- (void)registerServiceProtocol:(NSString *)serviceProtocol
                       IMPClass:(NSString *)serviceIMPClass
                  frameworkName:(NSString *)frameworkName;

/**
 *   服务提供者注册服务。
 *
 *  @param serviceProtocol  服务接口协议
 *  @param serviceIMPClass  服务接口具体实现
 *  @param frameworkName    服务所在的动态库名字
 *  @param serviceName      服务别名，非必须
 *  @param isSingleton      服务是否需要单例，默认NO
 */
- (void)registerServiceProtocol:(NSString *)serviceProtocol
                       IMPClass:(NSString *)serviceIMPClass
                  frameworkName:(NSString *)frameworkName
                    serviceName:(NSString *)serviceName
                    isSingleton:(BOOL)isSingleton;

#pragma mark - Service Get

/**
 *  获取指定protocol接口服务。
 *
 *  @param protocol 服务接口协议
 *
 *  @return 实现了服务接口协议的具体实例对象(id<protocol>)，否则返回nil。
 */
- (id)serviceForProtocol:(Protocol *)protocol;

/**
 *  该接口后续废弃掉
 */
- (id)serviceForName:(NSString *)serviceName;


/**
 * 加载动态库时外部如果需要知道这个时机做一些埋点之类的操作
 *
 * @param handleLogBlock 在手动load动态库成功或者失败时的埋点
 */
- (void)setLoadFrameworkResultBlock:(void (^)(NSString *frameworkName ,NSError* error))handleLogBlock;

@end
