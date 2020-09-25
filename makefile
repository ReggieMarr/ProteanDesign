
all: joinedModules

joinedModules: boatModuleIF.o boatModuleDefs.h
	gcc cnc.o beneteau.o boatModuleIF.o main.c -o getBoatCfg

boatModuleIF.o: cnc.o beneteau.o
	gcc -c boatModuleIF.c

cnc.o: boatModuleDefs.h
	gcc -c cnc.c

beneteau.o: boatModuleDefs.h
	gcc -c beneteau.c
