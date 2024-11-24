#include "../../include/main/Resource.hpp"
#include "../../include/util/ArgvUtil.hpp"
#include "../../include/resource/SystemResource.hpp"
#include "Resource.cpp"


#include <csignal>

void signalHandler(int sig) {
    if (sig == SIGINT) {
        Resource::getInstance().stop();
    }
}
int main(int argc, const char* argv[]) {
    ArgvUtil argvUtil;
    argvUtil.setArgument(argc, argv);

    std::signal(SIGINT, signalHandler);
    
    Resource::getInstance().start(argvUtil);

    return 0;
}