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

void output_students(ofstream& outfile, Student students[], int studentnum);

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

    file_input.open(filename_input);
    file_output.open(filename_output);

    if(file_input.fail()) {
        cout << "Unable to open input file.\n";
        return 0;
    }

    // First function, reads in the data & stores it
    num_students = get_student_numbers(file_input, students);

    if(num_students == 0) {
        file_output << "No students to report.\n";
        return 0;
    }

    // Second function, since the student names are in reverse
    reverse_students(students, num_students);

    // Third function, writes output file with formatting.
    output_students(file_output, students, num_students);

    file_input.close();
    file_output.close();

    return 0;
}

int get_student_numbers(ifstream& infile, Student students[])
{
    istringstream linestream;
    string linestring;
    int studentnum = 0;

    while(getline(infile, linestring)) {
        if (studentnum == MAX_STUDENTS) {
            // Reached the max number of students to read in,
            break;
        }
        if(linestring == "" || linestring == " ") {
            // No student data on this line
        } else {
            linestream.clear();
            linestream.str(linestring);
            linestream >> students[studentnum].firstname;
            linestream >> students[studentnum].lastname;

            double temp_score = 0, score_sum = 0;
            int score_count = 0;
            while(linestream >> temp_score) {
                score_count += 1;
                score_sum += temp_score;
            }
            if(score_count != 0.0)
                students[studentnum].averagescore = (score_sum / (score_count * 1.0));
            else
                students[studentnum].averagescore = 0.0;

            studentnum += 1;
            linestring = "";
        }
    }

    return studentnum;
}

// From http://utk.claranguyen.me/cs102/lab.php?id=cs102f16_lab9
// Good reversal example, can still be applied to object instead of chars

void reverse_students(Student students[], int studentnum)
{
    Student temp_student;
    int otheritem;

    for(int i = 0; i < studentnum / 2; i++) {
        temp_student = students[i];
        otheritem = studentnum - i - 1;
        students[i] = students[otheritem];
        students[otheritem] = temp_student;
    }
}

void output_students(ofstream& outfile, Student students[], int studentnum)
{
    outfile.setf(ios::fixed);
    outfile.setf(ios::showpoint);
    outfile.precision(2);

    for(int i = 0; i < studentnum; i++) {
        ostringstream outstr;
        outstr << students[i].lastname << ", " << students[i].firstname;

        outfile.width(20 + 1);
        outfile << left << outstr.str();
        outfile << "= " << students[i].averagescore;

        outfile << endl;
    }
}
