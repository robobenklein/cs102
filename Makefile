.PHONY: clean All

All:
	@echo "----------Building project:[ labF - Debug ]----------"
	@cd "labF" && "$(MAKE)" -f  "labF.mk"
clean:
	@echo "----------Cleaning project:[ labF - Debug ]----------"
	@cd "labF" && "$(MAKE)" -f  "labF.mk" clean
