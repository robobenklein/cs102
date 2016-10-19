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
    double temp_incoming;
    ifstream file_vector, file_matrix;
    ofstream file_output;
    string filename_vector, filename_matrix, filename_output;

    Vector var_vector, final_vector;
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

    for(int i = 0; i < VECTOR_SIZE; i++) {
        // Return if we can't get the values we need
        if(!(file_vector >> temp_incoming)) {
            cout << "Unable to read vector file." << endl;
            return 1;
        }
        var_vector.Set(i, temp_incoming);
    }

    // Try reading in the matrix file:

    for(int m_row = 0; m_row < MATRIX_ROWS; m_row++) {
        for(int m_col = 0; m_col < MATRIX_COLS; m_col++) {
            if(!(file_matrix >> temp_incoming)) {
                // Could not read another value from the file
                cout << "Unable to read matrix file." << endl;
                return 1;
            } else {
                // It worked, we should have our var in the temp var now:
                var_matrix.Set(m_row, m_col, temp_incoming);
                // Debug: cout << "Got in matrix: " << m_row << ", " << m_col << ": " << temp_incoming << endl;
            }
        }
    }

    // Multiply
    final_vector = Multiply(var_matrix, var_vector);

    // Output to the file.
    file_output.setf(ios::fixed);
    file_output.setf(ios::showpoint);
    file_output.precision(1);

    for(int i = 0; i < VECTOR_SIZE; i++) {
        // Supposed to be 6 chars wide but the example shows 7 per item.
        file_output.width(6 + 1);
        file_output << left << final_vector.Get(i);
    }

    // Finish program
    file_matrix.close();
    file_vector.close();
    file_output.close();

    return 0;
}

void Vector::Set(int index, double value)
{
    v[index] = value;
}

double Vector::Get(int index) const
{
    return v[index];
}

void Matrix::Set(int row, int col, double value)
{
    m[row][col] = value;
}

double Matrix::Get(int row, int col) const
{
    return m[row][col];
}

Vector Multiply(const Matrix& m, const Vector& v)
{
    int index_vec = 0, index_matrix_row = 0, index_matrix_col = 0;
    double linetotal;
    Vector output_vec;

    // Magic block of code
    // For every row,
    // Add up the items times the vector's row value,
    // Store that value for our output vector
    for(index_matrix_row = 0; index_matrix_row < MATRIX_ROWS; index_matrix_row++) {
        linetotal = 0.0;
        index_vec = 0;
        for(index_matrix_col = 0; index_matrix_col < MATRIX_COLS; index_matrix_col++) {
            linetotal += m.Get(index_matrix_row, index_matrix_col) * v.Get(index_vec);
            index_vec++;
        }
        output_vec.Set(index_matrix_row, linetotal);
    }

    return output_vec;
}
