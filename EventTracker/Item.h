//
//  Item.h
//  irEventTracker
//
//  Created by Tyler Thomas
//  Copyright (c) 2017 Impact Radius. All rights reserved.
//

#ifndef Item_h
#define Item_h
#import <Foundation/Foundation.h>

@interface Item : NSObject

- (void) setAmount:(NSString *)amt; // Amount
- (void) setQuantity:(NSString *)qty; // Quantity
- (void) setCategory:(NSString *)cat; // Category
- (void) setSku:(NSString *)sku;
- (void) setRebate:(NSString *)rebate;
- (void) setName:(NSString *)name;
- (void) setPromoCodeDescription:(NSString *)pd;
- (void) setPromoCode:(NSString *)p;
- (void) setPrice:(NSString *)pr;
- (void) setMPN:(NSString *)ms;
- (void) setSubCategory:(NSString *)sc;
- (void) setDeliveryType:(NSString *)dt;
- (void) setDiscount:(NSString *)r;
- (void) setTotalDiscount:(NSString *)tr;
- (void) addCustomParam:(NSString*)key value:(NSString*)value;

@end

#endif //Item_h
