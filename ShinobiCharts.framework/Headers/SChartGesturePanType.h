/** Defines gesture methods for zooming a chart
 
 - `SChartGesturePanTypeNone`: Disables pan gestures on the chart.
 - `SChartGesturePanTypePanPinch`: Use pinch zoom gestures.
 - `SChartGesturePanTypeBoxDraw`: Use touch gestures to generate a box on the chart. The chart will animate the zoom level to display the area marked by the box.
 */
typedef NS_ENUM(NSInteger, SChartGesturePanType) {
    SChartGesturePanTypeNone,
    SChartGesturePanTypePanPinch,
    SChartGesturePanTypeBoxDraw
};
