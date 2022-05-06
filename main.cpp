#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

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

int day2_1() {
    int finalHorizontalValue = 0, finalDepth = 0;
    ifstream file;
    file.open("../inputs/day2.txt");
    if (file.is_open()) {
        int value = 0;
        string direction;
        while (file >> direction >> value)
            if (direction == "forward")
                finalHorizontalValue += value;
            else if (direction == "down")
                finalDepth += value;
            else if (direction == "up")
                finalDepth -= value;
    }
    return finalHorizontalValue * finalDepth;
}

int day2_2() {
    int finalHorizontalValue = 0, finalDepth = 0;
    ifstream file;
    file.open("../inputs/day2.txt");
    if (file.is_open()) {
        int value = 0, aim = 0;
        string direction;
        while (file >> direction >> value)
            if (direction == "forward") {
                finalHorizontalValue += value;
                finalDepth += aim * value;
            } else if (direction == "down")
                aim += value;
            else if (direction == "up")
                aim -= value;
    }
    return finalHorizontalValue * finalDepth;
}


int main() {
    cout << "n: " << day1_1() << endl;
    cout << "n: " << day1_2() << endl;
    cout << "position: " << day2_1() << endl;
    cout << "position: " << day2_2() << endl;
    return 0;
}