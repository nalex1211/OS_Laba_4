#include <iostream>
#include <unistd.h>
#include <limits>

int main() {
    long secretValue = 0;

    std::cout << "Process 1 PID: " << getpid() << std::endl;
    std::cout << "Enter a number to store: ";
    std::cin >> secretValue;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Storing " << secretValue << " in memory" << std::endl;

    std::cout << "Address of secretValue: " << &secretValue << std::endl;
    std::cout << "Size of secretValue: " << sizeof(secretValue) << " bytes" << std::endl;

    std::cout << "Press enter to continue...";
    std::cin.get();

    return 0;
}