EESchema Schematic File Version 4
LIBS:WS2812B-Protect-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R1
U 1 1 5E2CD4A1
P 2100 3300
F 0 "R1" V 2175 3355 50  0000 C CNN
F 1 "270" V 2095 3305 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2030 3300 50  0001 C CNN
F 3 "https://www.reichelt.de/smd-widerstand-0805-270-ohm-125-mw-1-smd-0805-270-p32879.html?r=1" H 2100 3300 50  0001 C CNN
	1    2100 3300
	0    -1   -1   0   
$EndComp
$Comp
L Diode:1N4148 D1
U 1 1 5E2CD5CD
P 2300 3130
F 0 "D1" H 2300 3040 50  0000 L CNN
F 1 "1N4148" H 2180 3225 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323F" H 2300 2955 50  0001 C CNN
F 3 "https://www.reichelt.de/schalt-diode-75-v-150-ma-sod-323f-1n-4148-ws-p95197.html?r=1" H 2300 3130 50  0001 C CNN
	1    2300 3130
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148 D2
U 1 1 5E2CD6B1
P 2300 3470
F 0 "D2" H 2300 3385 50  0000 L CNN
F 1 "1N4148" H 2175 3565 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323F" H 2300 3295 50  0001 C CNN
F 3 "https://www.reichelt.de/schalt-diode-75-v-150-ma-sod-323f-1n-4148-ws-p95197.html?r=1" H 2300 3470 50  0001 C CNN
	1    2300 3470
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4148 D3
U 1 1 5E2CD786
P 2720 3470
F 0 "D3" H 2720 3390 50  0000 L CNN
F 1 "P6KE" H 2590 3565 50  0000 L CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 2720 3295 50  0001 C CNN
F 3 "https://www.reichelt.de/tvs-diode-bidirectional-6-v-600-w-do-214aa-smb-p6smb-6-0ca-smd-p204336.html?PROVID=2788&gclid=EAIaIQobChMIl83wmfKf5wIVGs93Ch3jmgCnEAYYASABEgIPI_D_BwE&&r=1" H 2720 3470 50  0001 C CNN
	1    2720 3470
	0    1    1    0   
$EndComp
Wire Wire Line
	1890 3300 1950 3300
Wire Wire Line
	2250 3300 2300 3300
Wire Wire Line
	2300 3280 2300 3300
Connection ~ 2300 3300
Wire Wire Line
	2300 3300 2300 3320
Wire Wire Line
	1890 2980 2300 2980
Connection ~ 2300 2980
Wire Wire Line
	1890 3620 2300 3620
Wire Wire Line
	2300 3620 2720 3620
Connection ~ 2300 3620
Wire Wire Line
	2720 3620 2940 3620
Connection ~ 2720 3620
Wire Wire Line
	2300 3300 2940 3300
Wire Wire Line
	2300 2980 2720 2980
Wire Wire Line
	2720 3320 2720 2980
Connection ~ 2720 2980
Wire Wire Line
	2720 2980 2940 2980
Wire Wire Line
	2940 2980 2940 3200
Wire Wire Line
	2940 3620 2940 3400
Wire Wire Line
	1890 2980 1890 3200
Wire Wire Line
	1890 3400 1890 3620
$Comp
L Homebrew:LED-Stripe(Eingang) J1
U 1 1 5E2DBD2F
P 1640 3300
F 0 "J1" H 1580 3540 50  0000 C CNN
F 1 "LED-Stripe(Eingang)" H 1465 3055 50  0000 C CNN
F 2 "Homebrew:PinHeader_1x03_P2.54mm_Horizontal" H 1640 3300 50  0001 C CNN
F 3 "" H 1640 3300 50  0001 C CNN
	1    1640 3300
	1    0    0    -1  
$EndComp
$Comp
L Homebrew:LED-Stripe J2
U 1 1 5E2DC525
P 3240 3300
F 0 "J2" H 3065 3500 50  0000 L CNN
F 1 "LED-Stripe" H 3050 3090 50  0000 L CNN
F 2 "Homebrew:LED-Stripe" H 3240 3400 50  0001 C CNN
F 3 "" H 3240 3400 50  0001 C CNN
	1    3240 3300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
