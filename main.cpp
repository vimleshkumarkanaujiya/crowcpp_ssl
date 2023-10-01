#define CROW_ENABLE_SSL

#include "crow.h"
using namespace std;
using namespace crow;

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([](const request &req, response &res){
     ifstream in("public/index.html", ifstream::in);
     if(in){
        ostringstream contents;
        contents << in.rdbuf();
        in.close();
        res.write(contents.str());
     }else{
        res.write("Not found");
     }
      res.end();
    });

    app.bindaddr("127.0.0.1")
    .port(443)
    .ssl_file("localhost.crt","localhost.key")
    .multithreaded()
    .run();
}
