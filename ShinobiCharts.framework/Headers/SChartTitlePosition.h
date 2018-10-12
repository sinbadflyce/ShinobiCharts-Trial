//
//  SChartTitlePosition.h
//  ShinobiCharts
//
//  Created by Jan Akerman on 05/02/2014.
//
//

/**
 The position of an `SChartTitle` for an `SChart` or `SChartAxis`.

 - `SChartTitlePositionCenter`: Aligns the title with the center of the chart or axis.
 - `SChartTitlePositionBottomOrLeft`: Aligns the title  with the left of the chart or x axis, or the bottom of the y axis.
 - `SChartTitlePositionTopOrRight`: Aligns the title with the right of the chart or x axis, or the top of the y axis.
 */
typedef NS_ENUM(NSInteger, SChartTitlePosition) {
    SChartTitlePositionCenter,
    SChartTitlePositionBottomOrLeft,
    SChartTitlePositionTopOrRight
};

