//
//  PageViewController.m
//  DATest
//
//  Created by xtc_lj on 15/11/26.
//  Copyright © 2015年 studyos. All rights reserved.
//

#import "PageViewController.h"
#import <EebbkDA/BBKBigData.h>
#import <EebbkFundationLib/EebbkFundationLib.h>

@implementation PageViewController


- (void) viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
//	[BBKBigData pageBegin:@"PageViewController"];
	
	[BBKBigData pageBegin:[NSString stringWithFormat:@"%@",[self class]]];
	[EebbkFundationLib startLoading:self.view];
}

- (void)viewWillDisappear:(BOOL)animated {
	[super viewWillDisappear:animated];
	[BBKBigData pageEnd];
}

@end
