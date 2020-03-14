#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int c;
unsigned char* symbolsUpRus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
unsigned char* symbolsLowRus = "abcdefghijklmnopqrstuvwxyz";//"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
unsigned char* numbers = "0123456789";
unsigned char* inputparam = "!*,.?;)(+-:\"/'";


void Keycode(unsigned char s,unsigned char* symb)
{
    for (int i = 0; i < strlen(symb); i++)
    {
        if (s == symb[i])
        {
            c = i;
            break;
        }
    }
}

unsigned char* choose(unsigned char a, unsigned char* paramSymbol)
{
    for (int i = 0; i < strlen(symbolsLowRus); i++)
    {
        if (a == symbolsLowRus[i])
        {
            return  symbolsLowRus;
        }
        if (a == symbolsUpRus[i])
        {
            return symbolsUpRus;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (a==numbers[i]) return numbers;
    }
    return paramSymbol;

}


unsigned char* atbash(unsigned char Text[],unsigned char param[])
{
    unsigned size = strlen(Text);
    char* text;
    text = (char*)malloc(255);
    text = strcpy(text, Text);
    int i = 0;
    char* symbolsText;
    while (Text[i] != '\0') {
        if (Text[i]!=' ')
        {
            symbolsText = choose(Text[i], param);
            Keycode(Text[i], symbolsText);
            unsigned pos = strlen(symbolsText) - c-1;
            text[i]= (symbolsText[pos]);
        }
            i++;

    }
    return text;
}

unsigned char* goodAddress(unsigned char badAddress[])
{
    int i=0;
    while(badAddress[i]!='\0')
    {
        if (badAddress[i]=='\n')
        {
            badAddress[i]='\0';
        }
        i++;
    }
    return badAddress;
}
int main() {
    setlocale(LC_ALL,"ru_RU.UTF-8");

    FILE *inputText, *outputText, *paramText;
    unsigned char inputAddress[255];
    unsigned char outputAddress[255];
    unsigned char paramAddress[255];
    unsigned char* message;
    unsigned char* param;
    message=(unsigned char*)malloc(255);
    param=(unsigned char*)malloc(255);
    printf("Добро пожаловать в программу шифрования методом Атбаш\n");
    printf("Введите адрес исходного файла:\n");
    fgets(inputAddress,255,stdin);
    printf("Введите адрес выходного файла\n");
    fgets(outputAddress,255,stdin);
    printf("Введите адрес файла с дополнительными параметрами\n");
    fgets(paramAddress,255,stdin);

    unsigned char* inputGood = goodAddress(inputAddress);
    unsigned char* outputGood = goodAddress(outputAddress);
    unsigned char* paramGood = goodAddress(paramAddress);

    inputText=fopen(inputGood,"r");
    if(inputText!=NULL)
    {
    fgets(message,255,inputText);
    fclose(inputText);
    }
    else exit(0);

    paramText = fopen(paramGood,"r");
    fgets(param,255,paramText);
    fclose(paramText);


    outputText = fopen(outputGood,"w");
    unsigned char* encoded;
    unsigned char* message1 = goodAddress(message);
    unsigned char* messageParam = goodAddress(param);

    encoded = atbash(message1,messageParam);
    puts(encoded);
    fputs(encoded,outputText);
    fclose(outputText);


    return 0;

}
