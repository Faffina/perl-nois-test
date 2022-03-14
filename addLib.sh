if test -f include/$1.h; then
    echo "file exist"
else
    echo "#pragma once" > include/$1.h
	echo "#include \"$1.h\"" > source/$1.cpp
fi