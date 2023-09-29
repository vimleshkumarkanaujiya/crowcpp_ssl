#define CROW_ENABLE_SSL
#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "SSL Testing";
    });

    app.bindaddr("127.0.0.1")
    .port(443)
    .ssl_file("localhost.crt","localhost.key")
    .multithreaded()
    .run();
}
