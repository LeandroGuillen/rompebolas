robot: main.cpp estadojuego.o motor.o automata.o
	g++ -o robot main.cpp estadojuego.o motor.o automata.o -g
	
.cpp:
	g++ $(CFLAGS) -c $<

clean:
	@rm *o
