if [ ! -e ../test_engine ]
	then cd ..
	make test_engine > /dev/null
	cd ./test
fi
cat q1.result | ../test_engine q1.correct > case_result
cat q2.result | ../test_engine q2.correct >> case_result
cat q3.result | ../test_engine q3.correct >> case_result
cat q4.result | ../test_engine q4.correct >> case_result
cat q5.result | ../test_engine q5.correct >> case_result