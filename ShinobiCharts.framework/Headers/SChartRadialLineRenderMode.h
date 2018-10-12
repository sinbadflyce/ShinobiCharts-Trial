//
//  SChartRadialLineRenderMode.h
//  ShinobiCharts
//
//  Created by Thomas Kelly on 07/02/2014.
//
//

/** Whether x-axis lines and y-axis grid lines on radial charts should be curved or straight.
 
 - `SChartRadialLineRenderModeCurved` Lines are drawn as an arc.
 - `SChartRadialLineRenderModeLinear` Lines are drawn as straight lines, in a "spider-web" style
 */
typedef NS_ENUM(NSUInteger, SChartRadialLineRenderMode)
{
    SChartRadialLineRenderModeCurved = 0,
    SChartRadialLineRenderModeLinear = 1
};
