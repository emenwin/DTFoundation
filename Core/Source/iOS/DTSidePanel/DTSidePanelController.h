//
//  DTSidePanelController.h
//  DTSidePanelController
//
//  Created by Oliver Drobnik on 15.05.13.
//  Copyright (c) 2013 Cocoanetics. All rights reserved.
//

// types of panels
typedef enum
{
	DTSidePanelControllerPanelCenter = 0,
	DTSidePanelControllerPanelLeft,
	DTSidePanelControllerPanelRight
} DTSidePanelControllerPanel;

@class DTSidePanelController;

/**
 Protocol by whiy DTSidePanelController communicates with its delegate
 */
@protocol DTSidePanelControllerDelegate <NSObject>

@optional
/**
 Asks the delegate if a presented panel can be closed. The default is to allow it, you may prevent the dragging or tap-to-close for example when showing a modal dialog.
 @param sidePanelController The side panel controller
 @param sidePanel The panel type that the user is trying to close
 @returns `YES` if the user may close a presented panel
 */
- (BOOL)sidePanelController:(DTSidePanelController *)sidePanelController shouldAllowClosingOfSidePanel:(DTSidePanelControllerPanel)sidePanel;

@end


/**
 A container view controller with a main view and one or two optional panels that appear when moving the main view to the left or right side. Having a center panel is mandatory the left and right panels are optional.
 
 If you don't set the width of the side panels then they auto-resize with the view, keeping a minimum visible portion of the center view always visible. If you set the width then they keep their width and the center view controller will be moved accordingly.
 
 Possible values for DTSidePanelControllerPanel are:
 
 - DTSidePanelControllerPanelCenter
 - DTSidePanelControllerPanelLeft,
 - DTSidePanelControllerPanelRight
 */
@interface DTSidePanelController : UIViewController

/**
 @name Showing Panels
 */

/**
 Shows the specified panel
 @param panel The panel to present
 @param animated Whether the presentation should be animated
 */
- (void)presentPanel:(DTSidePanelControllerPanel)panel animated:(BOOL)animated;


/**
 Returns the currently panel that is visible for the most part, i.e. that the user is focussing on
 */
- (DTSidePanelControllerPanel)presentedPanel;

/**
 @name Customizing Appearance
 */

/**
 Sets the display width for the given panel. The center panel is center-aligned, the left panel is left-aligned and the right panel is right-aligned. The center panel is always full width.
 @param width The width to set, or 0 to have the panel resize automatically
 @param panel The panel to set it for
 @param animated Whether the change should be animated
 */
- (void)setWidth:(CGFloat)width forPanel:(DTSidePanelControllerPanel)panel animated:(BOOL)animated;

/**
 @name Properties
 */

/**
 The view controller controlling the center panel
 */
@property (nonatomic, strong) UIViewController *centerPanelController;

/**
 The view controller controlling the panel that appears on the left side below the main view
 */
@property (nonatomic, strong) UIViewController *leftPanelController;

/**
 The view controller controlling the panel that appears on the left side below the main view
 */
@property (nonatomic, strong) UIViewController *rightPanelController;

/**
 The DTSidePanelControllerDelegate.
 */
@property (nonatomic, weak) id <DTSidePanelControllerDelegate> sidePanelDelegate;

@end
