// This is for remembering the basic concepts of C language

#include <stdio.h>

void printArray(int arr[], int arrSize){
    for(int i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
}

void dataEntry(int *arr, int size){
    for(int i=0; i<size; i++){
        arr[i]= (i+1)*100;
    }
}

struct Employee
{
    int id, 
        age;
};


void main(){
    int size=10, n[size];
    char arr[10];

    scanf("%s", &arr);

    printf("%s", arr);

    puts("");

    dataEntry(n, size);

    printArray(n, size);

    puts("");

    struct Employee Abrar = {553, 23};
    struct Employee Toma = {540, 16};
    struct Employee Tamanna = {354, 22};

    struct Employee *editor = &Abrar;
    

    printf("Data of Abrar:\n\tID: %d\n\tAge: %d\n", Abrar.id, Abrar.age);
    printf("Data of Toma:\n\tID: %d\n\tAge: %d\n", Toma.id, Toma.age);
    printf("Data of Tamanna:\n\tID: %d\n\tAge: %d\n", Tamanna.id, Tamanna.age);

    editor->id=7399;
    editor->age=55;
    printf("Data of Abrar:\n\tID: %d\n\tAge: %d\n", Abrar.id, editor->age);

}