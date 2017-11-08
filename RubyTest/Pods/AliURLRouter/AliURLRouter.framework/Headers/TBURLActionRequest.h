//
//  TBURLActionRequest.h
//  TBAppUISkeleton
//
//  Created by Tim Cao on 14-3-20.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBURLActionRequest : NSObject<NSCopying>

@property (nonatomic, strong, readonly) NSURL *url;

/**
 *	UI骨架导航时用来存储TBURLAction，私有不可修改
 */
@property (nonatomic, strong, readonly) id userInfo;

/**
 *	使用者所在源controller
 */
@property (nonatomic, strong) UIViewController *sourceController;

/**
 *	不适合放在url里的本地参数
 */
@property (nonatomic, strong) NSDictionary *nativeParams;

/**
 *	最终的query参数。包含了url里的key-value
 */
@property (nonatomic, strong) NSDictionary *query;

/**
 *	是否是重定向.默认NO，只能在response为TBURLActionResponseTypeRedirect才可设置为YES
 */
@property (nonatomic, assign) BOOL isRedirect;


- (id)initWithURL:(NSURL *)url userInfo:(id)userInfo;

@end
