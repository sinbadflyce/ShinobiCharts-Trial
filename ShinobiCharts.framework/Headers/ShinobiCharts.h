//
//  ShinobiCharts.h
//  ShinobiCharts
//
//

#import <Foundation/Foundation.h>
#import "ShinobiChart.h"
#import "ShinobiHeaderMacros.h"

@class SChartTheme;

NS_ASSUME_NONNULL_BEGIN

/** A utility class which allows you to set themes and trialKeys for all the `ShinobiChart` instances in your app, rather than having to configure each independently.
 
 This is best done early on, before any charts are created.

 */
@interface ShinobiCharts : NSObject

/** The trial key for all `ShinobiChart` instances in your app.
 */
@property (class, nonatomic, strong) NSString *trialKey;

/** Returns a string describing the version of the Charts framework being used.
 
 This includes a version number, the type of framework (Premium, Standard, or Trial) and the date upon which the version was released.
*/
+(NSString *)getInfo;

@end

NS_ASSUME_NONNULL_END

