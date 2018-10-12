//
//  SChartBubbleStyle.h
//  ShinobiControls_Source
//
//  Copyright (c) 2013 Scott Logic Ltd. All rights reserved.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** `SChartBasePointStyle` is the base class for all point styles in ShinobiCharts. This point style object manages the appearance of datapoint on a chart.

 This base class is used for the point style in the `SChartRadialLineSeriesStyle` class. It is also subclassed by `SChartBaselinePointStyle` which every other point style class corresponds to. For more information on these other point styles see `SChartBaselinePointStyle`.
 

 .*/

@interface SChartBasePointStyle : NSObject <NSCopying>

#pragma mark -
#pragma mark Styling Properties
/** Defines whether points should be displayed on our chart series. */
@property (nonatomic, assign)     BOOL showPoints;

/** The color of the data points. */
@property (nonatomic, strong, nullable)     UIColor   *color;

/** The radius of the outer section of a data point. 
 
 If a texture is used for a datapoint, the radius will set the size of the longest dimension of the image. The shorter of the two dimensions will update
 to keep aspect ratio.
 */
@property (nonatomic, strong, nullable)     NSNumber  *radius;

/** An image to be used for each data point.  If this property is set, the image will displayed rather than the default of an inner and outer circle. */
@property (nonatomic, strong, nullable)     UIImage   *texture;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
- (void)supplementStyleFromStyle:(SChartBasePointStyle *)style;

@end

NS_ASSUME_NONNULL_END
