# $Id:#

# 수정해야 할  변수
#  DESTDIR  : 테스팅 섹션 디렉토리
#  BINS     : 실행화일명
#  BINSRCS  : 실행화일 소스
#  run.sh   : 테스트 수행할 소스 코드

include ../tsmEnv.mk

DESTDIR = $(TSM_DIR)/tsm_parallel_logging
BINS    = tsm_readLog 
BINSRCS = tsm_readLog.cpp
RUN_SHELL= run.sh
BINOBJS = $(BINSRCS:.cpp=.$(OBJEXT))
OBJS=$(SRCS:$(DEV_DIR)/%.cpp=$(TARGET_DIR)/%.$(OBJEXT))
cmd_ld = $(LD) $(LFLAGS) $(LDOUT)$@ $^ $(TSMLIB) $(SMLIB) $(ID_LIB) $(LIBS)

all: $(COMPILE) install

compile:  $(OBJS) archive $(BINS)

install: $(BINS)
	$(RM) $(DESTDIR)
	mkdir $(DESTDIR)
	cp $(BINS) $(DESTDIR)

tsm_readLog: $(BINOBJS) $(TSMLIB) $(SMLIB) 
	$(cmd_ld)

tsmParent: $(BINOBJS) $(TSMLIB) $(SMLIB) 
	$(cmd_ld)

clean:
	$(RM) core .dependency $(BINS) *.$(OBJEXT) *.d SunWS_cache *~ ./*.*~

dep:
	-$(RM) ./.dependency
	$(CXX) $(CXXOPT_DEPENDANCY) $(INCLUDES) $(DEFINES) $(SRCS) > .dependency

ifeq (./.dependency,$(wildcard ./.dependency))
include ./.dependency
endif





