#!/bin/bash
echo "bash name: $0"
echo "param one: $1"
echo "count: $#"
echo "status: "

file="nihaonihao"

echo 'nihao '$file''
echo "haoma, $file"
echo ${#file}

testing=`date`
echo "the date and time are: $testing"

var1=10
var2=20
var3=`expr ${var2} / ${var1}`
echo "The resultis $var3"


test 5 -gt 2 && echo "Yes"
test 5 -eq 5 && echo "Yes"