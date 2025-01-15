#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_MAX 100

#define N_MAX 100
struct Mystruct
{
    char data1[11];
    char data2[11];
    int giorni;
    float media[2];
};

enum GiorniMese{
    GENNAIO = 31,
    FEBBRAIO = 28,
    MARZO = 31,
    APRILE = 30,
    MAGGIO = 31,
    GIUGNO = 30,
    LUGLIO = 31,
    AGOSTO = 31,
    SETTEMBRE = 30,
    OTTOBRE = 31,
    NOVEMBRE = 30,
    DICEMBRE = 31
};

int giorni_mese(int mese){
    switch(mese){
        case 1: return GENNAIO;
        case 2: return FEBBRAIO;
        case 3: return MARZO;
        case 4: return APRILE;
        case 5: return MAGGIO;
        case 6: return GIUGNO;
        case 7: return LUGLIO;
        case 8: return AGOSTO;
        case 9: return SETTEMBRE;
        case 10: return OTTOBRE;
        case 11: return NOVEMBRE;
        case 12: return DICEMBRE;
        default: return 0;
    }
}

int calcola_giorni(char *data1, char *data2){
    int anno1, mese1, giorno1;
    int anno2, mese2, giorno2;
    int giorni = 0;
    sscanf(data1, "%d/%d/%d", &anno1,&mese1,&giorno1);
    sscanf(data2, "%d/%d/%d", &anno2,&mese2,&giorno2);
    if(mese1 == mese2){
        giorni = giorno2-giorno1;
    }
    else{
        giorni += giorni_mese(mese1) - giorno1;
        for(int i = mese1 +1; i<mese2; i++){
            giorni += giorni_mese(i);
        }
        giorni += giorno2;
    }
    return giorni;

}


void ordina(struct Mystruct array[N_MAX], int n){
    struct Mystruct temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++)
        {
            if(array[j].giorni > array[j+1].giorni){
                temp = array[j];
                array[j]= array[j+1];
                array[j+1] = temp;
            }
        }
    }


}




int main()
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.bin", "wb");

    if(!fin || !fout){
        printf("Errore nell'apertura del file");
        return -1;
    }
    char date[11];
    char date_prev[11] = "";
    float val1;
    float val1_prev;
    float val2;
    float val2_prev;
    char line[N_MAX];
    int giorni;
    struct Mystruct array[N_MAX];
    memset(array, 0, sizeof(struct Mystruct)*N_MAX);
    int count =0;
    float diff1, diff2;
    while(fgets(line, sizeof(line),fin)){
        sscanf(line, "%10s,%f,%f", date, &val1, &val2);
        printf("%s ", date);
        printf("%f ", val1);
        printf("%f", val2);
        printf("\n");
        if(strlen(date_prev)>0){
            giorni = calcola_giorni(date_prev, date);
            strcpy(array[count].data1,date_prev);
            strcpy(array[count].data2, date);
            array[count].giorni = giorni;
            diff1 = val1-val1_prev;
            diff2 = val2-val2_prev;
            array[count].media[0] = diff1/giorni;
            array[count].media[1] = diff2/giorni;
            count++;
        }
        strcpy(date_prev, date);
        val1_prev = val1;
        val2_prev = val2;
    }

    for(int i=0; i<count; i++){
        printf("[%s, %s, %d, %f, %f]\n", array[i].data1, array[i].data2, array[i].giorni, array[i].media[0], array[i].media[1]);
    }

    ordina(array, count);

    for(int i=0; i<count; i++){
        printf("[%s, %s, %d, %f, %f]\n", array[i].data1, array[i].data2, array[i].giorni, array[i].media[0], array[i].media[1]);
    }

    fwrite(array, sizeof(struct Mystruct), count, fout);
    fclose(fin);
    fclose(fout);


}
