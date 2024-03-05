#include <iostream>
#include <fstream>
#include <thread>

int main()
{
    std::cout << "Server ON" << std::endl;
    int number;
    int result;

    while (true)
    {
        std::ifstream dane("dane.txt");
        if (!dane)
        {
            std::cout << "Unable to open file" << std::endl;
            return 1;
        }
        dane >> number;
        dane.close();

        result = number * number;

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        std::ofstream wyniki("wyniki.txt");
        if (!wyniki)
        {
            std::cout << "Unable to open file" << std::endl;
            return 1;
        }
        wyniki << result;
        wyniki.close();
    }
    return 0;
}
