#include "isr.h"



void UART4_RX_TX_IRQHandler(void)
{
    uint8_t ch;
    //中断发送处理过程
    UART_SendDataIntProcess(UART4);
    //如果成功接收到了数据
    if(UART_ReceiveData(UART4, &ch))
    {
        //把接收到的信息发送回去 echo
        UART_SendData(UART4,ch);
    }
}

