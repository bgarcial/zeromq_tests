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


#Patrones básicos de zeromq

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
 