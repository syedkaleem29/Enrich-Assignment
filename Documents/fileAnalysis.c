#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct wordList
{
    char *word;
    int count;
};
struct charList
{
    char c;
    int count;
};
int wordCount(FILE *);
int letterCount(FILE *);
int symCount(FILE *);
void topThreeWords(FILE *,struct wordList *,int *);
void topThreeLetters(FILE *,struct charList *,int *);
void oneTimeWords(struct wordList *,int );
void unusedLetters(struct charList *,int);
void lowerCase(char *);
int main()
{
    FILE *file;
    const char *fileaddr="C:\\Users\\kalam syed\\Desktop\\Abstract.txt";
    const char *mode="r";
    int wCount, lCount, sCount,nWords,nLetters;
    struct wordList wList[1000];
    struct charList cList[52];
    if(file==NULL)
    {
        printf("file not found\n");
        return 0;
    }
    file=fopen(fileaddr,mode);
    wCount=wordCount(file);
    printf("The number of words in the document is %d.\n",wCount);
    file=fopen(fileaddr,mode);
    lCount=letterCount(file);
    printf("The number of letters in the document is %d.\n",lCount);
    file=fopen(fileaddr,mode);
    sCount=symCount(file);
    printf("The number of symbols in the Document is %d\n", sCount);
    file=fopen(fileaddr,mode);
    printf("The top 3 words are\n");
    topThreeWords(file,wList,&nWords);
    file=fopen(fileaddr,mode);
    printf("The top 3 most common letters are\n");
    topThreeLetters(file,cList,&nLetters);
    printf("List of words appearing one time\n");
    oneTimeWords(wList,nWords);
    printf("List of non appearing characters\n");
    unusedLetters(cList,nLetters);
    return 0;
}
int wordCount(FILE *file)
{
    char *word;
    int numWords=0;
    char *line=malloc(1024*sizeof(char));
    while(fgets(line,1024,file))
    {
        word=strtok(line," ,.?[]\";\n");
        do
        {
            if(word!=NULL)
            {
                numWords++;
            }
            word=strtok(NULL," ,.?[]\";\n");
        }while(word!=NULL);
    }
    return numWords;
}
int letterCount(FILE *file)
{
    int numLetters=0,letter;
    char c;
    while((letter=fgetc(file))!=EOF)
    {
        if(letter>=65&& letter<=90 || letter>=97 && letter<=122)
        {
            numLetters++;
        }
    }
    return numLetters;
}
int symCount(FILE *file)
{
    int numSym=0;
    char c;
    int sym;
    while((sym=fgetc(file))!=EOF)
    {
        if(!((sym>=65&&sym<=90)||(sym>=97&&sym<=122)||sym==32||sym==10))
        {
            numSym++;
        }
    }
    return numSym;
}
void topThreeWords(FILE *file,struct wordList *wList,int *nWords)
{
    char *word=malloc(32*sizeof(char));
    char *tempWord=malloc(32*sizeof(char));
    char *line=malloc(1024*sizeof(char));
    int n=0,i=0,j=0,flag,ipos,temp;
    while(fgets(line,1024,file))
    {
        word=strtok(line," ,.?\"\n[];");
        while(word!=NULL)
        {
            lowerCase(word);
            flag=0;
            for(i=0;i<n;i++)
            {
                if(strcmp(wList[i].word,word)==0)
                {
                    flag=1;
                    ipos=i;
                    break;
                }
            }
            if(flag==0)
            {
                wList[n].word=malloc(32*sizeof(char));
                wList[n].count=0;
                strcpy(wList[n].word,word);
                wList[n].count++;
                n++;
            }
            else
            {
                wList[ipos].count++;
            }
            word=strtok(NULL," ,.?\"\n[];");
        }
    }
    *nWords=n;
    for(i=1;i<n;i++)
    {
        temp=wList[i].count;
        strcpy(tempWord,wList[i].word);
        j=i-1;
        while(j>=0 && wList[j].count>temp)
        {
                wList[j+1].count=wList[j].count;
                strcpy(wList[j+1].word,wList[j].word);
                j--;
        }
        wList[j+1].count=temp;
        strcpy(wList[j+1].word,tempWord);
    }
    for(j=n-1;j>=n-3;j--)
    {
        printf("%s appears %d times\n",wList[j].word,wList[j].count);
    }
}
void lowerCase(char *str)
{
    int i=0,c=0;
    while(str[i]!='\0')
    {
        if(str[i]>=65 && str[i]<=90)
        {
            str[i]=str[i]+32;
        }
        i++;
    }
}
void topThreeLetters(FILE *file,struct charList *cList,int *nLetters)
{
    char cchar,tempc;
    int ichar,i=0,n=0,flag,ipos,j,temp;
    while((ichar=fgetc(file))!=EOF)
    {
        cList[n].count=0;
        flag=0;
        if((ichar>=65&&ichar<=90)||(ichar>=97&&ichar<=122))
        {
            cchar=(char)ichar;
            for(i=0;i<n;i++)
            {
                if(cList[i].c==cchar)
                {
                    flag=1;
                    ipos=i;
                    break;
                }
            }
            if(flag==1)
            {
                cList[ipos].count++;
            }
            else
            {
                cList[n].c=cchar;
                cList[n].count++;
                n++;
            }
        }
    }
    *nLetters=n;
    for(i=1;i<n;i++)
    {
        temp=cList[i].count;
        tempc=cList[i].c;
        j=i-1;
        while(j>=0 && cList[j].count>temp)
        {
            cList[j+1].count=cList[j].count;
            cList[j+1].c=cList[j].c;
            j--;
        }
        cList[j+1].c=tempc;
        cList[j+1].count=temp;
    }
    for(i=n-1;i>=n-3;i--)
    {
        printf("%c appears with %d times\n",cList[i].c,cList[i].count);
    }
}
void oneTimeWords(struct wordList *wList,int nWords)
{
    int i=0;
    for(i=0;i<nWords;i++)
    {
        if(wList[i].count==1)
        {
            printf("%s\n",wList[i].word);
        }
    }
}
void unusedLetters(struct charList *cList,int nLetters)
{
    int i,index;
    int *lowerArray=calloc(26,sizeof(int));
    int *upperArray=calloc(26,sizeof(int));
    for(i=0;i<nLetters;i++)
    {
        if(cList[i].c>=65&&cList[i].c<=90)
        {
            index=cList[i].c-65;
            upperArray[index]++;
        }
        if(cList[i].c>=97&&cList[i].c<=122)
        {
            index=cList[i].c-97;
            lowerArray[index]++;
        }
    }
    for(i=0;i<26;i++)
    {
        if(lowerArray[i]==0)
        {
            printf("%c\n",i+97);
        }
        if(upperArray[i]==0)
        {
            printf("%c\n",i+65);
        }
    }
}
