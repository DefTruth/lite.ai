//
// Created by wangzijian on 24-7-11.
//

#ifndef LITE_AI_TOOLKIT_TRT_CORE_H
#define LITE_AI_TOOLKIT_TRT_CORE_H

#include "trt_config.h"
#include "trt_handler.h"
#include "trt_types.h"

namespace trtcv{
    class LITE_EXPORTS TRTYoloFaceV8; // [1] * reference: https://github.com/derronqi/yolov8-face
    class LITE_EXPORTS TRTYoloV5;     // [2] * reference: https://github.com/ultralytics/yolov5
    class LITE_EXPORTS TRTYoloX;      // [3] * reference: https://github.com/Megvii-BaseDetection/YOLOX
}

namespace trtcv{
    using trtcore::BasicTRTHandler;
}



#endif //LITE_AI_TOOLKIT_TRT_CORE_H
