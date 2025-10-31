#include <iostream>

int main() {
    std::cout << "Welcome to the Smart Study Program!" << std::endl;
    bool goodbye = false;
    while (!goodbye) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Import Data" << std::endl;
        std::cout << "3. Export Data" << std::endl;
        std::cout << "4. Create Pairs" << std::endl;
        std::cout << "5. Quit" << std::endl;
        int choice = 0;
        std::string choiceStr;
        std::cin >> choiceStr;
        try {
            choice = std::stoi(choiceStr);
        } catch (std::invalid_argument &_)
        {
            std::cout << "Please enter a number!" << std::endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                // TODO
                break;
            case 2:
                // TODO
                break;
            case 3:
                // TODO
                break;
            case 4:
                // TODO
                break;
            case 5:
                goodbye = true;
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Please make a valid selection!" << std::endl;
        }
    }
    return 0;
}