//
//  TBAppUISkeletonNavigator.h
//  TBAppUISkeleton
//
//  Created by junzhan on 14-3-31.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UISkeletonProtocol.h"
#import "TBUrlNavigatorService.h"
#import "TBNavigationParams.h"

///////////////////////////////////////////////////////导航////////////////////////////////////////////////////////////////////

/**
 *  导航：通过URL打开页面, 预留Native参数，解决为了安全等问题，不方便在url中传输入的参数,以及对象、block等非string类型数据的传递
 *
 *  @param urlPath      url字符串（注意:若有中文需要对key-value进行URLEncode）
 *  @param target       打开者所在的对象，必须为View或者ViewController(注意:1.若你的页面是多个ViewController嵌套，必须传最上层的ViewController，否则你的页面被其他present的页面打开后，你接下来的push新页面可能会被遮挡!!!。2.此参数传nil也会出现遮挡的情况!!!)
 *
 *  @return 是否成功打开此URL对应的页面
 */
BOOL TBOpenURLFromTarget(NSString* urlPath, id target);

/**
 *  导航：通过URL打开页面, 预留Native参数，解决为了安全等问题，不方便在url中传输入的参数,以及对象、block等非string类型数据的传递
 *
 *  @param urlPath      url字符串（注意:若有中文需要对key-value进行URLEncode）
 *  @param target       打开者所在的对象，必须为View或者ViewController(注意:1.若你的页面是多个ViewController嵌套，必须传最上层的ViewController，否则你的页面被其他present的页面打开后，你接下来的push新页面可能会被遮挡!!!。2.此参数传nil也会出现遮挡的情况!!!)
 *  @param navParams 导航相关参数，用于自定义导航方式比如present等形式
 *  @param nativeParams 预留Native参数，解决为了安全等问题或不方便在url中传输入的参数,以及对象、block等非string类型数据的传递.此参数对应initWithNavigatorURL:query:nativeParams中的nativeParams,也对应于URLAction中的nativeParams
 *
 *  @return 是否成功打开此URL对应的页面
 */
BOOL TBOpenURLFromTargetWithParams(NSString* urlPath, id target, TBNavigationParams *navParams, NSDictionary *nativeParams);


/**
 *  导航：返回
 *
 *  @param source 返回者所在的对象，必须为View或者ViewController(注意:1.若你的页面是多个ViewController嵌套，必须传最上层的ViewController，否则你的页面被其他present的页面打开后，你接下来的push新页面可能会被遮挡!!!。2.此参数传nil也会出现遮挡的情况!!!)
 *  @return 是否成功返回
 */
BOOL TBBackFromTarget(id source);

///////////////////////////////////////////////////////导航////////////////////////////////////////////////////////////////////


//void TBFinshAsyncURLAction(TBURLActionResponse *urlActionResponse, TBURLActionRequest *urlActionRequest);

@interface TBNavigator : NSObject<TBUrlNavigatorService>


/**
 单例

 @return 单例
 */
+ (instancetype)sharedInstance;


/**
 注册骨架实现类

 @param className 骨架实现类名
 */
- (void)registerSkeletonClass:(NSString *)className;

//图片库埋点需要获取pageURL，访问不了实例
+ (NSString *)getPageURLString;

@end
