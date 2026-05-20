#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double gradePoints;
    double creditHours;
};

double convertGradeToPoints(const string& grade) {
    if (grade == "A+" || grade == "A") return 4.0;
    if (grade == "A-") return 3.7;
    if (grade == "B+") return 3.3;
    if (grade == "B") return 3.0;
    if (grade == "B-") return 2.7;
    if (grade == "C+") return 2.3;
    if (grade == "C") return 2.0;
    if (grade == "C-") return 1.7;
    if (grade == "D+") return 1.3;
    if (grade == "D") return 1.0;
    if (grade == "F") return 0.0;

    return -1.0;
}

int main() {
    int totalCourses;

    cout << "=================================\n";
    cout << "        CGPA CALCULATOR          \n";
    cout << "=================================\n\n";

    cout << "Enter total number of courses: ";

    while (!(cin >> totalCourses) || totalCourses <= 0) {
        cout << "Invalid input. Enter again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    vector<Course> courses(totalCourses);

    double totalEarnedPoints = 0.0;
    double totalCreditHours = 0.0;

    cin.ignore();

    for (int i = 0; i < totalCourses; i++) {

        cout << "\n--- Course " << i + 1 << " ---\n";

        cout << "Enter Course Name/Code: ";
        getline(cin, courses[i].name);

        string letterGrade;
        double points = -1.0;

        while (points < 0) {
            cout << "Enter Letter Grade (A+, A, B, C, F etc.): ";
            cin >> letterGrade;

            points = convertGradeToPoints(letterGrade);

            if (points < 0) {
                cout << "Invalid grade! Try again.\n";
            }
        }

        courses[i].gradePoints = points;

        cout << "Enter Credit Hours: ";

        while (!(cin >> courses[i].creditHours) || courses[i].creditHours <= 0) {
            cout << "Invalid input. Enter positive credit hours: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        totalEarnedPoints += courses[i].gradePoints * courses[i].creditHours;
        totalCreditHours += courses[i].creditHours;

        cin.ignore();
    }

    cout << "\n=======================================================\n";
    cout << "                    SEMESTER SUMMARY                   \n";
    cout << "=======================================================\n";

    cout << left
         << setw(20) << "Course"
         << setw(15) << "Credits"
         << setw(15) << "Grade Point"
         << "Total Points\n";

    cout << "-------------------------------------------------------\n";

    for (const auto& course : courses) {

        cout << left
             << setw(20) << course.name
             << setw(15) << fixed << setprecision(1) << course.creditHours
             << setw(15) << course.gradePoints
             << fixed << setprecision(2)
             << (course.gradePoints * course.creditHours)
             << "\n";
    }

    cout << "-------------------------------------------------------\n";

    double finalCGPA = totalEarnedPoints / totalCreditHours;

    cout << "Total Credit Hours : " << totalCreditHours << "\n";
    cout << "Total Grade Points : " << totalEarnedPoints << "\n";

    cout << "-------------------------------------------------------\n";

    cout << "FINAL CGPA : "
         << fixed << setprecision(2)
         << finalCGPA << " / 4.00\n";

    cout << "=======================================================\n";

    return 0;
}