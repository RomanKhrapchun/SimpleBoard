#include <iostream>

#include "../../include/util/Result.hpp"

#include "../../include/print/ProgressBar.hpp"
#include "../../include/print/FontColor.hpp"
#include "../../include/print/TitleBar.hpp"
#include "../../include/print/PrintCPUInterfaceInfo.hpp"
#include "../../include/print/PrintMemoryUsageInfo.hpp"
#include "../../include/print/PrintNetworkUsageInfo.hpp"

#include "../../include/resource/CPUResource.hpp"
#include "../../include/resource/CPUInterfaceInfo.hpp"
#include "../../include/resource/MemoryResource.hpp"
#include "../../include/resource/MemoryUsageInfo.hpp"
#include "../../include/resource/NetworkResource.hpp"
#include "../../include/resource/NetworkUsageInfo.hpp"

void testProgressBar() {
    std::cout << ProgressBar("test 50%", 50.0, 100.0, FontColor(FONT_COLOR::CPU_FONT_COLOR)) << std::endl;
    std::cout << ProgressBar("test 100%", 100.0, 100.0) << std::endl;
}

void testTitleBar() {
    std::cout << TitleBar("Test main titlebar", TITLEBAR_TYPE::MAIN) << std::endl;
    std::cout << TitleBar("Test sub titlebar", TITLEBAR_TYPE::SUB) << std::endl;
}

void testPrintMemoryInfo() {
    MemoryResource resource;
    MemoryUsageInfo usageInfo;

    Result result;
    if (!resource.readMemoryUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    std::cout << TitleBar("Memory", TITLEBAR_TYPE::SUB) << std::endl;
    std::cout << PrintMemoryUsageInfo(usageInfo) << std::endl;
    std::cout << ProgressBar("사용량", usageInfo.getUsageMemoryToKbytes(), usageInfo.getTotalMemoryToKbytes(), FontColor(FONT_COLOR::MEMORY_FONT_COLOR)) << "\t\t"
              << ProgressBar("사용량", usageInfo.getUsageVirtualMemoryToKbytes() , usageInfo.getTotalVirtualMemoryToKbytes(), FontColor(FONT_COLOR::MEMORY_FONT_COLOR))
              << std::endl;
}

void testPrintNetworkInfo() {
    NetworkResource resource;
    NetworkUsageInfo usageInfo;

    std::string networkInterfaceName = "enp0s3";
    Result result;
    for (int i = 0; i < 2; i++) {
        if (!resource.readNetworkUsageInfoPerSecond(networkInterfaceName, &usageInfo, &result)) {
            std::cout << result.getErrorMessage() << std::endl;
            return;
        }
    }

    std::cout << TitleBar("Network", TITLEBAR_TYPE::SUB) << std::endl;
    std::cout << PrintNetworkUsageInfo(usageInfo) << std::endl;
}

void testPrintCPUInfo() {
    CPUResource resource;
    CPUInterfaceInfo interfaceInfo;

    Result result;
    if (!resource.readCPUInterfaceInfo(&interfaceInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    CPUUsageInfo usageInfo;
    if (!resource.readCPUUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    std::cout << TitleBar("CPU", TITLEBAR_TYPE::SUB) << std::endl;
    std::cout << PrintCPUInterfaceInfo(interfaceInfo) << std::endl;
    std::cout << ProgressBar("CPU 사용량", (double)usageInfo.getUsage(), 100.0, FontColor(FONT_COLOR::CPU_FONT_COLOR))
              << std::endl;
}

int main(void) {
    testProgressBar();
    testTitleBar();

    std::cout << TitleBar("System Resource", TITLEBAR_TYPE::MAIN) << std::endl;
    testPrintMemoryInfo();
    testPrintNetworkInfo();
    testPrintCPUInfo();
    return 0;
}