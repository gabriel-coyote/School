#!/bin/bash

temph=`date | cut -c12-13`
dat=`date +"%A %d in %B of %Y (%r)"`

if [ $temph -lt 12 ]
then
    msg="Good Morning $LOGNAME, Have nice day!"
fi

if [ $temph -ge 12 -a $temph -le 16 ]
then
    msg="Good Afternoon $LOGNAME"
fi

if [ $temph -gt 16 -a $temph -le 20 ]
then
    msg="Good Evening $LOGNAME"
fi

# Not Morning, Afternoon, or Evening message
if [ $temph -gt 20 ]
then
    msg="Hello $LOGNAME"
fi

# If greetingmsg exist then delete it and then output 
if [ -f greetingmsg ]
then
    rm greetingmsg
    echo -e "$msg\nThis is $dat" > greetingmsg
else
    echo -e "$msg\nThis is $dat" > greetingmsg
fi

#echo $temph
#echo $dat
#echo -e "$msg\nThis is $dat"
