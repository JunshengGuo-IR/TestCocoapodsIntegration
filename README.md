# Impact Radius Event Tracker SDK for iOS #

The Event Tracker provides basic to complex tracking of events for iOS applications. Once you have installed and integrated the iOS SDK into your project, you can track various kinds of events.

This document explains how to install the iOS SDK and demonstrates common use cases and their associated implementations.

## 1. Compatibility ##
This library is compatible with applications built for iOS 6.0 or later.

## 2. Install SDK ##

### Install via Cocoapods ###
The pre-built library is publshed on [cocoapods](https://link_to_cocoapods/). Add the following block to your Podfile:

```objective-c
target 'my app' do
  pod 'ir-event-tracker', '1.5.0'
end
```

After run `pod install`, the sdk will be downloaded and installed.

### Install Manually ###
Simply download the latest released zip from our [relase page](https://github.com/...). Unzip and copy it into your project tree. Remember add the *EventTracker/include* to your project's header search path, and add *libEventTracker.a* in the **Link Binary With Libraries** setting.

## 3. Setup Event Tracker in Your App ##
Include the `EventTracker.h` header in your source code, only include `Item.h`when you need to submit item level data (will be explained later in this documentation).

```objective-c
#import <EventTracker.h>
#import <Item.h>
```

To initiate the EventTracker, add the following code in the `didFinishLaunchingWithOptions` method:

```objective-c
EventTracker *tracker = [EventTracker sharedManager];
[tracker initializeWithAppId:@"Your app id"
                  accountSID:@"Your account sid from Impact Radius"
                  authorizationToken:@"YOUR authorization token from Impact Radius"];
```

Now that the EventTracker SDK has been successfully instantiated and you can start tracking events.

## 4. Set Debug Mode On/Off ##
Debug mode allows you to receive useful information using LogCat and enables debug functionality on the Impact Radius server.

To enable this mode, simply add this line to your AppDelegate's didFinishLaunchingWithOptions method:

```objective-c
[[EventTracker sharedManager] setDebug:YES];
```

It is vital for live applications to remove this line or comment it out as it will affect Impact Radius' ability to track your events accurately. Conversions that happen in debug mode are not processed by Impact Radius into reporting and are not payable; these conversions post only to the raw logs and do not go through any further processing.

## 5. Track Application Instaill/Update ##
The SDK relies on the developer to determine, via coding logic, whether a user is updating the application or installing it for the first time. One approach is to implement a static setting in an update prior to implementing the SDK. This way you are able to determine whether to call the `trackInstall()` or the `trackUpdate()` method.

```objective-c
if (newInstall) {
  [[EventTracker sharedManager] trackInstall];
}

if (update) {
  [[EventTracker sharedManager] trackUpdate];
}
```

## 6. Track Custom Event ##
Using EventTracker to track a custom event has never been easier. Simply add:

```objective-c
[[EventTracker sharedManager] trackEvent:@"My Custom Event"];
```

Examples of events would be: ad clicks, completed levels, menu across or any touch based events you can think of.

## 7. Track Money Events ##
Using the EventTracker for money-related events is as easy as overloading the `trackEvent()` method with an amount as a String.

```objective-c
[[EventTracker sharedManager] trackEvent:@”My Custom Event” amount:@”1.99”];
```

Examples of money events would be in-application purchases, shopping cart payments, etc.

## 8. Track Items ##
Event Tracker provides a class **"Item"** to easily track item level data points. Here is a glimpse of Item class:

```objective-c
@interface Item : NSObject

- (void) setAmount:(NSString *)amt;
- (void) setQuantity:(NSString *)qty;
- (void) setCategory:(NSString *)cat;
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
```

In order to start tracking multiple items, first instantiate an **Event** class from your instantiated EventTracker class. Once your Event class is instantiated you can create as many items as needed before submitting to the Impact Radius servers. Note that you can also pass in an unlimited number of Custom parameters with each item by calling `addCustomParam` method.

Below is a simple example of this in the context of a basic application. The code creates two separate items, leveraging the `Item` and `NSMutableArray` classes and submitted both to Impact Radius servers for tracking. A typical use case for this would be a mobile shopping cart application or an in-game store.

```objective-c
#import <EventTracker.h>
#import <Event.h>
#import <Item.h>

...

// Instantiate a new Event class via the EventTracker singleton variable 
Event *itemEvent = [[EventTracker sharedManager] newEvent];[itemEvent setOrderId:@"Multi Item Event"];
[itemEvent setAppVersion:@"3.6"];
NSMutableArray *itemArray = [[NSMutableArray alloc] init];

Item *item1 = [[Item alloc] init];
[item1 setName:@"Red T-Shirt"];
[item1 setPrice:@"9.99"];
[item1 setQuantity:@"1"];
[item1 setRebate:@"4.00"];
[item1 addCustomParam:@"YourCustomParameter" value:@"custom1"];
[item1 addCustomParam:@"YourCustomParameter" value:@"custom2"]; // You can add unlimited custom metrics
[itemArray addObject:item1];

Item *item2 = [[Item alloc] init];
[item2 setName:@"Red Hat"];
[item2 setPrice:@"19.99"];
[item2 setQuantity:@"2"];
[item2 setRebate:@"5.00"];
[item2 addCustomParam:@"YourCustomParameter" value:@"custom1"];
[item2 addCustomParam:@"YourCustomParameter" value:@"custom2"]; // You can add unlimited custom metrics
[itemArray addObject:item2];

[[EventTracker sharedManager] submit:itemEvent withItemArray:itemArray];
```

To see a detailed example of using cocoapods to integrate with Event Tracker library, please check out our open-sourced [demo app](https://github.com/...)
