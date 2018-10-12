//
//  SChartDiscontinuousAxis.h
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SChartNumberAxis.h"
#import "ShinobiHeaderMacros.h"

@class SChartNumberAxis;

/**
 An `SChartNumberSkip` is used to define a skip in an `SChartDiscontinuousNumberAxis`.

 It has `double` values `start` and `end`.
 */
typedef struct SChartNumberSkip {
    double start, end;
} SChartNumberSkip;

NS_ASSUME_NONNULL_BEGIN

/**
 An `SChartDiscontinuousNumberAxis` is a subclass of `SChartNumberAxis`, designed to allow skipping over given ranges.

 @note This is a Premium feature

 @warning This type of axis is not currently supported radial charts.
 */
@interface SChartDiscontinuousNumberAxis : SChartNumberAxis

/**
 Add an `SChartNumberSkip` with a start and end, to the list of ranges to skip

 An `SChartNumberSkip` is defined as follows:

```objective_c
     typedef struct {
        double start, end;
     } SChartNumberSkip;
```

You must reload the chart when adding new skips.

@param skip The `SChartNumberSkip` to add to the exclusions
*/
- (void)    addSkip:(SChartNumberSkip)skip;

/**
 * Remove a previously added SChartNumberSkip from the list of ranges to skip.
 *
 * You must reload the chart when removing skips.
 *
 * @param skip The `SChartNumberSkip` to be removed from the exclusions
 */
- (void) removeSkip:(SChartNumberSkip)skip;


/**
 * Returns an array of `NSValue`s, each containing an `SChartNumberSkip`.
 *
 * Note that you should not call `addSkip` or `removeSkip` while iterating over
 * this array.
 */
- (NSArray SC_GENERIC(NSValue *) *)skips;

@end

NS_ASSUME_NONNULL_END
