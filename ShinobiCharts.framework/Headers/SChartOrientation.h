/** The orientation of an `SChartAxis`.
 
 - `SChartOrientationHorizontal`: The axis is an x-axis (horizontal).
 - `SChartOrientationVertical`: The axis is a y-axis (vertical).
 
 @warning With regards to radial charts, horizontal is the outer (radial) axis, and vertical is the inner (polar) axis.
 */
typedef NS_ENUM(NSInteger, SChartOrientation) {
    SChartOrientationHorizontal,
    SChartOrientationVertical
};
