//
// Created by wangzijian on 11/5/24.
//
#include "lite/lite.h"

static void test_default()
{
#ifdef ENABLE_ONNXRUNTIME
    std::string face_swap_onnx_path = "/home/lite.ai.toolkit/examples/hub/onnx/cv/inswapper_128.onnx";
    std::string face_detect_onnx_path = "/home/lite.ai.toolkit/examples/hub/onnx/cv/yoloface_8n.onnx";
    std::string face_landmarks_68 = "/home/lite.ai.toolkit/examples/hub/onnx/cv/2dfan4.onnx";
    std::string face_recognizer_onnx_path = "/home/lite.ai.toolkit/examples/hub/onnx/cv/arcface_w600k_r50.onnx";;
    std::string face_embeding_onnx_path = "/home/lite.ai.toolkit/examples/hub/onnx/cv/yoloface_8n.onnx";

    std::string source_image_path = "/home/lite.ai.toolkit/1.jpg";
    std::string target_image_path = "/home/lite.ai.toolkit/5.jpg";

    lite::cv::face::detect::YOLOV8Face *yolov8_face = new lite::cv::face::detect::YOLOV8Face(face_detect_onnx_path);

    lite::cv::faceid::Face_68Landmarks *face68Landmarks = new lite::cv::faceid::Face_68Landmarks(face_landmarks_68);

    lite::cv::faceid::Face_Recognizer *face_recognizer = new lite::cv::faceid::Face_Recognizer(face_recognizer_onnx_path);

    lite::cv::face::swap::InSwapper *face_swap = new lite::cv::face::swap::InSwapper(face_swap_onnx_path);


    std::vector<lite::types::Boxf> detected_boxes;
    cv::Mat img_bgr = cv::imread(source_image_path);
    yolov8_face->detect(img_bgr, detected_boxes);
    int position = 0; // 0号位置的脸部
    auto test_bounding_box = detected_boxes[0];
    std::vector<cv::Point2f> face_landmark_5of68;
    face68Landmarks->detect(img_bgr, test_bounding_box, face_landmark_5of68);
    std::vector<float> source_image_embeding;
    face_recognizer->detect(img_bgr,face_landmark_5of68,source_image_embeding);

    // 上面是source的 现在下面是target的
    std::vector<lite::types::Boxf> target_detected_boxes;
    cv::Mat target_img_bgr = cv::imread(target_image_path);
    yolov8_face->detect(target_img_bgr, target_detected_boxes);
    auto target_test_bounding_box = target_detected_boxes[0];
    std::vector<cv::Point2f> target_face_landmark_5of68;
    face68Landmarks->detect(target_img_bgr, target_test_bounding_box,target_face_landmark_5of68);

    cv::Mat face_swap_image;
    face_swap->detect(target_img_bgr,source_image_embeding,target_face_landmark_5of68,face_swap_image);












    // 1. Test Default Engine ONNXRuntime


//    std::vector<cv::Point2f> face_landmark_5 = {
//            cv::Point2f(568.2485f, 398.9512f),
//            cv::Point2f(701.7346f, 399.64795f),
//            cv::Point2f(634.2213f, 482.92694f),
//            cv::Point2f(583.5656f, 543.10187f),
//            cv::Point2f(684.52405f, 543.125f)
//    };
//    cv::Mat img_bgr = cv::imread(test_img_path);
//
//    face_recognizer->detect(img_bgr,face_landmark_5);
//
//
//    std::cout<<"face id detect done!"<<std::endl;

    delete face_recognizer;
#endif
}

int main(__unused int argc, __unused char *argv[])
{
    test_default();
    return 0;
}