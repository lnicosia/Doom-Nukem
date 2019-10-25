# Makefile to build and install the SDL_mixer library

top_builddir = .
srcdir  = .
objects = build
prefix = /usr/local
exec_prefix = ${prefix}
bindir	= $(DESTDIR)${exec_prefix}/bin
libdir  = $(DESTDIR)${exec_prefix}/lib
includedir = $(DESTDIR)${prefix}/include
datarootdir = $(DESTDIR)${prefix}/share
datadir	= ${datarootdir}
mandir	= ${datarootdir}/man
auxdir	= ./build-scripts
distpath = $(srcdir)/..
distdir = SDL2_mixer-2.0.4
distfile = $(distdir).tar.gz


EXE	= .exe
SHELL	= /bin/sh
CC      = gcc
CFLAGS  = -g -O2 
# -mno-cygwin deleted after -I/usr/include/mingw
EXTRA_CFLAGS =  -I/usr/include/mingw -I/usr/local/include/SDL2 -I/usr/include/mingw -Dmain=SDL_main -DMUSIC_WAV -DMUSIC_MID -DMUSIC_MID_TIMIDITY -I$(srcdir)/timidity -DMUSIC_MID_NATIVE -I$(srcdir)/native_midi
LDFLAGS = 
# -mno-cygwin deleted before -L/usr/local/lib
EXTRA_LDFLAGS = -L/usr/local/lib -lcygwin -lSDL2main -lSDL2 -mwindows -lwinmm 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
INSTALL = /usr/bin/install -c
AR	= ar
RANLIB	= ranlib
WINDRES	= windres
SDL_CFLAGS = -I/usr/local/include/SDL2 -I/usr/include/mingw -Dmain=SDL_main
SDL_LIBS = -L/usr/local/lib -lcygwin -lSDL2main -lSDL2 -mwindows

TARGET  = libSDL2_mixer.la
OBJECTS = $(objects)/effect_position.lo $(objects)/effect_stereoreverse.lo $(objects)/effects_internal.lo $(objects)/load_aiff.lo $(objects)/load_voc.lo $(objects)/mixer.lo $(objects)/music.lo $(objects)/music_cmd.lo $(objects)/music_flac.lo $(objects)/music_fluidsynth.lo $(objects)/music_mad.lo $(objects)/music_mikmod.lo $(objects)/music_modplug.lo $(objects)/music_mpg123.lo $(objects)/music_nativemidi.lo $(objects)/music_ogg.lo $(objects)/music_opus.lo $(objects)/music_timidity.lo $(objects)/music_wav.lo $(objects)/common.lo $(objects)/instrum.lo $(objects)/mix.lo $(objects)/output.lo $(objects)/playmidi.lo $(objects)/readmidi.lo $(objects)/resample.lo $(objects)/tables.lo $(objects)/timidity.lo $(objects)/native_midi_common.lo $(objects)/native_midi_mac.lo $(objects)/native_midi_macosx.lo $(objects)/native_midi_win32.lo 
VERSION_OBJECTS = $(objects)/version.o
PLAYWAVE_OBJECTS = $(objects)/playwave.lo
PLAYMUS_OBJECTS = $(objects)/playmus.lo

DIST = *.txt Android.mk Makefile.in SDL2_mixer.pc.in SDL2_mixer.spec.in SDL_mixer.h VisualC VisualC-WinRT Xcode Xcode-iOS acinclude aclocal.m4 autogen.sh build-scripts configure configure.in debian effect_position.c effect_stereoreverse.c effects_internal.c effects_internal.h external gcc-fat.sh load_aiff.c load_aiff.h load_voc.c load_voc.h mixer.c mixer.h music.c music.h music_cmd.c music_cmd.h music_flac.c music_flac.h music_fluidsynth.c music_fluidsynth.h music_mad.c music_mad.h music_mikmod.c music_mikmod.h music_modplug.c music_modplug.h music_mpg123.c music_mpg123.h music_nativemidi.c music_nativemidi.h music_ogg.c music_ogg.h music_opus.c music_opus.h music_timidity.c music_timidity.h music_wav.c music_wav.h native_midi playmus.c playwave.c timidity version.rc

LT_AGE      = 2
LT_CURRENT  = 2
LT_RELEASE  = 2.0
LT_REVISION = 2
LT_LDFLAGS  = -no-undefined -rpath $(libdir) -release $(LT_RELEASE) -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

all: $(srcdir)/configure Makefile $(objects) $(objects)/$(TARGET) $(objects)/playwave$(EXE) $(objects)/playmus$(EXE)

$(srcdir)/configure: $(srcdir)/configure.in
	@echo "Warning, configure.in is out of date"
	#(cd $(srcdir) && sh autogen.sh && sh configure)
	@sleep 3

Makefile: $(srcdir)/Makefile.in
	$(SHELL) config.status $@

$(objects):
	$(SHELL) $(auxdir)/mkinstalldirs $@

.PHONY: all install install-hdrs install-lib install-bin uninstall uninstall-hdrs uninstall-lib uninstall-bin clean distclean dist

$(objects)/$(TARGET): $(OBJECTS) $(VERSION_OBJECTS)
	$(LIBTOOL) --mode=link $(CC) -o $@ $(OBJECTS) $(VERSION_OBJECTS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(LT_LDFLAGS)

$(objects)/playwave$(EXE): $(objects)/playwave.lo $(objects)/$(TARGET)
	$(LIBTOOL) --mode=link $(CC) -o $@ $(objects)/playwave.lo $(SDL_CFLAGS) $(objects)/$(TARGET) $(SDL_LIBS) $(LDFLAGS)

$(objects)/playmus$(EXE): $(objects)/playmus.lo $(objects)/$(TARGET)
	$(LIBTOOL) --mode=link $(CC) -o $@ $(objects)/playmus.lo $(SDL_CFLAGS) $(objects)/$(TARGET) $(SDL_LIBS) $(LDFLAGS)

install: all install-hdrs install-lib #install-bin
install-hdrs:
	$(SHELL) $(auxdir)/mkinstalldirs $(includedir)/SDL2
	for src in $(srcdir)/SDL_mixer.h; do \
	    file=`echo $$src | sed -e 's|^.*/||'`; \
	    $(INSTALL) -m 644 $$src $(includedir)/SDL2/$$file; \
	done
	$(SHELL) $(auxdir)/mkinstalldirs $(libdir)/pkgconfig
	$(INSTALL) -m 644 SDL2_mixer.pc $(libdir)/pkgconfig/
install-lib: $(objects) $(objects)/$(TARGET)
	$(SHELL) $(auxdir)/mkinstalldirs $(libdir)
	$(LIBTOOL) --mode=install $(INSTALL) $(objects)/$(TARGET) $(libdir)/$(TARGET)
install-bin:
	$(SHELL) $(auxdir)/mkinstalldirs $(bindir)
	$(LIBTOOL) --mode=install $(INSTALL) -m 755 $(objects)/playwave$(EXE) $(bindir)/playwave$(EXE)
	$(LIBTOOL) --mode=install $(INSTALL) -m 755 $(objects)/playmus$(EXE) $(bindir)/playmus$(EXE)

uninstall: uninstall-hdrs uninstall-lib uninstall-bin
uninstall-hdrs:
	for src in $(srcdir)/SDL_mixer.h; do \
	    file=`echo $$src | sed -e 's|^.*/||'`; \
	    rm -f $(includedir)/SDL2/$$file; \
	done
	-rmdir $(includedir)/SDL2
	rm -f $(libdir)/pkgconfig/SDL2_mixer.pc
	-rmdir $(libdir)/pkgconfig
uninstall-lib:
	$(LIBTOOL) --mode=uninstall rm -f $(libdir)/$(TARGET)
uninstall-bin:
	rm -f $(bindir)/playwave$(EXE)
	rm -f $(bindir)/playmus$(EXE)

clean:
	rm -rf $(objects)

distclean: clean
	rm -f Makefile
	rm -f config.status config.cache config.log libtool
	rm -f SDL2_mixer.pc
	rm -rf $(srcdir)/autom4te*
	find $(srcdir) \( \
	    -name '*~' -o \
	    -name '*.bak' -o \
	    -name '*.old' -o \
	    -name '*.rej' -o \
	    -name '*.orig' -o \
	    -name '.#*' \) \
	    -exec rm -f {} \;

dist $(distfile):
	$(SHELL) $(auxdir)/mkinstalldirs $(distdir)
	(cd $(srcdir); tar cf - $(DIST)) | (cd $(distdir); tar xf -)
	rm -rf `find $(distdir) -name .svn`
	rm -f `find $(distdir) -name '.#*'`
	tar cvf - $(distdir) | gzip --best >$(distfile)
	rm -rf $(distdir)

rpm: $(distfile)
	rpmbuild -ta $?

# Build rules for objects
-include $(OBJECTS:.lo=.d)

$(objects)/effect_position.lo: ./effect_position.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/effect_stereoreverse.lo: ./effect_stereoreverse.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/effects_internal.lo: ./effects_internal.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/load_aiff.lo: ./load_aiff.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/load_voc.lo: ./load_voc.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/mixer.lo: ./mixer.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music.lo: ./music.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_cmd.lo: ./music_cmd.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_flac.lo: ./music_flac.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_fluidsynth.lo: ./music_fluidsynth.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_mad.lo: ./music_mad.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_mikmod.lo: ./music_mikmod.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_modplug.lo: ./music_modplug.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_mpg123.lo: ./music_mpg123.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_nativemidi.lo: ./music_nativemidi.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_ogg.lo: ./music_ogg.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_opus.lo: ./music_opus.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_timidity.lo: ./music_timidity.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/music_wav.lo: ./music_wav.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/common.lo: ./timidity/common.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/instrum.lo: ./timidity/instrum.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/mix.lo: ./timidity/mix.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/output.lo: ./timidity/output.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/playmidi.lo: ./timidity/playmidi.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/readmidi.lo: ./timidity/readmidi.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/resample.lo: ./timidity/resample.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/tables.lo: ./timidity/tables.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/timidity.lo: ./timidity/timidity.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/native_midi_common.lo: ./native_midi/native_midi_common.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/native_midi_mac.lo: ./native_midi/native_midi_mac.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/native_midi_macosx.lo: ./native_midi/native_midi_macosx.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 
$(objects)/native_midi_win32.lo: ./native_midi/native_midi_win32.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@ 

$(objects)/version.o: ./version.rc
	$(WINDRES) $< $@

-include $(PLAYWAVE_OBJECTS:.lo=.d)

$(objects)/playwave.lo: ./playwave.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@

-include $(PLAYMUS_OBJECTS:.lo=.d)

$(objects)/playmus.lo: ./playmus.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(EXTRA_CFLAGS)  -c $< -o $@
