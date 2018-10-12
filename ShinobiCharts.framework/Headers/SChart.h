//
//  SChart.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SChartPointStruct.h"
#import "SChartTitlePosition.h"
#import "SChartGesturePanType.h"
#import "ShinobiHeaderMacros.h"

NS_ASSUME_NONNULL_BEGIN

@class SChartCanvas;
@class SChartAxis;
@class SChartTitle;
@class SChartLegend;
@class SChartTheme;
@class SChartSeries;
@class SChartAnnotation;
@class SChartGradientView;
@class SChartMappedSeries;
@class SChartGestureManager;
@class SChartAnimationTracker;

@protocol SChartDatasource;
@protocol SChartDelegate;
@protocol SChartData;
@protocol SChartCrosshair;

/** Axis types used for chart initialization

 When creating a chart these types are used to determine which subclass of `SChartAxis` will be used for the axes

 - `SChartAxisTypeNumber` see `SChartNumberAxis`
 - `SChartAxisTypeDateTime` see `SChartDateTimeAxis`
 - `SChartAxisTypeCategory` see `SChartCategoryAxis`
 - `SChartAxisTypeLogarithmic` see `SChartLogarithmicAxis`
 - `SChartAxisTypeDiscontinuousNumber` see `SChartDiscontinuousNumberAxis`
 - `SChartAxisTypeDiscontinuousDateTime` see `SChartDiscontinuousDateTimeAxis`
 */
typedef NS_ENUM(NSInteger, SChartAxisType) {
    SChartAxisTypeNumber,
    SChartAxisTypeDateTime,
    SChartAxisTypeCategory,
    SChartAxisTypeLogarithmic,
    SChartAxisTypeDiscontinuousNumber,
    SChartAxisTypeDiscontinuousDateTime
};

/** The position of the chart's title */


/**
 The position of the chart's title

 - `SChartTitleCentresOnChart` Centers on the `ShinobiChart` view
 - `SChartTitleCentresOnPlottingArea` Centers on chart's plot area
 - `SChartTitleCentresOnCanvas` Centers on the chart's canvas
 */
typedef NS_ENUM(NSInteger, SChartTitleCentresOn) {
    SChartTitleCentresOnChart,
    SChartTitleCentresOnPlottingArea,
    SChartTitleCentresOnCanvas
};

typedef struct SChartSize
{
    double width, height;
} SChartSize;

/**
 A `ShinobiChart` displays data arranged in either cartesian _or_ radial series. Here is an example with a few of the common features labelled:

 <img src="Images/api_chart.png" width="800">

 A `ShinobiChart` will display its cartesian series (line, column, bar, scatter) if a cartesian series is added to it first, or all its radial series (donuts, pies) if a radial series is added to it first. If a radial series is added to a 'cartesian chart' or vice versa, a warning will be issued and that series discarded.

 Data is always represented in a series or a set of series. The `SChartSeries` determines the look and style of the data contained in a `SChartDataSeries`. There is a one-to-one relationship between a chart series and the data series it represents.

 A chart must have a minimum of one x-axis and one y-axis to display cartesian series, however, these will be automatically generated if none are specified.

 A `ShinobiChart` must have an object that acts as the data source to display any data and optionally can have an object that acts as the delegate. The data source must adopt the `SChartDatasource` protocol and the delegate must adopt the `SChartDelegate` protocol. The data source provides the information needed by the chart to construct the series and represent the data.  Series are identified by an index integer by the data source.

 The `ShinobiChart` is a subclass of `UIView`,  and as such it can be added to other parent views or set as the root view of a view controller.

 A `ShinobiChart` will only update to reflect any changes to data when the `reloadData` method is called.
 */
@interface ShinobiChart : UIView

#pragma mark - Series

#pragma mark -
#pragma mark Layout and Styling

/** The frame of the plot area in the coordinate system of the chart view.

 This is the area in which your data is visualised in series.
 This area does not usually contain the chart title, legend, axes or axis titles, or any tickmarks or ticklabels unless they are explicitly positioned inside the plot area.
 */
@property (nonatomic, assign, readonly) CGRect plotAreaFrame;

/** Background color of the chart view */
- (nullable UIColor *)chartBackgroundColor;

/** Background colour of the plot area - ie: the area inside the axis. */
- (nullable UIColor *)plotBackgroundColor;

/**
 The Inset of the chart's canvas frame using the top, left, bottom & right values in the `UIEdgeInsets` object given.

 This inset will get applied after the canvas has taken everything else into account (e.g. chart and axis title positioning).
 */
@property (nonatomic, assign) UIEdgeInsets canvasInset;

/** Tells the chart to reposition its legend.

 The chart legend is an instance of SChartLegend.  The chart uses the value of its position property to position the legend on its canvas.
 */
- (void)positionLegend;

/** Tells the chart to redraw itself.  The chart is redrawn during the next draw cycle. */
- (void)redrawChart;

/** Tells the chart to redraw itself, as long as it has basic componenents.  If the chart is radial, it doesn't need to have any axes set in order to redraw.  */
- (void)setNeedsLayoutIfHaveAxesAndData;

/** Defines whether the chart rotates when the device is rotated.

 If the view that contains the chart doesn't actually rotate for a device orientation,
    set this flag to `NO` to prevent unnecessary fade out/in of the axes and the crosshair.

 By default, this property is set to `YES`.
 */
@property (nonatomic) BOOL rotatesOnDeviceRotation;

#pragma mark -
#pragma mark Notifications through the delegate

/** The object assigned as the chart delegate */
- (id<SChartDelegate>)delegate;

/** Returns a string that represents the specified x and y values

 A primary use case for this method is to generate text for the crosshair.
 @param x The specified x value.
 @param y The specified y value.
 */
- (NSString *)stringForX:(double)x andY:(double)y;

#pragma mark -
#pragma mark Delegates, Data Sources and Trial Key

/**
 The object that acts as the chart's delegate.

 The object must adopt the `SChartDelegate` protocol.  The `SChartDelegate` protocol provides the chart with a target to relay events to, such as when the user is zooming or other touch events. Objects that act as a delegate to the `ShinobiChart` can use these notifications to synchronise other charts or update objects with the current status of this chart.
 */
@property (nonatomic, weak, nullable) id <SChartDelegate> delegate;

/**
 The object that acts as the data source of the receiving chart.

 The object must adopt the `SChartDatasource` protocol.  The data source provides the chart with the information it needs to construct the chart object. In general, styling and event response is handled by objects implementing the `SChartDelegate` protocol - the data source has minimal impact on the look and feel of the chart.
 */
@property (nonatomic, weak, nullable) id <SChartDatasource> datasource;


#pragma mark -
#pragma mark Axes
/** The primary x-axis for this chart.

 The chart contains an array of x axes, as different series on the chart could use different axes.  The primary axis is the main one used by the chart.  If you haven't explicitly specified which axis is the primary one, this will be automatically generated by the chart.
 */
@property (nonatomic, strong, nullable) SChartAxis *xAxis;

/** The primary y-axis for this chart.

 The chart contains an array of y axes, as different series on the chart could use different axes.  The primary axis is the main one used by the chart.  If you haven't explicitly specified which axis is the primary one, this will be automatically generated by the chart.
 */
@property (nonatomic, strong, nullable) SChartAxis *yAxis;

#pragma mark - Configuring the axes
/** Adds an X-Axis for the chart
 @param newXAxis The new x axis which will be added to the chart.
 */
- (void)addXAxis:(SChartAxis *)newXAxis;

/** Adds a Y-Axis for the chart
 @param newYAxis The new y axis which will be added to the chart.
 */
- (void)addYAxis:(SChartAxis *)newYAxis;

/** Removes an X-Axis from the chart

 If this is the only x axis on the chart, it won't be removed.
 @param xAxis The axis which will be removed from the chart.
 */
- (void)removeXAxis:(SChartAxis *)xAxis;

/** Removes a Y-Axis from the chart

 If this is the only y axis on the chart, it won't be removed.
 @param yAxis The axis which will be removed from the chart.
 */
- (void)removeYAxis:(SChartAxis *)yAxis;

/** Replaces a X-Axis on the chart
 @param oldXAxis The axis which will be replaced.
 @param newXAxis The axis which will replace it.
 */
- (void)replaceXAxis:(SChartAxis *)oldXAxis withAxis:(SChartAxis *)newXAxis;

/** Replaces a Y-Axis on the chart
 @param oldYAxis The axis which will be replaced.
 @param newYAxis The axis which will replace it.
 */
- (void)replaceYAxis:(SChartAxis *)oldYAxis withAxis:(SChartAxis *)newYAxis;

/** Returns all axes associated with this chart

 A chart can contain multiple x and y axes, if the series on the chart use different axes.
 @return An array containing all the axes associated with this chart.  The x axes will be first in the array, followed by the y axes.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)allAxes;

/** Returns all Primary axes associated with this chart

 A chart can contain multiple x and y axes, if the series on the chart use different axes.  A chart will always have one primary x axis, and one primary y axis, unless it is radial.
 @return An array containing the primary axes associated with the chart.  The array will contain the primary x axis, followed by the primary y axis.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)primaryAxes;

/** Returns all Secondary axes associated with this chart

 A chart can contain multiple x and y axes, if the series on the chart use different axes.  A chart will always have one primary x axis, and one primary y axis, unless it is radial.  All the other axes on the chart are regarded as secondary.
 @return An array containing the secondary axes associated with the chart.  The array will contain the secondary x axes, followed by the secondary y axes.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)secondaryAxes;

/** Returns all X axes associated with this chart

 A chart can contain multiple x axes, if the series on the chart use different axes.  A chart will always have one primary x axis, unless it is radial.
 @return An array containing all the x axes associated with the chart.  The primary axis will be the first one in the array.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)allXAxes;

/** Returns all Y axes associated with this chart

 A chart can contain multiple y axes, if the series on the chart use different axes.  A chart will always have one primary y axis, unless it is radial.
 @return An array containing all the y axes associated with the chart.  The primary axis will be the first one in the array.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)allYAxes;

/** Returns all secondary X axes associated with this chart

 A chart can contain multiple x axes, if the series on the chart use different axes.  A chart will always have one primary x axis, unless it is radial.  All the other axes on the chart are regarded as secondary.
 @return An array containing all the secondary x axes associated with the chart.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)secondaryXAxes;

/** Returns all secondary Y axes associated with this chart

 A chart can contain multiple y axes, if the series on the chart use different axes.  A chart will always have one primary y axis, unless it is radial.  All the other axes on the chart are regarded as secondary.
 @return An array containing all the secondary y axes associated with the chart.
 */
- (NSArray SC_GENERIC(SChartAxis *) *)secondaryYAxes;

/** Returns this chart's primary X Axis

 A chart can contain multiple x axes, if the series on the chart use different axes.  A chart will always have one primary x axis, unless it is radial.
 @see `ShinobiChart.xAxis`
 */
- (nullable SChartAxis *)primaryXAxis;

/** Returns this chart's primary Y Axis

 A chart can contain multiple y axes, if the series on the chart use different axes.  A chart will always have one primary y axis, unless it is radial.
 @see `ShinobiChart.yAxis`
 */
- (nullable SChartAxis *)primaryYAxis;

/** Finds the axes associated with the chart which are linked to the specified chart series.

 This method then sets the axis pointers, which are passed in as arguments, to reference the axes which are associated with the chart series.
 @param series The chart series of interest
 @param xStore A pointer to a chart axis.  In this method, we set the pointer to reference the x axis associated with the chart series.
 @param yStore A pointer to a chart axis.  In this method, we set the pointer to reference the y axis associated with the chart series.
 @exception The chart will throw a fatal exception if it cannot find an x axis and a y axis on the chart which are linked to the specified chart series.
 */
- (void)axesForSeries:(SChartSeries *)series storeX:(SChartAxis * _Nullable * _Nonnull)xStore andStoreY:(SChartAxis * _Nullable * _Nonnull)yStore;

#pragma mark -
#pragma mark Series

/** A _readonly_ array of the `SChartSeries` objects displayed on the chart.

 Series are provided to the chart by its data source.  Once it has pulled them in from the data source and rendered them, you can query the series on the chart via this property.

 Modifying the data points in any of these series will have no effect on the data rendered in the chart.  To update it, update the chart data source, and then call `reloadData` on the chart.

 If you are reloading the data in your chart asynchronously, you will want to be notified when new data has loaded, as this will affect the series on the chart.  To do this, you should implement the `SChartDelegate` protocol, and use the `sChartWillStartLoadingData:` and the `sChartDidFinishLoadingData:` methods.

 @see `SChartSeries`
 */
@property (atomic, strong, readonly) NSArray SC_GENERIC(SChartSeries *) *series;

#pragma mark - Animation

/** The chart's animation tracker

 This class enables series to be shown or hidden using any `SChartAnimation`.
 */
@property (nonatomic, strong, readonly) SChartAnimationTracker *animationTracker;

#pragma mark -
#pragma mark Titles

/** Sets the text value of the chart title and displays in the standard position.

 See also titleLabel for the property representing the actual `SChartTitle` object.*/
@property (nonatomic, strong, nullable) NSString *title;

/** The title for the chart.

 This object is created and automatically handled through the title property. However, modifying this object will give greater control over the title attributes.*/
@property (nonatomic, strong) SChartTitle *titleLabel;

/** A BOOLean to indicate if the chart title label should reserve space at the top of the chart or overlap the canvas.

 Setting this attribute to `YES` will allow the `UILabel` to appear over the chart plot area. Setting it to `NO` will push the canvas area down and reserve space obove the chart plots for the title.  calculateTargetBounds controls the space reserved for chart objects outside of the canvas area.*/
@property (nonatomic, assign) BOOL overlapChartTitle;

/** Sets how the title centers.

 - `SChartTitleCentreOnChart` Centers the title on the full chart view.
 - `SChartTitleCentreOnPlottingArea` Centers the title on the plot area.
 - `SChartTitleCentreOnCanvas` Centers the title on the canvas.
 */
@property (nonatomic, assign) SChartTitleCentresOn titleCentresOn;

/** Where the title will appear relative to the chart */
@property (nonatomic, assign) SChartTitlePosition titlePosition;

#pragma mark -
#pragma mark Configuring a legend

/** The object that represents the chart's legend.*/
@property (nonatomic, strong) SChartLegend *legend;


#pragma mark -
#pragma mark Styling the chart

/** Applies a theme to the chart.

 A `ShinobiChart` will take all of its UI configuration - colors, line thicknesses, etc - from the `SChartTheme` object. The chart can be initially created with a theme - see `initWithFrame:usingTheme:`.  If a theme is not explicitly set on a chart, an instance of `SChartLightTheme` will be applied by default on charts running on versions of iOS prior to iOS 7, otherwise an instance of `SChartiOS7Theme` will be applied.

 This method applies the styling properties of the given theme to the chart, overwriting any changes which you have made to sub-objects on the chart.
 After this, changes made to individual objects will have precendence - for example setting the series color in the data source. To reset the styling configuration on a chart to a theme, alloc a new theme and call `applyTheme:` - this will clear all styling configuration from the chart and set it to the theme defaults.

```objective_c
    SChartTheme *chartTheme = [SChartiOS7Theme new];
    [yourChart applyTheme: chartTheme];
```
 */
- (void)applyTheme:(SChartTheme *)theme;

/** The background color of the _canvas area_ where the axes and plots are drawn.

 This area does not include any titles and legends etc. To set the background color of the whole chart area use `setBackgroundColor`.

 By default, this property is set to `clearColor`. */
@property (nullable, nonatomic, strong) UIColor *canvasAreaBackgroundColor;

/** The background color of the _plot area_ where the series are drawn.

 To set the background color of the whole chart area use `backgroundColor` - also see `canvasAreaBackgroundColor`.

 By default, this property is set to `clearColor`. */
@property (nullable, nonatomic, strong) UIColor *plotAreaBackgroundColor;

/** The color of the border around the _plot area_ where the series are drawn.

 To set the border color of the whole chart area use `borderColor`.

 By default, this property is set to `clearColor`. */
@property (nullable, nonatomic, strong) UIColor *plotAreaBorderColor;

/** The thickness of the border around the _plot area_ where the series are drawn.

 To set the border thickness of the whole chart area use `borderThickness`.

 By default, this property is set to `1.0f`  .*/
@property (nonatomic, assign) CGFloat plotAreaBorderThickness;

/** The color of the border around the chart view.

 Default value is `clearColor`.*/
@property (nullable, nonatomic, strong) UIColor *borderColor;

/** The thickness of the border chart view.

 Default value is `1.0f`.*/
@property (nullable, nonatomic, strong) NSNumber *borderThickness;


#pragma mark -
#pragma mark Displaying a crosshair

/** The object displayed after a _tap-and-hold_ gesture on the chart

 The default crosshair implementation will draw a target cirle with axis markers and also display a tooltip. To customize, set this property to an object conforming to the `SChartCrosshair` protocol. */
@property (nonatomic, strong, nullable) id<SChartCrosshair> crosshair;

#pragma mark -
#pragma mark Chart Gesture Options

/** A reference to the canvas object of the chart

 The chart canvas is responsible for drawing all of the axes and series on a chart.
 */
@property (nonatomic, readonly) SChartCanvas *canvas;

/** The chart's gesture manager

 This class holds the gestures used on the chart, providing access should an
 extra responder be required for one of the chart's gestures.
 */
@property (nonatomic, strong, readonly) SChartGestureManager *gestureManager;

#pragma mark -
#pragma mark Initialization

/** Initialise a chart object with a specified frame.

 As we haven't specified a theme, the default one is used.  This is `SChartLightTheme`.

 @param frame The frame to give the new chart.
 @return An initialized chart object or `nil` if the chart couldn't be created.
 */
- (id)initWithFrame:(CGRect)frame;

/** Initialise the chart object with the specified frame and the specified theme
 @param frame The frame to give the new chart.
 @param theme The theme to use to style the new chart.
 @return An initialized chart object or `nil` if the chart couldn't be created.
 */
- (id)initWithFrame:(CGRect)frame withTheme:(nullable SChartTheme *)theme;

/** Initialise the chart object with the specified frame and axes

 As we haven't specified a theme, the default one is used.  This is SChartLightTheme.  In this method, we specify the types of axes which we would like on our chart.  The init method will create an axis of this type, and set it as the primary axis on the chart.  The chart will contain one x axis and one y axis when it is created.  We can then add more axes if required.

 @param frame The frame to give the new chart.
 @param xAxisType The type of the primary x axis on the chart.
 @param yAxisType The type of the primary y axis on the chart.
 @return An initialized chart object or `nil` if the chart couldn't be created.
 */
- (id)initWithFrame:(CGRect)frame withPrimaryXAxisType:(SChartAxisType)xAxisType withPrimaryYAxisType:(SChartAxisType)yAxisType;

/** Initialise the chart object with the specified frame, theme and axes

 In this method, we specify the types of axes which we would like on our chart.  The init method will create an axis of this type, and set it as the primary axis on the chart.  The chart will contain one x axis and one y axis when it is created.  We can then add more axes if required.

 @param frame The frame to give the new chart.
 @param theme The theme to use to style the chart.
 @param xAxisType The type of the primary x axis on the chart.
 @param yAxisType The type of the primary y axis on the chart.
 @return An initialized chart object or `nil` if the chart couldn't be created.
 */
- (id)initWithFrame:(CGRect)frame withTheme:(nullable SChartTheme *)theme withPrimaryXAxisType:(SChartAxisType)xAxisType withPrimaryYAxisType:(SChartAxisType)yAxisType;


#pragma mark -
#pragma mark Data and Reloading

/** Reloads the data points for the chart.

 When the data provided by the data source changes, we use this method to tell the chart to reload.  The data is reloaded during the next draw cycle.  This method doesn't redraw the chart, for that you can call either `redrawChart` or `redrawChartIncludePlotArea:` after the data has been reloaded.

 This method reloads the data on the main thread.  If you wish to load data asynchronously, you should set the `loadDataInBackground` property to `YES` before you call this method.
 @see `loadDataInBackground`
 */
- (void)reloadData;

/** When set to `YES`, the chart will load its data on a background thread.  Otherwise, the chart will load its data on the main UI thread.

 By default, this property is set to `NO`. If the chart is loading its data asynchronously, it will pop up an activity indicator while the data is loading. See `loadingIndicator` for more information on this.
 */
@property (nonatomic, assign) BOOL loadDataInBackground;

/** This view will be displayed whilst an asynchronous data reload is in progress. By default it is a `UIActivityIndicatorView`, but can be assigned any `UIView` based class – such as an `SEssentialsActivityIndicator`, `UIImageView` etc.  To support animation of the view, it may also conform to the `SChartActivityIndicator` protocol and implement its animation methods.
 */
@property (nullable, nonatomic, strong) UIView *loadingIndicator;

/** Notifies the chart that the specified number of data points are available to be appended to the end of the specified chart series.

 More information about using this method can be found in our tutorial [Data streaming, crosshairs and custom tooltips in ShinobiCharts](http://www.shinobicontrols.com/blog/posts/2013/12/04/data-streaming,-crosshairs-and-custom-tooltips-in-shinobicharts).

 @param numberOfDataPoints  The number of data points which are available to be appended to the end of the series.
 @param seriesIndex The index of the series which should append the new data.
 */
- (void)appendNumberOfDataPoints:(NSInteger)numberOfDataPoints toEndOfSeriesAtIndex:(NSInteger)seriesIndex
NS_SWIFT_NAME(append(numberOfDataPoints:toEndOfSeriesAtIndex:));

/** Notifies the chart that the specified number of data points are available to be prepended to the start of the specified chart series.

 @param numberOfDataPoints The number of data points which are available to be prepended to the start of the series.
 @param seriesIndex The index of the series to which the new data should be prepended.
 */
- (void)prependNumberOfDataPoints:(NSInteger)numberOfDataPoints toStartOfSeriesAtIndex:(NSInteger)seriesIndex
NS_SWIFT_NAME(prepend(numberOfDataPoints:toStartOfSeriesAtIndex:));

/** Notifies the chart that the specified number of data points should be removed from the start of the specified chart series.

 @param numberOfDataPoints The number of data points which should be removed from the start of the series.
 @param seriesIndex The index of the series which should append the new data.
 */
- (void)removeNumberOfDataPoints:(NSInteger)numberOfDataPoints fromStartOfSeriesAtIndex:(NSInteger)seriesIndex
NS_SWIFT_NAME(remove(numberOfDataPoints:fromStartOfSeriesAtIndex:));

/** Update the canvas to allow for axes, titles, and legend. */
- (void)updateCanvasSize;

/** Tells the chart to redraw itself

 The chart will redraw itself during the next draw cycle.  This does not affect the data in the chart.  If the data provided by the data source has changed, then you should call `reloadData` to refresh the data in the chart.

 @param includePlotArea `YES` if the chart needs to redraw the data for its series, which is done in the chart plot area.
 */
- (void)redrawChartIncludePlotArea:(BOOL)includePlotArea;

/** This ensures all pending OpenGL operations are flushed to the graphics card, preventing issues where an App may be put in the background and attempt to invoke OpenGL commands, causing the App to be signalled/killed.
 */
- (void)flushPendingGLOperations;

/** This allows the user to prevent our OpenGL operations from initialising OpenGL objects if the application is about to be put in the background.

 @param enteringBackground `YES` if the application will go to the background. `NO` if the application will go to the foreground.
 */
-(void)setIsEnteringBackground:(BOOL)enteringBackground;

#pragma mark -
#pragma mark Interaction

/** Returns a string representing the given x and y double values on the specified chart axes

 This method queries each axis for a string which represents the given value, then concatenates them together to give a single string.  The x value is displayed before the y value.

 This method is commonly used for displaying the tooltip on the chart crosshair.

 @param fx The value on the x axis.
 @param fy The value on the y axis.
 @param xAxis The x axis on the chart with which the x value is associated.
 @param yAxis The y axis on the chart with which the y value is associated.
 @return A string representing the given x and y values on the specified chart axes.
 */
-(NSString *)stringForX:(double)fx andY:(double)fy usingXAxis:(SChartAxis *)xAxis andYAxis:(SChartAxis *)yAxis;

/** Returns a string representing the given x and y double values in the specified chart series

 This method queries the series for the string representation of the given x and y values.  It then concatenates those strings together.  The x value is displayed before the y value.

 This method is commonly used for displaying the tooltip on the chart crosshair.

 @param fx The value on the x axis.
 @param fy The value on the y axis.
 @param series The chart series with which the values are associated
 @return A string representing the given double values in the specified chart series.
 */
-(NSString *)stringForX:(double)fx andY:(double)fy usingSeries:(SChartSeries *)series;

/** Returns a string representing the given x and y values in the specified chart series

 This method queries the series for the string representation of the given x and y values.  It then concatenates those strings together.  The x value is displayed before the y value.

 This method is commonly used for displaying the tooltip on the chart crosshair.
 @param fx The value on the x axis.
 @param fy The value on the y axis.
 @param series The chart series with which the values are associated.
 @return A string representing the given values in the specified chart series.
 */
-(NSString *)stringForIdX:(id)fx andIdY:(id)fy usingSeries:(SChartSeries *)series;

/** Returns whether the specified chart point is currently visible on the chart
 @param point The point of interest on the chart.
 @param series The chart series which contains the point.
 @return `YES` if the specified point is visible on the chart.
 */
-(BOOL)pointIsVisible:(SChartPoint)point onSeries:(SChartSeries *)series;

#pragma mark -
#pragma mark Annotations

/** An array of all annotations on the chart.

 @note This is a Premium feature
 */
@property (nonatomic, strong, readonly) NSArray SC_GENERIC(SChartAnnotation *) *annotations;

/** Add an annotation view to be displayed on the chart plot area

 @note This is a Premium feature
 @param newAnnotation The new annotation to add to the chart.
 */
- (void)addAnnotation:(SChartAnnotation *)newAnnotation;

/** Replace an annotation on the chart with a new one

 Annotations are held in a chart within an array. This method allows you to replace one of those annotations with the new one you have specified.

 @note This is a Premium feature
 @param index The index of the existing annotation within the array which the chart holds.
 @param newAnnotation The new annotation which you will replace it with.
 */
- (void)replaceAnnotationAtIndex:(NSInteger)index withAnnotation:(SChartAnnotation *)newAnnotation;

/** Remove an annotation from the chart

 @note This is a Premium feature
 @param annotation The annotation to remove.
 */
-(void)removeAnnotation:(SChartAnnotation *)annotation;

/** Remove all annotations from the chart

 @note This is a Premium feature
 */
-(void)removeAllAnnotations;

@end

NS_ASSUME_NONNULL_END