//  ofxUITools
//  Created by David Spry on 27/1/21.

#ifndef UICOLOURSCHEME_H
#define UICOLOURSCHEME_H

#include "ofMain.h"

/// @brief A colour scheme intended to be used by a `UIComponent`.

struct UIColourScheme
{
    ofColor backgroundColour;
    ofColor foregroundColour;
    ofColor secondaryColour;
    ofColor accentColour;
    ofColor textColour;
    
    /// @brief Construct a colour scheme by specifying each colour.
    /// @param background A background colour
    /// @param foreground A foreground colour
    /// @param secondary A secondary colour
    /// @param accent An accent colour
    /// @param text A text colour

    UIColourScheme(ofColor const background = ofColor::black,
                   ofColor const foreground = ofColor::white,
                   ofColor const secondary  = ofColor::gray,
                   ofColor const accent     = ofColor::blue,
                   ofColor const text       = ofColor::white)
    {
        backgroundColour = background;
        foregroundColour = foreground;
        secondaryColour  = secondary;
        accentColour     = accent;
        textColour       = text;
    }
};

#endif
