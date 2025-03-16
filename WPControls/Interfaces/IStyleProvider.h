#pragma once

using namespace System;
using namespace System::Drawing;

namespace WindowPlus {
    namespace Controls {
        public interface class IStyleProvider {
        public:
            // Basic style properties that should work without WPStyles
            virtual Color GetBackColor() = 0;
            virtual Color GetForeColor() = 0;
            virtual Drawing::Font^ GetFont() = 0;
            
            // Advanced styling - returns false if WPStyles is not available
            virtual bool TryGetAdvancedStyle(String^ styleName, Object^% style) = 0;
        };

        // Default implementation when WPStyles is not available
        public ref class DefaultStyleProvider : public IStyleProvider {
        public:
            virtual Color GetBackColor() override {
                return SystemColors::Control;
            }

            virtual Color GetForeColor() override {
                return SystemColors::ControlText;
            }

            virtual Drawing::Font^ GetFont() override {
                return SystemFonts::DefaultFont;
            }

            virtual bool TryGetAdvancedStyle(String^ styleName, Object^% style) override {
                style = nullptr;
                return false;
            }
        };
    }
} 