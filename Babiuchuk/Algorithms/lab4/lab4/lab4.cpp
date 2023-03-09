#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;
#define SIZE 6

struct Date {
    int day;
    int month;
    int year;
};


struct Students {
    int treatmentCode;
    string lastName;
    int markMath;
    int markInf;
    int markPhysics;
    int rating;
    Date date;
};


void readStudentsData(Students students[]) {
    ifstream inputFile("students.txt");

    if (!inputFile.is_open()) {
        cout << "������� �������� �����" << endl;
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        Date date;

        inputFile >> students[i].treatmentCode
            >> students[i].lastName
            >> students[i].markMath
            >> students[i].markInf
            >> students[i].markPhysics;
        students[i].rating = (students[i].markMath + students[i].markInf + students[i].markPhysics) / 3.0;
        inputFile >> date.year >> date.month >> date.day;
        students[i].date = date;
    }

    inputFile.close();
}


//void printStudentsData(Passenger Students[]) {
//    for (int i = 0; i < SIZE; i++) {
//        cout << "��� �����: " << Students[i].ticketCode << endl;
//        cout << "������� ��������: " << Students[i].lastName << endl;
//        cout << "ʳ������ ����� ������: " << Students[i].luggageCount << endl;
//        cout << "�������� ���� ������: " << Students[i].luggageWeight << "��" << endl;
//        cout << "����: " << Students[i].date.day << "." << Students[i].date.month << "." << Students[i].date.year << endl;
//        cout << endl;
//    }
//}
void printStudentsData(Students students[]) {
    cout << left << setw(13) << "����� ��������"
        << setw(20) << "�������"
        << setw(18) << "������ � ����������"
        << setw(18) << "������ � �����������"
        << setw(12) << "������ � ������"
        << setw(12) << "�������"
        << setw(12) << "���� ������" << endl << endl;
        
    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(13) << students[i].treatmentCode
            << setw(20) << students[i].lastName
            << setw(18) << students[i].markMath
            << setw(18) << students[i].markInf
            << setw(18) << students[i].markPhysics
            << setw(18) << students[i].rating;
        cout << right << setw(2) << setfill('0') << students[i].date.day << "."
            << setw(2) << setfill('0') << students[i].date.month << "." << setfill(' ')
            << left << setw(6) << students[i].date.year << "  " << endl;
    }
}
void sortByTreatment(Students students[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (students[j].treatmentCode >= students[j + 1].treatmentCode) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void sortByDate (Students students[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (students[j].date.year < students[i].date.year ||
                (students[j].date.year == students[i].date.year && students[j].date.month  < students[i].date.month) ||
                (students[j].date.year == students[i].date.year && students[j].date.month == students[i].date.month && students[j].date.day < students[i].date.day)) {
                swap(students[i], students[j]);
            }
        }
    }
}
void sortByRating(Students students[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (students[j].rating < students[i].rating) {
                swap(students[i], students[j]);
            }
        }
    }
}
void sortByScores(Students students[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (students[j].markMath < students[i].markMath ||
                (students[j].markMath == students[i].markMath && students[j].markInf < students[i].markInf) ||
                (students[j].markMath == students[i].markMath && students[j].markInf == students[i].markInf && students[j].markPhysics < students[i].markPhysics)) {
                swap(students[i], students[j]);
            }
        }
    }
}
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Students Students[SIZE];
    readStudentsData(Students);
    int choice;
    cout << "��� � ������� ���������: " << endl;
    printStudentsData(Students);
    do {
        cout << "������� ��� �������������:" << endl;
        cout << "1. ������������� �� ������� ������� ������" << endl;
        cout << "2. ������������� �� ����� ����������" << endl;
        cout << "3. ������������� �� ���������" << endl;
        cout << "4. ������������� �� �������� � ��������" << endl;
        cout << "5. �����" << endl;

        cin >> choice;

        switch (choice) {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            cout << "1. ������������� �� ����� �����" << endl;
            sortByTreatment(Students);
            printStudentsData(Students);
            break;
        case 2:
            system("cls");
            cout << "2. ������������� �� ����� ������" << endl;
            sortByDate(Students);
            printStudentsData(Students);
            break;
        case 3:
            system("cls");
            cout << "3. ������������� �� ����� �� ������� ������" << endl;
            sortByRating(Students);
            printStudentsData(Students);
            break;
        case 4:
            system("cls");
            cout << "4. ������������� �� �������� � ��������" << endl;
            sortByScores(Students);
            printStudentsData(Students);
            break;
        case 5:
            cout << "�����..." << endl;
            break;
        default:
            cout << "������� ����. ��������� �����." << endl;
            break;
        }
    } while (choice != 5);


    return 0;
}
