#!/bin/bash

src=${1:-app.cpp}
out=${src%.cpp}.out

function try()
{
    [[ $- = *e* ]]; SAVED_OPT_E=$?
    set +e
}

function compile {
    try
    (
        printf "\ncompiling 'g++ %s -o %s -std=c++11 -stdlib=libc++'\n\n" $src $out

        [ -f $out ] && rm $out
        g++ -o $out $src -ggdb -std=c++11 -stdlib=libc++

        [ -f $out ] || {            ## validate new exe created
            printf "error: compilation failed. exiting script.\n\n"
            printf "usage:   %s source.cpp (default: app.cpp)\n\n"
            exit 1
        }

         ## validate it is executable
        [ -x $out ] || {
            printf "error: file produced from compilation is not executable.\n"
            exit 1
        }

        ## store disk usage (removing name)
        size=$(du -h $out | awk '{print $1}')

        ## print results
        # printf "\n Source file:  %s\n" "$src"
        # printf " output file:  %s\n" "$out"
        # printf " size of app:  %s bytes\n\n" "$size"

        ## compute execution time
        time ./$out 2>&1
    )
}

compile

# NOTE: 
#   The 'fswatch' watcher is for MacOS only!
#   The 'inotifywait' is possible to implement for Linux.
fswatch $src | (
    while read x; do
        compile
    done
)
