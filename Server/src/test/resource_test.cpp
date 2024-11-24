#include <iostream>

#include "../../include/util/Result.hpp"

#include "../../include/resource/NetworkResource.hpp"
#include "../../include/resource/NetworkUsageInfo.hpp"
#include "../../include/resource/MemoryResource.hpp"
#include "../../include/resource/MemoryUsageInfo.hpp"
#include "../../include/resource/CPUInterfaceInfo.hpp"
#include "../../include/resource/CPUResource.hpp"
#include "../../include/resource/CPUUsageInfo.hpp"
#include "../../include/resource/SystemResource.hpp"
#include "../../include/resource/SystemUsageInfo.hpp"
#include "../../include/resource/SystemInterfaceInfo.hpp"

static void testSystemResource() {
    SystemResource resource;

    Result result;
    SystemInterfaceInfo interfaceInfo;
    if (!resource.readInterfaceInfo(&interfaceInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
    }
    CPUInterfaceInfo cpuInterfaceInfo = interfaceInfo.getCPUInfo();
    std::cout << "System Interface Info ================================" << std::endl;
    std::cout << "Model: " << cpuInterfaceInfo.getModel() << std::endl;
    std::cout << "Vendor: " << cpuInterfaceInfo.getVendor() << std::endl;
    std::cout << "Cores : " << cpuInterfaceInfo.getCoreCount() << std::endl << std::endl;

    ResultList resultList;
    SystemUsageInfo usageInfo;
    std::string networkInterfaceName = "enp0s3";
    if (!resource.readUsageInfo(networkInterfaceName, &usageInfo, &resultList)) {
        std::cout << "readUsageInfo Error" << std::endl;
    }
    CPUUsageInfo cpuUsageInfo = usageInfo.getCPUInfo();
    MemoryUsageInfo memoryUsageInfo = usageInfo.getMemoryInfo();
    NetworkUsageInfo networkUsageInfo;
    networkUsageInfo = usageInfo.getNetworkInfo();
    std::cout << "System Usage Info ======================================" << std::endl;
    std::cout << "CPU Usage: " << cpuUsageInfo.getUsage() << "%" << std::endl;
    std::cout << "Total Memory: " << (int)memoryUsageInfo.getTotalMemoryToKbytes() << std::endl;
    std::cout << "Usage Memory: " << (int)memoryUsageInfo.getUsageMemoryToKbytes() << std::endl;
    std::cout << "Total Virtual Memory: " << (int)memoryUsageInfo.getTotalVirtualMemoryToKbytes() << std::endl;
    std::cout << "Usage Virtual Memory: " << (int)memoryUsageInfo.getUsageVirtualMemoryToKbytes() << std::endl;
    std::cout << "Network Total Size: " << networkUsageInfo.getTotalSize() << std::endl;
    std::cout << "Network Send Size: " << networkUsageInfo.getSendSize() << std::endl;
    std::cout << "Network Recv Size: " << networkUsageInfo.getRecvSize() << std::endl;
    std::cout << "Network Total Packet: " << networkUsageInfo.getTotalPacket() << std::endl;
    std::cout << "Network Send Packet: " << networkUsageInfo.getSendPacket() << std::endl;
    std::cout << "Network Recv Packet: " << networkUsageInfo.getRecvPacket() << std::endl;
}

int main(void) {
    testSystemResource();
    return 0;
}