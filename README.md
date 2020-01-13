# Control de acceso al garaje por identificación wifi de dispositivos

## El problema
Todos conocemos los mandos de radiofrecuencia o 'pastillas' utilizados para la apertura y cierre de puertas de garage. Comúnmente estos dispositivos se comunican una señal de radiofrecuencia en las bandas 433 ó 868 MHz. El emisor codifica una señal compuesta por una trama que no siempre le identifica y que tampoco codifica. Por lo que son fácilmente hackeables.

## Una solución 100% Maker que me permite abrir la puerta con el móvil
## El modo promiscuo 
En el modo promiscuo un dispositivo conectado a una red compartida, captura todo el tráfico que circula por ella. Esta es la manera en la que los sniffers trabajan capturando todos los paquetes de datos que circulan por la red aunque no sea el destinatario y entregando información que sólo se utiliza para la identificación de los paquetes como la dirección MAC (mac-address).



Desarrollar este concepto en el ecosistema Arduino es fácil porque desde hace años existe mucho firmware y librerias orientados a extender y desbloquear el uso de la comunicación wifi. En mi caso he utilizado como receptor un WEMOS D1 Mini que también he configurado como emisor a parte de 
