/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - LGPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/




//////////
// macros
//////////

//#define FloatToFixed(a)                     ((Fixed)((float)(a) * fixed1))

#import <QuickTime/QuickTime.h>

//////////
//
// constants
//
//////////

#define kDefaultNodeID                    1                            // default node ID
#define kQTVRVersion1                    (long)1
#define kQTVRVersion2                    (long)2
#define kObjectFormat1x0DataType        FOUR_CHAR_CODE('NAVG')

#define kObjSaveMoviePrompt                "Save object movie file as:"
#define kObjSaveMovieFileName            "Untitled.mov"

// default object settings;
// a real application would let the user select these values interactively
// (perhaps by displaying a dialog box with a bunch of edit text items....)

#define kDefaultNumOfColumns            (UInt16)10
#define kDefaultNumOfRows                (UInt16)10
#define kDefaultLoopSize                (UInt16)1
#define kDefaultLoopTicks                (UInt16)0                    // for looping object: display next frame as quickly as possible    
#define kDefaultFrameDuration            (UInt16)60
#define kDefaultMovieType                (UInt16)kGrabberUI   
#define kDefaultViewStateCount            (UInt16)1
#define kDefaultDefaultViewState        (UInt16)1
#define kDefaultMouseDownViewState        (UInt16)1

// version 1.0 uses Fixed for some of its data items, while version 2.x uses Float32;
// we'll define our default settings using Float32 and, when necessary, convert to Fixed using the FloatToFixed macro defined above
#define kDefaultFieldOfView                (Float32)360.0
#define kDefaultMinFieldOfView            (Float32)8.0
#define kDefaultStartPan                (Float32)0.0    
#define kDefaultEndPan                    (Float32)360.0
#define kDefaultStartTilt                (Float32)90.0
#define kDefaultEndTilt                    (Float32)-90.0
#define kDefaultInitialPan                (Float32)0.0                // not used; we calculate the initial pan angle from the source movie's current time
#define kDefaultInitialTilt                (Float32)0.0                // not used; we calculate the initial tilt angle from the source movie's current time
#define kDefaultMouseMotionScale        (Float32)180.0    
#define kDefaultDefaultViewCenterH        (Float32)0.0    
#define kDefaultDefaultViewCenterV        (Float32)0.0    
#define kDefaultViewRate                (Float32)1.0    
#define kDefaultFrameRate                (Float32)1.0
    
#define kDefaultAnimationSettings        (UInt32)0    
#define kDefaultControlSettings            (UInt32)(kQTVRObjectWrapPanOn | kQTVRObjectWrapTiltOn | kQTVRObjectCanZoomOn | kQTVRObjectTranslationOn)    

