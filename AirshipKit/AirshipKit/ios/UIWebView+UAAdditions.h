/* Copyright Airship and Contributors */

#import <UIKit/UIKit.h>
#import "UAInboxMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Category extensions for Airship web view additions.
 */
@interface UIWebView (UAAdditions)

///---------------------------------------------------------------------------------------
/// @name Web View Additions Internal Methods
///---------------------------------------------------------------------------------------

/**
 * Injects the current orientation into the webview. Should be called when the webview's
 * orientation changes.
 * @param toInterfaceOrientation The current webview orientation.
 */
- (void)injectInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation;

@end

NS_ASSUME_NONNULL_END
