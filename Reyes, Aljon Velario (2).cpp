#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float gpa;

};

const int MAX_STUDENTS = 5;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student record is full!\n";
        return;
    }

    Student newStudent;
    cout << "Enter Student ID: ";
    cin >> newStudent.id;


    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == newStudent.id) {
            cout << "Duplicate ID found! Try again.\n";
            return;
        }
    }

    cout << "Enter First Name: ";
    cin >> newStudent.firstName;
    cout << "Enter Last Name: ";
    cin >> newStudent.lastName;
    cout << "Enter Course: ";
    cin >> newStudent.course;
    cout << "Enter GPA: ";
    cin >> newStudent.gpa;

    students[studentCount++] = newStudent;
    cout << "Student added successfully!\n";
}

void editStudent() {
    if (studentCount == 0) {
        cout << "No student records found!\n";
        return;
    }

    int searchID;
    cout << "Enter Student ID to edit: ";
    cin >> searchID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            cout << "Editing Student " << searchID << "...\n";
            cout << "Enter New First Name: ";
            cin >> students[i].firstName;
            cout << "Enter New Last Name: ";
            cin >> students[i].lastName;
            cout << "Enter New Course: ";
            cin >> students[i].course;
            cout << "Enter New GPA: ";
            cin >> students[i].gpa;
            cout << "Student record updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

void deleteStudent() {
    if (studentCount == 0) {
        cout << "No student records found!\n";
        return;
    }

    int searchID;
    cout << "Enter Student ID to delete: ";
    cin >> searchID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student record deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No student records found!\n";
        return;
    }

    cout << "Student Records:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].id << " - " << students[i].firstName << " "
             << students[i].lastName << " (" << students[i].course
             << ") GPA: " << students[i].gpa << endl;
    }
}

void displayMenu() {
    cout << "\nStudent Management System\n";
    cout << "[1] Add Student\n";
    cout << "[2] Edit Student\n";
    cout << "[3] Delete Student\n";
    cout << "[4] View Students\n";
    cout << "[5] Exit\n";
    cout << "Select an option: ";
}

int main() {
    int option;
    do {
        displayMenu();
        cin >> option;

        switch (option) {
        case 1:
            addStudent();
            break;
        case 2:
            editStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            viewStudents();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }
    } while (option != 5);

    return 0;
}
