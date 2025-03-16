#pragma once

using namespace System;

namespace WindowPlus {
    namespace Math {
        /// <summary>
        /// Provides advanced vector operations
        /// </summary>
        public ref class VectorOperations {
        public:
            /// <summary>
            /// Calculates the cross product of two 3D vectors
            /// </summary>
            generic<typename T>
            where T : value class
            static Vector<T>^ CrossProduct(Vector<T>^ a, Vector<T>^ b) {
                if (a->Size != 3 || b->Size != 3)
                    throw gcnew ArgumentException("Cross product is only defined for 3D vectors");

                Vector<T>^ result = gcnew Vector<T>(3);
                result[0] = T((double)a[1] * (double)b[2] - (double)a[2] * (double)b[1]);
                result[1] = T((double)a[2] * (double)b[0] - (double)a[0] * (double)b[2]);
                result[2] = T((double)a[0] * (double)b[1] - (double)a[1] * (double)b[0]);
                return result;
            }

            /// <summary>
            /// Projects vector a onto vector b
            /// </summary>
            generic<typename T>
            where T : value class
            static Vector<T>^ Project(Vector<T>^ a, Vector<T>^ b) {
                double dotProduct = (double)a->DotProduct(b);
                double bMagnitudeSquared = Math::Pow(b->Magnitude(), 2);
                double scalar = dotProduct / bMagnitudeSquared;

                Vector<T>^ result = gcnew Vector<T>(a->Size);
                for (int i = 0; i < a->Size; i++) {
                    result[i] = T(scalar * (double)b[i]);
                }
                return result;
            }

            /// <summary>
            /// Calculates the angle between two vectors in radians
            /// </summary>
            generic<typename T>
            where T : value class
            static double AngleBetween(Vector<T>^ a, Vector<T>^ b) {
                double dotProduct = (double)a->DotProduct(b);
                double magnitudeProduct = a->Magnitude() * b->Magnitude();
                return Math::Acos(dotProduct / magnitudeProduct);
            }

            /// <summary>
            /// Checks if two vectors are orthogonal (perpendicular)
            /// </summary>
            generic<typename T>
            where T : value class
            static bool AreOrthogonal(Vector<T>^ a, Vector<T>^ b) {
                return Math::Abs((double)a->DotProduct(b)) < 1e-10;
            }

            /// <summary>
            /// Calculates the distance between two vectors
            /// </summary>
            generic<typename T>
            where T : value class
            static double Distance(Vector<T>^ a, Vector<T>^ b) {
                if (a->Size != b->Size)
                    throw gcnew ArgumentException("Vectors must have the same dimension");

                double sumSquared = 0;
                for (int i = 0; i < a->Size; i++) {
                    double diff = (double)a[i] - (double)b[i];
                    sumSquared += diff * diff;
                }
                return Math::Sqrt(sumSquared);
            }
        };
    }
} 