#include <stdio.h>

int main() {
    int frequency; 
    printf("Insert frequency:");
    scanf("%d", &frequency);
    int num_classes;
    printf("Insert # of classes:");
    scanf("%d", &num_classes);
    
    double cycle_time;
    cycle_time= 1.0 / (frequency * 1e6);
    int class_cpi[num_classes] ;
    int class_count[num_classes] ;
    
     for(int i = 0; i < num_classes; i++)
    {
        printf("Enter an integers for cpi %d:", i);
        scanf("%d", &class_cpi[i]);
    }
       for(int i = 0; i < num_classes; i++)
    {
        printf("Enter an integers for count %d:", i);
        scanf("%d", &class_count[i]);
    }
    
   
    

 
    int total_instructions = 0;
    int total_weighted_cpi = 0;

    for (int i = 0; i < num_classes; i++) {
        total_instructions += class_count[i];
        total_weighted_cpi += class_cpi[i] * class_count[i];
    }
    double average_cpi = (double)total_weighted_cpi / total_instructions;
    double cpu_time = total_weighted_cpi * cycle_time * 1000; 
    double mips = (frequency * 1e6) / (average_cpi * 1e6);

    printf("Correct table of parameters (MHz=%d):\n", frequency);
    printf("----------------------------\n");
    printf("|Class |CPI |Count |\n");
    printf("----------------------------\n");
    for (int i = 0; i < num_classes; i++) {
        printf("|%5d |%3d |%5d |\n", i + 1, class_cpi[i], class_count[i]);
    }
    printf("----------------------------\n\n");
    printf("Correct table of performance:\n");
    printf("----------------------------\n");
    printf("|Performance    |Value      |\n");
    printf("----------------------------\n");
    printf("|Average CPI    |%10.2f |\n", average_cpi);
    printf("|CPU Time (ms)  |%10.2f |\n", cpu_time);
    printf("|MIPS           |%10.2f |\n", mips);
    printf("----------------------------\n");

    return 0;
}

