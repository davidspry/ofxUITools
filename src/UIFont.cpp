//  ofxUITools
//  Created by David Spry on 27/1/21.

#include "UIFont.hpp"

UIFont::UIFont() noexcept
{
    fontType = UIFontType::BMP;
    ttf = nullptr;
}

UIFont::UIFont(const char * filepath, int pointSize) noexcept(false)
{
    fontType = UIFontType::TTF;
    setTrueTypeFont(filepath, pointSize);
}

void UIFont::setTrueTypeFont(const char * filepath, int pointSize) noexcept(false)
{
    fontType = UIFontType::TTF;

    ttf = UIFontLibrary::get(filepath, pointSize);
}

float UIFont::getLineHeight() const noexcept
{
    switch (fontType)
    {
        case UIFontType::TTF:
        {
            return ttf->getLineHeight() * 0.75f;
        }

        case UIFontType::BMP:
        {
            constexpr float fontSize = 8.0f;
            constexpr float leading  = 1.7f;
            return fontSize * leading - 1.0f;
        }
    }
}

const ofRectangle UIFont::getStringBoundingBox(std::string string, int x, int y)
{
    switch (fontType)
    {
        case UIFontType::TTF:
        {
            ofRectangle box = ttf->getStringBoundingBox(string, x, y);
            const int lines = numberOfLines(string);
            const int linht = getLineHeight();
            const int height = lines * linht;

            box.setPosition(x, y);
            box.translateY(-linht);
            box.setHeight(height);
            return box;
        }

        case UIFontType::BMP:
        {
            constexpr int dx = +0;
            constexpr int dy = -1;
            return ofBitmapFont().getBoundingBox(string, x + dx, y + dy);
        }
    }
}

void UIFont::drawString(std::string_view string, int x, int y) const noexcept
{
    switch (fontType)
    {
        case UIFontType::TTF:
        {
            constexpr int dx = +0;
            constexpr int dy = -3;
            return drawStringTTF(string, x + dx, y + dy);
        }

        case UIFontType::BMP:
        {
            constexpr int dx = +0;
            constexpr int dy = -1;
            return drawStringBMP(string, x + dx, y + dy);
        }
    }

}

