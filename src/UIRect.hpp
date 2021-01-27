//  ofxUITools
//  Created by David Spry on 27/1/21.

#ifndef UIRECT_H
#define UIRECT_H

#include "ofMain.h"
#include "UISize.h"
#include "UIPoint.h"
#include "UIMargins.h"
#include "UIConstants.h"

/// @brief A rectangular component that can be successively subdivided into smaller rectangles.

class UIRect: public ofRectangle
{
public:
    /// @brief Construct a UIRect at position (0, 0) with size (0, 0).

    UIRect();
    
    /// @brief Construct a UIRect at position (x, y) with size (width, height).
    /// @param x The x-coordinate of the desired origin point.
    /// @param y The y-coordinate of the desired origin point.
    /// @param width The desired width.
    /// @param height The desired height.
    
    UIRect(float x, float y, float width, float height);
    
    /// @brief Construct a UIRect with the given size at origin point zero.
    /// @param size The desired size.
    
    template <typename T>
    UIRect(const UISize<T>& size):
    ofRectangle(0, 0, size.w, size.h)
    {
        
    }

    /// @brief Construct a UIRect at the given origin point with the given size.
    /// @param origin The desired origin point.
    /// @param size The desired size.

    template <typename T, typename M>
    UIRect(const UIPoint<T>& origin, const UISize<M>& size):
    ofRectangle(origin.x, origin.y, size.w, size.h)
    {
        
    }

public:
    /// @brief Get the size of the UIRect.

    [[nodiscard]] const UISize<int> getSize() const noexcept;
    
    /// @brief Return a copy of the UIRect translated to the given origin point.
    /// @param x The x-coordinate of the desired origin point for the returned UIRect.
    /// @param y The y-coordinate of the desired origin point for the returned UIRect.

    [[nodiscard]] UIRect translatedTo(int x, int y) noexcept;
    
    /// @brief Remove a margin from the edges of the UIRect.
    /// @param fromTop The desired number of pixels to remove from the top.
    /// @param fromLeft The desired number of pixels to remove from the left.
    /// @param fromRight The desired number of pixels to remove from the right.
    /// @param fromBottom The desired number of pixels to remove from the bottom.
    /// @throw An exception will be thrown in the case where any of the amounts to trim is negative.

    UIRect& trim(int fromTop, int fromLeft, int fromRight, int fromBottom) noexcept(false);
    
    /// @brief Remove a rectangle from the top of the UIRect.
    /// @param amountToRemove The desired number of pixels to remove from the top.
    /// @throw An exception will be thrown in the case where the amount to trim is negative.

    UIRect& trimFromTop(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the bottom of the UIRect.
    /// @param amountToRemove The desired number of pixels to remove from the bottom.
    /// @throw An exception will be thrown in the case where the amount to trim is negative.

    UIRect& trimFromBottom(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the left of the UIRect.
    /// @param amountToRemove The desired number of pixels to remove from the left.
    /// @throw An exception will be thrown in the case where the amount to trim is negative.

    UIRect& trimFromLeft(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the right of the UIRect.
    /// @param amountToRemove The desired number of pixels to remove from the right.
    /// @throw An exception will be thrown in the case where the amount to trim is negative.

    UIRect& trimFromRight(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the top of the UIRect and return it.
    /// @param amountToRemove The desired number of pixels to remove from the top.
    /// @throw An exception will be thrown in the case where the amount to remove is not positive.

    [[nodiscard]] UIRect removeFromTop(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the bottom of the UIRect and return it.
    /// @param amountToRemove The desired number of pixels to remove from the bottom.
    /// @throw An exception will be thrown in the case where the amount to remove is not positive.

    [[nodiscard]] UIRect removeFromBottom(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the left of the UIRect and return it.
    /// @param amountToRemove The desired number of pixels to remove from the left.
    /// @throw An exception will be thrown in the case where the amount to remove is not positive.

    [[nodiscard]] UIRect removeFromLeft(int amountToRemove) noexcept(false);
    
    /// @brief Remove a rectangle from the right of the UIRect and return it.
    /// @param amountToRemove The desired number of pixels to remove from the right.
    /// @throw An exception will be thrown in the case where the amount to remove is not positive.

    [[nodiscard]] UIRect removeFromRight(int amountToRemove) noexcept(false);
    
    /// @brief Subdivide the UIRect into some number of smaller rectangles along the given axis.
    /// @param axis The axis along which to subdivide the UIRect
    /// @param subdivisions The number of subdivisions to compute
    /// @throw An exception will be thrown in the case where the requested number of subdivisions is not positive.

    [[nodiscard]] std::vector<UIRect> subdivide(Axis axis, int subdivisions) const noexcept(false);

public:
    /// @brief Subtract the given margins from the UIRect and return the result.
    /// @param margins The margins to be subtracted from the UIRect.

    template <typename T>
    [[nodiscard]] inline UIRect subtractMargins(UIMargins<T> margins) noexcept
    {
        UIRect r = *(this);
        
        r.translateY(margins.t);
        r.translateX(margins.l);
        r.setWidth(width - margins.l - margins.r);
        r.setHeight(height - margins.t - margins.b);

        return r;
    }
};

#endif
