/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool Prime(int num){
    if (num <= 1){
        return false;
    }
        for (int i = 2; i * i <= num; i++){
            if (num % i == 0){
                return false;
            }
            return true;
        }
    }
int main(){
    int arr[100];
    int count = 0;
    for(int i = 1; i <= 100; i++){
        if(Prime(i)){
            arr[count] = i;
            count++;
        }
    }
    for (int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    
}
