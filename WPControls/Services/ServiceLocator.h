#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace WindowPlus {
    namespace Controls {
        public ref class ServiceLocator {
        private:
            static ServiceLocator^ instance;
            Dictionary<Type^, Object^>^ services;

            ServiceLocator() {
                services = gcnew Dictionary<Type^, Object^>();
            }

        public:
            static property ServiceLocator^ Instance {
                ServiceLocator^ get() {
                    if (instance == nullptr) {
                        instance = gcnew ServiceLocator();
                    }
                    return instance;
                }
            }

            generic<typename T> where T : ref class
            void RegisterService(T service) {
                services[T::typeid] = service;
            }

            generic<typename T> where T : ref class
            T GetService() {
                Object^ service;
                if (services->TryGetValue(T::typeid, service)) {
                    return safe_cast<T>(service);
                }
                return nullptr;
            }

            generic<typename T> where T : ref class
            T GetServiceOrDefault(T defaultService) {
                T service = GetService<T>();
                return service != nullptr ? service : defaultService;
            }
        };
    }
} 