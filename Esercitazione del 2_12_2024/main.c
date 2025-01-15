#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100


struct Mystruct{
    int pos;
    char c;
    int l;
}struttura[N];

int trova_parole(char str[N], char p[N][N]);
void stampa(int d, char p[N][N]);
void stampa_struct(int d);
void stampa_solo_lettere(int d, char p[N][N]);
void stampa_solo_numeri(int d, char p[N][N]);
void stampa_lettere_e_numeri(int d, char p[N][N]);
void ordinamento_per_lunghezza(int d);
void ordinamento_per_posizione(int d);




int main()
{

    char s[N];
    char p[N][N];
    int num;
    int flag_lettere =0;
    int flag_numeri =0;
    int j = 0;
    FILE *fp = fopen("input.txt", "r");
    if(fp!=NULL){
        fgets(s, N, fp);
        fclose(fp);
    }
    else{
        return -1;
    }

    puts(s);

    num = trova_parole(s, p);
    stampa(num,p);
    int lettere_lette = 0;
    for(int i=0; i<num; i++){

        j = 0;
        flag_lettere = 0;
        flag_numeri = 0;
        while(p[i][j] != '\0'){
            if(p[i][j] >= '0' && p[i][j] <= '9'){
                flag_numeri = 1;
            }
            else{
                flag_lettere = 1;
            }
            j++;
        }
        if(flag_numeri == 1 && flag_lettere == 0){
            struttura[i].c = 'c';
        }
        else if(flag_lettere==1 && flag_numeri == 0){
            struttura[i].c = 'a';
        }
        else if(flag_lettere ==1 && flag_numeri ==1){
            struttura[i].c = 'b';
        }

        struttura[i].pos = lettere_lette + i;
        struttura[i].l = strlen(p[i]);
        lettere_lette += strlen(p[i]);
    }

    stampa_struct(num);
    return 0;


}


int trova_parole(char str2[N], char p[N][N]){
    int n = 0;
    char *token2;
    token2 = strtok(str2, " \n");
    while(token2 != NULL){
        strcpy(p[n], token2);
        n++;
        token2 = strtok(NULL, " \n");
    }
    return n;
}



void stampa(int d, char p[N][N]){
    for(int i = 0; i<d; i++){
        puts(p[i]);
    }
}


void stampa_struct(int d){
    for (int i=0; i<d; i++){
        printf("Lunghezza parola %d", struttura[i].l);
        printf("Tipo Parola %c", struttura[i].c);
        printf("Posizione carattere Parola %d", struttura[i].pos);
        printf("\n");
    }
}

void stampa_lettere_e_numeri(int d,char  p[N][N]){
    for(int i=0; i<d;i++){
        if(struttura[i].c == 'b'){
            puts(p[i]);
        }
    }
}

void stampa_solo_lettere(int d,char p[N][N]){
    for(int i=0; i<d;i++){
        if(struttura[i].c == 'a'){
            puts(p[i]);
        }
    }
}
void stampa_solo_numeri(int d,char p[N][N]){
    for(int i=0; i<d;i++){
        if(struttura[i].c == 'c'){
            puts(p[i]);
        }
    }
}


void ordinamento_per_posizione(int d){
    int temp;
    char tempc;
    for(int k=0; k<d; k++){
        for(int i =0; i<d-1; i++){
            if(struttura[i].pos > struttura[i+1].pos){
                temp = struttura[i].pos;
                struttura[i].pos = struttura[i+1].pos;
                struttura[i+1].pos = temp;
                temp = struttura[i].l;
                struttura[i].l = struttura[i+1].l;
                struttura[i+1].l = temp;
                tempc = struttura[i].c;
                struttura[i].c = struttura[i+1].c;
                struttura[i+1].c = tempc;
            }
        }
    }
}



void ordinamento_per_lunghezza(int d){
    int temp;
    char tempc;
    for(int k=0; k<d; k++){
        for(int i =0; i<d-1; i++){
            if(struttura[i].l > struttura[i+1].l){
                temp = struttura[i].pos;
                struttura[i].pos = struttura[i+1].pos;
                struttura[i+1].pos = temp;
                temp = struttura[i].l;
                struttura[i].l = struttura[i+1].l;
                struttura[i+1].l = temp;
                tempc = struttura[i].c;
                struttura[i].c = struttura[i+1].c;
                struttura[i+1].c = tempc;
            }
        }
    }
}



