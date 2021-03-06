#pragma once
#include "BaseLayer.hpp"

namespace aoce {

struct InputParamet {
    int32_t bCpu = true;
    int32_t bGpu = false;
};

// inputlayer 应该从VkBaseLayer/Dx11BaseLayer/CudaBaseLayer继承
class ACOE_EXPORT InputLayer : public ITLayer<InputParamet> {
   protected:
    VideoFormat videoFormat = {};
    uint8_t* frameData = nullptr;
    // 用于测试时复制frameData查找数据
    std::vector<uint8_t> videoFrameData;

   protected:
    virtual void onDataReady() = 0;

   public:
    // inputCpuData(uint8_t* data)这个版本没有提供长宽,需要这个方法指定
    void setImage(VideoFormat videoFormat, int32_t index = 0);
    // 输入CPU数据,这个data需要与pipegraph同线程,因为从各方面考虑这个不会复制data里的数据.
    void inputCpuData(uint8_t* data, int32_t index = 0);
    void inputCpuData(const VideoFrame& videoFrame, int32_t index = 0);
    void inputCpuData(uint8_t* data, const ImageFormat& imageFormat);
};

}  // namespace aoce