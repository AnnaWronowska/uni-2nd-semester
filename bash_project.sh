#!/bin/bash

function help() {
	echo "Script for guessing strings."
	echo ""
	echo "Usage:"
	echo "  $0 [-s strategy] [-t text to guess] [-c letter case]"
	echo ""
	echo "Options:"
	echo "  -h		Shows this help."
	echo "  -s strategy	Strategy of guessing: 'random' or 'incremental'."
	echo "  -t text	Text that this program should guess."
	echo "  -c case	Lowercase - 'lower', uppercase and lowercase - 'upper'."
	echo ""
	echo "Examples:"
	echo "  $0 -s incremental -t guessinG -c upper"
	echo "  $0 -s random -t string -c lower"
	echo ""
	echo "This program works for English alphabet only"
	exit 0
}


while getopts s:t:c:h flag
do
    case "${flag}" in
        s) strategy=${OPTARG};;
        t) text=${OPTARG};;
	c) case=${OPTARG};;
        h) help ;;
    esac
done

if [ "$case" == "lower" ] ; then
	chars="abcdefghijklmnoprstuwxyz"
	if [[ "$text" =~ [^a-z]+ ]] ; then
		echo "ERROR: text contains invalid characters"
		exit 1
	fi
elif [ "$case" == "upper" ] ; then
	chars="abcdefghijklmnoprstuwxyzABCDEFGHIJKLMNOPRSTUWXYZ"
	if [[ "$text" =~ [^a-zA-Z]+ ]] ; then
		echo "ERROR: text contains invalid characters"
		exit 1
	fi
else
	exit 1
fi

random_string=$(cat /dev/urandom | tr -dc "$chars" | head -c "${#text}")

if [ "$strategy" == "random" ] ; then
	while : ; do
		if [ "$random_string" == "$text" ] ; then
			echo "$random_string is equal to $text!"
			exit 0
		else
			random_string=$(cat /dev/urandom | tr -dc "$chars" | head -c "${#text}")
		fi
	done
elif [ "$strategy" == "incremental" ] ; then
	while : ; do
		new_string=""
		for((i=0;i<${#random_string};i++)); do
			if [ ${random_string:$i:1} == ${text:$i:1} ] ; then
				new_string+="${random_string:$i:1}"
			else
				new_string+=$(cat /dev/urandom | tr -dc "$chars" | head -c 1)
			fi
		done
		random_string="${new_string}"
		if [ "$random_string" == "$text" ] ; then
			echo "$random_string is equal to $text!"
			exit 0
		fi
	done
else
	exit 1
fi