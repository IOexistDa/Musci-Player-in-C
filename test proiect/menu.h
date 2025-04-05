extern char songname[100];
extern char genre[100];
extern char reparatie[100];
extern bool isFav;
extern bool isStopped;
extern char playlist[100];

void playNext();
void mainMenu();
void readContents(char folder[100], char song[100]);
void readFolders();
void stop();
