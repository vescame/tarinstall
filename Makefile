CXX:=g++
CXXFLAGS:=-Wall -Wextra -Werror -Wpedantic -std=c++17
LDFLAGS:=-Lm -lstdc++fs -larchive

incdir=include
srcdir=src
libdir=lib
bindir=bin

args_src=$(wildcard $(srcdir)/args/*.cpp)
args_obj=$(patsubst $(srcdir)/args/%.cpp, $(libdir)/%.o, $(args_src))

logging_src=$(wildcard $(srcdir)/logging/*.cpp)
logging_obj=$(patsubst $(srcdir)/logging/%.cpp, $(libdir)/%.o, $(logging_src))

files_copy_src:=$(wildcard $(srcdir)/files/copy.cpp)
files_copy_obj:=$(patsubst $(srcdir)/files/%.cpp, $(libdir)/%.o, $(files_copy_src))

files_extract_src:=$(wildcard $(srcdir)/files/extract_tar.cpp)
files_extract_obj:=$(patsubst $(srcdir)/files/%.cpp, $(libdir)/%.o, $(files_extract_src))

pointers_src:=$(wildcard $(srcdir)/pointers/*.cpp)
pointers_obj:=$(patsubst $(srcdir)/pointers/%.cpp, $(libdir)/%.o, $(pointers_src))

libs:=$(pointers_obj) $(args_obj) $(logging_obj) $(files_extract_obj) $(files_copy_obj)

main=$(srcdir)/main.cpp

target=$(bindir)/tarinstall

ifdef DEBUG
	CXXFLAGS+=-g
endif

ifdef EXTRAFLAGS
	CXXFLAGS+=$(EXTRAFLAGS)
endif

ifdef VERBOSE
	rmcmd:=@ rm -vr
	mkdircmd:=@ mkdir -v
else
	CXX:=@ $(CXX)
	rmcmd=@ rm -r
	mkdircmd:=@ mkdir
endif

all: $(libdir) $(bindir) $(target)

$(target): $(main) $(libs)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS)
 
$(args_obj): $(args_src)
	$(CXX) -c -o $@ $^ -Iinclude/args $(CXXFLAGS)

$(logging_obj): $(logging_src)
	$(CXX) -c -o $@ $^ -Iinclude/logging $(CXXFLAGS)

$(files_copy_obj): $(files_copy_src)
	$(CXX) -c -o $@ $^ -Iinclude/files $(CXXFLAGS)

$(files_extract_obj): $(files_extract_src)
	$(CXX) -c -o $@ $^ -Iinclude/files $(CXXFLAGS)

$(pointers_obj): $(pointers_src)
	$(CXX) -c -o $@ $^ -Iinclude/pointers $(CXXFLAGS)

$(libdir):
	$(mkdircmd) $@

$(bindir):
	$(mkdircmd) $@

.PHONY: clean

clean: $(libdir) $(bindir)
	$(rmcmd) $^

