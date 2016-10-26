#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

const int MAX_STUDENTS = 10;

struct Student {
    string firstname, lastname;
    double averagescore;
};

// Reads in the students from the file
// Returns the number of students read in.
int get_student_numbers(ifstream& infile, Student students[]);

void reverse_students(Student students[], int studentnum);

int main(int argc, char** argv)
{
    string filename_input, filename_output;
    ifstream file_input;
    ofstream file_output;
    Student students[MAX_STUDENTS];
    int num_students;

    cout << "Enter input filename: ";
    cin >> filename_input;
    cout << "Enter output filename: ";
    cin >> filename_output;

    // First function, reads in the data & stores it
    num_students = get_student_numbers(file_input, students);

    // Second function, since the student names are in reverse
    reverse_students(students, num_students);

    // Third function, writes output file with formatting.

    return 0;
}

int get_student_numbers(ifstream& infile, Student students[])
{
    istringstream linestream;
    string linestring;
    int studentnum = 0;

    while(getline(infile, linestring)) {
        linestream.str(linestring);
        linestream >> students[studentnum].firstname >> students[studentnum].lastname;

        double temp_score, score_sum = 0;
        int score_count = 0;
        while(linestream >> temp_score) {
            score_count += 1;
            score_sum += temp_score;
        }
        students[studentnum].averagescore = (score_sum / (score_count * 1.0));

        studentnum += 1;
        linestream.clear();
        linestring = "";
    }

    return studentnum;
}

// From http://utk.claranguyen.me/cs102/lab.php?id=cs102f16_lab9
// Good reversal example, can still be applied to object instead of chars
void reverse_strings(string lines[], int count)
{
    char temp;
    int length, end;
    for(int i = 0; i < count; i++) {
        length = lines[i].length();
        for(int j = 0; j < length / 2; j++) {
            temp = lines[i][j];
            end = length - j - 1;
            lines[i][j] = lines[i][end];
            lines[i][end] = temp;
        }
    }
}

void reverse_students(Student students[], int studentnum)
{
    Student temp_student;
    int otheritem;

    for (int i = 0; i < studentnum / 2; i++) {
        temp_student = students[i];
        otheritem = studentnum - i - 1;
        students[i] = students[otheritem];
        students[otheritem] = temp_student;
    }
}
