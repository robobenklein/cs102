.PHONY: clean All

All:
	@echo "----------Building project:[ labJ - Debug ]----------"
	@cd "labJ" && "$(MAKE)" -f  "labJ.mk"
clean:
	@echo "----------Cleaning project:[ labJ - Debug ]----------"
	@cd "labJ" && "$(MAKE)" -f  "labJ.mk" clean
