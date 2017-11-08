//
//  TBURLActionResponseMiddleware.h
//  TBAppUISkeleton
//
//  Created by Tim Cao on 14-3-20.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

#import "TBURLActionRequest.h"
#import "TBURLActionResponse.h"

@protocol TBURLActionResponseMiddleware <NSObject>

/**
 *	最后的机会修改response，如果你不需要修改那么请返回传入的urlActionResponse，此流程并不阻断后续response中间件
 *	@param 	urlActionResponse 	前面流程产生的response
 *	@param 	urlActionRequest 	发起的request请求
 *	@return	如果你不需要修改那么请返回传入的urlActionResponse
 */
- (TBURLActionResponse *)processURLActionResponse:(TBURLActionResponse*)urlActionResponse withURLActionRequest:(TBURLActionRequest*)urlActionRequest;


@end
