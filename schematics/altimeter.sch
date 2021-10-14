EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "HAB Altimeter"
Date "2021-08-31"
Rev "1"
Comp "Cambridge University Spaceflight"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Drawn By H. Franks"
$EndDescr
$Comp
L Strix:1v8 #PWR037
U 1 1 614B97EF
P 4950 3700
AR Path="/614B97EF" Ref="#PWR037"  Part="1" 
AR Path="/619FD90A/614B97EF" Ref="#PWR037"  Part="1" 
F 0 "#PWR037" H 4950 3810 50  0001 L CNN
F 1 "1v8" H 4950 3800 50  0000 C CNN
F 2 "" H 4950 3700 50  0001 C CNN
F 3 "" H 4950 3700 50  0001 C CNN
	1    4950 3700
	1    0    0    -1  
$EndComp
$Comp
L Strix:3v3 #PWR035
U 1 1 614B93CC
P 4750 3700
F 0 "#PWR035" H 4750 3810 50  0001 L CNN
F 1 "3v3" H 4750 3800 50  0000 C CNN
F 2 "" H 4750 3700 50  0001 C CNN
F 3 "" H 4750 3700 50  0001 C CNN
	1    4750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3700 4750 3750
$Comp
L Strix:GND #PWR036
U 1 1 614B83C5
P 4750 4000
F 0 "#PWR036" H 4620 4040 50  0001 L CNN
F 1 "GND" H 4750 3900 50  0000 C CNN
F 2 "" H 4750 4000 50  0001 C CNN
F 3 "" H 4750 4000 50  0001 C CNN
	1    4750 4000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4750 3900 4750 4000
Wire Wire Line
	4750 3900 4750 3850
Connection ~ 4750 3900
Wire Wire Line
	4950 3900 4750 3900
Wire Wire Line
	4950 3850 4950 3900
Wire Wire Line
	4950 3700 4950 3750
$Comp
L Strix:C C18
U 1 1 614B4366
P 4950 3750
F 0 "C18" V 4954 3808 50  0000 L CNN
F 1 "100n" V 5045 3808 50  0000 L CNN
F 2 "Strix:C_0402_1005Metric_Pad0.74x0.62mm_HandSolder" H 4950 3750 50  0001 C CNN
F 3 "" H 4950 3750 50  0001 C CNN
	1    4950 3750
	0    1    1    0   
$EndComp
$Comp
L Strix:C C17
U 1 1 614B3D60
P 4750 3750
F 0 "C17" V 4754 3808 50  0000 L CNN
F 1 "100n" V 4845 3808 50  0000 L CNN
F 2 "Strix:C_0402_1005Metric_Pad0.74x0.62mm_HandSolder" H 4750 3750 50  0001 C CNN
F 3 "" H 4750 3750 50  0001 C CNN
	1    4750 3750
	0    -1   1    0   
$EndComp
$Comp
L Strix:GND #PWR041
U 1 1 614AFE03
P 5400 3650
F 0 "#PWR041" H 5270 3690 50  0001 L CNN
F 1 "GND" H 5400 3550 50  0000 C CNN
F 2 "" H 5400 3650 50  0001 C CNN
F 3 "" H 5400 3650 50  0001 C CNN
	1    5400 3650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5400 3600 5400 3650
Wire Wire Line
	5400 3400 5550 3400
Wire Wire Line
	5400 3500 5400 3400
$Comp
L Strix:R R7
U 1 1 614AE40E
P 5400 3500
F 0 "R7" V 5404 3544 50  0000 L CNN
F 1 "100k" V 5495 3544 50  0000 L CNN
F 2 "Strix:R_0402_1005Metric_Pad0.72x0.64mm_HandSolder" H 5400 3500 50  0001 C CNN
F 3 "" H 5400 3500 50  0001 C CNN
	1    5400 3500
	0    1    1    0   
$EndComp
Text Notes 5800 4200 2    50   ~ 0
3v3/1v8 Level Shifter
Wire Notes Line
	5850 2150 5850 4250
Wire Notes Line
	4150 4250 5850 4250
Wire Notes Line
	4150 2150 4150 4250
Wire Notes Line
	5850 2150 4150 2150
Wire Wire Line
	6100 3250 5300 3250
Wire Wire Line
	6200 3350 6100 3350
$Comp
L Strix:GND #PWR033
U 1 1 61489648
P 4300 3650
F 0 "#PWR033" H 4170 3690 50  0001 L CNN
F 1 "GND" H 4300 3550 50  0000 C CNN
F 2 "" H 4300 3650 50  0001 C CNN
F 3 "" H 4300 3650 50  0001 C CNN
	1    4300 3650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 3400 4300 3650
Wire Wire Line
	4400 3400 4300 3400
Connection ~ 5400 3400
Wire Wire Line
	5300 3400 5400 3400
Wire Wire Line
	4050 3250 4400 3250
Wire Wire Line
	4400 2850 4050 2850
Wire Wire Line
	4050 3050 4400 3050
Wire Wire Line
	4400 2950 4050 2950
Wire Wire Line
	4050 3150 4400 3150
NoConn ~ 5300 2750
NoConn ~ 4400 2750
$Comp
L Strix:1v8 #PWR040
U 1 1 614849D6
P 5400 2500
AR Path="/614849D6" Ref="#PWR040"  Part="1" 
AR Path="/619FD90A/614849D6" Ref="#PWR040"  Part="1" 
F 0 "#PWR040" H 5400 2610 50  0001 L CNN
F 1 "1v8" H 5400 2600 50  0000 C CNN
F 2 "" H 5400 2500 50  0001 C CNN
F 3 "" H 5400 2500 50  0001 C CNN
	1    5400 2500
	1    0    0    -1  
$EndComp
$Comp
L Strix:3v3 #PWR032
U 1 1 61484366
P 4300 2500
F 0 "#PWR032" H 4300 2610 50  0001 L CNN
F 1 "3v3" H 4300 2600 50  0000 C CNN
F 2 "" H 4300 2500 50  0001 C CNN
F 3 "" H 4300 2500 50  0001 C CNN
	1    4300 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2600 5400 2500
Wire Wire Line
	5300 2600 5400 2600
Wire Wire Line
	4300 2600 4300 2500
Wire Wire Line
	4400 2600 4300 2600
$Comp
L Strix:TXB0106 U4
U 1 1 6148328B
P 4850 3000
F 0 "U4" H 4850 3665 50  0000 C CNN
F 1 "TXB0106" H 4850 3574 50  0000 C CNN
F 2 "" H 4750 2550 50  0001 C CNN
F 3 "" H 4750 2550 50  0001 C CNN
	1    4850 3000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6100 3450 6200 3450
Wire Notes Line
	7500 2150 7500 4250
Wire Notes Line
	5950 2150 7500 2150
Wire Notes Line
	5950 4250 5950 2150
Text Notes 7450 4200 2    50   ~ 0
IMU
Wire Notes Line
	7500 4250 5950 4250
Wire Wire Line
	6200 3150 5300 3150
Wire Wire Line
	6200 3050 5300 3050
Wire Wire Line
	6200 2950 5300 2950
Wire Wire Line
	6200 2850 5300 2850
NoConn ~ 7200 3050
NoConn ~ 7200 3150
$Comp
L Strix:GND #PWR047
U 1 1 61661433
P 7350 3950
F 0 "#PWR047" H 7220 3990 50  0001 L CNN
F 1 "GND" H 7350 3850 50  0000 C CNN
F 2 "" H 7350 3950 50  0001 C CNN
F 3 "" H 7350 3950 50  0001 C CNN
	1    7350 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 3350 7350 3950
Wire Wire Line
	7200 3350 7350 3350
$Comp
L Strix:GND #PWR045
U 1 1 6165D13C
P 6700 3950
F 0 "#PWR045" H 6570 3990 50  0001 L CNN
F 1 "GND" H 6700 3850 50  0000 C CNN
F 2 "" H 6700 3950 50  0001 C CNN
F 3 "" H 6700 3950 50  0001 C CNN
	1    6700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 3850 6700 3950
$Comp
L Strix:3v3 #PWR046
U 1 1 6165AFC3
P 6800 2350
F 0 "#PWR046" H 6800 2460 50  0001 L CNN
F 1 "3v3" H 6800 2450 50  0000 C CNN
F 2 "" H 6800 2350 50  0001 C CNN
F 3 "" H 6800 2350 50  0001 C CNN
	1    6800 2350
	1    0    0    -1  
$EndComp
$Comp
L Strix:1v8 #PWR044
U 1 1 6165AD4B
P 6600 2350
F 0 "#PWR044" H 6600 2460 50  0001 L CNN
F 1 "1v8" H 6600 2450 50  0000 C CNN
F 2 "" H 6600 2350 50  0001 C CNN
F 3 "" H 6600 2350 50  0001 C CNN
	1    6600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 2450 6600 2350
Wire Wire Line
	6800 2450 6800 2350
$Comp
L Strix:ICM-20948 U6
U 1 1 61658692
P 6700 3150
F 0 "U6" H 6950 3900 50  0000 L CNN
F 1 "ICM-20948" H 6950 3800 50  0000 L CNN
F 2 "Strix:InvenSense_QFN-24_3x3mm_P0.4mm" H 6700 2150 50  0001 C CNN
F 3 "http://www.invensense.com/wp-content/uploads/2016/06/DS-000189-ICM-20948-v1.3.pdf" H 6700 3000 50  0001 C CNN
	1    6700 3150
	1    0    0    -1  
$EndComp
Text HLabel 4050 3250 0    50   Output ~ 0
IMU_INT
Text HLabel 4050 3150 0    50   Input ~ 0
IMU_~CS
Text HLabel 4050 2850 0    50   Output ~ 0
IMU_MISO
Text HLabel 4050 2950 0    50   Input ~ 0
IMU_MOSI
Text HLabel 4050 3050 0    50   Input ~ 0
IMU_SCLK
Wire Notes Line
	5850 5750 4150 5750
Wire Notes Line
	4150 4350 4150 5750
Wire Notes Line
	5850 4350 4150 4350
Wire Notes Line
	5850 4350 5850 5750
$Comp
L Strix:GND #PWR?
U 1 1 6135BB59
P 4500 4850
AR Path="/6135BB59" Ref="#PWR?"  Part="1" 
AR Path="/619FD90A/6135BB59" Ref="#PWR034"  Part="1" 
F 0 "#PWR034" H 4370 4890 50  0001 L CNN
F 1 "GND" V 4500 4700 50  0000 C CNN
F 2 "" H 4500 4850 50  0001 C CNN
F 3 "" H 4500 4850 50  0001 C CNN
	1    4500 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 4850 4500 4850
$Comp
L Strix:3v3 #PWR?
U 1 1 6135AF2B
P 5000 4550
AR Path="/6135AF2B" Ref="#PWR?"  Part="1" 
AR Path="/619FD90A/6135AF2B" Ref="#PWR038"  Part="1" 
F 0 "#PWR038" H 5000 4660 50  0001 L CNN
F 1 "3v3" H 5000 4650 50  0000 C CNN
F 2 "" H 5000 4550 50  0001 C CNN
F 3 "" H 5000 4550 50  0001 C CNN
	1    5000 4550
	1    0    0    -1  
$EndComp
$Comp
L Strix:GND #PWR?
U 1 1 6135AB9D
P 5000 5550
AR Path="/6135AB9D" Ref="#PWR?"  Part="1" 
AR Path="/619FD90A/6135AB9D" Ref="#PWR039"  Part="1" 
F 0 "#PWR039" H 4870 5590 50  0001 L CNN
F 1 "GND" H 5000 5450 50  0000 C CNN
F 2 "" H 5000 5550 50  0001 C CNN
F 3 "" H 5000 5550 50  0001 C CNN
	1    5000 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 5450 5000 5550
Wire Wire Line
	5000 4650 5000 4550
$Comp
L Strix:MS5611-01BA U5
U 1 1 61359771
P 5000 5050
F 0 "U5" H 5200 5500 50  0000 L CNN
F 1 "MS5611-01BA" H 5200 5400 50  0000 L CNN
F 2 "Strix:LGA-8_3x5mm_P1.25mm" H 5000 5050 50  0001 C CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=MS5611-01BA03&DocType=Data+Sheet&DocLang=English" H 5000 5050 50  0001 C CNN
	1    5000 5050
	1    0    0    -1  
$EndComp
Text Notes 5800 5700 2    50   ~ 0
Barometer
Wire Wire Line
	4050 5250 4600 5250
Wire Wire Line
	4050 4950 4600 4950
Wire Wire Line
	4050 5050 4600 5050
Wire Wire Line
	4050 5150 4600 5150
Text HLabel 4050 5250 0    50   Input ~ 0
BARO_~CS
Text HLabel 4050 4950 0    50   Output ~ 0
BARO_MISO
Text HLabel 4050 5050 0    50   Input ~ 0
BARO_MOSI
Text HLabel 4050 5150 0    50   Input ~ 0
BARO_SCLK
$Comp
L Strix:1v8 #PWR042
U 1 1 614A5CF9
P 5550 3400
AR Path="/614A5CF9" Ref="#PWR042"  Part="1" 
AR Path="/619FD90A/614A5CF9" Ref="#PWR042"  Part="1" 
F 0 "#PWR042" H 5550 3510 50  0001 L CNN
F 1 "1v8" V 5550 3550 50  0000 C CNN
F 2 "" H 5550 3400 50  0001 C CNN
F 3 "" H 5550 3400 50  0001 C CNN
	1    5550 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 3350 6100 3250
$Comp
L Strix:GND #PWR043
U 1 1 62249604
P 6100 3950
F 0 "#PWR043" H 5970 3990 50  0001 L CNN
F 1 "GND" H 6100 3850 50  0000 C CNN
F 2 "" H 6100 3950 50  0001 C CNN
F 3 "" H 6100 3950 50  0001 C CNN
	1    6100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3450 6100 3950
$EndSCHEMATC
