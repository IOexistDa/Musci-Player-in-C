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


void player(){
    int choice;
do
    {

        ifFav();

            printf("\n Enter Choice");
            if (isStopped == true)
            {
                printf("\n1.Play");
            }
            else
            {
                printf("\n1.Stop");
            }
            printf("\n2.Lyrics \n3.Play next \n4.Main Menu");
            if(isFav == true)
            {
                  printf("\n5.Remove from favorites");
            }
            else
            {
                printf("\n5.Add to favorites");
            }
            printf("\n6.Add to playlist \n7.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:if(isStopped == true)
                    {
                        play(genre, songname);
                        break;
                    }
                    else
                    {
                        stop();
                        break;
                    }
            case 2:lyrics();
                    break;
            case 3:playNext();
                    break;
            case 4:mainMenu();
                    break;
            case 5:if(isFav == true)
                    {
                        removeFavorite();
                        break;
                    }
                    else
                    {
                        addFavorite();
                        break;
                    }
            case 6:addToPlaylist();
                    break;
        }


    }while(choice!=7);
}

void play()
{
    char s1[100];
    char s2[100] = "/";
    char s3[100] = ".wav";

    path();

    strcpy(s1, reparatie);

    strcat(s1, s2);
    strcat(s1, songname);
    strcat(s1, s3);

    PlaySound(TEXT(s1),NULL,SND_ASYNC);
    printf("\nPlayingSong\n");

    isStopped = false;
}

void play2()
{
    char s1[100];
    char s2[100] = "/";
    char s3[100] = ".wav";

    path2();

    strcpy(s1, reparatie);

    strcat(s1, s2);
    strcat(s1, songname);
    strcat(s1, s3);

    PlaySound(TEXT(s1),NULL,SND_ASYNC);
    printf("\nPlayingSong\n");

    isStopped = false;
}

void path(){
    char s1[100] = "./music/";


    strcat(s1, genre);

    strcpy(reparatie, s1);
}

void path2() {
    char s1[100] = "./music/";
    char s2[100] = "/";

    strcat(s1, genre);
    strcat(s1, s2);
    strcat(s1, playlist);

    strcpy(reparatie, s1);
}


