#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class LuckyNumberException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Число має бути 6-значним.";
    }
};

bool isHappyNumber(int number) {
    string numStr = to_string(number);
    if (numStr.length() < 6) {
        throw "Число має містити 6 цифр.";
    }
    else if (numStr.length() > 6) {
        throw LuckyNumberException();
    }

    int sumFirstHalf = 0, sumSecondHalf = 0;
    for (int i = 0; i < 3; ++i) {
        sumFirstHalf += numStr[i] - '0';
        sumSecondHalf += numStr[i + 3] - '0';
    }

    return sumFirstHalf == sumSecondHalf;
}

int main() {
    int number;
    cout << "Введіть 6-значне число: ";
    cin >> number;

    try {
        if (number < 100000 || number > 999999) {
            throw out_of_range("Число має бути від 100000 до 999999.");
        }

        bool isHappy;
        try {
            isHappy = isHappyNumber(number);
        }
        catch (const char* msg) {
            cerr << "Помилка: " << msg << endl;
            return 1;
        }
        catch (const LuckyNumberException& e) {
            cerr << "Помилка: " << e.what() << endl;
            return 1;
        }

        if (isHappy) {
            cout << number << " є щасливим числом." << endl;
        }
        else {
            cout << number << " не є щасливим числом." << endl;
        }
    }
    catch (const out_of_range& e) {
        cerr << "Помилка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
