//
//  SKMediator.h
//  SKMediator_Example
//
//  Created by 李烁凯 on 2019/4/16.
//  Copyright © 2019 luckySK. All rights reserved.
//

/**
 * 完全按照CTMediator写
 */

#import <UIKit/UIKit.h>

typedef void(^CompletionBlock)(NSDictionary *info);

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kSKMediatorParamsKeySwiftTargetModuleName;

@interface SKMediator : NSObject

+ (instancetype)sharedInstance;

// 远程App调用入口
- (id)performActionWithUrl:(NSURL *)url
                completion:(CompletionBlock)completion;

// 本地组件调用入口
- (id)performTarget:(NSString *)targetName
             action:(NSString *)actionName
             params:(NSDictionary *)params
  shouldCacheTarget:(BOOL)shouldCacheTarget;

- (void)releaseCachedTargetWithTargetName:(NSString *)targetName;

@end

NS_ASSUME_NONNULL_END
