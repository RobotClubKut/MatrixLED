#include <stdio.h>
#include <stdlib.h>
int main(){

	FILE *fp_in,*fp_out;
	char str[256],no[256];
	int i;

	if((fp_in = fopen("jiskan16-2004-1.txt","r")) == NULL){
		printf("file open error!\n");
		exit(EXIT_FAILURE);
	}

	if((fp_out = fopen("jiskan_lib.h","w")) == NULL){
		printf("file open error!\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp_out, "#ifndef JISKAN_LIB_H\n#define JISKAN_LIB_H\n\n");

	fprintf(fp_out, "//start ENCODING 0x2121\n\n");

	fprintf(fp_out, "const unsigned int jis_font[] = {\n");

	while(fscanf(fp_in,"%s",str) != EOF){
		if(strcmp("BITMAP", str) == 0){
			for(i=0;i<16;i++){
				fscanf(fp_in,"%s",str);
				fprintf(fp_out, "0x%s,", str);
			}
			fprintf(fp_out, "\n");
		}
	}

	fprintf(fp_out, "};\n#endif");

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}