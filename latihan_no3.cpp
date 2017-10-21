#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
    system("cvlc -I rc --rc-host localhost:5666 -d");
    sleep(1);
    system("echo add /home/falnerz/Music/dawn.mp3 | netcat localhost 5666");
    sleep(1);
    system("echo play | netcat localhost 5666");






}
