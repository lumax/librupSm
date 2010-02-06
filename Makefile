PROJECT_NAME=librupSm
MAJOR=1
MINOR=0
VERSION=$(MAJOR).$(MINOR)

DEFS+=-D_GNU_SOURCE=1 -D_REENTRANT
INCLUDES+=-I$(INCLUDE_DIR)/libruputils
LIBS+=-L$(LIB_DIR)

CFLAGS = 
LDFLAGS = -lruputils

CFLAGS+=-g -c -Wall -fPIC
LDFLAGS+=-shared -Wl

OBJS = rupSm.o

EXE_ANHANG = .so.$(VERSION)

include $(MAKE_DIR)/global.mak

