#pragma once

#include "boost/asio.hpp"

#include "Result.hpp"
#include "ByteBuffer.hpp"

class AsioSession {
public:
    explicit AsioSession(boost::asio::ip::tcp::socket socket);
    virtual ~AsioSession();

public:
    bool send(ByteBuffer& data, Result* result);
    bool recv(ByteBuffer* data, Result* result);

private:
    boost::asio::ip::tcp::socket socket;
};