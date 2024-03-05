#include <iostream>
#include <fstream>
#include <thread>

int main()
{
    std::cout << "Client ON" << std::endl;
    int number;
    int result;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::ofstream dane("dane.txt");
    if (!dane)
    {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    }
    dane << number;
    dane.close();

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::ifstream wyniki("wyniki.txt");
    if (!wyniki)
    {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    wyniki >> result;
    std::cout << "Result: " << result << std::endl;
    wyniki.close();

    return 0;
}
