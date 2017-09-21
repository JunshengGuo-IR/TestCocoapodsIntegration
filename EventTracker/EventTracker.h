//
//  irEventTracker.h
//  irEventTracker
//
//  Created by Tyler Thomas.
//  Copyright (c) 2017 Impact Radius. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Event.h"

@interface EventTracker : NSObject

@property (nonatomic, assign, getter=isDebug) BOOL debug;

@property (nonatomic, strong) NSString *actionTrackerId;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;


- (void) initEventTracker:(NSString*)actionTrackerId username:(NSString*)username password:(NSString *)password DEPRECATED_MSG_ATTRIBUTE("Use initializeWithAppId:username:authorizationToken");
- (void) initializeWithAppId:(NSString *)appId accountSID:(NSString *)accountSID authorizationToken:(NSString *)authorizationToken;

- (Event *) newEvent:(NSString *)eventName;
- (Event *) newEvent:(NSString *)eventName amount:(NSString *)amount;
- (Event *) newEvent:(NSString *)eventName referenceId:(NSString *)referenceId;

- (void) trackUpdate;
- (void) trackInstall;
- (void) trackSession;
- (void) trackEvent:(NSString*)eventName;
- (void) trackEvent:(NSString*)eventName amount:(NSString*)amount;
- (void) trackEvent:(NSString*)eventName referenceId:(NSString*)referenceId;
- (void) submit:(Event*)conv;
- (void) submit:(Event*)conv withItemArray:(NSMutableArray*)itemArray;

- (void) setExistingApp:(BOOL)existing;
- (void) setPluginName:(NSString *)plugin;

#pragma mark - Singleton sharedManager
+ (id) sharedManager;
- (void) changeAppId:(NSString *)appId accountSID:(NSString *)accountSID authorizationToken:(NSString *)authorizationToken;

@end

