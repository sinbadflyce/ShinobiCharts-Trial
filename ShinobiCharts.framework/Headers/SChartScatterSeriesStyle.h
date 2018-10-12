//
//  SChartScatterSeriesStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartPointSeriesStyle.h"

@class SChartPointStyle;

NS_ASSUME_NONNULL_BEGIN

/** `SChartScatterSeriesStyle` manages the appearance of an instance of `SChartScatterSeries` on a chart.
 */
@interface SChartScatterSeriesStyle : SChartPointSeriesStyle

#pragma mark -
#pragma mark Styling properties

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartScatterSeriesStyle *)style;

#pragma mark Point styling

/** Manages the appearance of points that are not selected. */

- (SChartPointStyle *) pointStyle;
- (void) setPointStyle:(SChartPointStyle *)pointStyle;

/** Manages the appearance of points that are selected. */

- (SChartPointStyle *) selectedPointStyle;
- (void) setSelectedPointStyle:(SChartPointStyle *)selectedPointStyle;

@end

NS_ASSUME_NONNULL_END

