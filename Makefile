a5:	Escape.o Hero.o MoveBehaviour.o Ninja.o Snorc.o main.o random.o Participant.o
	g++ -o a5 Escape.o Hero.o MoveBehaviour.o Ninja.o Snorc.o main.o random.o Participant.o
Escape.o: Escape.cc 
	g++ -c Escape.cc
Hero.o:	Hero.cc 
	g++ -c Hero.cc

MoveBehaviour.o: MoveBehaviour.cc
	g++ -c MoveBehaviour.cc
Ninja.o: Ninja.cc
	g++ -c Ninja.cc
Snorc.o: Snorc.cc
	g++ -c Snorc.cc
main.o:	main.cc 
	g++ -c main.cc
random.o: random.cc
	g++ -c random.cc
Participant.o: Participant.cc
	g++ -c Participant.cc
clean:
	rm -f *.o a5
