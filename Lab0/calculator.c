#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "linkedlist.h"

node* addition(node* num1, node* num2) {
    node* result = NULL;
    int carry = 0;
    while (num1) {
        int v = 0;
        if (num2) {
            v += num1->v;
            v += num2->v;
            v += carry;
            carry = v / 10;
            v %= 10;
            num1 = num1->next;
            num2 = num2->next;
        } else {
            v = num1->v;
            v += carry;
            carry = 0;
            num1 = num1->next;
        }
        result = prepend(result, new_node(v));
    }
    
    return result;
}

node* subtraction(node *num1,node *num2){
    node *result = NULL;
    int borrow = 0;
    while (num1) {
        int v = 0;
        if (num2) {
            int v1 = num1->v - borrow;
            borrow = 0;
            int v2 = num2->v;
            if (v1 < v2) { //do borrow logic and set v
                v1 += 10;
                borrow += 1;
                v = v1 - v2;
            } else {
                v = v1 - v2;
            }
            num1 = num1->next;
            num2 = num2->next;
        } else {
            v = num1->v - borrow;
            borrow = 0;
            num1 = num1->next;
        }
        result = prepend(result, new_node(v));
    }
    
    return result;
}


node *remove_leading_zeros(node *num){
    node *temp = num;
    while(temp!=NULL && temp->v == 0){
        node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    return temp;
}

int main(int argc,char *argv[]){
    if(argc < 3){
        printf("Usage: ./calculator number1 number2\n");
        exit(0);
    }
    node *num1=NULL,*num2 = NULL;
    node *sum = NULL;
    node *difference = NULL;

    for(int i=0;i<strlen(argv[1]);i++){
        if(!isdigit(argv[1][i])){
            printf("Invalid inputin number1\n");
            exit(0);
        }
        num1 = prepend(num1,new_node(argv[1][i]-'0'));
    }
    for(int i=0;i<strlen(argv[2]);i++){
        if(!isdigit(argv[2][i])){
            printf("Invalid input in number2\n");
            exit(0);
        }
        num2 = prepend(num2,new_node(argv[2][i]-'0'));
    }
    sum = addition(num1,num2);
    difference = subtraction(num1,num2);

    sum = remove_leading_zeros(sum);
    difference = remove_leading_zeros(difference);
    
    print_list(sum);
    print_list(difference);

    delete_list(num1);
    delete_list(num2);
    delete_list(sum);
    delete_list(difference);
    return 0;
}