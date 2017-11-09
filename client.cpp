/*
  ZeroMQ message client application in C++
  Connects REQ socket to tcp://localhost:5555 socket server in python
  Sends "Hola Servidor Python" to server, expects "World" back
  Source:
  This script client program is based in zeromq c+ client sample
  https://github.com/booksbyus/zguide/blob/master/examples/C%2B%2B/hwclient.cpp
  http://zguide.zeromq.org/page:all

*/

#include <zmq.hpp>
#include <string>
#include <iostream>
//#include <time.h>
//#include "math.h"

/*
 * time_t tv_sec
 * The number of seconds since 1970.

 * time_t tv_nsec
 * The number of nanoseconds expired in the current second.
 * This value increases by some multiple of nanoseconds,
 * based on the system clock's resolution.
 * https://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/
 * */


#define TIME_THIS(X)                                         \
  {                                                          \
    /*Creamos dos variables de tipo estructura timespec
 *  http://en.cppreference.com/w/cpp/chrono/c/timespec
 *  Usamos ademas la funcion clock_gettime https://linux.die.net/man/3/clock_gettime
 *
 *  */                                                        \
    struct timespec ts1, ts2;                                \
    clock_gettime( CLOCK_REALTIME, &ts1 );                   \
    X;                                                       \
    clock_gettime( CLOCK_REALTIME, &ts2 );\
    printf(" El mensaje de regreso del servidor Python se demora: %f\n",                               \
      (float) ( 1.0*(1.0*ts2.tv_nsec - ts1.tv_nsec*1.0)*1e-9 \
      + 1.0*ts2.tv_sec - 1.0*ts1.tv_sec ) );                 \
  }


int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Conectando al servidor python zeroMQ …" << std::endl;
    socket.connect ("tcp://localhost:5555");

    zmq::message_t request (20);
    memcpy (request.data (), "Hola Servidor Python", 20);
    //std::cout << "Sending " << request.data() << "…" << std::endl;
    socket.send (request);

    //  Get the reply.
    zmq::message_t reply;
    //socket.recv (&reply);
    //std::string replyMessage = std::string(static_cast<char *>(reply.data()), reply.size());

    TIME_THIS(socket.recv (&reply));

    // payload of the response from the server
    //std::cout << reply.data() << std::endl;

    std::string replyMessage = std::string(static_cast<char *>(reply.data()), reply.size());
    std::cout << "Mensaje recibido desde el servidor: " << replyMessage << std::endl;

}

