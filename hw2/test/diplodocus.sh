cd ..
if [ -e ./*.o ]
	then make clean
fi
make > /dev/null
./q1 < ./test/tq1 > ./test/q1.result
./q2 < ./test/tq2 > ./test/q2.result
./q3 < ./test/tq3 > ./test/q3.result
./q4 < ./test/tq4 > ./test/q4.result
./q5 < ./test/tq5 > ./test/q5.result
make clean > /dev/null
