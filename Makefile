OBJS = BigNumConstructors.o BigNumFunctions.o BigNumOperations.o test.o

BigNum:	$(OBJS)
	g++ -o BigNum $(OBJS)

BigNumConstructors.o: BigNumConstructors.cpp BigNum.h
	g++ -c BigNumConstructors.cpp

BigNumFunctions.o: BigNumFunctions.cpp BigNum.h
	g++ -c BigNumFunctions.cpp

BigNumOperations.o:	BigNumOperations.cpp BigNum.h
	g++ -c BigNumOperations.cpp

test.o:	test.cpp BigNum.h
	g++ -c test.cpp

.PHONY:	clean

clean:
	rm $(OBJS) BigNum
