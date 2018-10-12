//
//  SChartAxisTitleStyle.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChartTitleStyle.h"

/** Preset orientations for an axis title
 
 - `SChartAxisTitleOrientationHorizontal` horizontal axis title
 - `SChartAxisTitleOrientationVertical` vertical axis title
 */
typedef NS_ENUM(NSInteger, SChartAxisTitleOrientation) {
    SChartAxisTitleOrientationHorizontal,
    SChartAxisTitleOrientationVertical
};

NS_ASSUME_NONNULL_BEGIN

/** The axis title style object controls the look and feel for the axis title.
 
 @warning Axis titles are not currently supported by radial charts.
 */
@interface SChartAxisTitleStyle : SChartTitleStyle <NSCopying>

/** One of the preset orientations for the title
 
 - `SChartAxisTitleOrientationHorizontal` Configures axis title orientation to be horizontal.
 - `SChartAxisTitleOrientationVertical` Configures axis title orientation to be vertical.
*/
@property (nonatomic) SChartAxisTitleOrientation titleOrientation;

/** Supplements this style object by taking styles this object doesn't have, from the argument, `style` */
-(void)supplementStyleFromStyle:(SChartAxisTitleStyle *)style;

@end

NS_ASSUME_NONNULL_END
