
OSPL_LIBS = -lpthread -lddskernel -ldcpssacpp
LIBS = -L${OSPL_HOME}/lib ${OSPL_LIBS} -lboost_system -lboost_thread

CFLAGS=-Wall -O0 -g -I. -I./gen -I./include -I${OSPL_HOME}/include/dcps/C++/SACPP -I${OSPL_HOME}/include/sys
CXXFLAGS=-std=c++11

all: main
rebuild: clean main

IDL_GENERATED_H=\
				gen/ccpp_ubercasino.h \
				gen/ubercasinoDcps.h \
				gen/ubercasinoDcps_impl.h \
				gen/ubercasino.h \
				gen/ubercasinoSplDcps.h

IDL_GENERATED_CPP=\
				  gen/ubercasino.cpp \
				  gen/ubercasinoDcps.cpp \
				  gen/ubercasinoDcps_impl.cpp \
				  gen/ubercasinoSplDcps.cpp

IDL_GENERATED=${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
${IDL_GENERATED}: idl/ubercasino.idl
	${OSPL_HOME}/bin/idlpp -l cpp -d gen idl/ubercasino.idl

DEALER_FILES =\
			  src/card.cpp \
			  src/hand.cpp \
			  src/shoe.cpp \
			  src/dealer.cpp \
			  src/io.cpp \
			  src/dds_entity_manager.cpp \
			  src/check_status.cpp

DEALER_H_FILES =\
				src/card.h \
				src/hand.h \
				src/shoe.h \
				src/dealer.h \
				src/io.h \
				src/dds_entity_manager.h \
				src/check_status.h

main: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} src/main.cpp ${DEALER_FILES} ${DEALER_H_FILES}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

clean:
	-rm -f main
	-rm -rf gen
	-rm -f ospl-error.log ospl-info.log
