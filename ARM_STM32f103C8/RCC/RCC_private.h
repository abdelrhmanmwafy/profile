#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/**
 * @brief 
 * register rcc
 */
#define RCC_CR (*((volatile u32 *) 0x40021000))         
#define RCC_CFGR (*((volatile u32 *)0x40021004))
#define RCC_CIR (*((volatile u32 *)0x40021008))
#define RCC_APB2RSTR (*((volatile u32 *)0x4002100C))      
#define RCC_APB1RSTR (*((volatile u32 *)0x40021010))
#define RCC_AHBENR (*((volatile u32 *)0x40021014))
#define RCC_APB2ENR (*((volatile u32 *)0x40021018))
#define RCC_APB1ENR (*((volatile u32 *)0x4002101C))
#define RCC_BDCR (*((volatile u32 *)0x40021020))
#define RCC_CSR (*((volatile u32 *)0x40021024))
#define RCC_AHBRSTR (*((volatile u32 *)0x40021028))

#define RCC_RC_CLK_   0
#define RCC_CRYSTAL_CLK_   1

#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

/**
 * @brief 
 * RCC_RC_BITS USE 
 */
#define RCC_CR_HSION   0
#define RCC_CR_HSIRDY  1
#define RCC_CR_HSEON   16
#define RCC_CR_HSERDY  17
#define RCC_CR_HSEBYP  18
#define RCC_CR_PLLON   24
#define RCC_CR_PLLRDY  25



/**
 * @brief 
 * RCC_CGFGR BIT 
 * 
 */
#define RCC_CGFGR_SW 0

#define RCC_SELECT_HSI 0
#define RCC_SELECT_HSE 1
#define RCC_SELECT_PLL 2
#endif /*RCC_PRIVATE_H_*/



/**
 * @brief 
 * 
 * perpherial ahb _abp1 _abp2
 */
#define RCC_AHB      0
#define RCC_ABP1     1 
#define RCC_ABP2     2

/**
 * @defgroup RCC_AHB_BIT
 * identification BIT IN AHB Perpherial  REG (RCC_AHBENR) MACRO
 * 
 */
#define RCC_AHB_DMA1EN          0       /**< Bit 0 DMA1 clock enable */
#define RCC_AHB_DMA2EN          1       /**< Bit1 DMA2EN: DMA2 clock enable */
#define RCC_AHB_SRAMEN          2      /**<SRAMEN: SRAM interface clock enable */
#define RCC_AHB_FLITFEN         4      /**<FLITFEN: FLITF clock enable */
#define RCC_AHB_CRCEN           6       /**<Bit 6CRCEN: CRC clock enable*/
/**Bits 11:7Reserved, must be kept at reset value.*/
#define RCC_AHB_OTGFSEN         12        /**<Bit 12OTGFSEN: USB OTG FS clock enable*/
#define RCC_AHB_ETHMACEN        14        /**< ETHMACEN: Ethernet MAC clock enable*/
#define RCC_AHB_ETHMACTXEN      15         /**<ETHMACTXEN: Ethernet MAC TX clock enable */
#define RCC_AHB_ETHMACRXEN      16          /**<ETHMACRXEN: Ethernet MAC RX clock enable */


/**
 * @defgroup RCC_ABP1_BIT
 * identification BIT IN ABP1 Perpherial  REG (RCC_ABP1ENR) MACRO
 */

 #define RCC_ABP_TIM2EN     0
 #define RCC_ABP1_TIM3EN    1
 #define RCC_ABP1_TIM4EN    2   
 #define RCC_ABP1_TIM5EN    3   
 #define RCC_ABP1_TIM6EN    4   
 #define RCC_ABP1_TIM7EN    5
 /**Bits 10:6 Reserved, must be kept at reset value.*/
 #define RCC_ABP1_WWDGEN    11
 #define RCC_ABP1_SPI2EN    14
 #define RCC_ABP1_SPI3EN    15
 #define RCC_ABP1_USART2EN  17
 #define RCC_ABP1_USART3EN  18
 #define RCC_ABP1_UART4EN   19
 #define RCC_ABP1_UART5EN   20
 #define RCC_ABP1_I2C1EN    21
 #define RCC_ABP1_I2C2EN    22   
 #define RCC_ABP1_CAN1EN    25
 #define RCC_ABP1_CAN2EN    26    
 #define RCC_ABP1_BKPEN     27
 #define RCC_ABP1_PWREN     28
 #define RCC_ABP1_DACEN     29


 /**
 * @defgroup RCC_ABP2_BIT 
 * identification BIT IN ABP2 Perpherial  REG (RCC_ABP2ENR) MACRO
 */

 #define RCC_ABP2_AFIOEN              0
 #define RCC_ABP2_IOPAEN              2
 #define RCC_ABP2_IOPBEN              3
 #define RCC_ABP2_IOPCEN              4
 #define RCC_ABP2_IOPDEN              5
 #define RCC_ABP2_IOPEEN              6
 #define RCC_ABP2_ADC1EN              9
 #define RCC_ABP2_ADC2EN              10
 #define RCC_ABP2_TIM1EN              11
 #define RCC_ABP2_SPI1EN              12
 #define RCC_ABP2_USART1EN            14

/////////////*********************************************///////////////////////// 

 /**
  * @defgroup 
  *   register name AHB peripheral clock reset register (RCC_AHBRSTR)
  * page --> 153 
  * use rst peripheral 
  *                             ETHMACRST Ethernet MAC reset
  *                             OTGFSRST USB OTG FS reset
  */
  #define RCC_ETHMACRST 0
  #define RCC_OTGFSRST 1
/**
 * 
 * number of bit register RCC_AHBRSTR
 */
   #define  RCC_RST_ETHMACRST_  14 
   #define  RCC_RST_OTGFSRST_  12
