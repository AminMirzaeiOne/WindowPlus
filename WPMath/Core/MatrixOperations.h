#pragma once

using namespace System;

namespace WindowPlus {
    namespace Math {
        /// <summary>
        /// Provides advanced matrix operations
        /// </summary>
        public ref class MatrixOperations {
        public:
            /// <summary>
            /// Calculates the determinant of a square matrix using LU decomposition
            /// </summary>
            generic<typename T>
            where T : value class
            static double Determinant(Matrix<T>^ matrix) {
                if (matrix->Rows != matrix->Columns)
                    throw gcnew ArgumentException("Matrix must be square");

                int n = matrix->Rows;
                array<double, 2>^ lu = gcnew array<double, 2>(n, n);
                array<int>^ perm = gcnew array<int>(n);
                int toggle = 1;

                // Copy matrix to working array
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        lu[i, j] = (double)matrix[i, j];

                // Initialize permutation array
                for (int i = 0; i < n; ++i)
                    perm[i] = i;

                // LU decomposition
                for (int j = 0; j < n - 1; ++j) {
                    double max = Math::Abs(lu[j, j]);
                    int piv = j;

                    for (int i = j + 1; i < n; ++i) {
                        double xij = Math::Abs(lu[i, j]);
                        if (xij > max) {
                            max = xij;
                            piv = i;
                        }
                    }

                    if (piv != j) {
                        for (int k = 0; k < n; ++k) {
                            double tmp = lu[piv, k];
                            lu[piv, k] = lu[j, k];
                            lu[j, k] = tmp;
                        }
                        int tmp = perm[piv];
                        perm[piv] = perm[j];
                        perm[j] = tmp;
                        toggle = -toggle;
                    }

                    for (int i = j + 1; i < n; ++i) {
                        lu[i, j] /= lu[j, j];
                        for (int k = j + 1; k < n; ++k)
                            lu[i, k] -= lu[i, j] * lu[j, k];
                    }
                }

                double det = toggle;
                for (int i = 0; i < n; ++i)
                    det *= lu[i, i];

                return det;
            }

            /// <summary>
            /// Calculates the inverse of a matrix if it exists
            /// </summary>
            generic<typename T>
            where T : value class
            static Matrix<double>^ Inverse(Matrix<T>^ matrix) {
                if (matrix->Rows != matrix->Columns)
                    throw gcnew ArgumentException("Matrix must be square");

                if (Math::Abs(Determinant(matrix)) < 1e-10)
                    throw gcnew ArgumentException("Matrix is singular");

                int n = matrix->Rows;
                Matrix<double>^ result = gcnew Matrix<double>(n, n);
                array<double, 2>^ augmented = gcnew array<double, 2>(n, 2 * n);

                // Create augmented matrix [A|I]
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        augmented[i, j] = (double)matrix[i, j];
                        augmented[i, j + n] = (i == j) ? 1.0 : 0.0;
                    }
                }

                // Gaussian elimination
                for (int i = 0; i < n; i++) {
                    double pivot = augmented[i, i];
                    for (int j = 0; j < 2 * n; j++)
                        augmented[i, j] /= pivot;

                    for (int k = 0; k < n; k++) {
                        if (k != i) {
                            double factor = augmented[k, i];
                            for (int j = 0; j < 2 * n; j++)
                                augmented[k, j] -= factor * augmented[i, j];
                        }
                    }
                }

                // Extract inverse from augmented matrix
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        result[i, j] = augmented[i, j + n];

                return result;
            }

            /// <summary>
            /// Calculates the rank of a matrix
            /// </summary>
            generic<typename T>
            where T : value class
            static int Rank(Matrix<T>^ matrix) {
                int m = matrix->Rows;
                int n = matrix->Columns;
                array<double, 2>^ temp = gcnew array<double, 2>(m, n);

                // Copy matrix to working array
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                        temp[i, j] = (double)matrix[i, j];

                int rank = 0;
                array<bool>^ rowUsed = gcnew array<bool>(m);

                for (int j = 0; j < n; j++) {
                    int i;
                    for (i = 0; i < m; i++) {
                        if (!rowUsed[i] && Math::Abs(temp[i, j]) > 1e-10)
                            break;
                    }

                    if (i < m) {
                        rank++;
                        rowUsed[i] = true;
                        for (int p = i + 1; p < m; p++) {
                            if (Math::Abs(temp[p, j]) > 1e-10) {
                                double factor = temp[p, j] / temp[i, j];
                                for (int k = j; k < n; k++)
                                    temp[p, k] -= factor * temp[i, k];
                            }
                        }
                    }
                }

                return rank;
            }

            /// <summary>
            /// Calculates the trace of a square matrix
            /// </summary>
            generic<typename T>
            where T : value class
            static T Trace(Matrix<T>^ matrix) {
                if (matrix->Rows != matrix->Columns)
                    throw gcnew ArgumentException("Matrix must be square");

                T sum = T();
                for (int i = 0; i < matrix->Rows; i++)
                    sum += matrix[i, i];
                return sum;
            }
        };
    }
} 