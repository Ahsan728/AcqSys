# AcqSys ¨ Acquistion System
During the development of AI algorithms, we need high-quality data. It is quite tough to get these data from the field because products in the field are not 
usually connected to the system. To solve this issue this firmware proposes to Design a ready-to-run acquisition system for monitoring electrical parameters 
like voltage, current, temperature, and noise. This system will have high accuracy on battery and low power and will be connected to the cloud
through LTE-M. Then we will analyse the data by using MATLAB & Simulink.Finally, it could be able to run local algorithms, and connect a local MATLAB to
the cloud to train/deploy AI algorithms. 

## Testing with Texas instrument ADS131M08 module
The ADS131M08EVM kit includes the ADS131M08EVM board and a precision host interface (PHI) controller board. At first we integrated this board with our Arduino MKR board
to read the data from 8 channels. Because of having in built hardware clock generator this evalution module served sample data smoothly.
![image](https://github.com/Ahsan728/AcqSys/assets/34878134/8f5f6c68-9b21-4200-a77b-786e25ffdfda=250x250)


## Designing PCB 
## PCBA Assembly Prototype

## Firmware Design
- ADS131MO8 Library 
- Generating Fast Clock for ADC
- SAMD21 Turbo PWM
- Making Register Table 
- Arduino IoT Cloud Setup
- Reading Data from IoT cloud with Matlab
- Postman API writting in IoT Cloud
- Writting Data to IoT cloud with Matlab
- FreeRTOS Integration
- C code generation from Simulink
