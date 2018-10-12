//
//  SChartLinearAnimationCurve.h
//  ShinobiControls_Source
//
//  Created by Simon Withington on 28/11/2012.
//
//

#import "SChartAnimation.h"

NS_ASSUME_NONNULL_BEGIN

/** This curve progresses at a constant speed from 0.0 to 1.0.
 
 See the `SChartAnimationCurve` protocol for more information on curve evaluation.
 */
@interface SChartLinearAnimationCurve : NSObject <SChartAnimationCurve>

@end

NS_ASSUME_NONNULL_END

