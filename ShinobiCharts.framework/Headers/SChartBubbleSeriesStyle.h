//
//  SChartBubbleSeriesStyle.h
//  ShinobiControls_Source
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartPointSeriesStyle.h"

@class SChartBubblePointStyle;

NS_ASSUME_NONNULL_BEGIN

/** `SChartBubbleSeriesStyle` manages the appearance of an instance of `SChartBubbleSeries` on a chart.
 */
@interface SChartBubbleSeriesStyle : SChartPointSeriesStyle

/** Manages the appearance of unselected points/bubbles on a bubble series.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 */
- (SChartBubblePointStyle*) pointStyle;

/** Sets the unselected point/bubble style object for this bubble series style.
 
 @param pointStyle The new style object to use for the point style.
 @see `SChartBubbleSeriesStyle.pointStyle`
 */
- (void) setPointStyle:(SChartBubblePointStyle*)pointStyle;

/** Manages the appearance of selected points/bubbles on a bubble series.
 
 Style settings in this object will be applied when the point is marked as selected.
 
 The default settings of the style are inherited from the chart theme.  You can tweak the appearance of the series by modifying the style.
 */
- (SChartBubblePointStyle*) selectedPointStyle;

/** Sets the selected point/bubble style object for this bubble series style.
 
 @param selectedPointStyle The new style object to use for the point style.
 @see `SChartBubbleSeriesStyle.selectedPointStyle`
 */
- (void) setSelectedPointStyle:(SChartBubblePointStyle*) selectedPointStyle;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartBubbleSeriesStyle *)style;

@end

NS_ASSUME_NONNULL_END
