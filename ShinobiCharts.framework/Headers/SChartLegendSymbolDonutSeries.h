//
//  SChartLegendSymbolDonutSeries.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import "SChartLegendSymbol.h"

@class SChartDonutSeries, SChartDonutSeriesStyle;

NS_ASSUME_NONNULL_BEGIN

/** A symbol designed to represent a donut series in the chart legend.
 
 The symbol makes use of the series styling, in order to better represent it in the legend.
 */
@interface SChartLegendSymbolDonutSeries : SChartLegendSymbol 

#pragma mark - Styling 

/** The style object for the series associated with this legend symbol.
 
 This property allows you to query the style properties which have been used to create this legend symbol. */
@property (nonatomic, retain) SChartDonutSeriesStyle *style;

#pragma mark - Initialization 

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/** Initializes and returns a newly allocated symbol to represent the specified slice in the specified donut series.
 @param donutSeries The chart series which this symbol will be associated with.
 @param index The slice in the series which the symbol will represent.
 @return An initialized symbol, or `nil` if it couldn't be created. */
- (id)initWithSeries:(SChartDonutSeries *)donutSeries
       andSliceIndex:(NSInteger)index
    NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

