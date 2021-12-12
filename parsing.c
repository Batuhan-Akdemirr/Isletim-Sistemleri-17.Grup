#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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



int main()
{
	struct main main_obj;
	char location[100];
	
	//prompt gibi davranmasi icin sonsuz dongu 
	while(1)
	{
		//komutların ve parametrelerin tutulacagi dizi
		
		getcwd(location,100);
		printf("%s/: sau > ",location);
		fgets(main_obj.line,80,stdin);
		main_obj = splitter(main_obj);


	}
	
	
	return 0;


}