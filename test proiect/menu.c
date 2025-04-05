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

void playNext(){
    char song[100];
    struct dirent *dir;



    DIR *c;
    c = opendir(reparatie);
    if (c)
        {
            while ((dir = readdir(c)) != NULL)
            {
                printf("%s\n", dir->d_name);
            }
            closedir(c);
        }
    chooseSong();
    play();
}

void mainMenu() {
    printf("Choose a playlist or press p to go back to the player menu");

    readFolders();

    scanf("%s", genre);

    int toGoBackOrNot = strcmp(genre, "p");

    if(toGoBackOrNot == 0){
        player();
    }
    else {
        int toEnterOrNotCreate = strcmp(genre, "myPlaylists");

    if (toEnterOrNotCreate == 0) {

        readContents("./music/", genre);

        printf("Enter the playlist or c for a new playlist\n");
        scanf("%s", playlist);

        int toCreateOrNotToCreate = strcmp(playlist, "c");

        if(toCreateOrNotToCreate == 0){
            createPlaylist();
        }
        else{
            readContents("./music/myPlaylists/", playlist);
            chooseSong();
            int egalitate = strcmp(songname, "b");
            if(egalitate == 0){
                mainMenu();
            }
            else{
                play2();
            }
        }
    }
    else{

    readContents("./music/", genre);
    chooseSong();

    int egal = strcmp(songname, "b");
    if(egal == 0){
        mainMenu();
    }
    else{
        play();
    }
    }
    }




}

void readContents(char folder[100], char song[100]){
    struct dirent *dir;
    char fix[100];
    strcpy(fix, folder);
    strcat(fix, song);


    DIR *c;
    c = opendir(fix);
    if (c)
        {
            while ((dir = readdir(c)) != NULL)
            {
                printf("%s\n", dir->d_name);
            }
            closedir(c);
        }
}

void readFolders() {
    DIR *d;
    struct dirent *dir;
    d = opendir("./music");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

void stop()
{
    PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
    isStopped = true;
}
