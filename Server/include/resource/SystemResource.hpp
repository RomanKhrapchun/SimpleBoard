#pragma once

#include "../util/Result.hpp"
#include "../util/ResultList.hpp"

#include "SystemInterfaceInfo.hpp"
#include "SystemUsageInfo.hpp"

#include <vector>

class SystemResource {
public:
    explicit SystemResource();
    virtual ~SystemResource();

public:
    bool readInterfaceInfo(SystemInterfaceInfo* interfaceInfo, Result* result);

    bool readUsageInfo(std::string& networkInterfaceName, SystemUsageInfo* usageInfo, ResultList* resultList);

private:
    bool readSystemInterfaceInfo(SystemInterfaceInfo* interfaceInfo, Result* result);
    bool readSystemUsageInfo(std::string& networkInterfaceName, SystemUsageInfo* usageInfo, ResultList* resultList);
};