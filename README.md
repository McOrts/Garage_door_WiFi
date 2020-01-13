# Control de acceso al garaje por identificación wifi de dispositivos

## El problema
Todos conocemos los mandos de radiofrecuencia o 'pastillas' utilizados para la apertura y cierre de puertas de garage. Comúnmente estos dispositivos se comunican una señal de radiofrecuencia en las bandas 433 ó 868 MHz. El emisor codifica una señal compuesta por una trama que no siempre le identifica y que tampoco codifica. Por lo que son fácilmente hackeables.

## Una solución 100% Maker que me permite abrir la puerta con el móvil
## El modo promiscuo 
En el modo promiscuo un dispositivo conectado a una red compartida, captura todo el tráfico que circula por ella. Esta es la manera en la que los *sniffers* trabajan. Capturan todos los paquetes de datos que circulan por la red aunque no sea el destinatario y o sea información que sólo se utiliza para la identificación de los paquetes como la dirección MAC (mac-address).
<img src="https://github.com/McOrts/Garage_door_WiFi/blob/master/images/Garage_door_Wifi_control_diagram.JPG" width="400" align="left" />
La solución ha sido registrar una tabla de direcciones MAC de los dispositivos que utilizo en un microcontrolador conectado a un relé. Este receptor está permanentemente rastreando clientes wifi. Cuando una dirección de dispositivo existe en la tabla, activa el relé que abre la puerta del garaje. 
```
uint8_t friendmac[LIST_SIZE][ESPPL_MAC_LEN] = {
   {0x3C, 0x71, 0xBF, 0x39, 0xAB, 0x4C}
  ,{0x84, 0x0D, 0x8E, 0x83, 0xF2, 0x16}
  };
```
Curiosamente, la wifi de la cámara *dash-board* del coche es la que mejor se identifica. De manera que cuando arrancas el coche, la puerta de garaje se abre y cuando te aproximas desde la calle. Y desde una distancia suficiente como para no ser necesario parar. Así he ganado en comodidad y tiempo mis entradas y salidas a casa. 

## *How to*
Desarrollar este concepto en el ecosistema Arduino es fácil porque desde hace años existen firmware y librerías orientadas a extender y desbloquear el uso de la comunicación wifi. Si elejimos trabajar con procesadores ESP8266 tenemos la libreria [ESPProLib de Ricardo Oliveira](https://github.com/RicardoOliveira/ESPProLib) que incluye las funciones necesarias.

De todos los tipos de microprocesadores basados en ESP8266 he utilizado un WEMOS D1 Mini tanto como receptor y emisor a modo de mando a distancia. 

## Cosas que necesitarás para este proyecto
**Hardware**

- [WEMOS D1 Mini Pro 16M Bytes External Antenna](https://s.click.aliexpress.com/e/kMC1v8nW) ×	1	 
<img src="https://github.com/McOrts/Water_flow_sensor_MQTT/blob/master/Pictures/WemosD1MiniPro.PNG" width="250" align="right" />
- [G1/2 Inch Water Flow Hall Sensor Switch Flow Meter](http://es.aliexpress.com/item/33043594353.html) ×	1	
<img src="https://github.com/McOrts/Garage_door_WiFi/blob/master/images/WEMOSD1mIni_Relay_Shield.jpg?raw=true" width="250" align="right" />

**Software**
- [Arduino IDE](https://www.hackster.io/arduino/products/arduino-ide?ref=project-8e87cc)

**Esquemático**
<img src="https://github.com/McOrts/Garage_door_WiFi/blob/master/images/Garage_door_Wifi_control_bb.png" width="300"  align="center" />

## Resultado final
### Receptor
<img src="https://github.com/McOrts/Garage_door_WiFi/blob/master/images/IMG_6877.JPG" align="center" />
### Mando a distancia
<img src="https://github.com/McOrts/Garage_door_WiFi/blob/master/images/IMG_7845.JPG" align="center" />

