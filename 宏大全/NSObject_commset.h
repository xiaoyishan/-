//
//  NSObject_commset.h
//  宏大全
//
//  Created by Sundear on 2017/5/8.
//  Copyright © 2017年 xiexin. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark ---------常量---------
//---------常量---------

#define  Width   [[UIScreen mainScreen] bounds].size.width
#define  Height  [[UIScreen mainScreen] bounds].size.height
#define  kPoint  (1 / [UIScreen mainScreen].scale)

//图片资源获取
#define kimageFrom(X)           [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:X ofType:@""]]
#define kimageFromExt(X,ext)    [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:X ofType:ext]]
#define kImageName(X)           [UIImage imageNamed:[UIUtil imageName:_pointer]] // 传入图片名称,获取UIImage

//颜色
#define kColor_RGB(r,g,b)       [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0]
#define kColor_RGBA(r,g,b,a)    [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RandomColor UIColorRGB(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))

//定义字号
#define kFont(X)                [UIFont systemFontSize:X]

//强弱引用声明
#define kWS(weakSelf)           __weak __typeof(&*self)weakSelf = self;
#define kSS(type)               __strong typeof(type) type = weak##type;

//角度
#define kDegreesToRadian(x)         (M_PI * (x) / 180.0)
#define kRadianToDegrees(radian)    (radian*180.0)/(M_PI)

//路径
#define kDocumentPath           [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define kTempPath               NSTemporaryDirectory()
#define kCachePath              [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
#define kResource(f, t)         [[NSBundle mainBundle] pathForResource:(f) ofType:(t)];

//设备信息
#define kIOS_VERSION            [[[UIDevice currentDevice] systemVersion] floatValue]
#define kDEVICE_MODEL           [[UIDevice currentDevice] model]

#define kAPP_NAME               [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]
#define kAPP_VERSION            [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define kAPP_SUB_VERSION        [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]
#define kUDeviceIdentifier      [[UIDevice currentDevice] uniqueDeviceIdentifier]

//程序
#define kApplication            [UIApplication sharedApplication]
#define kKeyWindow              [UIApplication sharedApplication].keyWindow
#define kAppDelegate            ((AppDelegate*)[UIApplication sharedApplication].delegate)
//用户plist 和 通知
#define kUserDefaults           [NSUserDefaults standardUserDefaults]
#define kNotificationCenter     [NSNotificationCenter defaultCenter]

//数据转换
#define GetStrFromInt(X)        [NSString stringWithFormat:@"%d",X]
#define GetStrFromFloat(X)      [NSString stringWithFormat:@"%f",X]
#define GetStrFromNumber(X)     [NSString stringWithFormat:@"%@",X]

// 当前时间 精确到毫秒 15位
static inline NSString *DateNow15(){
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyyMMddHHmmssSSS"];
    return [dateFormatter stringFromDate:[NSDate new]];
}

// 当前日期 (年月日) 2018-05-05
static inline NSString *DateNowYMD(){
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    return [dateFormatter stringFromDate:[NSDate new]];
}

// 当前日期 (年月日 时分秒) 2018-05-05 15:25:21
static inline NSString *DateNowYMDHMS(){
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    return [dateFormatter stringFromDate:[NSDate new]];
}

#pragma mark ---------判断---------
//---------判断---------

//设备判断
#define isiPhone   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define isiPad     (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define k_IPAD     ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

//设备类型
#define kiPhone4     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define kiPhone5     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define kiPhone6     ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define kiPhone6P    ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242,2208), [[UIScreen mainScreen] currentMode].size) : NO)

//是否为空或是[NSNull null]
#define kNotNilAndNull(_ref)  (((_ref) != nil) && (![(_ref) isEqual:[NSNull null]]))
#define kIsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))
/** 字符串是否为空*/
#define kStringIsEmpty(str)     ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
/** 数组是否为空*/
#define kArrayIsEmpty(array)    (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
/** 字典是否为空*/
#define kDictIsEmpty(dic)       (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
/** 是否是空对象*/
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))






#pragma mark ---------事件---------
//---------事件---------

//G－C－D
#define BACK(block)     dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block)     dispatch_async(dispatch_get_main_queue(),block)

// 不堵塞线程并在主线程的延迟执行 timer:延迟时间，单位：秒；与主线程同步
#define GCDMainDelay(timer,block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, INT64_C(timer) * NSEC_PER_SEC), dispatch_get_main_queue(), block)

/** 获取一段时间间隔*/
#define kStartTime  CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kEndTime    NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

//安全释放
#define kRelearse(__POINTER) { [__POINTER release]; __POINTER = nil; }

//打印
#ifdef DEBUG
#define DLog(format, ...) printf("DLog[%s] %s\n", __TIME__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String])
#else
#define DLog(format, ...)
#endif



@interface NSObject ()

@end
