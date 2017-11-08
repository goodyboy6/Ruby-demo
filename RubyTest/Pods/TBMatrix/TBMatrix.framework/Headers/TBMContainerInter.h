/*!
 @header TBMContainer
 @abstract 手机淘宝容器, 提供手淘容器平台开发。目标解决业务耦合问题，以平台角度接入各个业务
 @author 方颖 (手机淘宝架构组 RD)
 @version 1.00 2016/07/27 Creation (Copyright (c) 2013年 Alibaba-inc. All rights reserved.
 )
 */
/**
 *	栅栏机制开启的宏
 */
#ifdef  DEBUG

#define TBMCONTAINER_FENCE_ENABLE

#endif


/*!
 @class TBMContainer
 @abstract 手机淘宝容器, 提供手淘容器平台开发。目标解决业务耦合问题，以平台角度接入各个业务
 */

@interface TBMContainer : NSObject




/*!
 @method sharedContainer
 @abstract 容器单例接口
 @result 容器实例
 */
+ (TBMContainer*)sharedContainer;


/*!
 @method startWithConfiguration:application:launchingOptions
 @abstract 启动并初始化容器
 @param configuration    App配置信息
 @param application      App UIApplication实例
 @param launchingOptions App 启动didFinish参数
 @result void
 */
- (void)startWithConfiguration:(NSDictionary*)configuration
                   application:(UIApplication*)application
              launchingOptions:(NSDictionary*)launchingOptions
                 andConfigFile:(NSString*)configFile;

// 加载配置文件信息
- (void)loadConfigFile:(NSString*)configFile;

@end
