//
//  ViewController.m
//  DataAttrDemo
//
//  Created by xtc_lj on 15/12/1.
//  Copyright © 2015年 studyos. All rights reserved.
//

#import "ViewController.h"
#import <EebbkDA/BBKBigData.h>
#import "PageViewController.h"

@interface ViewController ()

- (IBAction)clickToAddCountEvent:(id)sender;
- (IBAction)clickToAddTimeEvent:(id)sender;
- (IBAction)clickToAddSearchEvent:(id)sender;
- (IBAction)clickToAddCustomEvent:(id)sender;
- (IBAction)clickToAddCrashEvent:(id)sender;
- (IBAction)clickToChangeView:(id)sender;
- (IBAction)clickToTrigUpLoad:(id)sender;


@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	[BBKBigData pageBegin:@"com.eebbk.zndy.search"];
	
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	
	[BBKBigData pageEnd];
}


- (IBAction)clickToAddCountEvent:(id)sender {
	
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
	[dict setObject:@"计数事件测试" forKey:@"functionName"];
	[dict setObject:@"测试一下点击按钮的功能" forKey:@"moduleDetail"];

	[BBKBigData clickEventWithAttr:dict extend:nil];
}

- (IBAction)clickToAddTimeEvent:(id)sender {
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
	[dict setObject:@"计数按钮点击" forKey:@"functionName"];
	[dict setObject:@"测试一下计数按钮的功能" forKey:@"moduleDetail"];
	[dict setObject:@"20000" forKey:@"trigValue"];//单位 （ms）
	
	[BBKBigData countEventWithDict:dict extend:nil];
}

- (IBAction)clickToAddSearchEvent:(id)sender {
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
	[dict setObject:@"点击智能搜学" forKey:@"functionName"];
	[dict setObject:@"测试一下搜索按钮的功能" forKey:@"moduleDetail"];
	[dict setObject:@"30天精通iOS开发" forKey:@"keyWord"];//关键字
	[dict setObject:@"20" forKey:@"resultCount"];//数据条数
	
	[BBKBigData searchEventWithDict:dict extend:@{@"module":@"计算机基础知识学习"}];
}

- (IBAction)clickToAddCustomEvent:(id)sender {
	NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
	
	[dict setObject:@"我自己的事件" forKey:@"eventName"];
	[dict setObject:@"自己定义的事件" forKey:@"functionName"];
	[dict setObject:@"测试一下自己自定义的事件的功能" forKey:@"moduleDetail"];
	[dict setObject:@"触发值" forKey:@"trigValue"];
	
	[BBKBigData searchEventWithDict:dict extend:@{@"user":@"LIJUN"}];}

- (IBAction)clickToAddCrashEvent:(id)sender {
	[self performSelector:@selector(nonFunctionSoCrash:) withObject:@"异常测试"];
}

- (IBAction)clickToChangeView:(id)sender {
	PageViewController *pageViewCtrl = [self.storyboard instantiateViewControllerWithIdentifier:@"SecondPageTest"];
	
	[self.navigationController pushViewController: pageViewCtrl animated:true];
}

- (IBAction)clickToTrigUpLoad:(id)sender {
	[BBKBigData triggerToUploadEvent];
}
@end
