//
// Created by Tha Zin on 2023-03-18.
//
#include "stdio.h"
#include "stdlib.h"
#define USERSIZE 1000
int G_index=0;
int strong_pass_valid=-1;
int phone_valid=-1;
int email_found = -1;
int two_charArray=-1;
int char_counting(char my_char[50]);
void strong_pass_validation(char pass[50]);
void phone_validation(unsigned int phone);
void email_exist_checking(char email[50]);
void compare_two_charArray(char first[200],char second[200]);
void login();
struct trans{
    char note[200];
};
struct info{

    unsigned int id;
    char name[50];
    char nrc[20];
    char email[50];
    char password[50];
    unsigned int phoneNumber;
    char encryption_key[6];//>>
    char recovery_key[10];//>>
    char account_status[10]; //$
    int account_type; //1 personal ,2 business , 3 othersss...... //$
    int account_level;// 1 normal 2 inter 3 high boss
    int minimum_opening_deposit;//$
    char currency[5];//>>
    unsigned long long int current_amount;//llu//>>
    char loanStatus[1];//$
    unsigned int monthly_income;//>>
    unsigned int loan_amount;//$
    float loan_rate;//$
    char address[100];//>>
    int trans_amount_limit_perday;

    struct trans tr[300]; //transaction//>>

    // %u%s%s%s%s%u%s%s%s%d%d%d%s%llu%s%u%u%f%s


};

struct info db[USERSIZE];
int char_counting(char my_char[50]){

    int count=0;
    for(register int a=0; a<50; a++){

        if(my_char[a]  == '\0') {
            break;
        }
        count++;
    }

    return count;

}

void phone_validation(unsigned int phone){
    int phone_counter=0;
    for(int i=0; i<G_index ; i++){

        if(phone != db[i].phoneNumber){

            phone_counter++;
        } else{
            phone_valid=-1;
            break;
        }

    }
    if(phone_counter == G_index){
        phone_valid=1;
    }

}
void strong_pass_validation(char pass[50]){

    int i=0;
    int special=0;
    int number=0;
    int smallChar=0;
    int capChar=0;


    int pass_counter = char_counting(pass);

    if(pass_counter >=6) {

        while (strong_pass_valid == -1) {
            if( i == pass_counter){
                strong_pass_valid=-1;
                break;
            }
            if(pass[i] >=33 && pass[i]<=42){
                special++;
            } else if( pass[i] >=48 && pass[i]<=57){
                number++;
            } else if( pass[i]>=97 && pass[i]<=122){
                smallChar++;
            } else if(pass[i]>=65 && pass[i]<=90){
                capChar++;
            }
            i++;
            if(special>0 && number>0 && capChar >0 && smallChar>0){
                strong_pass_valid=1;
            }

        }
    } else{
        printf("[-]we need at least 6 characters!\n");
        strong_pass_valid=-1;
    }
}
void email_exist_checking(char email[50]){
    int counter = char_counting(email);

    int same_counting=0;
    for(register int gcc=0; gcc<G_index ; gcc++){
        int db_email_count = char_counting(db[gcc].email);

        if(counter == db_email_count) {

            for (register int a = 0; a < counter; a++) {
                if (email[a] != db[gcc].email[a]) {
                    break;
                }
                same_counting++;
            }
        }

        if(counter== same_counting){
            email_found=gcc;
            break;
        }
    }
}
void compare_two_charArray(char first[200],char second[200]){

    int first_counter = char_counting(first);
    int second_counter = char_counting(second);

    int same_counter=0;

    if(first_counter == second_counter){

        for(register int i=0; i<first_counter; i++){

            if(first[i] != second[i]){
                break;
            }
            same_counter++;
        }

        if(first_counter == same_counter){
            two_charArray = 1;

        }

    }


}
void login() {
    char l_email[50];
    char l_pass[50];
    email_found = -1;
    two_charArray = -1;
    while (email_found == -1 || two_charArray == -1) {
        printf("This is Online Bank Login!\n");
        printf("Enter your email to login!>>:");
        scanf(" %[^\n]", &l_email[0]);
        printf("Enter your password to login!>>:");
        scanf(" %[^\n]", &l_pass[0]);

        email_exist_checking(l_email);
        compare_two_charArray(db[email_found].password, l_pass);

        if (email_found == -1 || two_charArray == -1) {
            email_found = -1;
            two_charArray = -1;
            printf("Your Login credential incorrect!\n");
        }

    }
}


int main(){
    login();
    unsigned int re_phone=0;
    char re_pass[50];
    phone_valid=-1;
    while (phone_valid==-1){
        printf("[X]Enter your Phone Number:");
        scanf("%u",&re_phone);

        phone_validation(re_phone);

        if(phone_valid == -1){

            printf("[-]Your phone number is already registered:\n");
        }

    }

    printf("[+] Your phone is correct and saved!\n");
    strong_pass_valid=-1;
    while (strong_pass_valid==-1){

        printf("Enter your password:");
        scanf(" %[^\n]",&re_pass[0]);

        strong_pass_validation(re_pass);

        if(strong_pass_valid==-1){

            printf("[-]Your password format too weak and Try Again!\n");
        }

    }


    return 0;
}