#pragma once

using namespace System;

namespace WindowPlus {
    namespace Math {
        /// <summary>
        /// Represents a mathematical matrix with generic type
        /// </summary>
        generic<typename T>
        where T : value class
        public ref class Matrix {
        private:
            array<T, 2>^ elements;
            int rows, cols;

        public:
            /// <summary>
            /// Creates a new matrix with specified dimensions
            /// </summary>
            Matrix(int rows, int cols) {
                this->rows = rows;
                this->cols = cols;
                elements = gcnew array<T, 2>(rows, cols);
            }

            /// <summary>
            /// Creates a matrix from 2D array
            /// </summary>
            Matrix(array<T, 2>^ data) {
                rows = data->GetLength(0);
                cols = data->GetLength(1);
                elements = gcnew array<T, 2>(rows, cols);
                Array::Copy(data, elements, data->Length);
            }

            /// <summary>
            /// Gets or sets element at specified position
            /// </summary>
            property T default[int, int] {
                T get(int row, int col) {
                    if (row < 0 || row >= rows || col < 0 || col >= cols)
                        throw gcnew ArgumentOutOfRangeException();
                    return elements[row, col];
                }
                void set(int row, int col, T value) {
                    if (row < 0 || row >= rows || col < 0 || col >= cols)
                        throw gcnew ArgumentOutOfRangeException();
                    elements[row, col] = value;
                }
            }

            /// <summary>
            /// Gets number of rows
            /// </summary>
            property int Rows {
                int get() { return rows; }
            }

            /// <summary>
            /// Gets number of columns
            /// </summary>
            property int Columns {
                int get() { return cols; }
            }

            /// <summary>
            /// Multiplies matrix by another matrix
            /// </summary>
            Matrix<T>^ Multiply(Matrix<T>^ other) {
                if (cols != other->Rows)
                    throw gcnew ArgumentException("Matrix dimensions do not match for multiplication");

                Matrix<T>^ result = gcnew Matrix<T>(rows, other->Columns);
                
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < other->Columns; j++) {
                        T sum = T();
                        for (int k = 0; k < cols; k++) {
                            sum += elements[i, k] * other[k, j];
                        }
                        result[i, j] = sum;
                    }
                }
                
                return result;
            }

            /// <summary>
            /// Transposes the matrix
            /// </summary>
            Matrix<T>^ Transpose() {
                Matrix<T>^ result = gcnew Matrix<T>(cols, rows);
                
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        result[j, i] = elements[i, j];
                    }
                }
                
                return result;
            }

            /// <summary>
            /// Creates an identity matrix of specified size
            /// </summary>
            static Matrix<T>^ Identity(int size) {
                Matrix<T>^ result = gcnew Matrix<T>(size, size);
                
                for (int i = 0; i < size; i++) {
                    result[i, i] = T(1);
                }
                
                return result;
            }
        };
    }
} 