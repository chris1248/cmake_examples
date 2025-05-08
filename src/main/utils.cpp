
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <limits.h>
#endif

#include "utils.h"

std::string getMachineHostname() {
    char hostname[256] = {0};

#ifdef _WIN32
    if (GetComputerNameA(hostname, (LPDWORD)&(sizeof(hostname))) == 0) {
        throw std::runtime_error("Failed to get hostname on Windows");
    }
#elif defined(__linux__)
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        throw std::runtime_error("Failed to get hostname on Linux/Unix");
    }
#else
    return std::string("Unknown OS");
#endif

    return std::string(hostname);
}