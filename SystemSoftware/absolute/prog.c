#include<stdio.h>
#include<string.h>

void main()
{
        FILE *f1;
        f1=fopen("try1.txt","r");
        char type,objcode[20],progname[20],input[20];
        int sa,addr,len;
        fscanf(f1,"%c %s %x %x",&type,progname,&sa,&len);

        printf("Loading Program %s of length %06X starting at Address %06X :-\n",progname,len,sa);

        fscanf(f1,"%s",input);

        while(strcmp(input,"E")!=0)
        {
                if(strcmp(input,"T")==0)
                {
                        fscanf(f1,"%X",&addr);
                        fscanf(f1,"%X",&len);
                        fscanf(f1,"%s",input);

                }
                int i=0;
                while(i<strlen(input)-1)
                {
                        printf("%06X\t%c%c\n",addr,input[i],input[i+1]);
                        addr++;
                        i+=2;
                }
                fscanf(f1,"%s",input);
        }
        while(strcmp(input,"E")!=0)
		{
			if(strcmp(input,"T")==0)
			{
				fscanf(f1,"%X",&addr);
				fscanf(f1,"%s",input);
			}
			int i=0;
			while(i<strlen(input)-1)
			{
				printf("%06X\t%c%c%c%c%c%c\n",addr,input[i],input[i+1],input[i+2],input[i+3],input[i+4],input[i+5]);
				addr+=3;
				i+=6;
			}
			fscanf(f1,"%s",input);
		}
        fclose(f1);
}
