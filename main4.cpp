#include <iostream>
#include <vector>
#include <cmath>
enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {

    std::vector <std::string> melody (12);
    for (int i = 0; i<12; i++) {
        std::cout << "Enter notes numbers (from 1 to 7): " << std::endl;
        std::cin >> melody[i];
        for (int k = 0; k<melody[i].length(); k++) {
            while (!(melody[i][k] > '0' && melody[i][k] < '8')) {
                std::cout << "wrong input! enter again";
                std::cin >> melody[i];
                k = 0;
            }
        }
    }

    for (int i = 0; i < 12; i++){
        int chord = 0;

        for (int k = 0; k<melody[i].length(); k++){
            int numb = pow(2, melody[i][k] - '1');
            chord |= numb;
        }

        if (chord & DO) {
            std::cout << "DO ";
        }
        if (chord & RE) {
            std::cout << "RE ";
        }
        if (chord & MI) {
            std::cout << "MI ";
        }
        if (chord & FA) {
            std::cout << "FA ";
        }
        if (chord & SOL) {
            std::cout << "SOL ";
        }
        if (chord & LA) {
            std::cout << "LA ";
        }
        if (chord & SI) {
            std::cout << "SI ";
        }
        std::cout << std::endl;
    }
}