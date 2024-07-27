# this file is only to run `make fclean` for all subdirectories

all:
	@echo "Nothing to do here"

fclean:
	@echo "Cleaning all subdirectories";
	@find ./*/ -type f -name 'Makefile' | while read -r makefile; do \
		dir=$$(dirname $$makefile); \
		echo "Cleaning $$dir"; \
		make -C $$(dirname $$makefile) fclean; \
	done
	@echo "Done"
