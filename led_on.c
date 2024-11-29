#include <stdio.h>
#include <stdint.h>
//simple LED Turn On code with bit masking
int main() {

    //Initiailizing the variable for GPIOD from the pin-map of the device
    uint32_t pClkCtrlReg_val = (uint32_t) 0x40023830;
    uint32_t volatile *pClkCtrlReg = (uint32_t*)&pClkCtrlReg_val;
    uint32_t pPortDModeReg_val = (uint32_t) 0x40020C00;
    uint32_t volatile *pPortDModeReg = (uint32_t*)&pPortDModeReg_val;
    uint32_t pPortDOutReg_val = (uint32_t) 0x40020C14;
    uint32_t volatile *pPortDOutReg = (uint32_t*) &pPortDOutReg_val;

    //----> 1.  Enable Clock for the GPIOD Peripheral in the AHB1ENR
    /////Method 1:
    /*    
        uint32_t temp = *pClkCtrlReg;   //read:
        temp = temp | 0x08; //modify: //in binary it would be 0x00001000 i.e turning-on the third bit
        *pClkCtrlReg = temp; //write:
    */
   /////Method 2:
   *pClkCtrlReg |= 0x08;    
   hextobin("pClkCtrlReg Enabled : ", pClkCtrlReg);
   printf("Clock settings is Enabled for the AHB1 Bus\n");


    //----> 2. Configure the mode of the IO pin as output\
    //a. clear the 24th and 25th bit positions (CLEAR)
    *pPortDModeReg &= 0xFCFFFFFF;
    hextobin("pPortDModeReg cleared value: ",pPortDModeReg);
    //b. Make 24th bit position as 1 (SET)
    *pPortDModeReg |= 0x01000000;
    hextobin("pPortDModeReg updated value: ",pPortDModeReg);
    printf("Mode is SET correctly\n");
    //----> 3. set the 25th bit of the output data register to make the I/O pin 12 HIGH
    *pPortDOutReg |= 0x1000;
    hextobin("pPortDOutReg updated value: ",pPortDOutReg);
    printf("LED Turned ON\n");

    //[values on the right is actually the mask value which is determined w.r.t the pin-map]
    return 0;   
    while(getchar()!='\n'){
        getchar();
    }
}

void hextobin(char old[], uint32_t* hex){
    char str[9];
    char bin[32];
    sprintf(str,"%x",*hex);
    //printf("%s\n",str);
    char *p = str;
    printf("%s :",old);
    while (*p!='\0')
    {
        lookup(*p);
        //printf("%c\n",*p);
        p++;
    }
    printf("\n");   
}
void lookup(char p){
    switch(p)  
    {  
        case '0':  
        printf("0000");  
        break;  
        case '1':  
        printf("0001");  
        break;  
        case '2':  
        printf("0010");  
        break;  
        case '3':  
        printf("0011");  
        break;  
        case '4':  
        printf("0100");  
        break;  
        case '5':  
        printf("0101");  
        break;  
        case '6':  
        printf("0110");  
        break;  
        case '7':  
        printf("0111");  
        break;  
        case '8':  
        printf("1000");  
        break;  
        case '9':  
        printf("1000");  
        break;  
        case 'A':  
        printf("1010");  
        break;  
        case 'a':  
        printf("1010");  
        break;  
        case 'B':  
        printf("1011");  
        break;  
        case 'b':  
        printf("1011");  
        break;  
        case 'C':  
        printf("1100");  
        break;  
        case 'c':  
        printf("1100");  
        break;  
        case 'D':  
        printf("1101");  
        break;  
        case 'd':  
        printf("1101");  
        break;  
        case 'E':  
        printf("1110");  
        break;  
        case 'e':  
        printf("1110");  
        break;  
        case 'F':  
        printf("1111");  
        break;  
        case 'f':  
        printf("1111");  
        break;  
    }  
}