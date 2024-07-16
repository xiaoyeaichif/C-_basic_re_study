

#include <iostream>
#include <vector>
#include <string>
#include<sstream>
int main() {
    std::vector<int> numbers;
    std::string line;

    std::cout << "Enter numbers, one per line (press Ctrl+D on Unix or Ctrl+Z on Windows to end):\n";

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int number;

        while (iss >> number) {
            numbers.push_back(number);
        }
    }

    // Êä³ö½á¹û
    std::cout << "Numbers read:\n";
    for (int num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}