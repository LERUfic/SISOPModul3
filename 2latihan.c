#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[50];
int prime_arr[1000];
int atas;
int bawah;
int n;
int t;
int status = 1;
int iter =1;

void *tulis(void *arg){
	//printf("atas %d\n", atas);
    printf("------>Thread %d\n", iter);
    for(int i = bawah; i <= atas; i++){
        int isPrime = 0;
        for(int j = 2; j <= i/2; j++){
            if(i % j == 0){
                isPrime = 1;
                break;
            }
        }
        if(isPrime==0 && bawah!= 1){
            printf("%d\n",i);
            //prime_arr[i]= 1;
        }
    }
    status++;
}


void* baca(void *arg)
{
    while(status-1!=iter)
    {

    }
    bawah = atas+1;
    atas = bawah+n/t;
    if(atas>n) atas = n;
}

int main(void){
    scanf("%d %d",&n, &t);
  
    bawah=2;
    atas=n/t;
    for(iter=1; iter<=t; iter++){
        pthread_create(&tid[iter], NULL, &tulis, NULL);
        baca(NULL);
    }

    for(int i=1; i<=t; i++){
        pthread_join(tid[i], NULL);
    }

    /*for(int i=2; i<n; i++){
        //printf("check %d -> %d\n", i, prime_arr[i]);
        if(prime_arr[i]==1){
            printf("%d\n",i);
        }
    }*/

    return 0;
}
