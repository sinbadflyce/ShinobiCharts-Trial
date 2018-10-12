//
//  SChartDelegate.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ShinobiHeaderMacros.h"

@class ShinobiChart;
@class SChartSeries;
@class SChartDataPoint;
@class SChartRadialDataPoint;
@class SChartRadialSeries;
@class SChartTickMark;
@class SChartAnimation;
@class SChartAxis;
@class SChartDataPointLabel;
@protocol SChartData;

NS_ASSUME_NONNULL_BEGIN

/*
 SChartMovementInformation describes why a chart is triggering pan and zoom delegate methods.

 Currently it contains one member - movementIsMomentum. This is true if the chart is panning due to momentum.
 */
typedef struct SChartMovementInformation
{
    int movementIsMomentum : 1;
} SChartMovementInformation;

/**
 The delegate of a `ShinobiChart` object must adopt the `SChartDelegate` protocol.  Optional methods of the protocol allow the delegate to respond to the following types of events:

 - Axis range changes.
 - Selection on the chart.
 - Chart rendering.
 - Data loading.
 - Chart series animations.
 - Crosshair tracking.

 As well as methods to respond to events on the chart, the protocol also provides methods to allow the delegate to manage the chart axes, by altering tick marks on the axes, or by setting tick frequencies.

 More information about how to use the `SChartDelegate` can be found in the [user guide](chart-delegate.html).


 */
@protocol SChartDelegate <NSObject>

@optional

#pragma mark - Axis Range Updates

/**
 A notfication that the range has been changed on the specified axis.

 This delegate method will be invoked in all cases where an axis range changes, including:
 - setting the axis' range
 - a user is performing a zooming/panning gesture
 - the chart is momentum zooming/panning
 - the chart is bouncing back after being zoomed/panned outside its max range
 */
- (void)sChart:(ShinobiChart *)chart didAlterRangeOnAxis:(SChartAxis *)axis;

#pragma mark - Radial Series Panning

/** A notification that we have started panning on a pie/donut series.

 @param radial The chart containing the pie/donut series which has started panning.
 @param radialSeries The pie/donut series being panned.

 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)radial radialSeriesDidStartPanning: (SChartRadialSeries *)radialSeries;

/** A notification that a pie/donut series is being panned.

 The rotation of the series is updated as the user pans the chart.  You can query the current rotation of the series using the [SChartDonutSeries rotation] property.

 @param radial The chart containing the pie/donut series.
 @param radialSeries The pie/donut series being panned.

 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)radial radialSeriesIsPanning: (SChartRadialSeries *)radialSeries;

/** A notification that a panning gesture on a pie/donut series has ended, and the series will begin to decelerate.

 @param chart The chart containing the pie/donut series.
 @param radialSeries The pie/donut series which has started to decelerate.

 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)chart radialSeriesWillBeginDecelerating:(SChartRadialSeries *)radialSeries;

/** A notification that a pie/donut series has come to a halt after being panned and released.

 @param chart The chart containing the pie/donut series.
 @param radialSeries The pie/donut series which has finished panning.

 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)chart radialSeriesDidEndDecelerating:(SChartRadialSeries *)radialSeries;

#pragma mark -
#pragma mark Touch Gestures

/** A notification that a series has been selected or de-selected.

 A touch gesture has resulted in the `selected` property of the series changing. The nearest data point is passed into the method along with the current pixel coordinates of that point.

 @param chart The chart on which the selection has occurred.
 @param series The series which has been selected or de-selected.
 @param dataPoint The nearest data point on that series to the point on the screen which was touched.
 @param pixelPoint The pixel coordinates of that data point.
 */
- (void)sChart:(ShinobiChart *)chart toggledSelectionForSeries:(SChartSeries *)series nearPoint:(SChartDataPoint *)dataPoint
atPixelCoordinate:(CGPoint)pixelPoint NS_SWIFT_NAME(sChart(_:toggledSelectionFor:near:at:));

/** A notification that a data point has been selected or de-selected.

 A touch gesture has resulted in the closest data point to be added to our `selectedDataPoints` set. This data point is passed into the method along with the current pixel coordinates of that point and the series that it belongs to.

 @param chart The chart on which the selection has occurred.
 @param dataPoint The data point which was selected or de-selected.
 @param series The chart series which contains that data point.
 @param pixelPoint The pixel coordinates of that data point.
 */
- (void)sChart:(ShinobiChart *)chart toggledSelectionForPoint:(id<SChartData>)dataPoint inSeries:(SChartSeries *)series
atPixelCoordinate:(CGPoint)pixelPoint NS_SWIFT_NAME(sChart(_:toggledSelectionFor:in:at:));

/** A notification that a data point on a pie/donut chart has changed state to 'selected' from 'deselected' or vice versa.

 The`selected` property of the data point has changed. This could be as a result of a tap gesture on the chart, or of programmatically selecting the point (`setSlice:asSelected`). The data point is returned along with the series that it belongs to and the pixel coordinates of the tap, if any.

 @param chart The chart on which the selection occurred.
 @param dataPoint The data point which was selected or de-selected.
 @param series The pie/donut series which contains the data point.
 @param pixelPoint The pixel coordinate of the data point.

 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
*/
- (void)sChart:(ShinobiChart *)chart toggledSelectionForRadialPoint:(SChartRadialDataPoint *)dataPoint inSeries:(SChartRadialSeries *)series
atPixelCoordinate:(CGPoint)pixelPoint NS_SWIFT_NAME(sChart(_:toggledSelectionFor:in:at:));

#pragma mark -
#pragma mark Crosshair

/** Notifies the user when the crosshair moves.

 When the crosshair is panned, the new values at the crosshair point are passed into this method. For a line series, the values will be interpolated if they lie between actual data points. On a category axis - or bar/column series - the crosshair will snap to the discrete values.

 @param chart The chart containing the crosshair.
 @param x The x value of the current crosshair position.
 @param y The y value of the current crosshair position.
 */
- (void)sChart:(ShinobiChart *)chart crosshairMovedToXValue:(id)x andYValue:(id)y
NS_SWIFT_NAME(sChart(_:crosshairMovedToXValue:yValue:));

#pragma mark -
#pragma mark Rendering

/** A notification that the chart object has started rendering.

 This is called before the chart starts rendering its data. At this point, the chart axes will be up to date with your data, so a common use case of this method would be to update the chart axes before they are rendered, for example to modify the axis title or range.

 @param chart The chart which has started rendering.
 @param fullRedraw If the chart is carrying out a full redraw, this argument is set to `YES`.
 */
- (void)sChartRenderStarted:(ShinobiChart *)chart withFullRedraw:(BOOL)fullRedraw;

/** A notification that the chart object has finished rendering.

 This is called once the chart has finished rendering its data. A common use case for this method would be to display the crosshair on the chart after it has rendered, or to add annotations onto the chart. You could also update other UI elements in your application so that they reflect the new state of the chart. You shouldn’t modify the chart plot area or its axes here, as any changes won’t be visualized until the next time that the chart is rendered.

 @param chart The chart which has finished rendering.
 */
- (void)sChartRenderFinished:(ShinobiChart *)chart;

#pragma mark -
#pragma mark Tick Marks

/** Alter a tick mark before it is added to an axis on the chart.

 This method gives you each tick mark just before it is added to its axis. Use this to set colors, borders, or even move the tickmark's label elsewhere.

 @warning This method is called after the labels are positioned and tick label collision has been accounted for. Use the axis' `labelFormatter` property to format tick labels before these calculations.

 @param chart The chart containing the tick marks.
 @param tickMark The tick mark which will be added to its axis.
 @param axis The axis on the chart to which the tick mark will be added.
 */
-(void)sChart:(ShinobiChart *)chart alterTickMark:(SChartTickMark *)tickMark beforeAddingToAxis:(SChartAxis *)axis;

/** Assist the chart in calculating tick label lengths. This is useful when you provide an implementation for sChart:alterTickMark:beforeAddingToAxis:

 For example, if you lengthen the tick label strings in alterTickMark, you should hint to the axis that extra room will be required by implementing this method.

 The actual contents of this string are ignored, only its size with the current tick-label font is used.
 For example, if you are using a currency format, a string like @"$#.##" will ensure sufficient room is calculated.
 Return nil for the chart to use automatically calculated values for the tick label lengths.

 @param chart The chart containing the axis.
 @param axis The axis for which we are returning the longest tick label string.
 @return A string of the right size, from which the axis can deduce the maximum amount of space that tick mark labels will require.
 */
-(NSString * _Nullable)sChart:(ShinobiChart *)chart longestLabelStringOnAxis:(SChartAxis *)axis;

/** Alter a pie/donut label before it is added to the chart.

 This method gives you each label for each pie/donut series before it is added to the chart. Use this to set colors, borders, or reposition the label.

 More information about using this method can be found in our tutorial ['Pie chart labels that are out of this... slice'](http://www.shinobicontrols.com/blog/posts/2012/08/06/pie-chart-labels-that-are-out-of-this-slice).

 @param chart The chart containing the pie/donut label.
 @param label The pie/donut label being added to the chart.
 @param datapoint The data point on the chart to which the label applies.
 @param index The index of the data point in its pie/donut series.
 @param series The pie/donut series containing the data point.

 @warning The 'series' parameter will change to type `SChartSeries` to cope with `SChartRadialSeries` being removed in a future release.
 */
-(void)sChart:(ShinobiChart *)chart alterLabel:(UILabel *)label forDatapoint:(SChartRadialDataPoint *)datapoint atSliceIndex:(NSInteger)index inRadialSeries:(SChartRadialSeries *)series NS_SWIFT_NAME(sChart(_:alter:for:atSlice:in:));


/** Set the major and minor tick frequencies for an axis.

 Implement this method to customize your major and minor tick frequencies depending on the state of the axis.

 Set the `majorTickFrequency` and `minorTickFrequency` pointers to objects of your choosing.

 Not setting the `minorTickFrequency`, or setting it to `nil`, will result in minor ticks not being displayed.
 You should set frequencies of the correct type to match the axis - for example, `SChartDateFrequency` for `SChartDateTimeAxis`, or `NSNumber` for `SChartNumberAxis`.

 @param chart The chart containing the axis.
 @param majorTickFrequency A pointer to the major tick frequency on the axis.  If you set this value, the axis will update to use the new value.
 @param minorTickFrequency A pointer to the minor tick frequency on the axis.  If you set this value, the axis will update to use the new value.
 @param axis The axis for which we are setting the tick frequencies.
 */
-(void)sChart:(ShinobiChart *)chart setMajorTickFrequency:(id _Nullable * const _Nonnull)majorTickFrequency andMinorTickFrequency:(id _Nullable * const _Nonnull)minorTickFrequency onGeneratingTickMarksforAxis:(SChartAxis *)axis NS_SWIFT_NAME(sChart(_:majorTickFrequency:minorTickFrequency:onGeneratingTickMarksFor:));

#pragma mark Data point labels

/** Alter a data point label before it is added to the chart.

 This method gives you each data point label for each series before it is added to the chart. Use this to set colors, borders, or reposition the label.

 @param chart The chart containing the label.
 @param label The label being added to the chart.
 @param dataPoint The data point on the chart to which the label applies.
 @param series The series containing the data point.
 */
-(void)sChart:(ShinobiChart *)chart alterDataPointLabel:(SChartDataPointLabel*)label forDataPoint:(SChartDataPoint *)dataPoint inSeries:(SChartSeries *)series NS_SWIFT_NAME(sChart(_:alter:for:in:));

#pragma mark -
#pragma mark Data Loading

/** A notification that the chart will start loading its data.

 At this point, the chart has been created, but it either doesn’t contain any data, or it is about to reload its data. You shouldn’t do anything with chart axes at this point, as they will be out of date with the new data. A common use case for this method would be to pop up an activity indicator if you think the data will take a long time to load.

 @param chart The chart which started loading its data.
 */
-(void)sChartWillStartLoadingData:(ShinobiChart *)chart;

/** A notification that the chart has finished loading its data.

 This is called once the chart has finished loading its data, and before it starts rendering its plot area and axes. A common use of this method would be to close the activity indicator if you popped one up during loading. At this point, the chart axes will have been refreshed from the new data, so you could update the chart axes here before they are rendered. It is important to note that this method is only called when we load data, rather than each time the chart is rendered.

 @param chart The chart which finished loading its data.
 */
-(void)sChartDidFinishLoadingData:(ShinobiChart *)chart;

#pragma mark - Animation

/**
 A notfication that the specified axis has finished animating.

 This delegate method will be invoked in all cases where an axis animation completes, including:
 - setting the axis' range passing `withAnimation:YES`
 - a user finishes a zooming/panning gesture and the `enableMomentumPanning`/`enableMomentumZooming` properties are `YES`, causing the axis to animate to a stop
 - the chart finishes bouncing back after being zoomed/panned outside its max range
 */
- (void)sChart:(ShinobiChart *)chart didFinishAnimatingAxis:(SChartAxis *)axis;

@end

NS_ASSUME_NONNULL_END
