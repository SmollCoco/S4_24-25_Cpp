#include <array>
#include <iostream>

template<typename T, int M, int N>
class Matrix;

template<typename T, int M1, int N1, int M2, int N2, bool compatible = (M1 == M2 && N1 == N2)>
class MatrixAdder {
public:
    static Matrix<T, M1, N1> add(const Matrix<T, M1, N1>& a, const Matrix<T, M2, N2>& b) {
        Matrix<T, M1, N1> result;
        for (int i = 0; i < M1; i++) {
            for (int j = 0; j < N1; j++) {
                result.set(i, j, a.get(i, j) + b.get(i, j));
            }
        }
        return result;
    }
};

// MatrixAdder specialization for incompatible dimensions
template<typename T, int M1, int N1, int M2, int N2>
class MatrixAdder<T, M1, N1, M2, N2, false> {
public:
    static Matrix<T, M1, N1> add(const Matrix<T, M1, N1>& a, const Matrix<T, M2, N2>& b) {
        std::cout << "Erreur: Dimensions incompatibles" << std::endl;
        return Matrix<T, M1, N1>(); // Return empty matrix
    }
};

template<typename T, int M, int N>
class Matrix {
    private:
        std::array<std::array<T, N>, M> matrix;
    public:
        Matrix() {}
        void set(int i, int j, const T& value) {
            matrix[i][j] = value;
        }        
        T get(int i, int j) const {
            return matrix[i][j];
        }
        template<int M2, int N2>
        Matrix<T, M, N> add(const Matrix<T, M2, N2>& other) const {
            // Static assertion to check if dimensions are compatible at compile time
            static_assert(M == M2 && N == N2, "Les dimensions des deux matrices doivent être les mêmes pour l'addition");
            return MatrixAdder<T, M, N, M2, N2>::add(*this, other);
        }
};

int main() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);
    auto m3 = m1.add(m2);
    std::cout << m3.get(0, 0) << " " << m3.get(0, 1) << std::endl; // Affiche 6 8
    std::cout << m3.get(1, 0) << " " << m3.get(1, 1) << std::endl; // Affiche 10 12
    Matrix<int, 2, 3> m4; // Incompatible
    // m1.add(m4); // Erreur de compilation (static_assert)

    // Testing with floating point
    Matrix<float, 2, 2> f1;
    f1.set(0, 0, 1.5); f1.set(0, 1, 2.5);
    f1.set(1, 0, 3.5); f1.set(1, 1, 4.5);
    Matrix<float, 2, 2> f2;
    f2.set(0, 0, 0.5); f2.set(0, 1, 1.5);
    f2.set(1, 0, 2.5); f2.set(1, 1, 3.5);
    auto f3 = f1.add(f2);
    std::cout << f3.get(0, 0) << " " << f3.get(0, 1) << std::endl; // Should display 2 4
    std::cout << f3.get(1, 0) << " " << f3.get(1, 1) << std::endl; // Should display 6 8
    return 0;
}
