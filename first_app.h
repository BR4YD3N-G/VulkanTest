#pragma once

#include "ce_device.h"
#include "ce_pipeline.h"
#include "ce_swap_chain.h"
#include "ce_window.h"

//std
#include <memory>
#include <vector>

namespace ce {
    class FirstApp{
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;
        
            FirstApp();
            ~FirstApp();

            FirstApp(const FirstApp &) = delete;
            FirstApp &operator=(const FirstApp &) = delete;

            void run();

        private:
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void drawFrame();

            CeWindow ceWindow{WIDTH, HEIGHT, "Hello Vulkan"};
            CeDevice ceDevice{ceWindow};
            CeSwapChain ceSwapChain{ceDevice, ceWindow.getExtent()};
            std::unique_ptr<CePipeline> cePipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
    };
}