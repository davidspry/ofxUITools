//  ofxUITools
//  Created by David Spry on 27/1/21.

#ifndef UISIZE_H
#define UISIZE_H

#include <type_traits>

/// @brief A two-component struct representing the dimensions of a 2D rectangular object.

template <typename T>
struct UISize
{
    union
    {
        T w;
        T width;
    };
    
    union
    {
        T h;
        T height;
    };
    
    UISize(T width  = static_cast<T>(0),
           T height = static_cast<T>(0))
    {
        static_assert(std::is_arithmetic<T>::value, "The given type must be numeric.");

        this->w = width;
        this->h = height;
    }
    
    void set(T width, T height)
    {
        this->w = width;
        this->h = height;
    }
};

#endif
