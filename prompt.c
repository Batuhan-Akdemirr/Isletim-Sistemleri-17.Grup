#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char line[80];
	char location[100];
	char * parameters[10][80];
	//prompt gibi davranmasi icin sonsuz dongu 
	while(1)
	{
		//komutların ve parametrelerin tutulacagi dizi
		getcwd(location,100);
		printf("%s/: sau > ",location);
		fgets(line,100,stdin);
	}
}