# HB-OU-RGB-STACKFIRE - Kaminfeuer Leuchte

- 
- 

## Bilder

![pic](Images/*.jpg)

![pic](Images/*.jpg)

![pic](Images/*.jpg)


## Konfiguration




## Schaltplan

![pic](Images/PCB_HB-OU-RGB-STACKFIRE/Schaltplan_HB-OU-RGB-STACKFIRE-V2.png)

[:arrow_right: Schaltplan](Images/PCB_HB-OU-RGB-STACKFIRE/Schaltplan_HB-OU-RGB-STACKFIRE-V2.pdf)


## Platine

[:arrow_right: PCB Gerber](Platine/HB-OU-RGB-STACKFIRE(Mega2560)-V2/HB-OU-RGB-STACKFIRE-V2.zip)

![pic](Images/PCB_HB-OU-RGB-STACKFIRE/HB-OU-RGB-STACKFIRE_Front_klein.png)

![pic](Images/PCB_HB-OU-RGB-STACKFIRE/HB-OU-RGB-STACKFIRE_Back_klein.png)


## Aufbau / Stückliste
| Bauteil | Link |
| --------|------|
|50cm Alurohr Länge: 0,5-3 m Aluminium Rohr Alu Profil Rundrohr AlMgSi0,5 Modellbau | [:arrow_right: Ebay](https://www.ebay.de/itm/Alurohr-L%C3%A4nge-0-5-3-m-Aluminium-Rohr-Alu-Profil-Rundrohr-AlMgSi0-5-Modellbau/222169076786?ssPageName=STRK%3AMEBIDX%3AIT&var=521010583605&_trksid=p2057872.m2749.l2649) |
|55cm  PLEXIGLAS® XT Rohr 3mm weiß 200/194mm Durchmesser | [:arrow_right: Ebay](https://www.ebay.de/itm/PLEXIGLAS-XT-Rohr-3mm-wei%C3%9F-200-194mm-Durchmesser-74-00-lfdm/112415674967?ssPageName=STRK%3AMEBIDX%3AIT&var=412812679722&_trksid=p2057872.m2749.l2649) |
|PLEXIGLAS® Deckel 4 mm weiß Ø freiwählbar passend für unsere PLEXIGLAS® XT Rohr | [:arrow_right: Ebay](https://www.ebay.de/itm/PLEXIGLAS-Deckel-4-mm-wei%C3%9F-%C3%98-freiw%C3%A4hlbar-passend-f%C3%BCr-unsere-PLEXIGLAS-XT-Rohre/122355660437?ssPageName=STRK%3AMEBIDX%3AIT&var=422838977364&_trksid=p2057872.m2749.l2649)|
|WS2812B-Protect | [:arrow_right: Reichelt Bestell-Liste](https://www.reichelt.de/my/1667564) |
|Limeow Thermisch Klebeband Wärmeleitendes Doppelseitiges Klebeband Selbstklebend Tape Wärmeleitpaste Thermal Compound Thermische Verbindung Paste Kühlkörper Leitfähiges Kühlband Doppelseitig Klebend | [:arrow_right: Amazon](https://www.amazon.de/gp/product/B07FPKVML7/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1) |
|AZDelivery 5 x 220V zu 5V Mini-Netzteil für Arduino und Raspberry Pi | [:arrow_right: Amazon](https://www.amazon.de/gp/product/B07V7GHK51/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1) |


## Hinweise

- :exclamation: Viele Projekte verweisen auf Probleme mit dem WS2812B. Die Schutzschaltung WS2812B-Protect ist eine kleine 17x10mm Platine, welche die Stripes schützen soll. Sie ist je nach eigenem Ermessen einbaubar. 


## CCU2/CCU3/RaspberryMatic Installation

Einstellungen/Systemsteuerung/Zusatzsoftware -> Datei 

Ich nutze das AddOn von Jérôme (jp112sdl) [JP-HB-Devices-addon](https://github.com/jp112sdl/JP-HB-Devices-addon).
In dieses bzw. dessen Struckture müssen die Dateien aus dem Verzeichniss [AddOn](AddOn) entsprechend selbst eingebunden werden und das AddOn dann installiert werden.


## Benötige Libraries

[AskSinPP Library](https://github.com/pa-pa/AskSinPP)
 - sowie die dort aufgeführten [zusätzlichen Bibliotheken](https://github.com/pa-pa/AskSinPP#required-additional-arduino-libraries)
[EnableInterrupt](https://github.com/GreyGnome/EnableInterrupt)</br>
[Low-Power](https://github.com/rocketscream/Low-Power)</br>
[FastLED](https://github.com/FastLED/FastLED)


## Lizenz

**Creative Commons BY-NC-SA**<br>
Give Credit, NonCommercial, ShareAlike

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
