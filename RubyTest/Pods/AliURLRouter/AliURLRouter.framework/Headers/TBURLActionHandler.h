//
//  TBURLActionHandler.h
//  TBAppUISkeleton
//
//  Created by Tim Cao on 14-3-20.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//


#import "TBURLActionRequest.h"
#import "TBURLActionResponse.h"

@protocol TBURLActionHandler <NSObject>


/**
 URL路由处理类遵循接口

 @param urlActionRequest 路由Request
 @return 根据Request进行处理返回的路由Response
 */
- (TBURLActionResponse*)handleURLActionRequest:(TBURLActionRequest*)urlActionRequest;

@optional
//兼容集团的handler方案，Deprecated
- (id)handleUrl:(NSURL *)url withTarget:(id)target withParams:(id)params;

@end
