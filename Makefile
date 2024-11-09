# Project: 537 Clock
# Makefile created by Dev-C++ 5.11, edited by Sean537 in 537 Studio

MODE=RELEASE

ifeq ($(MODE), DEBUG)
CPP      = g++.exe -DDEBUG
CC       = gcc.exe -DDEBUG
LIBS     = -static-libgcc -L"./lib" -lgraphics -lgdiplus -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm -g3
CXXFLAGS = $(CXXINCS) -std=c++11 -g3 -DDEBUG
CFLAGS   = $(INCS) -std=c++11 -g3
else
CPP      = g++.exe
CC       = gcc.exe
LIBS     = -static-libgcc -L"./lib" -lgraphics -lgdiplus -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm
CXXFLAGS = $(CXXINCS) -std=c++11
CFLAGS   = $(INCS) -std=c++11
endif

WINDRES  = windres.exe
RES      = 537Clock_AppInfo.res
OBJ      = 537main.o language.o tclass.o about.o console.o $(RES)
LINKOBJ  = 537main.o language.o tclass.o about.o console.o $(RES)
INCS     = -I"./include"
CXXINCS  = -I"./include"
BIN      = 537Clock.exe
RM       = del	# rm -f 无法正常使用，返回值2

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after
	${BIN}

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

537main.o: 537main.cpp
	$(CPP) -c 537main.cpp -o 537main.o $(CXXFLAGS)

language.o: language.cpp
	$(CPP) -c language.cpp -o language.o $(CXXFLAGS)

tclass.o: tclass.cpp
	$(CPP) -c tclass.cpp -o tclass.o $(CXXFLAGS)

about.o: about.cpp
	$(CPP) -c about.cpp -o about.o $(CXXFLAGS)

console.o: console.cpp
	$(CPP) -c console.cpp -o console.o $(CXXFLAGS)

537Clock_AppInfo.res: 537Clock_AppInfo.rc 
	$(WINDRES) -i 537Clock_AppInfo.rc --input-format=rc -o 537Clock_AppInfo.res -O coff 

