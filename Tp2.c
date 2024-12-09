#include <stdio.h>
#include <stdlib.h>

// Function prototypes
char *LoadString(int N);
int StringLength(char *str);
void ReverseArray(char Array[], char Reversed[], int length);
void LoadArray(char *str, char Array[]);
void DisplayArray(char Array[], int length);

int main() {
    char *str;
    int n;
    printf("Please enter the maximum size of the string: ");
    scanf("%d", &n);
    str = LoadString(n);
    int length = StringLength(str);
    char Array[length], Reversed[length];
    LoadArray(str, Array);
    DisplayArray(Array, length);
    ReverseArray(Array, Reversed, length);
    DisplayArray(Reversed, length);
    free(str);
    return 0;
}

// Function definitions

// Function to load a string of maximum size N
char *LoadString(int N) {
    char *str = (char *)malloc(N * sizeof(char));
    printf("Please enter the string: ");
    scanf("%s", str);
    return str;
}

// Function to get the length of a string
int StringLength(char *str) {
    int string_length = 0;
    while(str[string_length] != '\0'){
        string_length++;
    }
    return string_length;
}

// Function to reverse the array
void ReverseArray(char Array[], char Reversed[], int length) {
    for (int i = 0; i < length; i++) {
        Reversed[i] = Array[length - 1 - i];
    }
}

// Function to load the array from the string
void LoadArray(char *str, char Array[]) {
    int i = 0;
    while(str[i] != '\0'){
        Array[i] = str[i];
        i++;
    }
    Array[i] = '\0';
}

// Function to display the array
void DisplayArray(char Array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", Array[i]);
    }
    printf("\n");
}
