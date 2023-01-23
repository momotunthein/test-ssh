#include <stdio.h>
#include <string.h>
int isValid_mail (char email[]);

int main() {
 char email [100];
 for (int j=0; j<5; j++) {
     printf(" Enter email:");
     gets(email);
// scanf ("%s",email);

     int result = isValid_mail(email);
     if (result == 1) {
         printf(" Email is valid.\n");
     } else {
         printf(" Email is invalid.\n");
     }
 }
    return 0;
}
int isValid_mail (char email[]){
    int  ad; int dot;
    int foundAd =0; int foundDot=0;
    for (int i = 0; i< strlen(email); i++){
        if (email[i]== '@'){
            ad   =i;
            foundAd  = 1;
        }
         if (email[i] == '.'){
            dot = i;
             foundDot = 1;
        }

    }
    if (ad > dot)  return -1;
    if (foundAd == 1 && foundDot ==1){
        return 1;
    }


}