#! /bin/sh

sudo ifconfig en1 down

sync
sleep 2

sudo ifconfig en1 up
