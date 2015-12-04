//
//  BBKBigData_iOS.h
//  BBKBigData_iOS	eeBBK大数据平台项目
//
//  Created by studyOS_lj on 15/11/13.
//  Copyright © 2015年 studyos. All rights reserved.

//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/CaptiveNetwork.h>

#pragma -mark 事件类定义

@interface BBKBigData : NSObject

#pragma -mark 获取与同步本地App与大数据uuuId
/**
 *  设置本地uuuID，同步uuuid,保持大数据与本地应用一致
 *  也可以直接获取getUuuId信息作为本地保存
 *
 *  @param uuuId 设置本地唯一识别码
 */
+(void) setUuuId:(NSString *)uuuId;

/**
 *  获取当前应用的唯一识别码
 */
+ (NSString *) getUuuId;

/**
 *  获取当前手机型号
 *
 *  @return 返回手机型号（例如：iPhone 4S (A1387/A1431)）
 */
+ (NSString *) getMobileModule;

/**
 *  //获取当前设备是否已经越狱
 *
 *  @return 是否越狱
 */
+ (BOOL) getDeviceRootable;

#pragma -mark 以下接口为app异常相关接口
/**
 *  捕获app异常崩溃信息
 *
 *  @param exception 未捕获的异常信息
 */
+(void) unCaughtcrashException;

#pragma -mark 设置应用AppId

/**
 *  设置AppId
 *
 *  @param appId appId
 *	@param mac	mac地址，作为唯一识别码表示一个app客户端
 *	@param channel	渠道号
 */
+ (void) installWithAppId:(NSString *)appId channel:(NSString *)channel;


#pragma -mark 初始化用户信息
/**
 *  初始化用户信息
 *
 *  @param attr 用户信息列表
 *  @param extend 其他信息
 */
+ (void) initUserInfoWithAttr:(NSMutableDictionary *)attr extend:(NSDictionary *)extend;


#pragma -mark 设置事件信息

/**
 *  计次事件 大数据信息采集
 *
 *  @param event 大数据信息列表
 *	@param extend	额外的信息
 */
+ (void) clickEventWithAttr:(NSMutableDictionary *)event extend:(NSDictionary *)extend;


/**
 *  计数事件 大数据信息采集
 *
 *  @param eventDict 大数据信息列表
 *	@param extend	额外信息
 */
+ (void)countEventWithDict:(NSMutableDictionary *)eventDict extend:(NSDictionary *)extend;

/**
 *  搜索事件 大数据信息采集
 *
 *  @param eventDict 搜索事件信息列表
 *	@param extend	额外的信息
 */
+ (void) searchEventWithDict:(NSMutableDictionary *)eventDict extend:(NSDictionary *)extend;

/**
 *  自定义事件
 *
 *  @param attr   自定义时间相关参数列表
 *  @param extend 额外信息
 */
+ (void) customEventWithAttr:(NSMutableDictionary *)attr extend:(NSDictionary *)extend;

/**
 *  uRL监控
 *
 *  @param attr 监控信息列表
 */
+ (void)uRLMonitoredEventWithAttr:(NSMutableDictionary *)attr;

/**
 *  异常收集 异常收集大数据处理
 *	APP开发人员不需要处理此接口
 *  @param dict 异常收集信息
 
 */
+ (void) crashExceptionValueWithDict:(NSMutableDictionary *)dict;

#pragma -mark 页面计时
/**
 *  页面开启
 *
 *  @param pageView 当前ViewController 名称
 */
+ (void)pageBegin:(NSString *)pageView;


/**
 *  页面离开
 *	请保证pageEnd与pageEnter成对出现
 */
+ (void)pageEnd;

#pragma -mark 手动触发上传数据
/**
 *  手动触发上传数据
 *	如果应用内需要手动上传时，如收到推送信息上传数据，可以手动触发数据上传
 */
+ (void) triggerToUploadEvent;

@end
