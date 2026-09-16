#ifndef RCC_CONFNIG_H_
#define RCC_CONFNIG_H_

/**
 * @brief 
 *   Your option :RCC_HSI
 *                RCC_HSE
 *                RCC_PLL            
 */ 

#define RCC_SYSCLK  RCC_HSE


/**
 * @brief 
 * your option : RCC_RC_CLK_     RC will be the sourse of clock system
 *              RCC_CRYSTAL_CLK_   CRYSTAL will be the sours of clock system
 */
#if RCC_SYSCLK== RCC_HSE     
#define RCC_CLK_BYPASS    RCC_RC_CLK_
#endif



#define RCC_ SYSTEM_CLOCK_SWITCH   RCC_SELECT_HSI

#endif 
/*RCC_CONFNIG_H_*/


