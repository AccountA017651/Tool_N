#pragma once

#include <string>
#include <print>

namespace TCU {
    struct TCU_ASCII_Values {
        inline static const std::string ANSI_FOREGROUND_COLOR_BLACK = "\033[30m";
        inline static const std::string ANSI_FOREGROUND_COLOR_WHITE = "\033[37m";
        inline static const std::string ANSI_FOREGROUND_COLOR_RED = "\033[31m";
        inline static const std::string ANSI_FOREGROUND_COLOR_GREEN = "\033[32m";
        inline static const std::string ANSI_FOREGROUND_COLOR_BLUE = "\033[34m";
        inline static const std::string ANSI_FOREGROUND_COLOR_YELLOW = "\033[33m";
        inline static const std::string ANSI_FOREGROUND_COLOR_MAGENTA = "\033[35m";
        inline static const std::string ANSI_FOREGROUND_COLOR_CYAN = "\033[36m";
        inline static const std::string ANSI_FOREGROUND_COLOR_RESET = "\033[0m";
    };

    inline std::string Terminal_Warn_No_Output(const std::string& msg) {
        return TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_YELLOW + msg + TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET;
    }

    inline std::string Terminal_Error_No_Output(const std::string& msg) {
        return TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RED + msg + TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET;
    }

    inline std::string Terminal_Info_No_Output(const std::string& msg) {
        return TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_BLUE + msg + TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET;
    }

    inline void Terminal_Warn(const std::string& msg) {
        std::print("{}{}{}", TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_YELLOW, msg, TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET);
    }

    inline void Terminal_Error(const std::string& msg) {
        std::print("{}{}{}", TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RED, msg, TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET);
    }

    inline void Terminal_Failure(const std::string& msg) {
        std::print("{}{}{}", TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RED, msg, TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET);
    }

    inline void Terminal_Info(const std::string& msg) {
        std::print("{}{}{}", TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_BLUE, msg, TCU_ASCII_Values::ANSI_FOREGROUND_COLOR_RESET);
    }
}