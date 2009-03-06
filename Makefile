#############################################################################
# Makefile for building: bin/olric
# Generated by qmake (2.01a) (Qt 4.4.3) on: Cum Mar 6 10:49:26 2009
# Project:  olric.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/qt/4/mkspecs/linux-g++ -unix -o Makefile olric.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/qt/4/mkspecs/linux-g++ -I. -I/usr/qt/4/include/QtCore -I/usr/qt/4/include/QtCore -I/usr/qt/4/include/QtGui -I/usr/qt/4/include/QtGui -I/usr/qt/4/include/QtXml -I/usr/qt/4/include/QtXml -I/usr/qt/4/include -I. -Isrc -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/qt/4/lib
LIBS          = $(SUBLIBS)  -L/usr/qt/4/lib -lQtXml -L/usr/qt/4/lib -pthread -pthread -lQtGui -L/usr/X11R6/lib -pthread -lpng -lSM -lICE -pthread -pthread -lXi -lXrender -lXrandr -lfreetype -lfontconfig -lXext -lX11 -lQtCore -lz -lm -pthread -lgthread-2.0 -lrt -lglib-2.0 -ldl -lpthread
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

OBJECTS_DIR   = build/

####### Files

SOURCES       = qtc-gdbmacros/gdbmacros.cpp \
		src/AnaPencere.cpp \
		src/client.cpp \
		src/main.cpp \
		src/tool.cpp build/moc_AnaPencere.cpp \
		build/qrc_source.cpp
OBJECTS       = build/gdbmacros.o \
		build/AnaPencere.o \
		build/client.o \
		build/main.o \
		build/tool.o \
		build/moc_AnaPencere.o \
		build/qrc_source.o
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
DESTDIR       = bin/
TARGET        = bin/olric

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

$(TARGET): build/ui_anapencere.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
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
		/usr/qt/4/lib/libQtXml.prl \
		/usr/qt/4/lib/libQtCore.prl \
		/usr/qt/4/lib/libQtGui.prl
	$(QMAKE) -spec /usr/qt/4/mkspecs/linux-g++ -unix -o Makefile olric.pro
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
/usr/qt/4/lib/libQtXml.prl:
/usr/qt/4/lib/libQtCore.prl:
/usr/qt/4/lib/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/qt/4/mkspecs/linux-g++ -unix -o Makefile olric.pro

dist: 
	@$(CHK_DIR_EXISTS) build/olric1.0.0 || $(MKDIR) build/olric1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/olric1.0.0/ && $(COPY_FILE) --parents src/AnaPencere.h src/client.h src/tool.h build/olric1.0.0/ && $(COPY_FILE) --parents resources/source.qrc build/olric1.0.0/ && $(COPY_FILE) --parents qtc-gdbmacros/gdbmacros.cpp src/AnaPencere.cpp src/client.cpp src/main.cpp src/tool.cpp build/olric1.0.0/ && $(COPY_FILE) --parents ui/anapencere.ui build/olric1.0.0/ && $(COPY_FILE) --parents resources/olric_tr_TR.ts build/olric1.0.0/ && (cd `dirname build/olric1.0.0` && $(TAR) olric1.0.0.tar olric1.0.0 && $(COMPRESS) olric1.0.0.tar) && $(MOVE) `dirname build/olric1.0.0`/olric1.0.0.tar.gz . && $(DEL_FILE) -r build/olric1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_AnaPencere.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_AnaPencere.cpp
build/moc_AnaPencere.cpp: build/ui_anapencere.h \
		src/client.h \
		src/tool.h \
		src/AnaPencere.h
	/usr/qt/4/bin/moc $(DEFINES) $(INCPATH) src/AnaPencere.h -o build/moc_AnaPencere.cpp

compiler_rcc_make_all: build/qrc_source.cpp
compiler_rcc_clean:
	-$(DEL_FILE) build/qrc_source.cpp
build/qrc_source.cpp: resources/source.qrc \
		resources/olric_tr_TR.qm \
		resources/olric.xml
	/usr/qt/4/bin/rcc -name source resources/source.qrc -o build/qrc_source.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_anapencere.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_anapencere.h
build/ui_anapencere.h: ui/anapencere.ui
	/usr/qt/4/bin/uic ui/anapencere.ui -o build/ui_anapencere.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/gdbmacros.o: qtc-gdbmacros/gdbmacros.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/gdbmacros.o qtc-gdbmacros/gdbmacros.cpp

build/AnaPencere.o: src/AnaPencere.cpp src/AnaPencere.h \
		build/ui_anapencere.h \
		src/client.h \
		src/tool.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/AnaPencere.o src/AnaPencere.cpp

build/client.o: src/client.cpp src/client.h \
		src/tool.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/client.o src/client.cpp

build/main.o: src/main.cpp src/AnaPencere.h \
		build/ui_anapencere.h \
		src/client.h \
		src/tool.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/tool.o: src/tool.cpp src/tool.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/tool.o src/tool.cpp

build/moc_AnaPencere.o: build/moc_AnaPencere.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_AnaPencere.o build/moc_AnaPencere.cpp

build/qrc_source.o: build/qrc_source.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_source.o build/qrc_source.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

