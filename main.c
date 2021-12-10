#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

//TODO: Renk eklenecek

struct main
{
	char line[80];
	char parameters[10][20];
	int counter;
};

struct main splitter(struct main main_obj)
{
	int i,j,counter;
    j=0; counter=0;
    for(i=0;i<=(strlen(main_obj.line));i++)
    {
        // if space or NULL found, assign NULL into newString[counter]
        if(main_obj.line[i]==' '||main_obj.line[i]=='\0')
        {
            main_obj.parameters[counter][j]='\0';
            counter++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            main_obj.parameters[counter][j]=main_obj.line[i];
            j++;
        }
    }
    main_obj.counter = counter;
    return main_obj;
}

int cd(struct main main_obj){
	main_obj.parameters[1][strlen(main_obj.parameters[1])-1] = '\0';
	//printf("%s\n",main_obj.parameters[1]);
	if(chdir(main_obj.parameters[1]) != 0)
	{
		printf("%s\n","Konum bulunamadi");
	}
	return 0;
}

int execvp_ls(){

	char *args[] = {"ls", "-l", NULL};
	pid_t pid = fork();

	if(pid == 0){
		//child proses
		execvp("ls", args);
	}
	else if(pid >= 0){
		//parent proses
		pid_t wpid;
	    int status;
	    wpid = waitpid(pid, &status, 0);
	}
 
    return 0;
}



int main()
{
	struct main main_obj;
	char location[100];
	
	//prompt gibi davranmasi icin sonsuz dongu 
	while(1)
	{
		//komutların ve parametrelerin tutulacagi dizi
		getcwd(location,100);//mevcut konumu dondurur
		printf("\033[1;31m%s/: sau > \033[0m",location);
		fgets(main_obj.line,80,stdin);
		main_obj = splitter(main_obj);
		
		//kullanici çikiş yapmak isterse
		if(!strcmp(main_obj.parameters[0],"exit") || !strcmp(main_obj.parameters[0],"exit\n")){
			printf("exit\n");
			exit(0);
		}

		//kullanici konum degistirmek isterse
		else if(!strcmp(main_obj.parameters[0],"cd") || !strcmp(main_obj.parameters[0],"cd\n")){
			cd(main_obj);
		}
		//show pid
		else if(!strcmp(main_obj.parameters[0],"showpid") || !strcmp(main_obj.parameters[0],"showpid\n")){
			for(int i = 0;i < 5;i++){
				pid_t pid = fork();

				if(pid == 0){
					//child proses
					printf("%d\n",getpid());
				}
				else if(pid >= 0){
					//parent proses
					pid_t wpid;
				    int status;
				    wpid = waitpid(pid, &status, 0);
				}
			}
		}
		//execvp ornek kullanim
		else if(!strcmp(main_obj.parameters[0],"ls") || !strcmp(main_obj.parameters[0],"ls\n")){
			execvp_ls();
		}

		else{
			printf("%s\n","Hata: Komut icra edilemiyor.");
		}


	}
	
	
	return 0;


}