#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <windows.h>
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string subject = "";
string difficulty = "";
string playerName = "";

struct Question {
    string ques;
    string opt[4];
    char correct = ' ';
};

string getFileName() {
    if (subject == "PF") {
        if (difficulty == "Beginner") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\pf easy.txt";
        if (difficulty == "Intermediate") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\pf med.txt";
        if (difficulty == "Advanced") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\pf hard.txt";
    }
    if (subject == "Eng") {
        if (difficulty == "Beginner") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\Eng easy.txt";
        if (difficulty == "Intermediate") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\Eng med.txt";
        if (difficulty == "Advanced") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\Eng hard.txt";
    }
    if (subject == "Math") {
        if (difficulty == "Beginner") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\math easy.txt";
        if (difficulty == "Intermediate") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\math med.txt";
        if (difficulty == "Advanced") return "C:\\Users\\user\\source\\repos\\Project PF\\Project PF\\math hard.txt";
    }
    return "";
}

bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name)
        if (!isalpha(c) && c != ' ')
            return false;
    return true;
}

void instructions() {
    system("cls");
    setColor(11);
    Beep(800, 150);

    cout << "================================================\n";
    cout << "               QUIZ INSTRUCTIONS               \n";
    cout << "================================================\n\n";

    setColor(7);
    cout << "1. Select subject and difficulty\n";
    cout << "2. Each question has 4 options: A B C D\n";
    cout << "3. Correct answer = +10 points\n";
    cout << "4. Advanced level: Wrong answer = -10 points\n";
    cout << "5. Have fun and try your best!\n\n";

    Sleep(5000);
}

void startQuiz() {
    system("cls");
    srand(time(0));

    cin.ignore();
    do {
        setColor(14);
        cout << "Enter your name: ";
        setColor(7);
        getline(cin, playerName);

        if (!isValidName(playerName)) {
            setColor(12);
            cout << "Invalid name! Only letters and spaces are allowed.\n";
            setColor(7);
        }
    } while (!isValidName(playerName));

    int ch;
    do {
        setColor(11);
        cout << "\nSelect subject:\n";
        setColor(7);
        cout << "1. PF\n2. Eng\n3. Maths\nChoice: ";
        cin >> ch;

        if (cin.fail() || ch < 1 || ch > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "Invalid input! Enter 1, 2, or 3.\n";
            setColor(7);
            ch = 0;
        }
    } while (ch == 0);

    subject = (ch == 1 ? "PF" : ch == 2 ? "Eng" : "Math");

    do {
        setColor(11);
        cout << "\nSelect difficulty:\n";
        setColor(7);
        cout << "1. Beginner\n2. Intermediate\n3. Advanced\nChoice: ";
        cin >> ch;

        if (cin.fail() || ch < 1 || ch > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(12);
            cout << "Invalid input! Enter 1, 2, or 3.\n";
            setColor(7);
            ch = 0;
        }
    } while (ch == 0);

    difficulty = (ch == 1 ? "Beginner" : ch == 2 ? "Intermediate" : "Advanced");

    ifstream fin(getFileName());
    if (!fin) {
        setColor(12);
        cout << "\nFile not found!";
        setColor(7);
        Sleep(1500);
        return;
    }

    Question q[50];
    int totalQ = 0;

    while (getline(fin, q[totalQ].ques)) {
        if (q[totalQ].ques.empty()) continue;

        for (int i = 0; i < 4; i++)
            getline(fin, q[totalQ].opt[i]);

        string ansLine;
        getline(fin, ansLine);
        if (!ansLine.empty())
            q[totalQ].correct = toupper(ansLine[0]);

        totalQ++;
    }
    fin.close();

    for (int i = totalQ - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(q[i], q[j]);
    }

    int quizQ = (totalQ >= 10 ? 10 : totalQ);
    int score = 0;

    for (int i = 0; i < quizQ; i++) {
        system("cls");

        setColor(10);
        cout << "================================================\n";
        cout << "Q" << i + 1 << ": " << q[i].ques << "\n";
        cout << "================================================\n\n";
        setColor(7);

        cout << "A. " << q[i].opt[0] << "    B. " << q[i].opt[1] << "\n";
        cout << "C. " << q[i].opt[2] << "    D. " << q[i].opt[3] << "\n";

        char ans;
        string ansStr;
        bool validAns = false;

        do {
            cout << "\nAnswer (A/B/C/D): ";
            cin >> ansStr;

            if (ansStr.length() == 1) {
                ans = toupper(ansStr[0]);
                if (ans >= 'A' && ans <= 'D')
                    validAns = true;
                else {
                    setColor(12);
                    cout << "Invalid option!\n";
                    setColor(7);
                }
            }
            else {
                setColor(12);
                cout << "Enter only one letter!\n";
                setColor(7);
            }
        } while (!validAns);

        if (ans == q[i].correct) {
            score += 10;
            setColor(10);
            Beep(1000, 150);
            cout << "\nCorrect!\n";
        }
        else {
            if (difficulty == "Advanced") score -= 10;
            setColor(12);
            Beep(400, 150);
            cout << "\nWrong! Correct answer was: " << q[i].correct << "\n";
        }

        setColor(14);
        cout << "Current Score: " << score << endl;
        setColor(7);

        Sleep(1500);
    }

    system("cls");
    setColor(11);
    cout << "================================================\n";
    cout << "                 QUIZ RESULT                  \n";
    cout << "================================================\n";
    setColor(7);

    cout << "Name       : " << playerName << endl;
    cout << "Subject    : " << subject << endl;
    cout << "Difficulty : " << difficulty << endl;
    cout << "Questions  : " << quizQ << endl;
    cout << "Final Score: " << score << endl;

    ofstream fout("results.txt", ios::app);
    fout << playerName << " | " << subject << " | " << difficulty << " | " << score << endl;
    fout.close();

    Sleep(5000);
}

void viewResults() {
    system("cls");
    setColor(11);
    cout << "================================================\n";
    cout << "                   RESULTS                    \n";
    cout << "================================================\n\n";
    setColor(7);

    ifstream fin("results.txt");
    string line;
    while (getline(fin, line))
        cout << line << endl;
    fin.close();

    cout << "\nPress any key to return...";
    system("pause>0");
}

int main() {
    int choice;
    do {
        system("cls");
        setColor(11);
        cout << "================================================\n";
        cout << "              QUIZ GENERATOR SYSTEM            \n";
        cout << "================================================\n";
        setColor(7);

        cout << "1. Start Quiz\n";
        cout << "2. Instructions\n";
        cout << "3. View Results\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1: startQuiz(); break;
        case 2: instructions(); break;
        case 3: viewResults(); break;
        case 4:
            setColor(10);
            cout << "\nGoodbye! Thanks Alot\n";
            setColor(7);
            break;
        default:
            setColor(12);
            cout << "\nInvalid choice!\n";
            setColor(7);
            Sleep(1000);
        }
    } while (choice != 4);

    return 0;
}
