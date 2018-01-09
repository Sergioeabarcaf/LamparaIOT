# NodeMCUIot

En este repositorio se guardan pequeños programas que permiten realizar funciones especificas en **NodeMCU** para luego utilizarlas en un proyecto correspondiente.

## Instalación de librerías necesarias en IDE Arduino.

1. Descargar e instalar IDE Arduino [Pagina Oficial](https://www.arduino.cc/en/Main/Software "Pagina Oficial")
2. Abrir IDE Arduino
3. Ir a **ARCHIVO** - **Preferencias**, Busca *Gestor de URLs Adicionales de Tarjetas* y en el cuadro de texto junto a esto pega lo siguiente: http://arduino.esp8266.com/stable/package_esp8266com_index.json
4. Ir a **HERRAMIENTAS** - **Placa** - **Gestor de Tarjetas**, se abrirá una ventana con un buscador. Ingresa en el buscador **ESP
 ** e instala la ultima version del paquete.
 5. Configurar en IDE Arduino que se usa la placa NODEMCU, para esto se debe ir a **HERRAMIENTAS** - **PLACA** y seleccionar *la tarjeta que se uste usando*.
 6. Configurar los parametros necesarios de la tarjeta como *CPU Frecuency*, *Flash Size*, ETC.
 7. Seleccionar el puerto **COM** donde esta conectada la NODEMCU.
 
 La librería instalada sirve para otras placa tambíen.    
 
 ## Programas desarrolldos:
 
 1. Alimentacan: Se conecta en modo *Station* y levanta un *Servidor* para controlar un *Servo Motor* con el fin de realizar un dispensado de comida para mascotas de manera remota.  
 2. Lampara: Codigo *En Desarrollo*
