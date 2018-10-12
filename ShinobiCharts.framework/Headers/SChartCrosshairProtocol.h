//
//  SChartCrosshair.h
//  ShinobiCharts
//
//  Copyright 2014 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ShinobiHeaderMacros.h"

@class ShinobiChart;
@class SChartCrosshairStyle;
@class SChartCrosshairTooltip;

NS_ASSUME_NONNULL_BEGIN

/**
 * The chart's crosshair interface - the chart will push 'show', 'move' and
 * 'hide' events onto the crosshair, which should respond appropriately.
 */
@protocol SChartCrosshair <NSObject>

/**
 * Instructs the crosshair to show itself in the chart at `pointInChart`,
 * which is in the chart's coordinate space.
 *
 * This method is called each time the chart wishes to make the crosshair
 * visible, and is paired with a -hide call.
 */
- (void)showAtPoint:(CGPoint)pointInChart inChart:(ShinobiChart *)chart;

/**
 * Instructs the crosshair to move itself in chart to the position
 * `pointInChart`, in the chart's coordinate space.
 *
 * This method is called every for frame of the crosshair's movement, when the
 * chart wishes to update the crosshair.
 */
- (void)moveToPoint:(CGPoint)pointInChart inChart:(ShinobiChart *)chart;

/**
 * Instructs the crosshair to hide itself from view (and usually to
 * removeFromSuperview)
 *
 * This method is called by the chart when the crosshair should be dismissed,
 * paired with the showAtPoint:inChart: call.
 */
- (void)hide;

/**
 * Returns a BOOL representing whether the crosshair is hidden.
 */
- (BOOL)isHidden;

@end

NS_ASSUME_NONNULL_END

