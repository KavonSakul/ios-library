/* Copyright 2018 Urban Airship and Contributors */

#import <Foundation/Foundation.h>
#import "UAScheduleTrigger+Internal.h"

@class UASchedule;
@class UAScheduleData;
@class UAScheduleTriggerData;
@class UAConfig;

/**
 * Manager class for the Automation CoreData store.
 */
@interface UAAutomationStore : NSObject

///---------------------------------------------------------------------------------------
/// @name Automation Store Internal Methods
///---------------------------------------------------------------------------------------

/**
* Factory method for automation store.
*
* @param storeName The store name.
* @param scheduleLimit The maximum number of schedules available for storage
* @param inMemory Whether to use an in-memory database. If `NO` the store will default to SQLite.

* @return Automation store.
*/
+ (instancetype)automationStoreWithStoreName:(NSString *)storeName scheduleLimit:(NSUInteger)scheduleLimit inMemory:(BOOL)inMemory;

/**
 * Factory method for automation store.
 *
 * @param storeName The store name.
 * @param scheduleLimit The maximum number of schedules available for storage

 * @return Automation store.
 */
+ (instancetype)automationStoreWithStoreName:(NSString *)storeName scheduleLimit:(NSUInteger)scheduleLimit;

/**
 * Saves the UAActionSchedule to the data store.
 *
 * @param schedule The schedule to save.
 * @param completionHandler Completion handler when the operation is finished. `YES` if the
 * schedule was saved, `NO` if the schedule failed to save or the data store contains
 * more schedules then the specified limit.
 */
- (void)saveSchedule:(UASchedule *)schedule completionHandler:(void (^)(BOOL))completionHandler;

/**
 * Save multiple UAActionSchedules to the data store.
 *
 * @param schedules The schedules to save.
 * @param completionHandler Completion handler when the operation is finished. `YES` if the
 * schedules were saved, `NO` if the schedules failed to save or the number of schedules in the
 * data store would exceed the specified limit.
 */
- (void)saveSchedules:(NSArray<UASchedule *> *)schedules completionHandler:(void (^)(BOOL))completionHandler;

/**
 * Deletes the schedule corresponding to the provided identifier.
 *
 * @param identifier A schedule identifier.
 */
- (void)deleteSchedule:(NSString *)identifier;

/**
 * Deletes all schedules corresponding to the provided identifier.
 *
 * @param identifier A group identifier.
 */
- (void)deleteSchedules:(NSString *)identifier;

/**
 * Deletes all schedules.
 */
- (void)deleteAllSchedules;

/**
 * Gets all schedules corresponding to the provided identifier.
 *
 * @param identifier A group identifier.
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getSchedules:(NSString *)identifier completionHandler:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all schedules.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets the schedule corresponding to the provided identifier.
 *
 * @param identifier A schedule identifier.
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getSchedule:(NSString *)identifier completionHandler:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all expired schedules that have not exceeded their grace period.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getActiveExpiredSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all currently delayed schedules.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getDelayedSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets the schedule corresponding to the provided identifier and delayed execution date.
 *
 * @param identifier A schedule identifier.
 * @param date The delayed execution date.
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getDelayedSchedule:(NSString *)identifier executionDate:(NSDate *)date completionHandler:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all currently paused schedules.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getPausedSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets a paused schedule corresponding to the provided identifier.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getPausedSchedule:(NSString *)identifier completionHandler:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all currently pending schedules.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getPendingSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all currently executing schedules.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getExecutingSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all finished schedules
 *
 * @param completionHandler Completion handler called back with the retrieved schedule data.
 */
- (void)getFinishedSchedules:(void (^)(NSArray<UAScheduleData *> *))completionHandler;

/**
 * Gets all active triggers corresponding to the provided schedule identifier and trigger type.
 *
 * @param identifier A schedule identifier.
 * @param type A trigger type
 * @param completionHandler Completion handler called back with the retrieved trigger data.
 */
- (void)getActiveTriggers:(NSString *)identifier
                     type:(UAScheduleTriggerType)type
        completionHandler:(void (^)(NSArray<UAScheduleTriggerData *> *triggers))completionHandler;

/**
 * Gets the schedule count.
 *
 * @param completionHandler Completion handler called back with the retrieved schedule count as an NSNumber.
 */
- (void)getScheduleCount:(void (^)(NSNumber *))completionHandler;

/**
 * Waits for the store to become idle and then returns. Used by Unit Tests.
 */
- (void)waitForIdle;


@end
