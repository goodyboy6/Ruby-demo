//
//  AliAppLifeCycleManager.h
//  AliAppLifeCycle
//
//  Created by lv on 15-3-24.
//  Copyright (c) 2015年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliAppLifeCycleEventProtocol.h"

@interface AliAppLifeCycleManager : NSObject <AliAppLifeCycleEventProtocol>

+ (instancetype)sharedInstance;

/**
 读取配置信息，并将配置信息中的消息及事件进行注册

 @param config 配置信息,格式如下
    {
        EventList =     {
            "application:didFinishLaunchingWithOptions:" =  (
                                                             {
                                                                 class = AppRootVCInitilize;
                                                                 isSingleton = 0;
                                                             },
                                                             {
                                                                 class = NetworkInitilize;
                                                                 frameworkName = NetworkDynamicFramework;
                                                                 isSingleton = 1;
                                                             }
                                                             );
        };
        MessageList =     {
            UIApplicationDidBecomeActiveNotification =  (
                                                         {
                                                             class = VRAppDidBecomeActiveReceiver;
                                                             frameworkName = VRDynamicFramework;
                                                             isSingleton = 1;
                                                         }
                                                         );
        };
    }
 config中包括两个key,"EventList","MessageList",分别注册给事件接收和消息接收者，它们对应的value都是一个NSDictionary,EventList对应的NSDictionary中的所有key就是要接收的所有消息，MessageList对应的所有Key所有要监听的消息名称，每个key对应的value是一个数组，数组中的每一项是一个描述对象的Dictionary,class对应的值是需要处理访消息或事件的对象className，isSingleton对应的是一个BOOL值，1代表对象是单例，0代表非单例，缺少则默认为非单例，frameworkName对应的是动态库的名字，没有该key，就认为该class不需要手动load动态库
 使用方可以将该配置以plist文件的方式进行保存，如果业务方需要注册一个事件或消息，则在plist配置文件中添加一个对应的object即可，配置文件可以参考Demo中的AppLifeCycleConfig.plist文件
 */
- (void)registerFromConfig:(NSDictionary*)config;

/**
 注册消息监听

 @param messageName 需要监听的消息名称，比如 @"UIApplicationDidBecomeActiveNotification" 等
 @param className 用于处理该消息的class类名，该class需要confirm AliAppLifeCycleMessageProtocol的协议，当AliAppLifeCycleManager收到该消息时会调用该class中的didReceiveMessageNotification:方法来进行消息的分发
 @param singlelton 该对象是否应该以单例方式存在
        如果是YES，则AliAppLifeCycleManager中会对该class init出来的对象进行存储，下一次需要发送给该对象消息时，则直接复用。单例对象一旦创建出来，则是在整个app生命周期结束之前都一直存在的。
        如果是NO，则每次需要对该对象发送消息时，都会init出来一个全新的对象，该对象在执行完didReceiveMessageNotification:后就会被回收。
 @param frameworkName 如果该class是在动态库中，且不是启动时自动load的动态库，则需要指明动态库所在的framework名字，这样当manager需要分发给该class的消息时，可以去手动load该动态库。如果不是动态库，则传入nil即可
 */
- (void)registerMessage:(NSString*)messageName
          receiverClass:(NSString*)className
            isSingleton:(BOOL)singlelton
          frameworkName:(NSString*)frameworkName;

/**
 注册事件接收

 @param event 需要接收的事件方法名，限于UIApplicationDelegate中定义的方法，比如@"application:didFinishLaunchingWithOptions:",这里的事件名必须与真正的method名字完全一致，包括方法中的:也不能丢失，需要绝对匹配
 @param className 需要接收该事件的class类名，这个class需要实现event中指定的方法
 @param singlelton 该对象是否应该以单例方式存在
        如果是YES，则AliAppLifeCycleManager中会对该[[class alloc] init]出来的对象进行存储，下一次需要传递事件给该对象时，则直接复用。单例对象一旦创建出来，则是在整个app生命周期结束之前都一直存在的。
        如果是NO，则每次需要对该对象传递事件时，都会init出来一个全新的对象，该对象在执行完event中指明的方法后就会被回收。
 @param frameworkName 如果该class是在动态库中，且不是启动时自动load的动态库，则需要指明动态库所在的framework名字，这样当manager需要分发给该class的消息时，可以去手动load该动态库。如果不是动态库，则传入nil即可
 */
- (void)registerEvent:(NSString*)event
         handlerClass:(NSString*)className
          isSingleton:(BOOL)singlelton
        frameworkName:(NSString*)frameworkName;


- (NSArray<id>*)registeredProcessersOfEvent:(NSString*)event;

- (void)setLoadFrameworkResultBlock:(void (^)(NSString *frameworkName ,NSError* error))handleLogBlock;

@end
