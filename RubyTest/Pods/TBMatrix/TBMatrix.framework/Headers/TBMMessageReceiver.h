//
//  TBMMessageReceiver.h
//  TBMatrix
//
//  Created by Tim Cao on 14-3-19.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//


@protocol TBMMessageReceiver <NSObject>

- (void)didReceiveMessageNotification:(NSNotification*)notification;

@end
