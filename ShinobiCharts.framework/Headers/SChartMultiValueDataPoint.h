//
//  SChartMultiValueDataPoint.h
//  ShinobiControls_Source
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import "SChartDataPoint.h"

NS_ASSUME_NONNULL_BEGIN

/** Represents a data point that has values that are not related to any axes. An example of a series that uses such values is the `SChartBubbleSeries`.
 */

@interface SChartMultiValueDataPoint : SChartDataPoint

/** A dictionary of axis independent values for this data point.
 
 In order to query the values at a point, you can use the `[SChartDataSeries valueKeys]` property.
 */
@property (nonatomic, retain) NSMutableDictionary *values;

@end

NS_ASSUME_NONNULL_END