# ADS131M08 based electrical data acquistion and supervision with LTE-M, Matlab and Arduino cloud
At Schneider Electric, engineers engaged in the development of AI algorithms require high-quality data samples. However, obtaining these data from the field presents challenges due to the limited connectivity of field products to the system. To address this challenge, this project proposes designing a ready-to-run acquisition system for monitoring electrical parameters such as voltage, current, temperature, and noise. This system will demonstrate high accuracy while operating efficiently on battery power, and it will establish a connection to the cloud using narrowband IoT technology, such as LTE-M. Subsequently, the acquired data will undergo analysis using local MATLAB and Simulink tools. Following the data analysis, our developed Simulink embedded algorithms will generate C code, which will then be seamlessly integrated into the firmware. This code will facilitate RMS measurements and anomaly detection for various loads.

<img width="280" alt="PCB Valise" src="https://github.com/Ahsan728/AcqSys/assets/34878134/772a7bcc-7d74-44e9-a8ab-280cc6242c1f"> <img width="260" alt="Board" src="https://github.com/Ahsan728/AcqSys/assets/34878134/a25cca0b-d202-45e5-9c46-35ad21eb7e82">

## Functionality Status and Reliability

| Feature       | Status  | Reliability | Notes |
|--------------|--------|-------------|--------------------------------------------------------------------------------------------------|
| Data Acq     | Stable | High        | Collects analog data from devices through ADS131M08 ADC and SPI |
| Sending Cloud| Stable | High        | Uses LTEM to send the data in Arduino Cloud|
| Matlab Session| Stable | High       | Access the data from the cloud through matlab script|
| Simulink Algorithm| Stable | High   | Simulink Algorithm detects the anomaly in the system and provide feedback |
| FreeRTOS  | Stable | Medium        | Handles different tasks of the firmware|


## Block Diagram
<img width="580" alt="Acqsys" src="https://github.com/Ahsan728/AcqSys/assets/34878134/b06272f2-f530-438e-b3c9-c1974115136c">


From the figure above, we can observe that this acquisition system can be accessed both manually and via a Matlab session. For the manual option, Technician2 on-site pushes the button. Then, two ADS131M08 ADCs handle the analog data from voltage contacts, current Rogowski sensors, noise, and vibration. The Arduino SAMD21 ARM Cortex M0 processor collects these analog data through SPI communication and sends them to the Arduino IoT cloud using LTE-M. The analog data becomes visible in the cloud, and this acquisition can also be controlled from a push button designed in the cloud. Internal DAC generates analog waveforms for our calibration in house R&D purpose.

Technician1 can analyze the sample data from the cloud using local Matlab web access. Reading from and writing to the cloud are possible through Matlab web access scripts. Technician1 can also write register values to ADCs via API oath and IoT protocol. For further feature extractions, the RMS calculation algorithm is generated using Simulink, and the resulting C codes can be integrated with the Arduino firmware. 

## ADS131M08 24-bit, 32-kSPS, 8-channel, simultaneous-sampling, delta-sigma ADC

Delta-sigma ADCs are commonly used for applications that require high-resolution and high-precision analog-to-digital conversion, such as industrial instrumentation, medical devices, and data acquisition systems. Texas Instruments produces the ADS131M08 analog-to-digital converter (ADC) integrated circuit. In a physical view its a 32 pin ADC shown in figure. For applications that demand precise and dependable data conversion from analog to digital format, this high-precision, low-power, 24-bit ADC has been developed.

<img width="190" alt="ADS131M08 Chip" src="https://github.com/Ahsan728/AcqSys/assets/34878134/f4f4e96e-7cf1-4720-9dbd-a9ecf111c403"><img width="200" alt="pinoutADC" src="https://github.com/Ahsan728/AcqSys/assets/34878134/285c0da3-a9bc-4db4-a63d-61382245a1e7">

## Software Architecture
<img width="500" alt="Software Architecture" src="https://github.com/Ahsan728/AcqSys/assets/34878134/a84e4e36-2f9c-4769-a888-ef970ef78064">

The crucial part of this project was to develop the firmware of the system. We choose the PlatformIO ecosystem and integrated it into Visual Studio Code. PlatformIO is an open-source ecosystem for IoT development that provides an IDE for various microcontroller platforms. The figure above depicts the whole software development process.We developed the ADC library within the firmware, along with configuring NB-IoT configuration within the Real-Time Operating System FreeRTOS. The ADC samples are transmitted to the Arduino Cloud, where the data can be read and written through a local Matlab script. Moreover, a Simulink model was created for computing RMS. This feature extraction algorithm generates C code that updates the firmware, enabling the calculation of subsequent samples within a synchronous function. Any kind of anomaly in electrical parameters are instantly available in cloud server.

## Simulink Embedded Algorithm

<img width="450" alt="Feature Extraction" src="https://github.com/Ahsan728/AcqSys/assets/34878134/5b756efe-9cdc-4300-8977-e044b524dba2"><img width="460" alt="PostProcessing" src="https://github.com/Ahsan728/AcqSys/assets/34878134/1d78fa87-4323-4801-b7b2-360e8e83b13c">

Algorithms that are implemented on embedded systems, which are specialized hardware platforms made to carry out certain activities or operations, are referred to as embedded algorithms. In the figure above, we have designed an embedded algorithm in simulink to serve the RMS calculation purpose for our acquisition system.In the left block, there are 8 distinct analog signals originating from 8 channels of the ADS131M08. Additionally, 8 unique calibration factors are directed towards the "PostProcessing" block. The "RMSDisplay" and "PowerDisplay" blocks depict the computed outcomes during simulation. On the right block, the PostProcessing segment has been constructed, within which a "PhPhConversion" block (depicted as Blue) is utilized to analyze the three-phase voltages. The variance across two lines as the phases intersect at an angle is commonly termed as the line-to-line voltage. In the PhPhConversion block, the calculation of the differences between V1, V2, and V3 is carried out, with V4 representing the ground reference. In the "SamplesCalibration" block (depicted as Yellow), all these analog signals undergo calibration using the 8 distinct calibration factors. Subsequently, the RMS is determined by the Red Block, while the Power values are computed by the Green Block.

## Calibration and Validation
<img width="460" alt="LabSetup" src="https://github.com/Ahsan728/AcqSys/assets/34878134/59068313-f8e4-454e-9aed-b5d90c7e34f9">
<img width="460" alt="Output 2" src="https://github.com/Ahsan728/AcqSys/assets/34878134/775b6e70-a449-4e4f-b510-5d8cd03f6fe2">

We have defined 8 calibration factors in our firmware. To put those factors we have analysed the AC current samples through our serial monitor. We have supplied 1 Amp current and found analog samples shown in figure. After analysing the AC current samples from one channel, maximum sample value was 460687. From the AC currents samples figure we can assume the data rate was approximately 4KSPS. Output from oscilloscope has been depicted in the figure above, where $\color{yellow}{\textsf{YELLOW}}$ Signal represents Current sample (single channel), $\color{green}{\textsf{GREEN}}$ Signal represents the Data Ready, $\color{brown}{\textsf{BROWN}}$ Signal represents the master Clock, and $\color{blue}{\textsf{BLUE}}$ Signal represents the Data Output.


