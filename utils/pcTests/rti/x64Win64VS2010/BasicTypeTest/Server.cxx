/** 
 * Generated by DDSRPC   *
 * Simplest server main  *
 */

#include "BasicTypeTestServer.h"
#include "strategies/ThreadPoolStrategy.h"

int main(int argc, char **argv)
{
    int returnedValue = 0;
    unsigned int threadPoolSize = 5;
    eProsima::DDSRPC::ThreadPoolStrategy *pool = new eProsima::DDSRPC::ThreadPoolStrategy(threadPoolSize);
    BasicTypeTestServer *server = new BasicTypeTestServer("BasicTypeTestService", pool);
    server->serve();
    
    while(1)
    {
        Sleep(10000);
    }

    delete server;
    delete pool;
    
    return 0;
}
