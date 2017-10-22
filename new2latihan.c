#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[50];
pthread_t tid2[50];
int prime_arr[1000];
int status;
int temp[2];
int iter;
int n;
int t;

void *buat(void *arg){
	//printf("=======masuk buat\n");
	status = 0;
	printf("awal %d\n",temp[0]);
    printf("akhir %d\n",temp[1]);
    for(int i = temp[0]; i <= temp[1]; i++){
        int isPrime = 0;
        for(int j = 2; j <= i/2; j++){
            if(i % j == 0){
                isPrime = 1;
                break;
            }
        }
        if(isPrime==0 && temp[1]!= 1){
            prime_arr[i]= 1;
        }
    }

    status = 1;

    return NULL;
}


void *tulis(void *arg){
	
    while(status != 1)
    {

    }
    //printf("=======mulai print\n");
    for(int i=temp[0]; i<=temp[1]; i++){
        if(prime_arr[i]==1){
            printf("%d\n",i);
        }
    }

    if(iter==t){
            temp[0] = 1+(n/t)*iter;
            temp[1] = n;
            
    }
    else{
            temp[0] = 1+(n/t)*iter;
            temp[1] = (n/t)*iter*2;
    }

}

int main(void){
    scanf("%d %d",&n, &t);
    temp[0]=2;
    temp[1]=n/t;

    for(iter = 0; iter<t; iter++){
    	//printf("=======buat proses\n");

        pthread_create(&tid[iter], NULL, &buat, NULL);
        pthread_create(&tid2[iter], NULL, &tulis, NULL);
    }

    for(int i=0; i<t; i++){
        pthread_join(tid[i], NULL);
        pthread_join(tid2[i], NULL);
    }

    return 0;
}
