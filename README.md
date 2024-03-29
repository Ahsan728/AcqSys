# ADS131M08 based electrical data acquistion and supervision with LTE-M, Matlab and Arduino cloud
During the development of AI algorithms, we need high-quality data. It is quite tough to get these data from the field because products in the field are not 
usually connected to the system. To solve this issue this firmware proposes to Design a ready-to-run acquisition system for monitoring electrical parameters 
like voltage, current, temperature, and noise. This system will have high accuracy on battery and low power and will be connected to the cloud
through LTE-M. Then we will analyse the data by using MATLAB & Simulink.Finally, it could be able to run local algorithms, and connect a local MATLAB to
the cloud to train/deploy AI algorithms. 
<img width="600" alt="Acqsys" src="https://github.com/Ahsan728/AcqSys/blob/main/Acqsys.jpg">

## ADS131M08 24-bit, 32-kSPS, 8-channel, simultaneous-sampling, delta-sigma ADC

The [ADS131M08](https://www.ti.com/product/ADS131M08?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-eu&utm_content=ADS131M08&ds_k=ADS131M08&DCM=yes&gclid=Cj0KCQjwj_ajBhCqARIsAA37s0w4aU0EHOuMJ_rvznhDMplgt0EuXRgVnTscBn1Xp007JM5lLw-OlZcaAjmYEALw_wcB&gclsrc=aw.ds) is a eight-channel, simultaneouslysampling, 24-bit, delta-sigma (ΔΣ), analog-to-digital converter (ADC) that offers wide dynamic range, low power, and energy-measurement-specific features, making the device an excellent fit for energy metering,power metrology, and circuit breaker applications.

<img width="350" alt="ADS131MO8 ADC" src="https://github.com/Ahsan728/AcqSys/blob/main/12aa6594544afb753217d5977a6ac90a.jpg"><img width="400" alt="Block ADC" src="https://github.com/Ahsan728/AcqSys/blob/main/Block%20ADC.PNG">




## Testing with Texas instrument ADS131M08 module
The [ADS131M08EVM kit](https://www.ti.com/tool/ADS131M08EVM#overview) includes the ADS131M08EVM board and a precision host interface (PHI) controller board. At first we integrated this board with our Arduino MKR board to read the data from 8 channels. Because of having in built hardware clock generator this evalution module served sample data smoothly.

<img width="400" alt="Evalution" src="https://github.com/Ahsan728/AcqSys/blob/main/ads131m08evm-angled.png">



## Designing PCB 

<img width="400" alt="PCB Valise" src="https://github.com/Ahsan728/AcqSys/blob/main/PCB%20Valise.PNG"><img width="400" alt="Valise" src="https://github.com/Ahsan728/AcqSys/blob/main/Valise.PNG"> 


Figure: Our designed PCB layout 


## PCBA Assembly Prototype

<img width="400" alt="Prototype" src="https://github.com/Ahsan728/AcqSys/blob/main/Board.png"> 



## Firmware Design
- ADS131MO8 Library 

We have started the firmware development from the [ADS131MO8 library](https://github.com/joshbrew/ADS131M08_Arduino) developed by Joshua Brewster.


- Generating Fast Clock for ADC
- SAMD21 Turbo PWM

[SAMD21 Turbo PWM Library](https://github.com/ocrdu/Arduino_SAMD21_turbo_PWM), developed by Oscar den Uijl has been utilised to provide the 2MHz clock signal to the ADC.

- Making Register Table 
- Arduino IoT Cloud Setup
- Reading Data from IoT cloud with Matlab
- Postman API writting in IoT Cloud
- Writting Data to IoT cloud with Matlab
- FreeRTOS Integration
- C code generation from Simulink
