#pragma once

#include <print>
#include <stdexcept>
#include <string>
#include <cstdint>

// Check OS (preprocessor)
#if defined(_WIN32)
    #include <windows.h>
#elif defined(__linux__)
    #include <cstdio>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/types.h>
    #include <sys/sysctl.h>
#endif


namespace OBTP {
    namespace RAOU {
        uint64_t Obtain_RAM_Amount() {
            #if defined(_WIN32)
                MEMORYSTATUSEX memory_status;
                memory_status.dwLength = sizeof(memory_status);
                if (!GlobalMemoryStatusEx(&memory_status)) {
                    throw std::runtime_error("Failure: GlobalMemoryStatus failed.");
                }

                return memory_status.ullTotalPhys;
            
            #elif defined(__linux__)
                FILE* meminfo_file fopen("/proc/meminfo", "r");
                if (!meminfo_file) throw std::runtime_error("Failure: Cannot open /proc/meminfo.");

                char line[256];
                uint64_t kb = 0;

                while (fgets(line, sizeof(line), meminfo_file)) {
                    if (sscanf(line, "MemTotal: %lu kB", &kb) == 1) {
                        fclose(meminfo_file);
                        return kb * 1024ULL;
                    }
                }

                fclose(meminfo_file);
                throw std::runtime_error("Error: MemTotal not found.");
            
            #elif defined(__APPLE__) && defined(__MACH__)
                uint64_t memsize = 0;
                size_t len = sizeof(memsize);
                int mib[2] = { CTL_HW, HW_MEMSIZE };

                if (sysctl(mib, 2, &memsize, &len, NULL, 0) != 0) {
                    throw std::runtime_error("sysctl HW_MEMSIZE failed");
                }

                return memsize;
            #endif
        }
    }
}