#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

char cabodeguerra[87];
char letra1 = 'A';
char letra2 = 'J';
char letra3 = 'Z';
char traco = '_';
char fim = '\0';

int num1 = 42;
int num2 = 0;
int RA = 202010639;
int quant1;
int quant2;
int loop = 1;
int max = 22;
int min = 7;

void *esquerda(void *arg);
void *direita(void *arg);

pthread_mutex_t buffer_mutex;

int main(int argc, char **argv) {

    srand48(time(0));

    quant1 = (int) ((drand48() * ((max - min) + 1) + min));
    quant2 = (int) ((drand48() * ((max - min) + 1) + min));


while (quant1 == quant2) {
    quant1 = (int) ((drand48() * ((max - min) + 1) + min));
    quant2 = (int) ((drand48() * ((max - min) + 1) + min));
}

pthread_mutex_init(&buffer_mutex, NULL);

while(num2 < quant1 + quant2) {
    if(num2 < quant1) {
        pthread_t nome;
        pthread_create(&nome,NULL, esquerda, NULL);
    }
    if(num2 < quant2) {
        pthread_t nome;
        pthread_create(&nome,NULL, direita, NULL);
    }
    num2++;
}


for(num2 = 0; num2 < 86; num2++) {
    cabodeguerra[num2] = traco;
}
cabodeguerra[87] = fim;

while(loop) {
    system("clear");
    printf("Esquerda: %d\nDireita: %d\n \n", quant1, quant2, "\n");
    printf("%s\n", cabodeguerra);

    if(num1 == 0 ){
        loop = 0;
        printf("\n Esquerda ganhou \n");

    }

    if(num1 + 2 == 87-2 ){
        loop = 0;
        printf("\n Direita ganhou \n");

        }

    }

}

void *esquerda(void *arg) {
    while(1) {
        pthread_mutex_lock(&buffer_mutex);
        if(num1 > 0){
            num1 = num1 - 1;
            cabodeguerra[num1] = letra1;
            cabodeguerra[num1 + 1] = letra2;
            cabodeguerra[num1 + 2] = letra3;
            cabodeguerra[num1 + 3] = traco;
            }

        pthread_mutex_unlock(&buffer_mutex);
        usleep((long) (drand48() * RA/89.0));

    }
    }
void *direita(void *arg) {
    while(1) {
        pthread_mutex_lock(&buffer_mutex);
        if (num1 + 2 != 87 - 2){
            num1 = num1 + 1;
            cabodeguerra[num1] = letra1;
            cabodeguerra[num1 + 1] = letra2;
            cabodeguerra[num1 + 2] = letra3;
            cabodeguerra[num1 - 1] = traco;
            pthread_mutex_unlock(&buffer_mutex);
        }
        usleep((long) (drand48() * RA/89.0));
    }

}
