//
//  UISkeletonProtocol.h
//  TBAppUISkeleton
//
//  Created by Dafeng Jin on 2017/2/20.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBURLAction.h"

@protocol UISkeletonProtocol <NSObject>


/**
 指定source的ViewController，由于没有约束source的类别，因此source可以为ViewController，View甚至其他情况，方便业务控件等调用导航接口。

 @param source 指定source
 @return 对应的ViewController
 */
- (UIViewController *)viewControllerForSource:(id)source;


/**
 使用指定action导航打开ViewController页面

 @param toVC 要打开的ViewController
 @param action 指定打开方式的action
 */
- (void)openViewController:(UIViewController *)toVC urlAction:(TBURLAction*)action;


/**
 使用指定action进行导航回退

 @param action 指定action
 */
- (void)backFromAction:(TBURLAction*)action;

@end
