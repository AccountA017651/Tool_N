#include <iostream>
#include <fstream>
#include <print>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>

#include "Central_Versioning_Utility/central_versioning_utility.hpp"
#include "Obtainer_Panel/OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"
#include "Terminal_Color_Utility/terminal_color_utility.hpp"
#include "Miscellaneous_Panel/Crasher_Utility/crasher_utility.hpp"
#include "Miscellaneous_Panel/Long_Outputs_Utility/help_command_long_print_utility.hpp"
#include "Obtainer_Panel/CPU_Architecture_Obtainer_Utility/cpu_architecture_obtainer_utility.hpp"
#include "Exit_Type_Utility/exit_type_utility.hpp"
#include "Computer_Vision_Panel/Webcam_Opener_Utility/webcam_opener_utility.hpp"
#include "Computer_Vision_Panel/Basic_Face_Detection_Utility/basic_face_detection_utility.hpp"
#include "Obtainer_Panel/RAM_Amount_Obtainer_Utility/ram_amount_obtainer_utility.hpp"


int main(int argc, char* argv[]) {
    std::string os_name = OBTP::OSOU::Obtain_OS();
    std::string cpu_architecture_name = OBTP::CPUARCHOU::Obtain_CPU_Architecture();
    auto total_ram_amount = OBTP::RAOU::Obtain_RAM_Amount();
    bool command_used = false;
    bool main_running = true;

    while (main_running) {
        if (argc < 2) {
            TCU::Terminal_Error("No command provided, please provide a command.\n");
            return 1;
        }

        // Flag handler
        std::unordered_map<std::string, std::function<void(const std::string&)>> flag_map = {
            // QoL flags
            {"--version", [&](const std::string&){ std::print("Tool_N version: {}.{}.{}.{}\n", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE); }},
            {"-v",        [&](const std::string&){ std::print("Tool_N version: {}.{}.{}.{}\n", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE); }},
            {"--help",    [&](const std::string&){ LN_PRINT::Help_Command_Output(); }},
            {"-h",        [&](const std::string&){ LN_PRINT::Help_Command_Output(); }},
            // Flags with values
            {"--repeat",  [&](const std::string& value){ while (true) std::print("{}", value ); }}
        };

        // Command handler
        std::unordered_map<std::string, std::function<void()>> command_map = {
            // Misc commands
            {"Misc-Predictable-Terminate-0",      [&](){ CHR::DFND_BHVR::Explicit_Abort(); } },
            {"Misc-Unpredictable-Terminate-0",    [&](){ CHR::UNDN_BHVR::Divide_Zero(); } },
            {"Misc-Unpredictable-Terminate-1",    [&](){ CHR::UNDN_BHVR::Null_Pointer_Dereference(42); } },
            {"Misc-Unpredictable-Terminate-2",    [&](){ CHR::UNDN_BHVR::Stack_Overflow(); } },
            {"Misc-Unpredictable-Terminate-3",    [&](){ CHR::UNDN_BHVR::Volatile_Assembly_Illegal_Instruction(); } },
            {"Misc-Computer-Vision-Open-Webcam",       [&](){ CVP::WOU::Open_Webcam(); }},
            {"Misc-Computer-Vision-Face-Recognition",  [&](){ CVP::BFDU::Face_Recognition_Webcam(); }},
            // Info commands
            {"Info-CPU-Architecture",             [&](){ std::print("CPU Architecture: {}", cpu_architecture_name); }},
            {"Info-Operating-System",             [&](){ std::print("OS name: {}\n", os_name); }},
            {"Info-Total-RAM-Amount-Bytes",       [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount, "B"); }},
            {"Info-Total-RAM-Amount-KB",          [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount / 1000, "KB"); }},
            {"Info-Total-RAM-Amount-MB",          [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount / 1000 / 1000, "MB"); }},
            {"Info-Total-RAM-Amount-GB",          [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount / 1000 / 1000 / 1000, "GB"); }},
            {"Info-Total-RAM-Amount-KiB",         [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount / 1024, "KB"); }},
            {"Info-Total-RAM-Amount-MiB",         [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount / 1024 / 1024, "MB"); }},
            {"Info-Total-RAM-Amount-GiB",         [&](){ std::print("Total RAM Amount: {} {}\n", total_ram_amount / 1024 / 1024 / 1024, "GB"); }},
            // Formatting commands
            {"[NL]",                              [&](){ std::print("\n"); }}
        };


        for (int index = 1; index < argc; index++) {
            std::string arg = argv[index];

            auto flag_it = flag_map.find(arg);
            if (flag_it != flag_map.end()) {
                std::string value;
                if (index + 1 < argc && std::string(argv[index + 1]).starts_with("-") == false) {
                    value = argv[++index];
                }

                flag_it->second(value);
                continue;
            }

            auto cmd_it = command_map.find(arg);
            if (cmd_it != command_map.end()) {
                cmd_it->second();
                command_used = true;
                continue;
            }


            TCU::Terminal_Error("Unknown argument: " + arg + "\n");
            return 1;
        }

        return command_used ? 0 : 0;
    }
}
