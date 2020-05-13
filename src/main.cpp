#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
    /* code */
    std::cout << "hello " << std::endl;
    spdlog::info("{}", "world");

#ifdef DEBUG
    spdlog::info("Debug macro");
#endif

#ifdef RELEASE
    spdlog::info("Release macro");
#endif

    return 0;
}
