//  ofxUITools
//  Created by David Spry on 27/1/21.

#include "UIComponent.hpp"

UIComponent::UIComponent(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
    setSize(width, height);
    setPositionWithOrigin(x, y);
}

UIComponent::~UIComponent()
{
    
}

void UIComponent::setBounds(UIRect bounds) noexcept
{
    const auto origin = bounds.getTopLeft();

    setSize(bounds.width, bounds.height);

    setPositionWithOrigin(origin.x, origin.y);
}

void UIComponent::setPositionWithOrigin(const int x, const int y)
{
    origin.x = x;
    origin.y = y;
    centre.x = x + static_cast<int>((float) size.w * 0.5f);
    centre.y = y + static_cast<int>((float) size.h * 0.5f);
}

void UIComponent::setPositionWithCentre(const int x, const int y)
{
    centre.x = x;
    centre.y = y;
    origin.x = x - static_cast<int>((float) size.w * 0.5f);
    origin.y = y - static_cast<int>((float) size.h * 0.5f);
}

void UIComponent::translatePosition(const int x, const int y)
{
    setPositionWithCentre(centre.x - x, centre.y - y);
}

void UIComponent::setSize(const float width, const float height)
{
    size.w = static_cast<int>(width);
    size.h = static_cast<int>(height);
    setPositionWithOrigin(origin);

    setShouldRedraw();
}

void UIComponent::setSizeFromCentre(const float width, const float height)
{
    size.w = static_cast<int>(width);
    size.h = static_cast<int>(height);
    setPositionWithCentre(centre);

    setShouldRedraw();
}

void UIComponent::setMargins(const int top, const int left, const int right, const int bottom)
{
    margins.t = top;
    margins.l = left;
    margins.r = right;
    margins.b = bottom;

    setShouldRedraw();
}

