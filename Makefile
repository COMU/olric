#############################################################################
# Makefile for building: olric
# Generated by qmake (2.01a) (Qt 4.4.1) on: Cmt Eki 25 23:46:11 2008
# Project:  olric.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -unix -o Makefile olric.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/qt/4/mkspecs/linux-g++ -I. -I/usr/qt/4/include/QtCore -I/usr/qt/4/include/QtCore -I/usr/qt/4/include/QtGui -I/usr/qt/4/include/QtGui -I/usr/qt/4/include -I. -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/qt/4/lib
LIBS          = $(SUBLIBS)  -L/usr/qt/4/lib -lQtGui -L/usr/qt/4/lib -L/usr/X11R6/lib -pthread -lpng -lSM -lICE -pthread -pthread -lXi -lXrender -lXrandr -lfreetype -lfontconfig -lXext -lX11 -lQtCore -lz -lm -pthread -lgthread-2.0 -lrt -lglib-2.0 -ldl -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = AnaPencere.cpp \
		main.cpp \
		pencereclient.cpp moc_AnaPencere.cpp \
		moc_pencereclient.cpp \
		qrc_simgeler.cpp
OBJECTS       = AnaPencere.o \
		main.o \
		pencereclient.o \
		moc_AnaPencere.o \
		moc_pencereclient.o \
		qrc_simgeler.o
DIST          = /usr/qt/4/mkspecs/common/g++.conf \
		/usr/qt/4/mkspecs/common/unix.conf \
		/usr/qt/4/mkspecs/common/linux.conf \
		/usr/qt/4/mkspecs/qconfig.pri \
		/usr/qt/4/mkspecs/features/qt_functions.prf \
		/usr/qt/4/mkspecs/features/qt_config.prf \
		/usr/qt/4/mkspecs/features/exclusive_builds.prf \
		/usr/qt/4/mkspecs/features/default_pre.prf \
		/usr/qt/4/mkspecs/features/release.prf \
		/usr/qt/4/mkspecs/features/default_post.prf \
		/usr/qt/4/mkspecs/features/warn_on.prf \
		/usr/qt/4/mkspecs/features/qt.prf \
		/usr/qt/4/mkspecs/features/unix/thread.prf \
		/usr/qt/4/mkspecs/features/moc.prf \
		/usr/qt/4/mkspecs/features/resources.prf \
		/usr/qt/4/mkspecs/features/uic.prf \
		/usr/qt/4/mkspecs/features/yacc.prf \
		/usr/qt/4/mkspecs/features/lex.prf \
		olric.pro
QMAKE_TARGET  = olric
DESTDIR       = 
TARGET        = olric

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: olric.pro  /usr/qt/4/mkspecs/linux-g++/qmake.conf /usr/qt/4/mkspecs/common/g++.conf \
		/usr/qt/4/mkspecs/common/unix.conf \
		/usr/qt/4/mkspecs/common/linux.conf \
		/usr/qt/4/mkspecs/qconfig.pri \
		/usr/qt/4/mkspecs/features/qt_functions.prf \
		/usr/qt/4/mkspecs/features/qt_config.prf \
		/usr/qt/4/mkspecs/features/exclusive_builds.prf \
		/usr/qt/4/mkspecs/features/default_pre.prf \
		/usr/qt/4/mkspecs/features/release.prf \
		/usr/qt/4/mkspecs/features/default_post.prf \
		/usr/qt/4/mkspecs/features/warn_on.prf \
		/usr/qt/4/mkspecs/features/qt.prf \
		/usr/qt/4/mkspecs/features/unix/thread.prf \
		/usr/qt/4/mkspecs/features/moc.prf \
		/usr/qt/4/mkspecs/features/resources.prf \
		/usr/qt/4/mkspecs/features/uic.prf \
		/usr/qt/4/mkspecs/features/yacc.prf \
		/usr/qt/4/mkspecs/features/lex.prf \
		/usr/qt/4/lib/libQtGui.prl \
		/usr/qt/4/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile olric.pro
/usr/qt/4/mkspecs/common/g++.conf:
/usr/qt/4/mkspecs/common/unix.conf:
/usr/qt/4/mkspecs/common/linux.conf:
/usr/qt/4/mkspecs/qconfig.pri:
/usr/qt/4/mkspecs/features/qt_functions.prf:
/usr/qt/4/mkspecs/features/qt_config.prf:
/usr/qt/4/mkspecs/features/exclusive_builds.prf:
/usr/qt/4/mkspecs/features/default_pre.prf:
/usr/qt/4/mkspecs/features/release.prf:
/usr/qt/4/mkspecs/features/default_post.prf:
/usr/qt/4/mkspecs/features/warn_on.prf:
/usr/qt/4/mkspecs/features/qt.prf:
/usr/qt/4/mkspecs/features/unix/thread.prf:
/usr/qt/4/mkspecs/features/moc.prf:
/usr/qt/4/mkspecs/features/resources.prf:
/usr/qt/4/mkspecs/features/uic.prf:
/usr/qt/4/mkspecs/features/yacc.prf:
/usr/qt/4/mkspecs/features/lex.prf:
/usr/qt/4/lib/libQtGui.prl:
/usr/qt/4/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile olric.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/olric1.0.0 || $(MKDIR) .tmp/olric1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/olric1.0.0/ && $(COPY_FILE) --parents AnaPencere.h client.h pencereclient.h .tmp/olric1.0.0/ && $(COPY_FILE) --parents simgeler.qrc .tmp/olric1.0.0/ && $(COPY_FILE) --parents AnaPencere.cpp main.cpp pencereclient.cpp .tmp/olric1.0.0/ && $(COPY_FILE) --parents translations/olric_eng.ts .tmp/olric1.0.0/ && (cd `dirname .tmp/olric1.0.0` && $(TAR) olric1.0.0.tar olric1.0.0 && $(COMPRESS) olric1.0.0.tar) && $(MOVE) `dirname .tmp/olric1.0.0`/olric1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/olric1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_AnaPencere.cpp moc_pencereclient.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_AnaPencere.cpp moc_pencereclient.cpp
moc_AnaPencere.cpp: AnaPencere.h
	/usr/qt/4/bin/moc $(DEFINES) $(INCPATH) AnaPencere.h -o moc_AnaPencere.cpp

moc_pencereclient.cpp: client.h \
		pencereclient.h
	/usr/qt/4/bin/moc $(DEFINES) $(INCPATH) pencereclient.h -o moc_pencereclient.cpp

compiler_rcc_make_all: qrc_simgeler.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_simgeler.cpp
qrc_simgeler.cpp: simgeler.qrc \
		translations/olric_eng.qm \
		icons/olric.png
	/usr/qt/4/bin/rcc -name simgeler simgeler.qrc -o qrc_simgeler.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

AnaPencere.o: AnaPencere.cpp AnaPencere.h \
		pencereclient.h \
		client.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AnaPencere.o AnaPencere.cpp

main.o: main.cpp AnaPencere.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

pencereclient.o: pencereclient.cpp pencereclient.h \
		client.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pencereclient.o pencereclient.cpp

moc_AnaPencere.o: moc_AnaPencere.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AnaPencere.o moc_AnaPencere.cpp

moc_pencereclient.o: moc_pencereclient.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pencereclient.o moc_pencereclient.cpp

qrc_simgeler.o: qrc_simgeler.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_simgeler.o qrc_simgeler.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
