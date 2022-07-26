#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>
int main(int argc, char** argv){
	if (argc == 3) {
		uint32_t f1, f2;
		
		FILE* fp = fopen(argv[1], "rb");
		FILE* fp2 = fopen(argv[2], "rb");

		if (fp==NULL || fp2==NULL){
			printf("error\n");
			return 1;
		}

		fread(&f1, sizeof(uint32_t), 1, fp);
		fread(&f2, sizeof(uint32_t), 1, fp2);
		
		//printf("0x%x\n", f1);
		//printf("0x%x\n", f2);

		uint32_t f1_host = htonl(f1);
		uint32_t f2_host = htonl(f2);

		//printf("host: 0x%x\n", f1_host);
		//printf("host: 0x%x\n", f2_host);

		//char str1[8];
		//char str2[8];	

		//sprintf(str1, "%d", f1_host);
		//sprintf(str2, "%d", f2_host);
                //printf("%s\n", str1);
		//printf("%s\n", str2);

		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1_host, f1_host, f2_host, f2_host, f1_host+f2_host, f1_host+f2_host);

		fclose(fp);
		fclose(fp2);

	}


	return 0;
}
