//
// Created by wangzijian on 8/7/24.
//

#ifndef LITE_AI_TOOLKIT_TRT_CLIP_H
#define LITE_AI_TOOLKIT_TRT_CLIP_H
#include "lite/trt/core/trt_config.h"
#include "lite/trt/core/trt_logger.h"

namespace trtsd
{
    class TRTClip{
    public:
        TRTClip(const std::string &_onnx_path, unsigned int _num_threads = 1 );
        ~TRTClip();

    private:
        std::unique_ptr<nvinfer1::IRuntime> trt_runtime;
        std::unique_ptr<nvinfer1::ICudaEngine> trt_engine;
        std::unique_ptr<nvinfer1::IExecutionContext> trt_context;

        Logger trt_logger;
        std::vector<void*> buffers;
        cudaStream_t stream;

        std::vector<int64_t> input_node_dims;
        std::vector<std::vector<int64_t>> output_node_dims;
        std::size_t output_tensor_size = 512;
        const char * input_names = "TEXT";
        const char * output_names = "TEXT_EMBEDDING";


        const char* trt_model_path = nullptr;
        const char* log_id = nullptr;
    public:

        void encode_text(std::vector<std::string> input_text, std::vector<std::vector<int>> &output);

        void inference(std::vector<std::string> input,std::vector<std::vector<float>> &output);

    };


}



#endif //LITE_AI_TOOLKIT_TRT_CLIP_H
