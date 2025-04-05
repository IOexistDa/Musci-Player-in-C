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

char songname[100];
char genre[100];
char reparatie[100];
bool isFav;
bool isStopped;
char playlist[100];


void createPlaylist() {

    char folder[100] = "music/myPlaylists/";

    printf("Enter name\n");
    scanf("%s", playlist);

    strcat(folder, playlist);

    mkdir(folder);

    addMusic();
}

void addMusic(){
    int isNO;
    char carare1[100] = " copy music\\";
    char carare2[100] = "\\";
    char carare3[100] = ".wav music\\myPlaylists\\";

    printf("Choose music to add to the playlist");
    readFolders();
    scanf("%s", genre);
    readContents("./music/", genre);
    scanf("%s", songname);

    strcat(carare1, genre);
    strcat(carare1, carare2);
    strcat(carare1, songname);
    strcat(carare1, carare3);
    strcat(carare1, playlist);

    system(carare1);

    do{
        char response[1];
        printf("Add another song?(y/n)\n");
        scanf("%s", response);
        isNO = strcmp(response, "y");

        if(isNO != 0){
            break;
        }

        char carare1[100] = " copy music\\";
        char carare2[100] = "\\";
        char carare3[100] = ".wav music\\myPlaylists\\";

        printf("Choose music to add to the playlist");
        readFolders();
        scanf("%s", genre);
        readContents("./music/", genre);
        scanf("%s", songname);

        strcat(carare1, genre);
        strcat(carare1, carare2);
        strcat(carare1, songname);
        strcat(carare1, carare3);
        strcat(carare1, playlist);

        system(carare1);
    }while(isNO == 0);
}

void addToPlaylist(){
    printf("Which playlist to add the song to");
    readContents("./music/myPlaylists", "");
    scanf("%s", playlist);

    char carare1[100] = " copy music\\";
    char carare2[100] = "\\";
    char carare3[100] = ".wav music\\myPlaylists\\";

    strcat(carare1, genre);
    strcat(carare1, carare2);
    strcat(carare1, songname);
    strcat(carare1, carare3);
    strcat(carare1, playlist);

    system(carare1);
}

void chooseSong() {
    printf("Enter SongName or press b to go back\n");
    scanf("%s", songname);
}

void playFirst() {
    char s1[100];
    char s2[100] = "/";
    char s3[100] = ".wav";
    printf("\nChoose the type of music that you want to listen to\n");

    readFolders();

    scanf("%s", genre);

    printf("Choose a song");

    readContents("./music/", genre);

    scanf("%s", songname);

    path();

    strcpy(s1, reparatie);

    strcat(s1, s2);
    strcat(s1, songname);
    strcat(s1, s3);

    PlaySound(TEXT(s1),NULL,SND_ASYNC);
    printf("\nPlayingSong\n");
}
