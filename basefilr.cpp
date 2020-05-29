#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>
#include <iostream>

int main2();
void gotoxy(int x,int y);
void SetColor(int ForgC);
void time();
void dataLibrary();
void shutdown();
void restart();

int main()
{

    printf("\n Enter Question to ask \n");

    system("COLOR F2");
       main2();



   return 0;
}

int main2()
{
    int n=2;
    while(n>0)
    {
    FILE *fp ;
    //int mm=1000,nn=1000,bb=100;
         char data[10000] ;
         //char rev[50] ;
         char arrdata[1000][500];
         int i=1;int l;int nextLine=0;int strstore=0;int j,k;
         int posofarr=0;

         //for cheking inputation
         char inputstring[1000];
         char inputcheckwordarr[1000][500];
         int inputwordstore=0;
         int inputwordnextLine=0;
         int inputlength;

         //word extraction of the main data array
         char maincheckwordarr[1000][500];
         int mainLength;
         int mainwordstore=0;
         int mainwordnextLine=0;

         //calculating compare percentage
         float per=0;
         int total_number_of_words=0;
         int match_word=0;
         int match_word_in_sentence=0;
         bool match_found=false;
         bool for_functions=false;
         int found_line=0;

         // second answer file
         FILE *afp ;
         char ansdata[10000] ;
         //char rev[50] ;
         char ansarrdata[1000][500];
         int ansi=1;int ansl;int ansnextLine=0;int ansstrstore=0;int ansj,ansk;
         int ansposofarr=0;

         //predfined functions

         char exite[5]={'e','x','i','t'};
         char timee[5]={'t','i','m','e'};
         char shutdowne[9]={'s','h','u','t','d','o','w','n'};
         char restarte[8]={'r','e','s','t','a','r','t'};



         //initializing with null to all array

         /*
         for(i=0;i<mm;i++)
            {
            data[i]=NULL;
            ansdata[i]=NULL;
            }

            for(i=0;i<nn;i++)
            {

                    arrdata[i][0]=NULL;
                inputcheckwordarr[i][0]=NULL;
                maincheckwordarr[i][0]=NULL;
                ansarrdata[i][0]=NULL;


            }

            */


// program start
        // printf( "Opening the file test.c in read mode\n" ) ;
         fp = fopen( "Questions.txt", "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file Questions.text\n" ) ;

         }
       //  printf( "Reading the file test.c\n" ) ;
         while( fgets ( data,10000, fp ) != NULL )
         {

         }

         //printf("%s\n",data);

         //extracting data

         l=strlen(data);


            for(i=0;i<=l;i++)
            {
                if(data[i]=='.')
                {
                nextLine++;
                strstore=0;
                posofarr++;
                }

                else
                {
                arrdata[nextLine][strstore]=data[i];// extracting and storing word in array
                strstore++;
                }

            }

//sentence sepetating with symbol '.'

            //for(i=0;i<=l;i++)
            //{
                //for(j=0;j<=l;j++)
              //  printf("%s\n",arrdata[i]);

            //lo}



//input from user

        //gotoxy(2,n);
        SetColor(12);
        gets(inputstring);
        //n++;
        inputlength=strlen(inputstring);

            for(i=0;i<=inputlength;i++)
            {

                if(inputstring[i]==' ')
                {
                    inputwordnextLine++;
                    inputwordstore=0;

                }
                else
                {
                    inputcheckwordarr[inputwordnextLine][inputwordstore]=inputstring[i];// extracting and storing word in array
                    inputwordstore++;
                }
            }






//comparing  words

        total_number_of_words=inputwordnextLine+1;

        for(i=0;i<=posofarr;i++)
        {
            //extracting word of the main data array sentence
            mainLength=strlen(arrdata[i]);
           for(j=0;j<=mainLength;j++)
            {

                if(arrdata[i][j]==' ')
                {
                    mainwordnextLine++;
                    mainwordstore=0;

                }
                else
                {
                    maincheckwordarr[mainwordnextLine][mainwordstore]=arrdata[i][j];// extracting and storing word in array
                    mainwordstore++;
                }
            }


             //pre defined functions
                    if((strcasecmp(inputcheckwordarr[i],timee)==0))
                    {
                        time();
                        for_functions=true;
                    }
                    else if((strcasecmp(inputcheckwordarr[i],shutdowne)==0))
                    {
                        shutdown();
                        for_functions=true;
                    }
                    else if((strcasecmp(inputcheckwordarr[i],restarte)==0))
                    {
                        restart();
                        for_functions=true;
                    }







            for(k=0;k<=inputwordnextLine;k++)
            {
                for(j=0;j<=mainwordnextLine;j++)
                {
                    if((strcasecmp(inputcheckwordarr[k],maincheckwordarr[j]))==0)
                    {


                    match_word++;
                    //printf("\n matched");
                    //printf("\n %d",match_word);
                    //printf("\t%s",inputcheckwordarr[k]);
                    //printf("\t%s",maincheckwordarr[j]);
                    //printf("\n matched over");
//                    finding maximum match
                        if(match_word_in_sentence<match_word)
                        {
                        match_word_in_sentence=match_word;
                        found_line=i;
                        }
                    }

                    else if((strcasecmp(inputcheckwordarr[k],exite)==0))
                    {
                        exit(0);
                        //for_functions=true;
                    }



                    //else
                    //{
                    //printf("\n %d",match_word);
                    //printf("\t%s",inputcheckwordarr[k]);
                   // printf("\t%s",maincheckwordarr[j]);

                   // }
                }


            }

            for(j=0;j<=mainLength;j++)
            {
                for(k=0;k<500;k++)
                maincheckwordarr[j][k]=NULL;
            }

            match_word=0;
            mainwordstore=0;
           mainwordnextLine=0;
           mainLength=0;
        }

        int a=match_word_in_sentence;
        int b=total_number_of_words;
        per=(a*100)/b;


        if(per>=60&&for_functions==false)
        {
            match_found=true;
        }
         else if(per<60&&for_functions==false)
         {
             match_found=false;

         }
        //printf("\n%d matched sentence",match_word_in_sentence);
        //printf("\n%d total number of words",total_number_of_words);
        // printf("\n%f its a percent\n",per);

 //___________________________________________________________________answer file________________________________________
         //printf( "Opening the file test.c in read mode\n" ) ;
         afp = fopen( "Answers.txt", "r" ) ;
         if ( afp == NULL )
         {
                 printf( "Could not open file Answers.txt\n" ) ;

         }
        // printf( "Reading the file test.c\n" ) ;
         while( fgets ( ansdata,10000, afp ) != NULL )
         {

         }

         //extracting data

         ansl=strlen(ansdata);


            for(i=0;i<=ansl;i++)
            {
                if(ansdata[i]=='.')
                {
                ansnextLine++;
                ansstrstore=0;
                ansposofarr++;
                }

                else
                {
                ansarrdata[ansnextLine][ansstrstore]=ansdata[i];// extracting and storing word in array
                ansstrstore++;
                }

            }


         //for(i=0;i<=ansl;i++)
            //{
                //for(j=0;j<=l;j++)
            //    printf("%s\n",ansarrdata[i]);
          // }

          //printf("%d",found_line);

          //gotoxy(10,n);

          if(match_found==true&&for_functions==false)
          {
                SetColor(9);
              puts(ansarrdata[found_line]);
          }

            else if(match_found==false&&for_functions==false)
            {
                SetColor(14);
                printf("Please Update Data\n");
                dataLibrary();
            }


        // printf("Closing the file test.c\n") ;
         fclose(fp) ;fclose(afp) ;
         //n++;
   }

         return 0;
}

void gotoxy(int b,int v)
{
    COORD c;
    c.X=b;
    c.Y=v;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void time()
{
    time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  SetColor(9);
  printf ( "%s", asctime (timeinfo) );
}

void dataLibrary()
{
    system ("start chatbotdata.exe");
}
void shutdown()
{
    system("c:\\windows\\system32\\shutdown /s /t 20 \n\n");
}
void restart()
{
    system("c:\\windows\\system32\\shutdown /r /t 10 \n\n");
}
