#include <opencv2/opencv.hpp>

#include "Terminal_Color_Utility/terminal_color_utility.hpp"
#include "Exit_Type_Utility/exit_type_utility.hpp"

namespace CVP {
    namespace WOU {
        ETU::ET Open_Webcam() {
            cv::VideoCapture camera_0(0);

            if (!camera_0.isOpened()) {
                TCU::Terminal_Failure("Failure: Failed to open Camera_0.");
                return ETU::ET::Failure;
            }

            cv::Mat frame;
            bool camera_enabled = true;

            while (camera_enabled) {
                if (!camera_0.read(frame)) {
                    TCU::Terminal_Error("Error: Could not read frame from Camera_0.");
                    camera_enabled = false;
                }

                cv::imshow("Webcam", frame);

                int key_press = cv::waitKey(1);

                if (key_press == 27) {
                    camera_enabled = false;
                }
            }

            camera_0.release();
            cv::destroyAllWindows();

            return ETU::ET::Success;

        }
    }
}
