
all: joinedModules

joinedModules: boatModule_Cnc.o boatModule_Beneteau.o boatModuleIF.o boatModuleDefs.h
	gcc boatModuleIF.o boatModule_Cnc.o boatModule_Beneteau.o main.c -o getBoatCfg

boatModuleIF.o:
	gcc -c boatModuleIF.c

boatModule_Beneteau.o: boatModule.o beneteau.o boatModuleDefs.h
	ld -r beneteau.o boatModule.o -o boatModule_Beneteau.o
	objcopy --redefine-sym printCfg=printCfg_Beneteau boatModule_Beneteau.o
	objcopy --redefine-sym init_moduleIF=init_moduleIF_Beneteau boatModule_Beneteau.o
	objcopy --redefine-sym dfltBoatCfg=dfltBoatCfg_Beneteau boatModule_Beneteau.o

boatModule_Cnc.o: boatModule.o cnc.o boatModuleDefs.h
	ld -r cnc.o boatModule.o -o boatModule_Cnc.o
	objcopy --redefine-sym printCfg=printCfg_CNC boatModule_Cnc.o
	objcopy --redefine-sym init_moduleIF=init_moduleIF_CNC boatModule_Cnc.o
	objcopy --redefine-sym dfltBoatCfg=dfltBoatCfg_CNC boatModule_Cnc.o

boatModule.o: beneteau.o cnc.o boatModuleDefs.h
	gcc -c -fPIE boatModule.c

cnc.o: boatModuleDefs.h
	gcc -c -fPIE cnc.c

beneteau.o: boatModuleDefs.h
	gcc -c -fPIE beneteau.c
