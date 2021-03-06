//
//  SChartLineSeriesStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "SChartLineSeriesBaseStyle.h"
#import "SChartLineCrosshairTraceStyleEnum.h"

@class SChartPointStyle;

NS_ASSUME_NONNULL_BEGIN

/** `SChartLineSeriesStyle` manages the appearance of an instance of `SChartLineSeries` on a chart.
 */
@interface SChartLineSeriesStyle : SChartLineSeriesBaseStyle

/** The color of the line below the baseline 
 
 This property is used as long as `showFill` isn't set to `YES`.  If the area is filled, `areaLineColorBelowBaseline` is used instead.
 */
@property (nonatomic, strong, nullable)     UIColor   *lineColorBelowBaseline;

/** The color for the line if the area is filled 
 
 If the area isn't filled, `lineColorBelowBaseline` is used instead.
 */
@property (nonatomic, strong, nullable)     UIColor   *areaLineColorBelowBaseline;

/** The color of the fill between the line and the axis, when the line goes below the series baseline. 
 @see `SChartLineSeriesBaseStyle.showFill` */
@property (nonatomic, strong, nullable)     UIColor   *areaColorBelowBaseline;

/** The second color which is used to form a gradient area fill when the line goes below the series baseline 
 @see `SChartLineSeriesBaseStyle.fillWithGradient` */
@property (nonatomic, strong, nullable)     UIColor   *areaColorGradientBelowBaseline;

/** Updates this style object using the configuration of the passed in style.
 @param style The new style with which to update this style object. */
- (void)supplementStyleFromStyle:(SChartLineSeriesStyle *)style;

#pragma mark -
#pragma mark Crosshair styling

/** The direction of the line data to allow the crosshair to traverse it smoothly
 
 Line data points my be ordered from left to right (x-value sorted) or top to bottom (y-value sorted). This parameter lets the chart know in order to aid the tracing process.
 
 - `SChartLineCrosshairTraceStyleHorizontal` Configures the line data points to be ordered from left to right (x-value sorted).
 - `SChartLineCrosshairTraceStyleVertical` Configures the line data points to be ordered from top to bottom (y-value sorted).
 */
@property (nonatomic)             SChartLineCrosshairTraceStyle lineCrosshairTraceStyle;

@end

NS_ASSUME_NONNULL_END
