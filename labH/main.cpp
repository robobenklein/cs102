#include <fstream>
#include <iostream>

using namespace std;

const int VECTOR_SIZE = 4;
const int MATRIX_ROWS = 4;
const int MATRIX_COLS = 4;

class Vector
{
    double v[VECTOR_SIZE];

public:
    void Set(int index, double value);
    double Get(int index) const;
};

class Matrix
{
    double m[MATRIX_ROWS][MATRIX_COLS];

public:
    void Set(int row, int col, double value);
    double Get(int row, int col) const;
};

Vector Multiply(const Matrix& m, const Vector& v);

int main(int argc, char** argv)
{
    double temp_incoming
    fstream file_vector, file_matrix, file_output;
    string filename_vector, filename_matrix, filename_output;

    Vector var_vector;
    Matrix var_matrix;

    cout << "Enter vector filename: ";
    cin >> filename_vector;
    cout << "Enter matrix filename: ";
    cin >> filename_matrix;
    cout << "Enter result filename: ";
    cin >> filename_output;

    cout << endl;

    // Test the filenames provided:
    file_vector.open(filename_vector);
    file_matrix.open(filename_matrix);
    file_output.open(filename_output);

    if(file_vector.fail()) {
        cout << "Unable to open vector file." << endl;
        return 1;
    } else if(file_matrix.fail()) {
        cout << "Unable to open matrix file." << endl;
        return 1;
    }

    // Try reading in the vector file:

    for (int i = 0; i < VECTOR_SIZE; i++) {
        // Return if we can't get the values we need
        if (!(cin >> temp_incoming)) {
            return 1;
        }
        var_vector.Set(i, temp_incoming);
    }

    // Try reading in the matrix file:

    // Multiply

    // Output to the file.

    return 0;
}

void Vector::Set(int index, double value) {
    v[index] = value;
}

double Vector::Get(int index) const {
    return v[index];
}
