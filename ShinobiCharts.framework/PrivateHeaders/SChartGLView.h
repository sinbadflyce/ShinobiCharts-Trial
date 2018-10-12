//
//  SChartGLView.h
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@class SChartSeries;
@class SChartAnimation;
@class SChartAnimationTracker;

@interface SChartGLView : UIView {

@private
    
    CAEAGLLayer* _eaglLayer;
    UIColor *areaColor;

    BOOL needsResize;
    BOOL frameBufferInitialised;
    
    GLuint _framebuffer;
    GLuint _colorRenderBuffer;
    GLuint _depthStencilRenderBuffer;
    
    GLuint _framebufferMSAA;
    GLuint _colorRenderBufferMSAA;
    
    NSMutableDictionary *userTextures;
    
}

#pragma mark Public

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
-(id)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
-(id)initWithFrame:(CGRect)frame animationTracker:(SChartAnimationTracker *)tracker NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) CGRect glBounds;

- (float) glWidth;
- (float) glHeight;

@property (nonatomic, strong) NSMutableArray *allSeries;
@property (nonatomic, retain) NSMutableDictionary *userTextures;

-(GLuint) getFramebuffer;
-(GLuint) getColorRenderBuffer;

@property (nonatomic, strong) EAGLContext *context;
-(CAEAGLLayer *) getEAGLLayer;

@property (nonatomic, assign) BOOL isEnteringBackground;

- (void)reset;

// @name beginRender */
// Clears the canvas and buffers and resets the buffers */
- (void)beginRenderWithReloadedData:(BOOL)reloadedData;

// @name endRender */
// Displays objects drawn since beginRender was last called
- (void)endRender;

- (void)flushPendingGLOperations;

// Resize the render buffer and recalculate the viewport
- (void)resize;

#pragma mark -
#pragma mark Private

@property (nonatomic, retain) UIColor *areaColor;

// @name setupLayer */
// Sets up a CAEAGLLayer */
- (void)setupLayerWithBackgroundColor:(UIColor*)backgroundColor;
-(void)addSeries:(SChartSeries *)s;


#pragma mark -

@end

