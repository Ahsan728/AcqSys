# AcqSys ¨ Acquistion System
During the development of AI algorithms, we need high-quality data. It is quite tough to get these data from the field because products in the field are not 
usually connected to the system. To solve this issue this firmware proposes to Design a ready-to-run acquisition system for monitoring electrical parameters 
like voltage, current, temperature, and noise. This system will have high accuracy on battery and low power and will be connected to the cloud
through LTE-M. Then we will analyse the data by using MATLAB & Simulink.Finally, it could be able to run local algorithms, and connect a local MATLAB to
the cloud to train/deploy AI algorithms. 

## ADS131M08 24-bit, 32-kSPS, 8-channel, simultaneous-sampling, delta-sigma ADC

The [ADS131M08](https://www.ti.com/product/ADS131M08?utm_source=google&utm_medium=cpc&utm_campaign=asc-null-null-GPN_EN-cpc-pf-google-eu&utm_content=ADS131M08&ds_k=ADS131M08&DCM=yes&gclid=Cj0KCQjwj_ajBhCqARIsAA37s0w4aU0EHOuMJ_rvznhDMplgt0EuXRgVnTscBn1Xp007JM5lLw-OlZcaAjmYEALw_wcB&gclsrc=aw.ds) is a eight-channel, simultaneouslysampling, 24-bit, delta-sigma (ΔΣ), analog-to-digital converter (ADC) that offers wide dynamic range, low power, and energy-measurement-specific features, making the device an excellent fit for energy metering,power metrology, and circuit breaker applications.

<img width="395" alt="ADS131MO8 ADC" src="https://github.com/Ahsan728/AcqSys/assets/34878134/cf75ea02-5791-4011-996a-50f07d80848d">
<img width="410" alt="Block ADC" src="https://github.com/Ahsan728/AcqSys/assets/34878134/b36343f2-f3a1-4b6b-93a6-7ef024c0110d">



## Testing with Texas instrument ADS131M08 module
The [ADS131M08EVM kit](https://www.ti.com/tool/ADS131M08EVM#overview) includes the ADS131M08EVM board and a precision host interface (PHI) controller board. At first we integrated this board with our Arduino MKR board to read the data from 8 channels. Because of having in built hardware clock generator this evalution module served sample data smoothly.

<img width="400" alt="Evalution" src="https://github.com/Ahsan728/AcqSys/assets/34878134/6617d9fa-873d-4db5-bdc3-74293da2058e">



## Designing PCB 

<img width="450" alt="PCB Valise" src="https://github.com/Ahsan728/AcqSys/assets/34878134/17bd8811-b529-4477-8953-8109e1c3dff8">
<img width="450" alt="Valise" src="https://github.com/Ahsan728/AcqSys/assets/34878134/d2c1920f-33a1-4cb3-a819-6a4a06f91ec3"> 


Figure: Our designed PCB layout 


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
