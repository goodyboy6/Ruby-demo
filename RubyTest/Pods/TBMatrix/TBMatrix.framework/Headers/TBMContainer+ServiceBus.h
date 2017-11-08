/*!
 @header TBMContainer (ServiceBus)
 @abstract 手机淘宝容器Service Bus功能对外接口
 @author 方颖 (手机淘宝架构组 RD)
 @version 1.00 2016/07/27 Creation (Copyright (c) 2013年 Alibaba-inc. All rights reserved.
 )
 */

#import "TBMContainerInter.h"

/*!
 @class TBMContainer
 @abstract ！！服务总线已被弃用，接口迁移至MSOA库，详细改动见文档：https://lark.alipay.com/msoa/wlille/nzl0bv！！
 */
@interface TBMContainer (ServiceBus)

/*!
 @method serviceForName:
 @abstract 根据业务service，获得对应业务协议指定的实例
 @param  serviceName              业务协议名参数
 @result 获得对应业务协议指定的实例
 */
- (id)serviceForName:(NSString*)serviceName __attribute__ ((deprecated("已弃用，请使用MSOA的[MSOAEngine obtainServiceForAlias:sourceBiz:sourceScene], 并确保业务通过MSOAConsumeProtocolService宏(动态库用MSOAC文件)声明消费过服务，否则将返回nil")));


/**
 根据Protocol，获取对应的实例对象

 @param protocol
 @return 一个遵循该protocol的实例对象
 */
- (id)serviceForProtocol:(Protocol *)protocol __attribute__ ((deprecated("已弃用，请使用MSOA的[MSOAEngine obtainServiceForProtocol:sourceBiz]，并确保业务通过MSOAConsumeProtocolService宏(动态库用MSOAC文件)声明消费过服务，否则将返回nil")));


@end
