#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
    /* code */
    std::cout << "hello " << std::endl;
    spdlog::info("{}", "world");
    return 0;
}
