#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

// Template Function：取得較大值
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template Function：取得較小值
template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

// 學生資料結構
struct Student {
    string id;
    string name;
    int score;
};

// 新增學生
void addStudent(vector<Student>& students) {
    Student s;

    cout << "Enter student id: ";
    cin >> s.id;

    for (const auto& student : students) {
        if (student.id == s.id) {
            cout << "This id already exists. Add failed.\n";
            return;
        }
    }

    cout << "Enter student name: ";
    cin >> s.name;

    cout << "Enter score: ";
    cin >> s.score;

    students.push_back(s);
    cout << "Student added successfully.\n";
}

// 列出所有學生
void listStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student data.\n";
        return;
    }

    cout << left << setw(15) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Score" << endl;

    cout << "-----------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(15) << s.id
             << setw(15) << s.name
             << setw(10) << s.score << endl;
    }
}

// 依成績排序
void sortByScore(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    cout << "Students sorted by score from high to low.\n";
}

// 查詢學生
void searchStudent(const vector<Student>& students) {
    string id;
    cout << "Enter student id to search: ";
    cin >> id;

    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Student found:\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Score: " << s.score << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

// 統計成績
void showStatistics(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student data.\n";
        return;
    }

    int total = 0;
    int highest = students[0].score;
    int lowest = students[0].score;
    int passCount = 0;
    int failCount = 0;

    for (const auto& s : students) {
        total += s.score;

        highest = getMax(highest, s.score);
        lowest = getMin(lowest, s.score);

        if (s.score >= 60) {
            passCount++;
        } else {
            failCount++;
        }
    }

    double average = static_cast<double>(total) / students.size();

    cout << fixed << setprecision(2);
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;
    cout << "Pass students: " << passCount << endl;
    cout << "Fail students: " << failCount << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Grade Management System =====\n";
        cout << "1. Add student\n";
        cout << "2. List all students\n";
        cout << "3. Sort by score\n";
        cout << "4. Search by id\n";
        cout << "5. Show statistics\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                listStudents(students);
                break;
            case 3:
                sortByScore(students);
                break;
            case 4:
                searchStudent(students);
                break;
            case 5:
                showStatistics(students);
                break;
            case 0:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}