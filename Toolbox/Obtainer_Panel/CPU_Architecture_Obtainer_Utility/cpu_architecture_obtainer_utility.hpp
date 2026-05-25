#pragma once

#include <string>

namespace OBTP {
    namespace CPUARCHOU {
        std::string Obtain_CPU_Architecture() {
            #if defined(__x86_64__) || defined(_M_X64)
                return "x64";
            #elif defined(__i386__) || defined(_M_IX86)
                return "x86/i386";
            #elif defined(__aarch64__) || defined(_M_ARM64)
                return "AArch64";
            #elif defined(__arm__) || defined(_M_ARM)
                return "AArch32";
            #elif defined(__riscv) || defined(__riscv_xlen)
                return "RISC-V";
            #else
                return "Unknown_CPU_Architecture";
            #endif
        }
    }
}