#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    cout << "\nEnter Roll Number: ";
    cin >> s.roll;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    file << s.roll << " " << s.name << " " << s.marks << endl;
    file.close();

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");

    Student s;

    cout << "\n----- Student Records -----\n";

    while (file >> s.roll >> s.name >> s.marks) {
        cout << "Roll: " << s.roll
             << " | Name: " << s.name
             << " | Marks: " << s.marks << endl;
    }

    file.close();
}
int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}