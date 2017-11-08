//
//  TBNavigationParams+Private.h
//  AliNavigator
//
//  Created by 晨燕 on 2017/3/9.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <AliNavigator/AliNavigator.h>

@interface TBNavigationParams (Private)

- (NSString *)stringOfNavigationParamsValue;

- (void)mergeWithParamDictionary:(NSDictionary *)paramDict;

@end
