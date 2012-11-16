/** 
 * Generated by DDSRPC                                                   *
 * Example client. Method params should be initialized before execution  *
 */

#include "HelloWorldAsyncProxy.h"
#include "HelloWorldAsyncRequestReplyPlugin.h"
#include "exceptions/Exceptions.h"

class SayHelloHandler : public HelloWorldAsync_sayHelloCallbackHandler
{
    public:
		SayHelloHandler() : received(false){}

        void sayHello(/*out*/ char* sayHello_ret)
		{
			printf("%s\n", sayHello_ret);
			received = true;
		}
   
        void on_exception(const eProsima::DDSRPC::Exception &ex)
		{
			printf("Exception: %s\n", ex.what());
			received = true;
		}

		bool isReceived() const
		{
			return received;
		}

private:
	    bool received;
};

int main(int argc, char **argv)
{
    HelloWorldAsyncProxy *proxy = new HelloWorldAsyncProxy("HelloWorldAsyncService");
    SayHelloHandler handler;
    char*  name = "Ricardo";        

    try
    {
        proxy->sayHello_async(handler, name);
    }
    catch(eProsima::DDSRPC::Exception &ex)
    {
		printf("Exception\n", ex.what());
    }

	while(!handler.isReceived())
		Sleep(1000);

    delete(proxy);
   
    return 0;
}
