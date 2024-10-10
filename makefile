all: stk

fg = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

stk: a.exe
	a.exe

a.exe: main.o CDtor.o PushPop.o DumpErr.o
	g++ main.o CDtor.o PushPop.o DumpErr.o

main.o: main.cpp
	g++ -c $(fg) main.cpp

CDtor.o: CDtor.cpp
	g++ -c $(fg) CDtor.cpp

PushPop.o: PushPop.cpp
	g++ -c $(fg) PushPop.cpp

DumpErr.o: DumpErr.cpp
	g++ -c $(fg) DumpErr.cpp

clean:
	rm -rf *.o *.exe
