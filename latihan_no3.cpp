#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(){
    system("cvlc -I rc --rc-host localhost:5666 -d");
    string arg;
    int detik;
    printf("For more information \'help\'\n");
    while(1){
        printf("command > ");
        cin>>arg;
        if(arg == "help"){
            printf("Add to playlist : add [file]\n");
            printf("Display playlist's music : list\n");
            printf("Play music : play\n");
            printf("Pause music : pause\n");
            printf("Continue music : continue\n");
            printf("Stop music : stop\n");
        }
        else if(arg == "playlist"){
            system("echo playlist | netcat localhost 5666");
        }
        else if(arg == "add"){
            cin>>arg;
            arg = "echo add "+arg+" | netcat localhost 5666";
            //konversi string C++ ke string konvensional pakai .c_str() dari stdlib
            system(arg.c_str());
        }
        else if(arg == "play"|| arg=="continue"){
            if(arg=="continue"){
                cin>>detik;
                sleep(detik);
            }
            cout<<"playing.."<<endl;
            system("echo play | netcat localhost 5666");
        }
        else if(arg == "pause"){
            cin>>detik;
            sleep(detik);
            system("echo pause | netcat localhost 5666");
        }
        else if(arg == "stop"){
            cin>>detik;
            sleep(detik);
            system("echo stop | netcat localhost 5666");
        }

    }

    return 0;


}
