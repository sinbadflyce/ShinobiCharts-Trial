//
//  SChartLegendSymbolCandlestickSeries.h
//  ShinobiControls_Source
//
//  Copyright (c) 2012 Scott Logic Ltd. All rights reserved.
//

#import "SChartLegendSymbol.h"

@class SChartCandlestickSeries, SChartCandlestickSeriesStyle;

NS_ASSUME_NONNULL_BEGIN

/** A symbol designed to represent a candlestick series in the chart legend.
 
 The symbol makes use of the series styling, in order to better represent it in the legend.
 
 @note This is a Premium feature
 */
@interface SChartLegendSymbolCandlestickSeries : SChartLegendSymbol

#pragma mark - Initialization 

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/** Initializes and returns a newly allocated symbol to represent this candlestick series.
 @param series The chart series which this symbol will represent in the chart legend.
 @return An initialized symbol, or `nil` if it couldn't be created. */
- (id)initWithSeries:(SChartCandlestickSeries *)series
    NS_DESIGNATED_INITIALIZER;

#pragma mark - Styling 

/** The style object for the series associated with this legend symbol.
 
 This property allows you to query the style properties which have been used to create this legend symbol. */
@property (nonatomic, readonly) SChartCandlestickSeriesStyle *style;

@end

NS_ASSUME_NONNULL_END
