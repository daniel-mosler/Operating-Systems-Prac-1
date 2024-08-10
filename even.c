#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void HUP_reaction(int sig){
    printf("Ouch!\n");
}

void INT_reaction(int sig){
    printf("Yeah!\n");
}

int main(int argc, char *argv[]){

    //convert input to integer
    int n = atoi(argv[1]);

    //set up signal handlers
    signal(SIGINT, INT_reaction);
    signal(SIGHUP, HUP_reaction);

    //print the first n even numbers
    for (int i = 1; i <= n; i++){
            printf("%d\n", i * 2);
            sleep(5);
    }

    return 0;
}