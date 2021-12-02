#include <iostream>
#include <fstream>

using namespace std;

int day1_1() {
    int n = 0;
    ifstream file;
    file.open("../inputs/day1.txt");
    if (file.is_open()) {
        int value1;
        int value2;
        file >> value1;
        while (file >> value2) {
            if (value1 < value2)
                ++n;
            value1 = value2;
        }
        file.close();
    }
    return n;
}

int day1_2() {
    int n = 0;
    ifstream file;
    file.open("../inputs/day1.txt");
    if (file.is_open()) {
        int value1, value2, value3, value4;
        file >> value1 >> value2 >> value3;
        while (file >> value4) {

            int sum1 = value1 + value2 + value3;
            int sum2 = value2 + value3 + value4;

            if (sum1 < sum2)
                ++n;
            value1 = value2;
            value2 = value3;
            value3 = value4;
        }
        file.close();
    }
    return n;
}


int main() {
    cout << "n: " << day1_1() << endl;
    cout << "n: " << day1_2() << endl;
    return 0;
}