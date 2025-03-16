#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace WindowPlus {
    namespace Math {
        /// <summary>
        /// Represents a mathematical vector with generic type
        /// </summary>
        generic<typename T>
        where T : value class
        public ref class Vector {
        private:
            array<T>^ elements;

        public:
            /// <summary>
            /// Creates a new vector with specified size
            /// </summary>
            Vector(int size) {
                elements = gcnew array<T>(size);
            }

            /// <summary>
            /// Creates a vector from array
            /// </summary>
            Vector(array<T>^ data) {
                elements = gcnew array<T>(data->Length);
                Array::Copy(data, elements, data->Length);
            }

            /// <summary>
            /// Gets or sets element at specified index
            /// </summary>
            property T default[int] {
                T get(int index) {
                    if (index < 0 || index >= elements->Length)
                        throw gcnew ArgumentOutOfRangeException("index");
                    return elements[index];
                }
                void set(int index, T value) {
                    if (index < 0 || index >= elements->Length)
                        throw gcnew ArgumentOutOfRangeException("index");
                    elements[index] = value;
                }
            }

            /// <summary>
            /// Gets the size of the vector
            /// </summary>
            property int Size {
                int get() {
                    return elements->Length;
                }
            }

            /// <summary>
            /// Calculates dot product with another vector
            /// </summary>
            T DotProduct(Vector<T>^ other) {
                if (other->Size != Size)
                    throw gcnew ArgumentException("Vectors must be of same size");

                T sum = T();
                for (int i = 0; i < Size; i++)
                    sum += elements[i] * other[i];
                return sum;
            }

            /// <summary>
            /// Calculates magnitude (length) of the vector
            /// </summary>
            double Magnitude() {
                double sum = 0;
                for (int i = 0; i < Size; i++)
                    sum += (double)(elements[i] * elements[i]);
                return System::Math::Sqrt(sum);
            }

            /// <summary>
            /// Normalizes the vector
            /// </summary>
            Vector<double>^ Normalize() {
                double mag = Magnitude();
                Vector<double>^ result = gcnew Vector<double>(Size);
                for (int i = 0; i < Size; i++)
                    result[i] = (double)elements[i] / mag;
                return result;
            }
        };
    }
} 