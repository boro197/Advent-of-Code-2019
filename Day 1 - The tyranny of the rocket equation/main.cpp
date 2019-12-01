#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>

using namespace std;

class Sleigh {
public:
    Sleigh(const vector<uint> &a_Masses) : m_Masses(a_Masses) {}

    uint getNeededFuel();

    static uint countNeededFuelForGivenMass(int a_Mass);

private:
    vector<uint> m_Masses;
};

uint Sleigh::countNeededFuelForGivenMass(int a_Mass) {
    return a_Mass / 3 - 2;
}

uint Sleigh::getNeededFuel()
{
    return accumulate(m_Masses.begin(), m_Masses.end(), 0, [](int a, int b) {return a + Sleigh::countNeededFuelForGivenMass(b);});
}

bool unitTests() {
    if (Sleigh::countNeededFuelForGivenMass(12) != 2) {
        cout << Sleigh::countNeededFuelForGivenMass(12) << " is not equal " << 2 << " !\n";
        return false;
    }

    if (Sleigh::countNeededFuelForGivenMass(14) != 2) {
        cout << Sleigh::countNeededFuelForGivenMass(14) << " is not equal " << 2 << " !\n";
        return false;
    }

    if (Sleigh::countNeededFuelForGivenMass(1969) != 654) {
        cout << Sleigh::countNeededFuelForGivenMass(1969) << " is not equal " << 654 << " !\n";
        return false;
    }

    if (Sleigh::countNeededFuelForGivenMass(100756) != 33583) {
        cout << Sleigh::countNeededFuelForGivenMass(1006756) << " is not equal " << 33583 << " !\n";
        return false;
    }

    Sleigh sleigh({12, 14, 1969, 100756});

    if (sleigh.getNeededFuel() != 34241) {
        cout << sleigh.getNeededFuel() << " is not equal " << 34241 << " !\n";
        return false;
    }
    return true;
}

int main()
{
    cout << "--- Day 1: The Tyranny of the Rocket Equation ---\n" << endl;
    if (!unitTests()) {
        cout << "Unit tests failed !\n";
        return -1;
    }
    else cout << "Unit tests passed !\n";

    std::fstream input("input.txt");
    std::vector<uint> inputVector;

    string line;

    while (getline(input, line)){
        inputVector.push_back(atoi(line.c_str()));
    }

    Sleigh sleigh(inputVector);
    cout << "Result: " << sleigh.getNeededFuel() << endl;

    return 0;
}
