/*!
 @header TBMContainer (UrlBusHandler)
 @abstract 手机淘宝容器URL总线对外接口
 @author 方颖 (手机淘宝架构组 RD)
 @version 1.00 2016/07/27 Creation (Copyright (c) 2013年 Alibaba-inc. All rights reserved.
 )
 */

#import "TBMContainerInter.h"


@class TBURLActionRequest;
@class TBURLActionResponse;


/*!
 @class TBMContainer
 @abstract 手机淘宝容器URL Bus功能对外接口 Category。
 */
@interface TBMContainer (UrlBusHandler)

/*!
 @method viewControllerForURL:query:nativeParameters:
 @abstract 根据参数URL，和native参数，获得对于UIViewController实例
 @param url              业务URL参数
 @param query            业务URL query参数
 @param nativeParameters 业务native参数
 @result 目标UIViewController实例
 */
- (UIViewController*)viewControllerForURL:(NSURL*)url
                                    query:(NSDictionary*)query
                         nativeParameters:(NSDictionary*)nativeParameters;


/*!
 @method viewControllerForURL:
 @abstract 根据参数URL，和native参数，获得对于UIViewController实例
 @param url              业务URL参数
 @result 目标UIViewController实例
 */
- (UIViewController *)viewControllerForURL:(NSURL *)url;


/*!
 @method processURLActionRequest:
 @abstract 根据业务URL Action Request获取对应业务URL Action Response
 @param urlActionRequest 业务URL Action Request参数
 @result 目标业务TBURLActionResponse响应
 */
- (TBURLActionResponse*)processURLActionRequest:(TBURLActionRequest*)urlActionRequest;

@end
