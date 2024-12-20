#pragma once

#include "ServiceInterface.hpp"

class PrintService : public ServiceInterface {
public:
    explicit PrintService();
    virtual ~PrintService();

public:
    virtual bool run(ArgvUtil& argvUtil, SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ResultList* resultList) override;
    virtual void stop() override;
};