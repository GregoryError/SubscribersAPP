#include "myclient.h"
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setApplicationName("Успех");
    app.setApplicationDisplayName("Успех");


    app.setOrganizationName("Success");
    app.setOrganizationDomain("www.comfort-tv.ru/");
    app.setApplicationName("Success");


    QPixmap lg(":/logo.png");


    QSplashScreen splash(lg);


    splash.show();


    app.processEvents();

    QTime time;
    time.start();
    for(int i(0); i < 50;)
    {
        if(time.elapsed() > 15){
            time.start();
            ++i;
        }
    }



    QLabel lbl("Loading");
    splash.finish(&lbl);


   BackEnd* obj = new BackEnd;
   MyClient* client = new MyClient;

  // qmlRegisterType<*client>("lib.MyClient", 1, 0, "myClient");
   obj->cont->setContextProperty("myClient", client);



  // client->Sender("(len1-29c#h7rJ2Pn4)getAllData!");


  // Q_UNUSED(obj);
  // Q_UNUSED(client);


    return app.exec();
}
