//
//  SChartAxisPosition.h
//  ShinobiCharts
//
//  Created by Jan Akerman on 24/12/2013.
//
//

/** The `SChartAxisPosition` defines whether an axis will be positioned at the normal or reverse location.
 
 - `SChartAxisPositionNormal` For x-axes, the 'normal' position is below the plot area. For y-axes, the 'normal' position is to the left of the plot area.
 - `SChartAxisPositionReverse` For x-axes, the 'reverse' position is above the plot area. For y-axes, the 'reverse' position is to the right of the plot area.
 */
typedef NS_ENUM(NSInteger, SChartAxisPosition) {
    SChartAxisPositionNormal,
    SChartAxisPositionReverse,
};
