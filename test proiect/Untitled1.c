#include<stdio.h>
#include<dirent.h>
#include<windows.h>
#include<windowsx.h>
#include<mmsystem.h>
#include<MMSystem.h>
#include<string.h>
#include<conio.h>
#include<MMsystem.h>
#include<stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "playlist.c"
#include "player.c"
#include "menu.c"
#include "favorite.c"

char songname[100];
char genre[100];
char reparatie[100];
bool isFav;
bool isStopped;
char playlist[100];

int main() {

    system("color 0a");

    printf("\n 888b     d888                   d8b               8888888b.  888                                    ");
    printf("\n 8888b   d8888                   Y8P               888   Y88b 888                                    ");
    printf("\n 88888b.d88888                                     888    888 888                                    ");
    printf("\n 888Y88888P888 888  888 .d8888b  888  .d8888b      888   d88P 888  8888b.  888  888  .d88b.  888d888 ");
    printf("\n 888 Y888P 888 888  888 88K      888 d88P          8888888P   888      88b 888  888 d8P  Y8b 888P    ");
    printf("\n 888  Y8P  888 888  888  Y8888b. 888 888           888        888 .d888888 888  888 88888888 888     ");
    printf("\n 888       888 Y88b 888      X88 888 Y88b.         888        888 888  888 Y88b 888 Y8b.     888     ");
    printf("\n 888       888   Y88888  88888P' 888   Y8888P      888        888  Y888888   Y88888   Y8888  888     ");
    printf("\n                                                                                888                  ");
    printf("\n                                                                           Y8b d88P                  ");
    printf("\n                                                                             Y88P                    ");



    playFirst();
    player();

    return 0;
}
