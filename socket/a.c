#include <lpc21xx.h>
void delay(int);
void sendCommand(int);
void sendData(char);
int displayPotentiometerValue(int, int);
void displayString(const char *, int, int);
int main()
{

    IO1DIR = 0xFFFFFFFF;
    IO0DIR = 0xFFFFFFFF;
    PINSEL1 = 0x15400000;
    sendCommand(0x38);          
    sendCommand(0x80);          
    sendCommand(0x01);          
    sendCommand(0x06);          
    sendCommand(0x0E);          
    while (1)
    {
		int potentiometerValue = 0; 
        delay(50);
        sendCommand(0x01); 
        ADCR = 0x01200401;
        while ((ADDR & 0x80000000) == 1)
            ;                                                         
        potentiometerValue = displayPotentiometerValue(ADDR >> 6, 0); 
        if (potentiometerValue >= 1023)
        {
            displayString("Crash Detected!", 1, 0);
        }
        else
        {
            displayString("SAFE", 1, 0);
        }
        delay(2000);
    }
}
void sendCommand(int command)
{
    IO1CLR = 0xFFFFFFFF;
    IO1SET = command << 16;
    IO1SET = 0x20000000;
    delay(50);
    IO1CLR = 0x20000000;
    delay(50);
}
void sendData(char data)
{
    IO1CLR = 0xFFFFFFFF;
    IO1SET = data << 16;
    IO1SET = 0x30000000;
    delay(50);
    IO1CLR = 0x20000000;
    delay(50);
}
void delay(int t)
{
    int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 500; j++)
            ;
}
int displayPotentiometerValue(int value, int column)
{
    sendCommand(0x80 + column); 
    sendData((value / 1000) + 48);
    sendData(((value / 100) % 10) + 48);
    sendData((value % 100) / 10 + 48);
    sendData((value % 10) + 48);
    return value;
}
void displayString(const char *str, int row, int column)
{
    int position = 0;
    if (row == 0)
        position = 0x80 + column;
    else if (row == 1)
        position = 0xC0 + column;
    sendCommand(position); 
    while (*str != '\0')
    {
        sendData(*str);
        str++;
    }
}