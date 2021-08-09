#! /bin/bash

select name in mark john
do
	case $name in
		mark )
		echo mark selected ;;
		john )
		echo john selected ;;
		* )
		echo error ;;
	esac
done