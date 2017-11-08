//
//  AliAppLifeCycleMessageProtocol.h
//  AliAppLifeCycle
//
//  Created by 晨燕 on 2017/2/8.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AliAppLifeCycleMessageProtocol <NSObject>

- (void)didReceiveMessageNotification:(NSNotification*)notification;

@end
