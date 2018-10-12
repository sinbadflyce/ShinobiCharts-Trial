//
//  SChartTickLabelClippingMode.h
//  ShinobiCharts
//
//  Created by Jan Akerman on 22/12/2013.
//
//

/** Defines the tick label clipping mode for the ends of an `SChartAxis`.
 
 - `SChartTickLabelClippingModeTicksAndLabelsPersist` Keeps both the label and tick visible for as long as possible, allowing the label to overlap with adjacent axes.
 - `SChartTickLabelClippingModeTicksPersist` Keeps the tick mark visible for as long as possible and clip the label as soon as it reaches the edge of its view.
 - `SChartTickLabelClippingModeNeitherPersist` Keeps the tick mark visible as long as the tick label is visible - as soon as the tick label reaches its bounds, and is clipped, clip the tick mark too.
 
 @warning Tick label clipping isn't currently supported on radial charts.
 */
typedef NS_ENUM(NSInteger, SChartTickLabelClippingMode) {
    SChartTickLabelClippingModeTicksAndLabelsPersist,
    SChartTickLabelClippingModeTicksPersist,
    SChartTickLabelClippingModeNeitherPersist
};
