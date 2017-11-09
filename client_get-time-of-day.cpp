/*
  Hello World client in C++
  Connects REQ socket to tcp://localhost:5555
  Sends "Hello" to server, expects "World" back
  Source:
  https://github.com/booksbyus/zguide/blob/master/examples/C%2B%2B/hwclient.cpp
  http://zguide.zeromq.org/page:all

*/

#include <zmq.hpp>
#include <string>
#include <iostream>
#include <time.h>
#include <sys/time.h>


/* retorna "a - b" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b)
{
    return
            (double)(a->tv_sec + (double)a->tv_usec/1000000) -
            (double)(b->tv_sec + (double)b->tv_usec/1000000);
}


int main ()
{
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
    struct timeval t_ini, t_fin;
    double secs;

    gettimeofday(&t_ini, NULL);



    // Llamamos el proceso al cual le queremos medir el tiempo
    std::cout << "Conectando al servidor python zeroMQ…" << std::endl;
    socket.connect ("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response

    zmq::message_t request (20);
    memcpy (request.data (), "Hola Servidor Python", 20);
    //std::cout << "Sending " << request.data() << "…" << std::endl;
    socket.send (request);

    //  Get the reply.
    //zmq::message_t reply;
    //socket.recv (&reply);
    // std::cout << 'Mostrando reply' << &reply << std::endl;
    // std::cout << 'Mostrando reply was delivered' << std::endl;
    // std::cout << "Received from server " << request_nbr << std::endl; reply;

    zmq::message_t reply;
    socket.recv (&reply);
    std::string replyMessage = std::string(static_cast<char *>(reply.data()), reply.size());



    std::cout << "Recibiendo respuesta desde el servidor: " + replyMessage << " "  << std::endl;

    gettimeofday(&t_fin, NULL);

    secs = timeval_diff(&t_fin, &t_ini);
    printf("mensaje en RTT tomó  %.16g milliseconds\n", secs * 1000.0);
    return 0;
}