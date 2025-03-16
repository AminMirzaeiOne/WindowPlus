#pragma once

using namespace System;

namespace WindowPlus {
    namespace Controls {
        public interface class IAnimationProvider {
        public:
            // Basic animation properties
            virtual bool IsAnimationEnabled() = 0;
            
            // Try to start an animation - returns false if WPAnimation is not available
            virtual bool TryStartAnimation(String^ animationName, Object^ target, Object^ properties) = 0;
            
            // Try to stop an animation
            virtual bool TryStopAnimation(String^ animationName, Object^ target) = 0;
        };

        // Default implementation when WPAnimation is not available
        public ref class DefaultAnimationProvider : public IAnimationProvider {
        public:
            virtual bool IsAnimationEnabled() override {
                return false;
            }

            virtual bool TryStartAnimation(String^ animationName, Object^ target, Object^ properties) override {
                return false;
            }

            virtual bool TryStopAnimation(String^ animationName, Object^ target) override {
                return false;
            }
        };
    }
} 