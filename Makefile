.PHONY: clean All

All:
	@echo "----------Building project:[ labH - Debug ]----------"
	@cd "labH" && "$(MAKE)" -f  "labH.mk"
clean:
	@echo "----------Cleaning project:[ labH - Debug ]----------"
	@cd "labH" && "$(MAKE)" -f  "labH.mk" clean
