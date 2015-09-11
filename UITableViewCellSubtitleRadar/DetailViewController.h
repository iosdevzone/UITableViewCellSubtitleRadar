//
//  DetailViewController.h
//  UITableViewCellSubtitleRadar
//
//  Created by idz on 9/11/15.
//  Copyright (c) 2015 iOSDeveloperZone.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end

