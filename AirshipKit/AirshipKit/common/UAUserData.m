/* Copyright Airship and Contributors */

#import "UAUserData.h"

@interface UAUserData()

@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *url;

@end

@implementation UAUserData

- (instancetype)initWithUsername:(NSString *)username password:(NSString *)password url:(NSString *)url {
    self = [super init];
    if (self) {
        self.username = username;
        self.password = password;
        self.url = url;
    }

    return self;
}

+ (instancetype)dataWithUsername:(NSString *)username password:(NSString *)password url:(NSString *)url {
    return [[self alloc] initWithUsername:username password:password url:url];
}


@end
