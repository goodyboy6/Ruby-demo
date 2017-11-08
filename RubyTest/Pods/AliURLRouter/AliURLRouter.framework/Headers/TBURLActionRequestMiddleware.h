//
//  TBURLActionRequestMiddleware.h
//  TBAppUISkeleton
//
//  Created by Tim Cao on 14-3-20.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//


#import "TBURLActionRequest.h"
#import "TBURLActionResponse.h"

@protocol TBURLActionRequestMiddleware <NSObject>

/**
 *	返回nil代表你不能或者不需要处理此请求，非nil代表你拦截了此请求，将不会再往后传递
 *	@param 	urlActionRequest 	路由Request
 *	@return	路由Response
 */
- (TBURLActionResponse*)processURLActionRequest:(TBURLActionRequest*)urlActionRequest;


@end
