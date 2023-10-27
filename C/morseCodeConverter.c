#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse Code array for each letter and digit
char* morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", 
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

char getCharFromMorse(char* morse) {
    for (int i = 0; i < 36; i++) {
        if (strcmp(morse, morseCode[i]) == 0) {
            if (i < 26)
                return 'A' + i;
            else
                return '0' + i - 26;
        }
    }
    return ' ';  // return space for unmatched Morse code
}

void getTextFromMorse(char* morse) {
    char delimiter[] = " ";
    char* token = strtok(morse, delimiter);

    while (token != NULL) {
        printf("%c", getCharFromMorse(token));
        token = strtok(NULL, delimiter);
    }
    printf("\n");
}

void getMorseFromText(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            printf("%s ", morseCode[toupper(text[i]) - 'A']);
        } else if (isdigit(text[i])) {
            printf("%s ", morseCode[text[i] - '0' + 26]);
        } else if (text[i] == ' ') {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char choice;
    char input[100];

    printf("Choose an option:\n");
    printf("1. Convert Text to Morse\n");
    printf("2. Convert Morse to Text\n");
    printf("Enter your choice (1/2): ");
    scanf("%c", &choice);
    getchar();  // To consume the newline character

    if (choice == '1') {
        printf("Enter text: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';  // Remove newline character
        getMorseFromText(input);
    } else if (choice == '2') {
        printf("Enter Morse code (separate letters with spaces and words with two spaces): ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';  // Remove newline character
        getTextFromMorse(input);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
