#!/bin/bash
for i in `seq 1 8`; do
    for j in `seq 1 10`; do
	./count_matrix $i 
    done
done
