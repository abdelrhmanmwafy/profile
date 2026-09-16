#ifndef RCC_PROGRAME_H_
#define RCC_PROGRAME_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

 



Set_ReeturnType Mcal_Rcc_InitSysClock(void)
{
    
       Set_ReeturnType local_FunctionStatueds=E_NOT_OK;
    #if  RCC_SYSCLK  == RCC_HSE 
     SET_BIT(RCC_CR,RCC_CR_HSEON);/** <- ENABel HSE */

        #if RCC_CLK_BYPASS ==RCC_RC_CLK_ 
            CLR_BIT(RCC_CR,RCC_CR_HSEBYP);/**<- RCC_RC_CLK */
            #elif RCC_CLK_BYPASS ==RCC_CRYSTAL_CLK_ /**<- RCC_CRYSTAL_CLK */
            SET_BIT(RCC_CR,RCC_CR_HSEBYP);

            #else 
            #error "Wrong CHOICE" 

           
        #endif
            /**<wait the time stable  */
            while (!GET_BIT(RCC_CR,RCC_CR_HSERDY));//BISY WAIT         //ALWAYSE WHILE TRUE 1 // <- NOT =0  ENGH TOUR 0 LOOP AGAIN TO = 1 
           
        RCC_CFGR &=~(0b11 << 0);
        RCC_CFGR |=(0b01 << 0);
local_FunctionStatueds=E_OK;



        #elif RCC_SYSCLK == RCC_HSI
        SET_BIT(RCC_CR,RCC_CR_HSION);
         while (!GET_BIT(RCC_CR,RCC_CR_HSIRDY));
       
        RCC_CFGR &=~(0b11 << 0);
        RCC_CFGR |=(0b00 << 0);

        #elif RCC_SYSCLK == RCC_PLL
 SET_BIT(RCC_CR,RCC_CR_PLLON );
          while (!GET_BIT(RCC_CR,RCC_CR_PLLRDY));
 RCC_CFGR &=~(0b11 << 0);
        RCC_CFGR |=(0b11 << 0);
       
            #endif

            return local_FunctionStatueds;
}

Set_ReeturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId)
{

        Set_ReeturnType local_FunctionStatueds = E_NOT_OK;

        switch (Copy_BusId)
        {
            case RCC_AHB :
            SET_BIT(RCC_AHBENR,Copy_PeripheralId);
            local_FunctionStatueds = E_OK ;
            break;
            case RCC_ABP1 :
            SET_BIT(RCC_APB1ENR,Copy_PeripheralId);
            
            local_FunctionStatueds = E_OK ;
            break;
            case RCC_ABP2 :
            SET_BIT(RCC_APB2ENR,Copy_PeripheralId);
            local_FunctionStatueds = E_OK ;
                break;
            

            default:
             local_FunctionStatueds = E_NOT_OK;
            break;
        }

            return local_FunctionStatueds;  


}
Set_ReeturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId)
{
    Set_ReeturnType local_FunctionStatueds = E_NOT_OK;

        switch (Copy_BusId)
        {
            case RCC_AHB :
            CLR_BIT(RCC_AHBENR,Copy_PeripheralId);
            local_FunctionStatueds = E_OK ;
            break;
            case RCC_ABP1 :
            CLR_BIT(RCC_APB1ENR,Copy_PeripheralId);
            
            local_FunctionStatueds = E_OK ;
            break;
            case RCC_ABP2 :
            CLR_BIT(RCC_APB2ENR,Copy_PeripheralId);
            local_FunctionStatueds = E_OK ;
                break;
            

            default:
             local_FunctionStatueds = E_NOT_OK;
            break;
        }

            return local_FunctionStatueds;  



}

Set_ReeturnType Mcal_RCC_RST(u8 Copy_RstType)
{
Set_ReeturnType localFunction = E_OK;
switch (Copy_RstType)
{
case RCC_ETHMACRST:
    SET_BIT(RCC_AHBRSTR,RCC_RST_ETHMACRST_);
    break;

    case RCC_OTGFSRST :
    SET_BIT(RCC_AHBRSTR,RCC_RST_OTGFSRST_);
    break;
default:
localFunction = E_NOT_OK;
    break;
}

return localFunction;
}


#endif
/*RCC_PROGRAME_H_*/


