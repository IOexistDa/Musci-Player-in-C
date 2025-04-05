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

void ifFav() {

    char carare1[100] = "music/favorites/";
    char carare3[100] = ".wav";

    strcat(carare1, songname);
    strcat(carare1, carare3);

    FILE *file;

    if (file = fopen(carare1, "r"))
    {
        fclose(file);
        isFav = true;
    }
    else
    {
        isFav = false;
    }
}

void removeFavorite(){
    char carare1[100] = "music/favorites/";
    char carare3[100] = ".wav";

    strcat(carare1, songname);
    strcat(carare1, carare3);

    remove(carare1);
}

void addFavorite() {
    char carare1[100] = " copy music\\";
    char carare2[100] = "\\";
    char carare3[100] = ".wav music\\favorites";

    strcat(carare1, genre);
    strcat(carare1, carare2);
    strcat(carare1, songname);
    strcat(carare1, carare3);

    system(carare1);
}

void back(){
    readFolders();

    scanf("%s", genre);

    readContents("./music/", genre);

    chooseSong();
    play();
}

void lyrics()
{
    FILE *fptr;

    char c;
    char s1[100] = "./lyrics/";
    char s3[100] = ".txt";

    strcat(s1, songname);
    strcat(s1, s3);

    fptr = fopen(s1, "r");

    if (fptr == NULL)
    {
        printf("No lyrics available for this song \n");
    }

    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

}
