#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[50];
int prime_arr[1000];

void *tulis(int *arg)
{
    for(int i = arg[0]; i <= arg[1]; i++){
        int isPrime = 0;
        for(int j = 2; j <= i/2; j++){
            if(i % j == 0){
                isPrime = 1;
                break;
            }
        }
        if(isPrime==0 && arg[1]!= 1){
            printf("cekcek %d\n",arg[1]);
            prime_arr[i]= 1;
        }
    }
}


/*void* baca(int *arg)
{
    printf("masuk baca");
    while(status != 1)
    {

    }
    tulis(&arg);
    status = 0;

}*/

int main(void)
{
    int n;
    int t;
    scanf("%d %d",&n, &t);
    int temp[2];
    temp[0]=2;
    temp[1]=n/t;
    for(int i=0; i<t; i++){

        pthread_create(&tid[i], NULL, &tulis, &temp);

        if(i==(t-1)){
            temp[0] = temp[1]+1;
            temp[1] = n;
            
        }
        else{
            temp[0] = temp[1]+1;
            temp[1] = temp[1]+n/t;
        }
    }

    for(int i=0; i<t; i++){
        pthread_join(tid[i], NULL);
    }

    for(int i=2; i<n; i++){
        //printf("check %d -> %d\n", i, prime_arr[i]);
        if(prime_arr[i]==1){
            printf("%d\n",i);
        }
    }

    return 0;
}
