#! /bin/bash

echo "How many years old are you?"
read AGE
echo -n "You are "
days=`expr 365 * $AGE`
echo -n " years old."
