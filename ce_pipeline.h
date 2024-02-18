#pragma once

#include "ce_device.h"

#include <string>
#include <vector>

namespace ce {

    struct PipelineConfigInfo {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttatchment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencileInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class CePipeline{
        public:
        CePipeline(
            CeDevice &device,
            const std::string& vertFilepath,
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);
        ~CePipeline();

        CePipeline(const CePipeline&) = delete;
        void operator=(const CePipeline&) = delete;

        void bind(VkCommandBuffer commandBuffer);

        static PipelineConfigInfo defaultPiplineConfigInfo(uint32_t width, uint32_t height);
    
        private:
            static std::vector<char> readFile(const std::string& filepath);

            void createGraphicsPipeline(
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);

            void createShaderModule(const std::vector<char>& code, VkShaderModule* VkShaderModule);

            CeDevice& ceDevice;
            VkPipeline graphicsPipline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };

}
