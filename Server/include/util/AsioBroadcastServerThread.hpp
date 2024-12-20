#pragma once

#include "Result.hpp"
#include "ResultList.hpp"
#include "ReturnedThread.hpp"
#include "AsioSessionList.hpp"
#include "ByteBuffer.hpp"

#include "boost/asio.hpp"

#include <memory>
#include <mutex>

class AsioBroadcastServerThread : public ReturnedThread<Result> {
public:
    explicit AsioBroadcastServerThread(int servicePort);
    virtual ~AsioBroadcastServerThread();

public:
    virtual void run(Result* returnValue, Result* result) override;

public:
    void broadcast(ByteBuffer& byteBuffer, ResultList* resultList);

    bool isRunning();
    void stop();

private:
    bool createAcceptor(Result* result);
    bool serviceStart(Result* result);
    
    void asyncAcceptStart();

private:
    bool isIOContextRunning;
    int servicePort;
    boost::asio::io_context ioContext;
    std::shared_ptr<boost::asio::ip::tcp::acceptor> acceptor;

    std::mutex sessionListMutex;
    AsioSessionList sessionList;
};