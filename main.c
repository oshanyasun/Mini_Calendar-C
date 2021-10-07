#include <stdio.h>
#include <stdlib.h>


int isLeapYear( int year );        /* True if leap year */
int leapYears( int year );         /* The number of leap year */
int todayOf( int y, int m, int d); /* The number of days since the beginning of the year */
long days( int y, int m, int d);   /* Total number of days */
void calendar(int y, int m);       /* display calendar at m y */
int getDayNumber(int d,int m,int y);
char *getName(int day);


void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
  int day;
  int month;
  int year;
  char note[255];
} Note;

int main(int argc, char* argv[]){
    int year,month, day;
    char choice;
    Note note;
    FILE *fp;

    fp = fopen("note.bin", "r");
    if (fp == NULL) {
      fp = fopen("note.bin", "w");
    }
    fclose(fp);

    while(1) {
      printf("1. Find the day\n");
      printf("2. Print calendar of a month\n");
      printf("3. Add Note\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("\n%c", &choice);
      switch(choice) {
        case '1':
        printf("Enter the day, month and year: ");
        scanf("%d %d %d", &day, &month, &year);
        printf("The day is : %s\n", getName(getDayNumber(day, month, year)));
        break;
        case '2':
        printf("Enter the month and year: ");
        scanf("%d %d", &month, &year);
        printf("Please enter 's' to see the notes\n Press any other key to continue\n");
        calendar(year, month);
        break;
        case '3':
        printf("Enter the day, month and year: ");
        scanf("%d %d %d", &note.day, &note.month, &note.year);
        flush();
        printf("Enter the note: ");
        fgets(note.note, 255, stdin);
        fp = fopen("note.bin", "a+");
        if (fp == NULL) {
          printf("File note.bin can not be opened\n");
          exit(1);
        }
        fwrite(&note, sizeof(Note), 1, fp);
        printf("Note added sucessfully\n");
        fclose(fp);
        break;
        case '4':
        printf("Bye!!");
        exit(0);
        break;
        default:
        printf("Not a valid option\n");
        break;
      }
    }
    return 0;
}