# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  tictactoe_config = debug
endif
ifeq ($(config),release)
  tictactoe_config = release
endif

PROJECTS := tictactoe

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

tictactoe:
ifneq (,$(tictactoe_config))
	@echo "==== Building tictactoe ($(tictactoe_config)) ===="
	@${MAKE} --no-print-directory -C . -f tictactoe.make config=$(tictactoe_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f tictactoe.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   tictactoe"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"