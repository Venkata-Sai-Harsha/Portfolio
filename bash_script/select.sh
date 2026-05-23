#!/usr/bin/bash

select i in sai harsha
do
    case $i in 
        sai)
            echo sai is selected
            ;;
        harsha)
            echo "harsha is selected"
            ;;
        *)
            echo "invalid option"
            ;;
    esac
done