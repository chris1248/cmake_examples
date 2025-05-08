#include <string>
#include <cstdlib>

std::string getPlatformArchitecture() {
#if defined(_WIN32) || defined(_WIN64)
    #if defined(_WIN64)
        return "x64";
    #else
        return "x86";
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC
        return "macOS";
    #endif
#elif defined(__linux__)
    #if defined(__x86_64__) || defined(_M_X64)
        return "x64";
    #elif defined(__i386__) || defined(_M_IX86)
        return "x86";
    #elif defined(__aarch64__)
        return "ARM64";
    #elif defined(__arm__)
        return "ARM";
    #else
        return "Unknown Linux Architecture";
    #endif
#elif defined(__unix__)
    return "Unix";
#elif defined(_POSIX_VERSION)
    return "POSIX";
#else
    return "Unknown Platform";
#endif
}