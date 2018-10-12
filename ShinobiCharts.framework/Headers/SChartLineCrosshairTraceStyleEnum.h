/** Used by `SChartLineSeriesStyle` to allow an `SChartCrosshair` to traverse a line series smoothly.
 
 Line data points my be ordered from left to right (x-value sorted) or top to bottom (y-value sorted).
 
 - `SChartLineCrosshairTraceStyleHorizontal` Line data points are ordered from left to right (x-value sorted).
 - `SChartLineCrosshairTraceStyleVertical` Line data points are ordered from top to bottom (y-value sorted).
 */
typedef NS_ENUM(NSInteger, SChartLineCrosshairTraceStyle) {
    SChartLineCrosshairTraceStyleHorizontal,
    SChartLineCrosshairTraceStyleVertical,
};
