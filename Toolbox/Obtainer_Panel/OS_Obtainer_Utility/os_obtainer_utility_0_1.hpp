#pragma once

#include <iostream>

namespace OBTP {
    namespace OSOU {
        std::string Obtain_OS() {
            #if defined(_WIN32)
                return "Windows";
            #elif defined(__linux__)
                return "Linux";
            #elif defined(__APPLE__) && defined(__MACH__)
                return "macOS";
            #elif defined(__ANDROID)
                return "Android";
            #elif defined(__FreeBSD__)
                return "FreeBSD";
            #elif defined(_OpenBSD__)
                return "OpenBSD";
            #elif defined(_NetBSD__)
                return "NetBSD";
            #elif defined(_DragonFly__)
                return "DragonFly_BSD";
            #elif defined(__sun)
                return "Solaris";
            #elif defined(_AIX)
                return "AIX";
            #elif defined(__hpux)
                return "HP_UX";
            #else
                return "Unknown_OS";
            #endif
        }
    }
}
