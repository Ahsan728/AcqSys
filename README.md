# ADS131M08 based electrical data acquistion and supervision with LTE-M, Matlab and Arduino cloud
At Schneider Electric, engineers engaged in the development of AI algorithms require high-quality data samples. However, obtaining these data from the field presents challenges due to the limited connectivity of field products to the system. To address this challenge, this project proposes designing a ready-to-run acquisition system for monitoring electrical parameters such as voltage, current, temperature, and noise. This system will demonstrate high accuracy while operating efficiently on battery power, and it will establish a connection to the cloud using narrowband IoT technology, such as LTE-M. Subsequently, the acquired data will undergo analysis using local MATLAB and Simulink tools. Following the data analysis, our developed Simulink embedded algorithms will generate C code, which will then be seamlessly integrated into the firmware. This code will facilitate RMS measurements and anomaly detection for various loads.

## Block Diagram
![Acqsys](https://github.com/Ahsan728/AcqSys/assets/34878134/b06272f2-f530-438e-b3c9-c1974115136c)

From the figure above, we can observe that this acquisition system can be accessed both manually and via a Matlab session. For the manual option, Technician2 on-site pushes the button. Then, two ADS131M08 ADCs handle the analog data from voltage contacts, current Rogowski sensors, noise, and vibration. The Arduino SAMD21 ARM Cortex M0 processor collects these analog data through SPI communication and sends them to the Arduino IoT cloud using LTE-M. The analog data becomes visible in the cloud, and this acquisition can also be controlled from a push button designed in the cloud. Internal DAC generates analog waveforms for our calibration in house R&D purpose.

Technician1 can analyze the sample data from the cloud using local Matlab web access. Reading from and writing to the cloud are possible through Matlab web access scripts. Technician1 can also write register values to ADCs via API oath and IoT protocol. For further feature extractions, the RMS calculation algorithm is generated using Simulink, and the resulting C codes can be integrated with the Arduino firmware. 

## ADS131M08 24-bit, 32-kSPS, 8-channel, simultaneous-sampling, delta-sigma ADC

Delta-sigma ADCs are commonly used for applications that require high-resolution and high-precision analog-to-digital conversion, such as industrial instrumentation, medical devices, and data acquisition systems. Texas Instruments produces the ADS131M08 analog-to-digital converter (ADC) integrated circuit. In a physical view its a 32 pin ADC shown in figure. For applications that demand precise and dependable data conversion from analog to digital format, this high-precision, low-power, 24-bit ADC has been developed.

<img width="190" alt="ADS131M08 Chip" src="https://github.com/Ahsan728/AcqSys/assets/34878134/f4f4e96e-7cf1-4720-9dbd-a9ecf111c403"><img width="200" alt="pinoutADC" src="https://github.com/Ahsan728/AcqSys/assets/34878134/285c0da3-a9bc-4db4-a63d-61382245a1e7">




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
