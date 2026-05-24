#pragma once

#include <vector>
#include <opencv2/opencv.hpp>

#include "Exit_Type_Utility/exit_type_utility.hpp"
#include "Terminal_Color_Utility/terminal_color_utility.hpp"

namespace CVP {
    namespace BFDU {
        ETU::ET Face_Recognition_Webcam() {
            cv::VideoCapture camera_0(0);
            if (!camera_0.isOpened()) {
                TCU::Terminal_Failure("Failure: Failed to open Camera_0.");
                return ETU::ET::Failure;
            }

            cv::CascadeClassifier face_cascade;
            if (!face_cascade.load("External/OpenCV/sources/data/haarcascades/haarcascade_frontalface_default.xml")) {
                TCU::Terminal_Error("Error: Could not load haarcascade_frontalface_default.xml");
                return ETU::ET::Error;
            }

            cv::Mat frame;
            bool camera_enabled = true;
            while (camera_enabled) {
                if (!camera_0.read(frame)) {
                    TCU::Terminal_Error("Error: Could not read frame from Camera_0.");
                    camera_enabled = false;
                }

                std::vector<cv::Rect> faces;
                face_cascade.detectMultiScale(frame, faces);
                
                // Draw blue-bounding-boxes
                for (const auto& face : faces) {
                    cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);
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