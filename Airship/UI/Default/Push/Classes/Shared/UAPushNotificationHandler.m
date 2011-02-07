/*
 Copyright 2009-2011 Urban Airship Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "UAPushUI.h"
#import "UAPushNotificationHandler.h"

#import <AudioToolbox/AudioServices.h>

@implementation UAPushNotificationHandler

- (void)displayNotificationAlertMessage:(NSString *)alertMessage {
	
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle: @"Notification" 
                                                    message: alertMessage
                                                   delegate: nil
                                          cancelButtonTitle: @"OK"
                                          otherButtonTitles: nil];
	[alert show];
	[alert release];
}

- (void)displayNotificationAlert:(NSDictionary *)alertDict {
    UALOG(@"Got an alert with a body.");
    
    NSString *body = [alertDict valueForKey:@"body"];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle: @"Notification" 
                                                    message: body
                                                   delegate: nil
                                          cancelButtonTitle: @"OK"
                                          otherButtonTitles: nil];
	[alert show];
	[alert release];
}

- (void)playNotificationSound:(NSString *)sound {
    
    UALOG(@"Received an alert with a sound: %@", sound);
    
    if (sound) {
        
        SystemSoundID soundID;
        NSString *path = [[NSBundle mainBundle] pathForResource:[sound stringByDeletingPathExtension] 
                                                         ofType:[sound pathExtension]];
        
        AudioServicesCreateSystemSoundID((CFURLRef)[NSURL fileURLWithPath:path], &soundID);
        AudioServicesPlayAlertSound(soundID);
        
    } else {
        
        // Vibrates on supported devices, on others, does nothing
        AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
    
    }

}

- (void)handleCustomPayload:(NSDictionary *)data {
    UALOG(@"Received an alert with a custom payload");
}

- (void)handleBackgroundNotification:(NSDictionary *)notification {
    UALOG(@"The application resumed from a notification.");
}

@end
