#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "array_list.h"
#include "naive_solution.h"

#define PACKET_SIZE 2       // The size of the packet header describing the size of the rest from Erlang

typedef unsigned char byte;


// Reads message into buffer, returns the number of bytes read
static int read_to_buf(byte* buf, int len)
{
    int i, got=0;

    do {
        if ((i = read(0, buf+got, len-got)) <= 0){
            return(i);
        }
        got += i;
    } while (got<len);

    return(len);
}

// Reads an int from a packge from the socket
static int read_int(byte* buf)
{
    if (read_to_buf(buf, PACKET_SIZE) != PACKET_SIZE)
    {
        printf("Error when reading message!\n");
        exit(-1);
    }
    else
    {
        int packet_len = (buf[0] << 8) | buf[1];
        int int_len = read_to_buf(buf, packet_len);
        int sum = 0;

        for (int i = 0; i < int_len; i++)
        {
            sum = (sum << 8) + buf[i];
        }

        return sum;
    }
}

static array_list read_list(byte* buf)
{
    int read;
    array_list list;
    array_list_init(&list);

    while ((read = read_int(buf)) > 0)
    {
        if (list.length == list.alloced) {
            list.alloced *= 2;
            list.array = realloc(list.array, list.alloced * sizeof(int));
        }
        list.array[list.length] = read;
        list.length += 1;
    }

    return list;
}


static int write_int(int msg, int len)
{
    int i, wrote = 0;

    do {
        if ((i = write(1, &msg+wrote, len-wrote)) <= 0)
        return (i);
        wrote += i;
    } while (wrote<len);

    return (len);
}


static void send_msg(int msg, int len)
{

    // Write the package header of two bytes with the message length
    byte left_header = (len >> 8) & 0xff;
    write_int(left_header, 1);
    byte right_header = len & 0xff;
    write_int(right_header, 1);

    write_int(msg, len);
}


int main()
{
    byte buf[10];
    int sum, result[3];
    array_list list;

    sum = read_int(buf);
    list = read_list(buf);
    naive_find_result(&list, sum, result);

    for (int i = 0; i < 3; i++)
    {
        send_msg(result[i], 2);
    }
}
