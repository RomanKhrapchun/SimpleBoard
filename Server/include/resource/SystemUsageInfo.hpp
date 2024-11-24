#pragma once

#include "CPUUsageInfo.hpp"
#include "NetworkUsageInfo.hpp"
#include "MemoryUsageInfo.hpp"

class SystemUsageInfo {
public:
    explicit SystemUsageInfo();
    virtual ~SystemUsageInfo();

public:
    // setter
    void setCPUInfo(const CPUUsageInfo& usageInfo);
    void setMemoryInfo(const MemoryUsageInfo& usageInfo);
    void setNetworkInfo(const NetworkUsageInfo& usageInfo);

    // getter
    const CPUUsageInfo&     getCPUInfo();
    const MemoryUsageInfo&  getMemoryInfo();
    const NetworkUsageInfo& getNetworkInfo();
    
private:
    void calcNetworkUsageMaximum(const NetworkUsageInfo& usageInfo);

private:
    CPUUsageInfo cpuUsageInfo;
    MemoryUsageInfo memoryUsageInfo;
    NetworkUsageInfo networkUsageInfo;
};