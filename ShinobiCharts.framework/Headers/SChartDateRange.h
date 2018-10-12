//
//  SChartDateRange.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SChartRange.h"

NS_ASSUME_NONNULL_BEGIN

/** An `SChartDateRange` object is an instance of `SChartRange` that is specific to NSDate - with each element in the range represented by an NSDate object. This is the likely range of choice for an `SChartDateTimeAxis`.
 */
@interface SChartDateRange : SChartRange

#pragma mark -
#pragma mark Initialization

- (instancetype)initWithMinimum:(NSNumber *)min
                     andMaximum:(NSNumber *)max
__attribute__((unavailable("Use '[[SChartRange alloc] initWithMinimum:andMaximum:]'")));

/** Initializes and returns a newly allocated range object with the specified minimum and maximum dates.
 @param min The minimum date in the range.
 @param max The maximum date in the range.
 @return An initialized range object or `nil` if the range couldn't be created.
 */
- (id)initWithDateMinimum:(NSDate *)min
           andDateMaximum:(NSDate *)max
NS_DESIGNATED_INITIALIZER
NS_SWIFT_NAME(init(dateMinimum:dateMaximum:));

#pragma mark - Information about the range 

/** Returns the minimum of the range as an NSDate object. */
- (NSDate *)minimumAsDate;

/** Returns the maximum of the range as an NSDate object. */
- (NSDate *)maximumAsDate;

@end

NS_ASSUME_NONNULL_END

