#define CROW_ENABLE_SSL

#include "crow.h"
using namespace std;
using namespace crow;

void sendFile(response &res, string filename, string contentType){
      ifstream in("public/" + filename, ifstream::in);
     if(in){
        ostringstream contents;
        contents << in.rdbuf();
        in.close();
        res.set_header("Content-Type", contentType);
        res.write(contents.str());
     }else{
        res.code = 404;
        res.write("Not found");
     }
        res.end();   
}

void sendHTML(response &res, string filename){
    sendFile(res, filename + ".html", "text/html");
}

void sendStyle(response &res, string filename){
    sendFile(res, "styles/" + filename, "text/css");
}

void sendScript(response &res, string filename){
    sendFile(res, "scripts/" + filename, "text/javascript");
}

void sendImage(response &res, string filename){
    sendFile(res, "images/" + filename, "image/jpeg");
}

void sendFont(response &res, string filename){
    sendFile(res, "fonts/" + filename, "font/ttf");
}

int main(int argc, char* argv[])
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/scripts/<string>")
    ([](const request &req, response &res, string filename){
     sendScript(res, filename);
    });

    CROW_ROUTE(app, "/styles/<string>")
    ([](const request &req, response &res, string filename){
     sendStyle(res, filename);
    });

    CROW_ROUTE(app, "/images/<string>")
    ([](const request &req, response &res, string filename){
     sendImage(res, filename);
    });

    CROW_ROUTE(app, "/fonts/<string>")
    ([](const request &req, response &res, string filename){
     sendFont(res, filename);
    });

    CROW_ROUTE(app, "/")
    ([](const request &req, response &res){
     sendHTML(res, "index");
    });

    app.bindaddr("127.0.0.1")
    .port(443)
    .ssl_file("localhost.crt","localhost.key")
    .multithreaded()
    .run();
}
