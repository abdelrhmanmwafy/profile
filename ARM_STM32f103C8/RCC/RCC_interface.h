#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_



Set_ReeturnType Mcal_Rcc_InitSysClock(void);

Set_ReeturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId);
Set_ReeturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId , u8 Copy_BusId);
Set_ReeturnType Mcal_RCC_RST(u8 Copy_RstType);
#endif /*RCC_INTERFACE_H_*/