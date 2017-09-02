//
//  Event.h
//
//  Created by Tyler Thomas on 1/10/13.
//  Copyright (c) 2013 Impact Radius. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface Event : NSObject

@property (nonatomic, strong) NSMutableArray *itemArray;

- (NSMutableDictionary*) getEventParamTable;

- (id)init:(NSString *)eventName;
- (void) setActionTrackerId: (NSString *)actionTrackerId;
- (void) setCurrency: (NSString*)currency;
- (void) setClickId: (NSString*)clickId;
- (void) setCustomerId: (NSString*)customerId;
- (void) setCustomerStatus: (NSString*)status;
- (void) setCustomerCity: (NSString *)customerCity;
- (void) setCustomerCountry: (NSString *)customerCountry;
- (void) setCustomerRegion: (NSString *)customerRegion;
- (void) setDisposition: (NSString*)disp;
- (void) setExchangeRate: (NSString*)exchangeRate;
- (void) setEvent: (NSString*)event;
- (void) setMargin: (NSString*)margin;
- (void) setNote: (NSString*)note;
- (void) setPostalCode: (NSString*)postalCode;
- (void) setPromoCode: (NSString*)promoCode;
- (void) setStatus: (NSString*)status;
- (void) setUserAgent: (NSString*)userAgent;
- (void) setRebate: (NSString*)rebate;
- (void) setSubTotal: (NSString*)subTotal;
- (void) setSharedId: (NSString*)sharedId;
- (void) setString1: (NSString*)str1;
- (void) setString2: (NSString*)str2;
- (void) setString3: (NSString*)str3;
- (void) setDate1: (NSString*)date1;
- (void) setDate2: (NSString*)date2;
- (void) setDate3: (NSString *)date3;
- (void) setMoney1: (NSString *)money1;
- (void) setMoney2: (NSString *)money2;
- (void) setMoney3: (NSString *)money3;
- (void) setHearAboutUs: (NSString *)hearAboutUs;
- (void) setLocationId: (NSString *)locationId;
- (void) setLocationName: (NSString *)locationName;
- (void) setLocationType: (NSString *)locationType;
- (void) setLatitude: (NSString*)lat;
- (void) setLongitude: (NSString*)lon;
- (void) setDisplayDense: (NSString*)displayDense;
- (void) setConnType: (NSString*) connType;
- (void) setSdk: (NSString*)sdk;
- (void) setSdkVer: (NSString*)sdkVer;
- (void) setPayable: (BOOL)payable;
- (void) setPaymentType: (NSString *)paymentType;
- (void) setIpAddressCarrier: (NSString*)ipAddressCarrier;
- (void) setIpAddressWifi: (NSString*)ipAddressWifi;
- (void) setArmAbi: (NSString*)armAbi;
- (void) setCountryCode: (NSString*)countryCode;
- (void) setOrderId: (NSString *)orderId;
- (void) setOrderDiscount: (NSString *)orderDiscount;
- (void) setOrderPromoCodeDescription: (NSString *)orderPromoCodeDescription;
- (void) setOrderShipping: (NSString *)orderShipping;
- (void) setOrderTax: (NSString *)orderTax;
- (void) setGiftPurchase: (NSString *)giftPurchase;


- (BOOL)isSession;
- (BOOL)isInstall;
- (BOOL)isUpdate;
- (void)changeToUpdate;
- (void)changeToOpen;
- (void)changeToInstall;

@end
