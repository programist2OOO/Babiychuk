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
        cout << "Помилка відкриття файлу" << endl;
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
//        cout << "Код білета: " << Students[i].ticketCode << endl;
//        cout << "Прізвище пасажира: " << Students[i].lastName << endl;
//        cout << "Кількість речей багажу: " << Students[i].luggageCount << endl;
//        cout << "Загальна вага багажу: " << Students[i].luggageWeight << "кг" << endl;
//        cout << "Дата: " << Students[i].date.day << "." << Students[i].date.month << "." << Students[i].date.year << endl;
//        cout << endl;
//    }
//}
void printStudentsData(Students students[]) {
    cout << left << setw(13) << "Номер заліковки"
        << setw(20) << "Прізвище"
        << setw(18) << "Оцінка з математики"
        << setw(18) << "Оцінка з інформатики"
        << setw(12) << "Оцінка з фізики"
        << setw(12) << "Рейтинг"
        << setw(12) << "Дата приїзду" << endl << endl;
        
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
    cout << "Дані в порядку створення: " << endl;
    printStudentsData(Students);
    do {
        cout << "Виберіть тип впорядкування:" << endl;
        cout << "1. Впорядкування за номером залікової книжки" << endl;
        cout << "2. Впорядкування за датою народження" << endl;
        cout << "3. Впорядкування за рейтингом" << endl;
        cout << "4. Впорядкування за оцінками з предметів" << endl;
        cout << "5. Вийти" << endl;

        cin >> choice;

        switch (choice) {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            cout << "1. Впорядкування за кодом білета" << endl;
            sortByTreatment(Students);
            printStudentsData(Students);
            break;
        case 2:
            system("cls");
            cout << "2. Впорядкування за датою приїзду" << endl;
            sortByDate(Students);
            printStudentsData(Students);
            break;
        case 3:
            system("cls");
            cout << "3. Впорядкування за вагою та кількістю багажу" << endl;
            sortByRating(Students);
            printStudentsData(Students);
            break;
        case 4:
            system("cls");
            cout << "4. Впорядкування за оцінками з предметів" << endl;
            sortByScores(Students);
            printStudentsData(Students);
            break;
        case 5:
            cout << "Вихід..." << endl;
            break;
        default:
            cout << "Невірний вибір. Спробуйте знову." << endl;
            break;
        }
    } while (choice != 5);


    return 0;
}
