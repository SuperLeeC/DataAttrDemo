//
//  EebbkFundationLib.h
//  EebbkFundationLib
//
//  Created by xtc_lj on 15/12/4.
//  Copyright © 2015年 studyos. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for EebbkFundationLib.
FOUNDATION_EXPORT double EebbkFundationLibVersionNumber;

//! Project version string for EebbkFundationLib.
FOUNDATION_EXPORT const unsigned char EebbkFundationLibVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <EebbkFundationLib/PublicHeader.h>

@interface EebbkFundationLib : NSObject {
	
}


/**
 *  异步加载按钮图片信息
 *
 *  @param imageUrl       路径
 *  @param btn            需要加载的按钮
 *  @param defaultImgName 默认图片信息
 *  @param imgSizeInfo    图片url加载信息 例如 ?imageView2/3/w/135/h/135
 */
+ (void) loadButtonImageFromUrl:(NSString *)imageUrl imageView:(UIButton *)btn defaultImg:(NSString *)defaultImgName imgSize:(NSString *)imgSizeInfo;

/**
 *  异步加载图片信息
 *
 *  @param imageUrl       加载图片的的url
 *  @param imageView      目标UIImageView 对象
 *  @param defaultImgName 默认图片
 *  @param imgSizeInfo    图片url加载信息 例如 ?imageView2/3/w/135/h/135
 */
+ (void) loadIconImageFromUrl:(NSString *)imageUrl imageView:(UIImageView *)imageView defaultImg:(NSString *)defaultImgName imgSize:(NSString *)imgSizeInfo;

+ (void) showToast:(NSString *)toast :(UIView *)uiview;


+ (void) startLoading:(UIView *)uiview;

+ (void) stopLoading:(UIView *)uiview;
@end

