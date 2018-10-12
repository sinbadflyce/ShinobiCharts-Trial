//
//  SChartNumberRange.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SChartRange.h"

NS_ASSUME_NONNULL_BEGIN

/** `SChartNumberRange` represents numerical ranges on a chart axis (`SChartAxis`).  This is the likely range of choice for a `SChartNumberAxis`, but numerical ranges can also be applied to other axis types, including `SChartDateTimeAxis` and `SChartCategoryAxis`.
 */
@interface SChartNumberRange : SChartRange

@end

NS_ASSUME_NONNULL_END

