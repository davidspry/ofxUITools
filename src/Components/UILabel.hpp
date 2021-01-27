//  ofxUITools
//  Created by David Spry on 27/1/21.

#ifndef UILABEL_H
#define UILABEL_H

#include "ofMain.h"
#include "UIFont.hpp"
#include "Utilities.h"
#include "UIConstants.h"
#include "UIComponent.hpp"

class UILabel: public UIComponent
{
public:
    UILabel();
    
    /// @brief Construct a Label with the given text.
    /// @param text The text that should be drawn on the Label.
    /// @note  The Label will shrink to fit the given text.
    /// @note  The Label will use the default bitmap font by default.

    UILabel(std::string_view text);

public:
    void draw() override;

    /// @brief Match the size of the label to the size of the label's text

    void shrinkToFitText() noexcept;

    inline void setSize(const float width, const float height) override
    {
        UIComponent::setSize(width, height);

        setShouldRedraw();
    }
    
    inline void setSizeFromCentre(const float width, const float height) override
    {
        UIComponent::setSizeFromCentre(width, height);

        setShouldRedraw();
    }
    
    inline void setMargins(const int top, const int left, const int right, const int bottom) override
    {
        UIComponent::setMargins(top, left, right, bottom);
        
        setShouldRedraw();
    }

public:
    /// @brief Set the label's text component.
    /// @param string The desired text.
 
    inline void setText(std::string_view string) noexcept
    {
        text = string;

        setShouldRedraw();
    }

    /// @brief Get the label's text component.

    inline std::string_view getText() const noexcept
    {
        return {text};
    }
    
    /// @brief Indicate whether the label should fill its background with its background colour or not.
    /// @param fillBackground Whether the label should fill its background with its background colour or not.

    inline void setShouldFillBackground(bool fillBackground) noexcept
    {
        shouldFillBackground = fillBackground;

        setShouldRedraw();
    }
    
    /// @brief Set the label's text colour.
    /// @param colour The desired text colour.

    inline void setTextColour(ofColor colour) noexcept
    {
        textColour = colour;
    }
    
    /// @brief Set the label's background fill colour.
    /// @param backgroundColour The desired fill colour.

    inline void setBackgroundFillColour(ofColor backgroundColour) noexcept
    {
        backgroundFillColour = backgroundColour;
    }
    
    /// @brief Set the label's font.
    /// @param filepath The filepath of the TrueTypeFont font file, relative to Ensemble's 'data' folder.
    /// @param pointSize The desired point size of the font.

    inline void setFont(const char * filepath, int pointSize) noexcept(false)
    {
        font.setTrueTypeFont(filepath, pointSize);
        
        setShouldRedraw();
    }
    
    /// @brief Use the default bitmap font as the label's font.

    inline void setUseBitmapFont() noexcept
    {
        font.setBitmapFont();
        
        setShouldRedraw();
    }
    
    /// @brief Set the label text's alignment in terms of its horizontal and veritcal positions.
    /// @param horizontal The desired horizontal position for the label's text.
    /// @param vertical The desired vertical position for the label's text.

    void setTextAlignment(HorizontalAlignment horizontal, VerticalAlignment vertical) noexcept;

private:
    /// @brief Whether the label's background should be filled with the component's background colour or not.
    
    bool shouldFillBackground = false;

private:
    /// @brief The label's text component.

    std::string text;
    
    /// @brief The label's font.
    
    UIFont font;
    
    /// @brief The origin point of the label's text.
    /// @note  ofTrueTypeFont uses the bottom-left corner as the origin point.

    UIPoint<int> textOrigin;
    
    /// @brief The vertical alignment of the label's text.
    
    VerticalAlignment verticalTextAlignment = VerticalAlignment::Centre;
    
    /// @brief The horizontal alignment of the label's text.
    
    HorizontalAlignment horizontalTextAlignment = HorizontalAlignment::Centre;
    
    /// @brief The label's text colour.
    
    ofColor textColour = ofColor::white;

    /// @brief The label's background fill colour.
    
    ofColor backgroundFillColour = {50, 85, 164};
};

#endif
