#include "Server/include/src/main/Resource.hpp"
#include "Server/include/src/util/ArgvUtil.hpp"
#include "Server/include/src/resource/SystemResourceService.hpp"


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