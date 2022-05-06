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


int day3_1() {
    ifstream file;
    file.open("../inputs/day3.txt");
    if (file.is_open()) {
        string line;

        // create vector with same amount of collumns as input
        file >> line;
        auto width = line.size();
        vector<int> sums(width, 0);

        // reset input file
        file.seekg(0);

        // for each line count 0 and 1
        while (file >> line) {
            if (line.size() != width) {
                cerr << "Got an invalid line length" << endl;
                continue;
            }
            for (int i = 0; i < width; ++i)
                if (line[i] == '0')
                    --sums[i];
                else
                    ++sums[i];
        }

        double gamma = 0;
        double epsilon = 0;
        for (int i = 0; i < width; ++i) {
            int g = sums[i] < 0 ? 0 : 1;
            int e = sums[i] < 0 ? 1 : 0;
            gamma += pow(2, width - 1 - i) * g;
            epsilon += e * pow(2, width - 1 - i);
        }
        return gamma * epsilon;
    } else
        return 0;

}

int day3_2() {
    ifstream file;
    file.open("../inputs/day3.txt");
    if (file.is_open()) {
        string line;
        vector <string> rowss;
        double o2 = 0;
        double co2 = 0;
        while (file >> line)
        {
            rowss.push_back(line);
            vector <string> rows(rowss);
            for (int n = 0; rows.size() > 1; ++n) {
                int acc = 0;
                for (auto row: rows) {
                    if (row[n] == '0') {
                        --acc;
                    } else if (row[n] == '1') {
                        ++acc;
                    }
                }
                char sign = acc < 0 ? 0 : 1;
                rows.erase(remove_if(rows.begin(), rows.end(), [n, sign](string row) { return row[n] == sign; }),
                           rows.end());
            }
            for (int i = 0; i < rows[0].size(); ++i) {
                int oxygen = rows[0][i] < 0 ? 0 : 1;
                o2 += pow(2, rows[0].size() - 1 - i) * oxygen;
            }
        }
        {
            vector <string> rows(rowss);
            for (int n = 0; rows.size() > 1; ++n) {
                int acc = 0;
                for (auto row: rows) {
                    if (row[n] == '0') {
                        --acc;
                    } else if (row[n] == '1') {
                        ++acc;
                    }
                }
                char sign = acc < 0 ? 1 : 0;
                rows.erase(remove_if(rows.begin(), rows.end(), [n, sign](string row) { return row[n] == sign; }),
                           rows.end());
            }
            for (int i = 0; i < rows[0].size(); ++i) {
                int carbonDioxide = rows[0][i] < 0 ? 0 : 1;
                co2 += pow(2, rows[0].size() - 1 - i) * carbonDioxide;
            }
        }
        return o2 * co2;
    }
    return 0;
}

int main() {
    cout << "n: " << day1_1() << endl;
    cout << "n: " << day1_2() << endl;
    cout << "position: " << day2_1() << endl;
    cout << "position: " << day2_2() << endl;
    cout << "power: " << day3_1() << endl;
    cout << "life support: " << day3_2() << endl;

    return 0;
}