.PHONY: clean All

All:
	@echo "----------Building project:[ debugE - Debug ]----------"
	@cd "debugE" && "$(MAKE)" -f  "debugE.mk"
clean:
	@echo "----------Cleaning project:[ debugE - Debug ]----------"
	@cd "debugE" && "$(MAKE)" -f  "debugE.mk" clean
