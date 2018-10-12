//
//  SChartCanvasUnderlay.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "SChartLayer.h"

@class ShinobiChart;
@class SChartLayer;

NS_ASSUME_NONNULL_BEGIN

/**
 The canvas underlay is responsible for drawing things like gridlines and the
 axes. It's a transparent layer that is currently rendered _below_ the openGL
 layer.
 */

@interface SChartCanvasUnderlay : UIView <SChartLayer>

/**
 The chart owner  - available to let us access the chart objects when we need
 */
@property (nullable, nonatomic, assign) ShinobiChart *chart;

#pragma mark - Initializing the underlay

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

/**
 Create our drawing layer
 */
-(id)initWithFrame:(CGRect)frame
        usingChart:(ShinobiChart *)chart
    NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
