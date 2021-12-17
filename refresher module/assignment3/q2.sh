#!/bin/bash

if [ $1 == "add" ]
then
  shift 
  sum=$1
  shift
  for i do
    sum=$(($sum + $i))
  done
  echo $sum
elif [ $1 == "sub" ]
then
  shift 
  res=$1
  shift
  for i do
    res=$(($res - $i))
  done
  echo $res
elif [ $1 == "mul" ]
then
  shift 
  res=$1
  shift
  for i do
    res=$(($res * $i))
  done
  echo $res
elif [ $1 == "div" ]
then
  shift 
  res=$1
  shift
  for i do
    res=$(($res / $i))
  done
  echo $res
elif [ $1 == "exp" ]
then
  shift 
  res=$1
  shift
  for i do
    res=$(($res ** $i))
  done
  echo $res
fi