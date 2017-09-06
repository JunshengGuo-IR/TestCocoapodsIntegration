//
//  irViewController.m
//  DemoApplication
//
//  Created by Tyler Thomas on 1/10/13.
//  Copyright (c) 2013 Impact Radius. All rights reserved.
//

#import "irViewController.h"
#import "EventTracker.h"
#import "Event.h"


@interface irViewController ()

-(IBAction)trackSession:(id)sender;
-(IBAction)trackEventWithSingleItem:(id)sender;
-(IBAction)trackEventWithMultipleItems:(id)sender;


@end

@implementation irViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    _tracker = [EventTracker sharedManager];
}

-(IBAction)trackSession:(id)sender {
    [_tracker trackSession];
}
-(IBAction)trackEventWithSingleItem:(id)sender {
    Event* event = [_tracker newEvent:@"Event Name"];
    NSDictionary * item = [[NSDictionary alloc]initWithObjectsAndKeys:
                           @"Item Name", @"Name",
                           @"Category Name", @"Category",
                           @"1", @"Amount",
                           @"1", @"Quantity",
                           @"1", @"Rebate",
                           @"1", @"sku",
                           @"custom1", @"custom name or value",
                           @"custom2", @"custom name or value",
                           @"promodescription", @"testing promo description",
                           @"promoCode", @"testing promo code",
                           @"price", @"testing price",
                           @"mpn", @"testing mpn",
                           @"subCategory", @"testing subCat",
                           @"deliveryType", @"testing DeliveryType",
                           @"discount", @"testing Discount",
                           @"totaldiscount", @"testing total discount",
                           nil];
    
    NSMutableArray* itemArray = [[NSMutableArray alloc] initWithObjects:item, nil];
    
    [_tracker submit:event withItemArray:itemArray];

    
    
    
}
-(IBAction)trackEventWithMultipleItems:(id)sender {
    
    [_tracker trackSession];
//    Event* event = [_tracker newEvent:@"Event Name"];
//    
//    NSDictionary * item1 = [[NSDictionary alloc]initWithObjectsAndKeys:
//                           [NSString stringWithFormat:@"Item Name%@", @"1"], @"Name",
//                           [NSString stringWithFormat:@"Category Name %@", @"1"], @"Category",
//                           [NSString stringWithFormat:@"1%@", @"1"], @"Amount",
//                           [NSString stringWithFormat:@"1%@", @"1"], @"Quantity",
//                           [NSString stringWithFormat:@"1%@", @"1"], @"Rebate",
//                           [NSString stringWithFormat:@"1%@", @"1"], @"sku",
//                           [NSString stringWithFormat:@"custom1%@", @"1"], [NSString stringWithFormat:@"custom value%@",@"1"],
//                           [NSString stringWithFormat:@"custom2%@", @"1"], [NSString stringWithFormat:@"custom value%@",@"1"], nil];
//    
//    NSDictionary * item2 = [[NSDictionary alloc]initWithObjectsAndKeys:
//                            [NSString stringWithFormat:@"Item Name%@", @"2"], @"Name",
//                            [NSString stringWithFormat:@"Category Name %@", @"2"], @"Category",
//                            [NSString stringWithFormat:@"1%@", @"2"], @"Amount",
//                            [NSString stringWithFormat:@"1%@", @"2"], @"Quantity",
//                            [NSString stringWithFormat:@"1%@", @"2"], @"Rebate",
//                            [NSString stringWithFormat:@"1%@", @"2"], @"sku",
//                            [NSString stringWithFormat:@"custom1%@", @"2"], [NSString stringWithFormat:@"custom value%@",@"2"],
//                            [NSString stringWithFormat:@"custom2%@", @"2"], [NSString stringWithFormat:@"custom value%@",@"2"], nil];
//    
//    NSMutableArray* itemArray = [[NSMutableArray alloc] initWithObjects:item1, item2, nil];
//    
//    [_tracker submit:event withItemArray:itemArray];
}





- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

@end
