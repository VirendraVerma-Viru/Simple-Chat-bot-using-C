#include <stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
         FILE *fp ;
         char data[10000] ;
         //char rev[50] ;
         char arrdata[1000][100];
         int i=1;int l;int nextLine=0;int strstore=0;int j,k;
         int posofarr=0;

         //for cheking inputation
         char inputstring[1000];
         char inputcheckwordarr[1000][100];
         int inputwordstore=0;
         int inputwordnextLine=0;
         int inputlength;

         //word extraction of the main data array
         char maincheckwordarr[1000][100];
         int mainLength;
         int mainwordstore=0;
         int mainwordnextLine=0;

         //calculating compare percentage
         float per=0;
         int total_number_of_words=0;
         int match_word=0;
         int match_word_in_sentence=0;
         bool match_found=false;
         int found_line=0;

         // second answer file
         FILE *afp ;
         char ansdata[10000] ;
         //char rev[50] ;
         char ansarrdata[1000][100];
         int ansi=1;int ansl;int ansnextLine=0;int ansstrstore=0;int ansj,ansk;
         int ansposofarr=0;

// program start
        // printf( "Opening the file test.c in read mode\n" ) ;
         fp = fopen( "Questions.txt", "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file test.c\n" ) ;

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

                printf("\n Enter Question to ask \n");

//input from user

        gets(inputstring);
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
                for(k=0;k<200;k++)
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


        if(per>=60)
        {
            match_found=true;
        }
         else
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
                 printf( "Could not open file answer.c\n" ) ;

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

          if(match_found)
            puts(ansarrdata[found_line]);
            else
                printf("Please Update Data");

        // printf("Closing the file test.c\n") ;
         fclose(fp) ;fclose(afp) ;
         getch();
   return 0;
}
