# Prueba de interoperabilidad entre un proceso C++ y Python

**zeroMQ**

[zeromq](http://zguide.zeromq.org/page:all) actúa como un framework de mensajería asíncrona
para aplicaciones concurrentes y distribuidas. Trabaja con encolamiento de mensajes.

Normalmente, la comunicación entre aplicaciones necesitan de una entidad intermediaria que
traduce un mensaje desde un protocolo formal de mensajería que maneje el emisor a otro
que maneje el receptor. Es así como se maneja la comunicación para intercambi formal de 
mensajes definidos

>Un sistema mq puede correr sin la necesidad de esa entidad intermediaria o broker message
dedicado

**zeromq** provee sockets, cada uno de los cuales representa una conexión muchos a muchos 
entre endpoints.


# Patrones básicos de zeromq

zeromq trabaja con los siguientes [patrones de mensajería](http://zguide.zeromq.org/page:all#Messaging-Patterns)


+ **Request - Reply**
 
 Conecta un conjunto de clientes a un conjunto de servicios.
 
 + **Publish - Subscribe**
 
 Conecta un conjunto de publishers a un conjunto de suscriptores
 
 + **Push - Pull** (Pipeline)
 
 Conecta nodos en un patrón de fan-out/fan-in  que puede tener muchos pasos y ciclos.
 
 + **Exclusive pair**
 
 Conecta dos sockets en un par exclusivo
 
 
 
 
 En zeromq, cada patrón define una particular topología de red. Los mensajes pueden ser llevados a través
 de TCP, Multicast, IPC, soportando muchos lenguajes y plataformas y permitiendo trabajar cualquier arquitectura
 (centralizada, distribuida, pequeña, grande)
 
 Esta ideado para tratar problemas de escalabilidad permitiendo múltiples conexiones entre sockets con los
 patrones de mensajería previamente mencionados
 
 
 # Instalando el cliente c++
 
 + **Descargar los paquetes necesarios** (Ubuntu)
 
 `sudo apt-get install libtool pkg-config build-essential autoconf automake`
 
 + **Instalar la librería `libsodium`** 
 
 ```
 wget https://download.libsodium.org/libsodium/releases/LATEST.tar.gz
 
 tar -zxvf LATEST.tar.gz
 
 cd libsodium-stable
 
 sudo ./configure
 
 sudo make
 
 sudo make install
 
 sudo ldconfig
  ```
  
 + **Instalando el paquete zeroMQ**
 
 ```
 wget https://github.com/zeromq/libzmq/releases/download/v4.2.2/zeromq-4.2.2.tar.gz
 tar -zxvf zeromq-4.2.2.tar.gz 
 cd zeromq-4.2.2/
 sudo ./configure
 sudo make
 sudo make install
 sudo ldconfig 
 ```
 
 + **Usando zeroMQ binding para C++**
 
  ```
  cd /usr/include/
  
  sudo wget https://raw.githubusercontent.com/zeromq/cppzmq/master/zmq.hpp
  ```
  
  De esta manera, uatilizamos `#include <zmq.hpp>` como headers en el cliente C++
  
  
  + **Verificando la instalación correcta de ambos paquetes**
  
   ```
   cd /usr/local/lib
   
   
   ls
   ```
   
   Debemos mirar `libsodium.so` y `libzmq.so` en este directorio.
   
   
   
Adicionalmente se debe tener instalado los siguientes paquetes

* gcc
* Cmake
* Pyzmq --- Para el servidor python ---  `pip install pyzmq`


# Ejecutando scripts Cliente y Servidor

+ Ejecutando el servidor python

```
cd zeroMQ_Server
 
python server.py
```

+ Ejecutando el cliente C++

Es necesario compilarlo primero y despues ejecutar el archivo binario

```
g++ client_get-time-of-day.cpp -o client_get-time-of-day.out -lzmq


./client_get-time-of-day.out
```

Tambien existe un cliente python llamado `client.py`   y un servidor c++ llamado `server.cpp`

Su ejecución es de la misma manera.

   
      
  