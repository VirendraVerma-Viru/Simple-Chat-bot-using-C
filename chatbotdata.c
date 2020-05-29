# include <stdio.h>
# include <string.h>
#include<windows.h>

    FILE *fp ;
    char data[1000];
    int l,i;
    int n=1;

void clrscr(void);
void question();
void answer();
void gotoxy(int x,int y);



int main( )
{
//initializing with zero
    for(i=0;i<1000;i++)
            data[i]=NULL;


while(n>0)
{
    clrscr();
    gotoxy(30,4);
    printf("Data Library");


    gotoxy(10,10);
    printf("Question");
    gotoxy(10,15);
    printf("Answer");
    gotoxy(15,12);
    question();


    gotoxy(15,17);
    answer();

}



    return 0;
}

void question()
{
   // opening an existing file
    fp = fopen("Questions.txt", "a") ;
    if ( fp == NULL )
    {
        printf( "Could not open file test.c" ) ;

    }

    // getting input from user
    //while ( (strlen ( gets( data ) ))> 0 )
    //{
        gets( data );

        l=strlen(data);

        data[l]='.';

        // writing in the file
        fputs(data, fp) ;
        for(i=0;i<1000;i++)
            data[i]=NULL;

    //}
     fclose(fp) ;
}

void answer()
{
   // opening an existing file
    fp = fopen("Answers.txt", "a") ;
    if ( fp == NULL )
    {
        printf( "Could not open file test.c" ) ;

    }

    // getting input from user
    //while ( (strlen ( gets( data ) ))> 0 )
    //{
        gets( data );
        l=strlen(data);

        data[l]='.';

        // writing in the file
        fputs(data, fp) ;


        for(i=0;i<1000;i++)
            data[i]=NULL;

    //}
     fclose(fp) ;
}

void clrscr()
{
    system("cls");
}
void gotoxy(int b,int v)
{
    COORD c;
    c.X=b;
    c.Y=v;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
