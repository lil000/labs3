 Вот пример реализации программы на языке C++ с использованием классов `vect` и `matr` для работы с векторами и матрицами соответственно.

```cpp
#include <iostream>
#include <cstdlib>

class vect {
private:
    int dim;
    double* v;
    int num;
    static int count;

public:
    vect(int d, double* vec, int n) : dim(d), v(new double[d]), num(n) {
        std::cout << "Конструктор вектора " << num << " вызван" << std::endl;
        for (int i = 0; i < dim; ++i) {
            v[i] = vec[i];
        }
        ++count;
    }

    ~vect() {
        std::cout << "Деструктор вектора " << num << " вызван" << std::endl;
        delete[] v;
        --count;
    }

    static int getCount() {
        return count;
    }

    vect operator+(const vect& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = v[i] + other.v[i];
        }
        return vect(dim, result, count + 1);
    }

    vect operator-(const vect& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = v[i] - other.v[i];
        }
        return vect(dim, result, count + 1);
    }

    vect operator-() const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = -v[i];
        }
        return vect(dim, result, count + 1);
    }

    double operator*(const vect& other) const {
        double result = 0;
        for (int i = 0; i < dim; ++i) {
            result += v[i] * other.v[i];
        }
        return result;
    }

    vect operator*(double k) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = v[i] * k;
        }
        return vect(dim, result, count + 1);
    }

    vect& operator=(const vect& other) {
        if (this != &other) {
            delete[] v;
            dim = other.dim;
            v = new double[dim];
            for (int i = 0; i < dim; ++i) {
                v[i] = other.v[i];
            }
            num = other.num;
        }
        return *this;
    }
};

int vect::count = 0;

class matr {
private:
    int dim;
    double** a;

public:
    matr(int d, double** matrix) : dim(d) {
        a = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            a[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                a[i][j] = matrix[i][j];
            }
        }
    }

    ~matr() {
        for (int i = 0; i < dim; ++i) {
            delete[] a[i];
        }
        delete[] a;
    }

    matr operator+(const matr& other) const {
        double** result = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                result[i][j] = a[i][j] + other.a[i][j];
            }
        }
        return matr(dim, result);
    }

    matr operator-(const matr& other) const {
        double** result = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                result[i][j] = a[i][j] - other.a[i][j];
            }
        }
        return matr(dim, result);
    }

    matr operator-() const {
        double** result = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                result[i][j] = -a[i][j];
            }
        }
        return matr(dim, result);
    }

    matr operator*(const matr& other) const {
        double** result = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < dim; ++k) {
                    result[i][j] += a[i][k] * other.a[k][j];
                }
            }
        }
        return matr(dim, result);
    }

    vect operator*(const vect& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = 0;
            for (int j = 0; j < dim; ++j) {
                result[i] += a[i][j] * other.v[j];
            }
        }
        return vect(dim, result, vect::getCount() + 1);
    }

    matr operator*(double k) const {
        double** result = new double*[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = new double[dim];
            for (int j = 0; j < dim; ++j) {
                result[i][j] = a[i][j] * k;
            }
        }
        return matr(dim, result);
    }

    matr& operator=(const matr& other) {
        if (this != &other) {
            for (int i = 0; i < dim; ++i) {
                delete[] a[i];
            }
            delete[] a;
            dim = other.dim;
            a = new double*[dim];
            for (int i = 0; i < dim; ++i) {
                a[i] = new double[dim];
                for (int j = 0; j < dim; ++j) {
                    a[i][j] = other.a[i][j];
                }
            }
        }
        return *this;
    }
};

int main() {
    double v1_data[] = {1, 2, 3};
    double v2_data[] = {4, 5, 6};
    vect v1(3, v1_data, 1);
    vect v2(3, v2_data, 2);

    double** m1_data = new double*[3];
    for (int i = 0; i < 3; ++i) {
        m1_data[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            m1_data[i][j] = i + j;
        }
    }
    matr m1(3, m1_data);

    double** m2_data = new double*[3];
    for (int i = 0; i < 3; ++i) {
        m2_data[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            m2_data[i][j] = i * j;
        }
    }
    matr m2(3, m2_data);

    vect v3 = v1 + v2;
    vect v4 = v1 - v2;
    vect v5 = -v1;
    double dot_product = v1 * v2;
    vect v6 = v1 * 2.0;

    matr m3 = m1 + m2;
    matr m4 = m1 - m2;
    matr m5 = -m1;
    matr m6 = m1 * m2;
    vect v7 = m1 * v1;
    matr m7 = m1 * 2.0;

    // Освобождение памяти
    for (int i = 0; i < 3; ++i) {
        delete[] m1_data[i];
        delete[] m2_data[i];
    }
    delete[] m1_data;
    delete[] m2_data;

    return 0;
}
```

В этом примере класс `vect` представляет вектор, а класс `ma
