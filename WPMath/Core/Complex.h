#pragma once

using namespace System;

namespace WindowPlus {
    namespace Math {
        /// <summary>
        /// Represents a complex number
        /// </summary>
        public value class Complex {
        private:
            double real;
            double imaginary;

        public:
            /// <summary>
            /// Creates a new complex number
            /// </summary>
            Complex(double real, double imaginary) {
                this->real = real;
                this->imaginary = imaginary;
            }

            /// <summary>
            /// Gets the real part
            /// </summary>
            property double Real {
                double get() { return real; }
            }

            /// <summary>
            /// Gets the imaginary part
            /// </summary>
            property double Imaginary {
                double get() { return imaginary; }
            }

            /// <summary>
            /// Gets the magnitude (absolute value)
            /// </summary>
            property double Magnitude {
                double get() {
                    return Math::Sqrt(real * real + imaginary * imaginary);
                }
            }

            /// <summary>
            /// Gets the phase angle in radians
            /// </summary>
            property double Phase {
                double get() {
                    return Math::Atan2(imaginary, real);
                }
            }

            /// <summary>
            /// Gets the complex conjugate
            /// </summary>
            Complex Conjugate() {
                return Complex(real, -imaginary);
            }

            /// <summary>
            /// Adds two complex numbers
            /// </summary>
            static Complex operator+(Complex a, Complex b) {
                return Complex(a.real + b.real, a.imaginary + b.imaginary);
            }

            /// <summary>
            /// Subtracts two complex numbers
            /// </summary>
            static Complex operator-(Complex a, Complex b) {
                return Complex(a.real - b.real, a.imaginary - b.imaginary);
            }

            /// <summary>
            /// Multiplies two complex numbers
            /// </summary>
            static Complex operator*(Complex a, Complex b) {
                return Complex(
                    a.real * b.real - a.imaginary * b.imaginary,
                    a.real * b.imaginary + a.imaginary * b.real
                );
            }

            /// <summary>
            /// Divides two complex numbers
            /// </summary>
            static Complex operator/(Complex a, Complex b) {
                double denominator = b.real * b.real + b.imaginary * b.imaginary;
                return Complex(
                    (a.real * b.real + a.imaginary * b.imaginary) / denominator,
                    (a.imaginary * b.real - a.real * b.imaginary) / denominator
                );
            }

            /// <summary>
            /// Raises e to the complex power
            /// </summary>
            static Complex Exp(Complex z) {
                double expReal = Math::Exp(z.real);
                return Complex(
                    expReal * Math::Cos(z.imaginary),
                    expReal * Math::Sin(z.imaginary)
                );
            }

            /// <summary>
            /// Calculates the natural logarithm of a complex number
            /// </summary>
            static Complex Log(Complex z) {
                return Complex(
                    Math::Log(z.Magnitude),
                    z.Phase
                );
            }

            /// <summary>
            /// Raises a complex number to a power
            /// </summary>
            static Complex Pow(Complex base, Complex exponent) {
                return Exp(Log(base) * exponent);
            }

            /// <summary>
            /// Converts the complex number to string representation
            /// </summary>
            virtual String^ ToString() override {
                if (imaginary == 0)
                    return real.ToString();
                else if (real == 0)
                    return imaginary.ToString() + "i";
                else if (imaginary < 0)
                    return String::Format("{0}{1}i", real, imaginary);
                else
                    return String::Format("{0}+{1}i", real, imaginary);
            }
        };
    }
} 