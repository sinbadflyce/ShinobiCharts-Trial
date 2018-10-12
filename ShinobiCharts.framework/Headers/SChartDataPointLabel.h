//
//  SChartDataPointLabel.h
//  ShinobiCharts
//
//  Created by Thomas Kelly on 14/11/2013.
//
//

#import <UIKit/UIKit.h>

@protocol SChartData;
@class SChartSeries;
@class ShinobiChart;

NS_ASSUME_NONNULL_BEGIN

/** A label representing a single `SChartDataPoint`, styled by `SChartDataPointLabelStyle`.
 

*/
@interface SChartDataPointLabel : UILabel

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/** Create a label for a given dataPoint */
-(id)initWithDataPoint:(id<SChartData>)dataPoint NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

