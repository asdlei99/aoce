#pragma once
#include <Layer/InputLayer.hpp>

#include "VkLayer.hpp"

namespace aoce {
namespace vulkan {
namespace layer {

// 把各种VideoFormat转化成ImageFormat,主要二种,R8/RGBA8
class VkInputLayer : public InputLayer, public VkLayer {
    AOCE_LAYER_QUERYINTERFACE(VkInputLayer)
   private:
    std::unique_ptr<VulkanBuffer> inBuffer;
    // 如果需要GPU计算,需要先把inBuffer copy 到 gpu local
    std::unique_ptr<VulkanBuffer> inBufferX;
    // 是否需要GPU计算
    bool bUsePipe = false;

   public:
    VkInputLayer(/* args */);
    ~VkInputLayer();

    // InputLayer
   public:
    virtual void onDataReady() override{};
    // VkLayer
   protected:
    virtual void onInitGraph() override;
    virtual void onInitVkBuffer() override;
    virtual void onInitPipe() override;
    virtual void onPreCmd() override;
    virtual bool onFrame() override;
};

}  // namespace layer
}  // namespace vulkan
}  // namespace aoce