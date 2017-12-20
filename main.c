#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WORDSIZE 20

int main(int argc ,char *argv[])
{
	char ch;
	FILE *ofp;	//Object File Pointer;
	FILE *dicfp;	//Dictionary File Pointer;

	if(argc != 2)
	{
		printf("Sorry,I can't open this %s... \n"
				"Please give the command like:\n"
				"\t./match wozuimei.txt\n"
				"\t./match wozuishuai.txt\n"
				"Terminated!!!\nPlease retry!", argv[1]);
		exit(EXIT_FAILURE);
	}
		
	char word[WORDSIZE] = {'\0'};
	char *trace = NULL;
	int i = 0,count = 0;
	int condition = 0;


	dicfp = fopen( "words_table_primer_new.txt" , "r");	
	for(count = 0 ; (ch = getc(dicfp)) != EOF ;count++);	
	char *dic = (char*)malloc(sizeof(char) * (count +1));
	char *dics = dic;
	
	fseek( dicfp, 0L ,SEEK_SET);
	
	if(dic == NULL){
		puts("Malloc Fail!");
		return 0;
	}else{
		while((ch = getc(dicfp)) != EOF)
		{
			*dic = ch;
			dic++;
		}
	}
	fclose(dicfp);
	

	if((ofp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s,Please check the suffix(Extension name).",argv[1]);
		exit(EXIT_FAILURE);
	}

	int cnt,match1,match2;
	char* tmp;	
	while((ch = getc(ofp)) != EOF)
	{
		condition = (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <='z');
		if(condition){
			word[i] = ch;
			i++;
		}
		else{
			word[i] = '\0';
			i = 0;
			trace = strstr(dics,word);
			tmp = trace - 1;	
			if(trace == NULL){
				continue;
			}else{
				if(*tmp == ' '){
					tmp++;
					match1 = 1;
				}else
					match1 = 0;

				for(cnt = 0; *tmp != ' ' && tmp;cnt++,tmp++){
					if( cnt > strlen(word) ){	//
						match2 = 0;
						break;						
					}else{
						match2 = 1;
					}
				}
				if(match1 && match2) 
					printf("CET_DICTIONARY:%s\n",word);
			}
		}
	}
	fclose(ofp);
	
	return 0;
}
