#include <iostream>

#include <vector>


using namespace std;


class vect {

public:

    int dim;  // Разме

    double* v; // Указатель на массив значений вектора

    int num;  // Номер вектора

    static int count;  // Счетчик количества созданных векторов


    // Конструктор по умолчанию

    vect() : dim(0), v(nullptr), num(0) {

        cout << "Конструктор по умолчанию для вектора " << num << endl;

    }


    // Конструктор с параметрами

    vect(int d) : dim(d), v(new double[d]), num(++count) {

        cout << "Конструктор с параметрами для вектора " << num << endl;

    }


    // Деструктор

    ~vect() {

        delete[] v;

        cout << "Деструктор для вектора " << num << endl;

    }


    // Оператор сложения

    vect operator+(const vect& other) {

        if (dim != other.dim) {

            cout << "Ошибка: Размеры векторов не совпадают" << endl;

            return *this;

        }

        vect result(dim);

        for (int i = 0; i < dim; i++) {

            result.v[i] = v[i] + other.v[i];

        }

        return result;

    }


    // Оператор вычитания

    vect operator-(const vect& other) {

        if (dim != other.dim) {

            cout << "Ошибка: Размеры векторов не совпадают" << endl;

            return *this;

        }

        vect result(dim);

        for (int i = 0; i < dim; i++) {

            result.v[i] = v[i] - other.v[i];

        }

        return result;

    }


    // Унарный оператор отрицания

    vect operator-() {

        vect result(dim);

        for (int i = 0; i < dim; i++) {

            result.v[i] = -v[i];

        }

        return result;

    }


    // Оператор умножения на число

    vect operator*(double k) {

        vect result(dim);

        for (int i = 0; i < dim; i++) {

            result.v[i] = v[i] * k;

        }

        return result;

    }


    // Оператор присваивания

    vect& operator=(const vect& other) {

        if (dim != other.dim) {

            cout << "Ошибка: Размеры векторов не совпадают" << endl;

            return *this;

        }

        for (int i = 0; i < dim; i++) {

            v[i] = other.v[i];

        }

        return *this;

    }

};


// Статическая переменная для подсчета количества созданных векторов

int vect::count = 0;


int main() {

    // Создание и работа с векторами

    vect v1(3);

    v1.v[0] = 1;

    v1.v[1] = 2;

    v1.v[2] = 3;


    vect v2(3);

    v2.v[0] = 4;

    v2.v[1] = 5;

    v2.v[2] = 6;


    vect v3 = v1 + v2;

    for (int i = 0; i < v3.dim; i++) {

        cout << v3.v[i] << " ";

    }

    cout << endl;


    vect v4 = v1 - v2;

    for (int i = 0; i < v4.dim; i++) {

        cout << v4.v[i] << " ";

    }

    cout << endl;


    vect v5 = -v1;

    for (int i = 0; i < v5.dim; i++) {

        cout << v5.v[i] << " ";

    }

    cout << endl;


    vect v6 = v1 * 2;

    for (int i = 0; i < v6.dim; i++) {

        cout << v6.v[i] << " ";

    }

    cout << endl;


    vect v7;

    v7 = v1;

    for (int i = 0; i < v7.dim; i++) {

        cout << v7.v[i] << " ";

    }

    cout << endl;


    return 0;

}