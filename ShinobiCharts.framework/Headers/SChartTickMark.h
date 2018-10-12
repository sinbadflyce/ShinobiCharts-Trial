//
//  SChartTickMark.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SChartAxis;

NS_ASSUME_NONNULL_BEGIN

/** An object that represents each tick mark on the chart. The label for the tick mark is also managed by this class.
 
 
 @see `SChartAxis` <br/> `SChartAxisStyle` <br/> `SChartTickStyle` <br/> `SChartMajorGridlineStyle`
 
 */
@interface SChartTickMark: NSObject

#pragma mark - Initializing a new tickmark
/** Initialize a tick mark */
- (id)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Current status
/** Is this tick mark visible on the chart? 
 
 By default, this property is set to `YES`. */
@property (nonatomic) BOOL    tickEnabled;


#pragma mark - Sorting tick marks
/** Compare the X values for this tick mark */
-(NSComparisonResult)compareForXAxis:(SChartTickMark*)tm;

/** Compare the Y values for this tick mark */
-(NSComparisonResult)compareForYAxis:(SChartTickMark*)tm; 

#pragma mark - Labelling the tick mark
/** The label object to visually represent the value of this tick mark
 
 If this is `nil` then no label will be displayed. */
@property (nonatomic, retain, nullable)   UILabel *tickLabel;

/** Called when the axis wishes to remove this tick mark label.
 
 Override this to provide a custom exit routine for the label */
- (void)removeLabel;

/** Whether or not the tickmark is major 
 
 By default, this property is set to `NO`. */
@property (nonatomic)           BOOL    isMajor;

/** The origin of the tickmark in X, in pixels. */
@property (nonatomic)           CGFloat   tickMarkX;

/** The origin of the tickmark in Y, in pixels. */
@property (nonatomic)           CGFloat   tickMarkY;

/** A double representing the value of the tickmark.
 
 It is from this value that the text of the tickmark is determined.

 On an `SChartNumberAxis`, this will be the numeric value of the tick mark.
 On an `SChartDateTimeAxis`, this will be a number of seconds elapsed from the `anchorPoint` of the `SChartAxis`.
 On an `SChartCategoryAxis`, this will be the index of the category represented. */
@property (nonatomic)           double  value;

/** The `UIView` in which the tickmark is drawn.
 
 This is the view in which the 'tick' is drawn - the line between the axis and any associated ticklabel.
 Note that this view does not contain the label, gridLine, or gridStripe UIViews.
 */
@property (nonatomic, retain, nullable)   UIView  *tickMarkView;

/** The `UIView` that is the gridLine for the tickmark.
 
 This view sits underneath the plot area.
  This will be nil is gridLines are not enabled.
 */
@property (nonatomic, retain, nullable)   UIView  *gridLineView;

/** The `UIView` that is the gridStripe for the tickmark.
 
 This view sits underneath the plot area.
 This will be nil is gridStripes are not enabled.
 */
@property (nonatomic, retain, nullable)   UIView  *gridStripeView;

@end

NS_ASSUME_NONNULL_END
