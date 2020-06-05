#include "GPIO.h"
#include "KeyPad.h"
#include "LCD.h"
#include "UART.h"
#include "stdlib.h"
#include <stdio.h>
#include "Interrupt.h"
extern  uint8 Str[100];
uint8 Room_Status[100];
uint8 Lock_Status[100];
uint32 Passwords[100];
uint8 pass [20];
uint8 room [20];
void setRoomsStatus(uint8 RoomNum)
{
    uint8 i;
    UART_Send_String("For Each Room Enter It's Status : \r\n",UART_0);
    for(i=0; i<RoomNum; i++)
    {
        uint8 snum[5];
        sprintf(snum,"%d",i+1) ;
        UART_Send_String("Room ",UART_0);
        UART_Send_String(snum,UART_0);
        UART_Send_String(" : ",UART_0);
        UART_Receive_String(UART_0);
        UART_Send_String("\r\n",UART_0);
        Room_Status[i]=atoi(Str);
        if(Room_Status[i] != 3  ) //Busy or Free and its locked
            Lock_Status[i]=1;
        else
            Lock_Status[i]=0;
        UART_Send_String("Enter The Password : ",UART_0);
        UART_Receive_String(UART_0);
        Passwords[i] = atoi(Str) ;
        UART_Send_String("\r\n",UART_0);
    }
}
void GPIOPortF_Handler(void)
{
    uint8 j =0;
    GPIO_PORTF_ICR_R = 0x10;
    digitalWrite(PortF,P3,High);
    Clear_Screen();
    Display_String("Enter Room Number Then Press '*'");
    Set_Position(1,0);
    j=0;
    while(keypad_get_char() != '*')
    {
        room[j] = keypad_get_char();
        Display_Character(room[j]);
        j++;
    }
    if(Room_Status[atoi(room)]==3)
    {
        Clear_Screen();
        Display_String("Unloced");
        Lock_Status[atoi(room)]=0;
    }
    else
    {
        j=0;
        Display_String("Enter Password Then Press '*'");
        Set_Position(1,0);
        while(keypad_get_char() != '*')
        {
            pass[j] = keypad_get_char();
            Display_Character(pass[j]);
            j++;
        }
        Clear_Screen();
        if(Passwords[atoi(room)] == atoi(pass))
        {
            Clear_Screen();
            Display_String("Unloced");
            Lock_Status[atoi(room)]=0;
        }
        else
        {
            Clear_Screen();
            Display_String("Wrong Try Again");
        }
				digitalWrite(PortF,P2,Lock_Status[atoi(room)]);
    }
}
void SystemInit() {}
int main()
{
    uint8 curRoom;
    uint8 Room_Num ;
    uint8 chose;
		pinMode(PortF,P2,Output);
		GPIO_Int(PortF ,P0);
    Control_Pins_Init();
    Data_Port_Init();
    keypad_init();
    Display_String("Press 'OK' to Unlock"); // P0 PortF
    UART_Init(UART_0,8,9600);
    UART_Send_String("DOORS LOCK CONTROL\r\n=====================\r\n\r\n**** SETUP MODE *****\r\n\r\nPlease Enter The Number Of Rooms : ",UART_0);
    UART_Receive_String(UART_0);
    UART_Send_String("\r\n",UART_0);
    Room_Num = atoi(Str);
    setRoomsStatus(Room_Num);
    UART_Send_String("\r\n**** OPERATIONAL MODE *****\r\n\r\n",UART_0);
    while(1)
    {
        UART_Send_String("MAIN MENU\r\n",UART_0);
        UART_Send_String("1-Check the room status.\r\n",UART_0);
        UART_Send_String("2-Change the room status.\r\n",UART_0);
        UART_Send_String("3-Change Password.\r\n",UART_0);
        UART_Receive_String(UART_0);
        chose = atoi(Str);
        while(chose!= 1 || chose!= 2 || chose!= 3 )
        {
            UART_Send_String("\r\nTry Again\r\n",UART_0);
            UART_Receive_String(UART_0);
            chose = atoi(Str);
        }
        UART_Send_String("\r\nEnter Room Number\r\n",UART_0);
        UART_Receive_String(UART_0);
        UART_Send_String("\r\n",UART_0);
        curRoom = atoi(Str);
        if(chose == 1)
        {
            curRoom--;
            UART_Send_String("Room Is ",UART_0);
            if(Room_Status[curRoom] == 1 )
                UART_Send_String("Busy",UART_0);
            else if(Room_Status[curRoom] == 2 )
                UART_Send_String("Free",UART_0);
            else
                UART_Send_String("Room Service",UART_0);
            UART_Send_String("\r\n",UART_0);
        }
        else if(chose == 2)
        {
            UART_Send_String("Enter Room Status : ",UART_0);
            UART_Receive_String(UART_0);
            Room_Status[curRoom] = atoi(Str);
            if(Room_Status[curRoom] != 3  ) //Busy or Free and its locked
                Lock_Status[curRoom]=1;
            else
                Lock_Status[curRoom]=0;
            UART_Send_String("\r\n",UART_0);
        }
        else if(chose == 3)
        {
            UART_Send_String("Enter Room Password : ",UART_0);
            UART_Receive_String(UART_0);
            Passwords[curRoom] = atoi(Str) ;
            UART_Send_String("\r\n",UART_0);
        }
    }

}
