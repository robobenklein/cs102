.PHONY: clean All

All:
	@echo "----------Building project:[ debugA - Debug ]----------"
	@cd "debugA" && "$(MAKE)" -f  "debugA.mk"
clean:
	@echo "----------Cleaning project:[ debugA - Debug ]----------"
	@cd "debugA" && "$(MAKE)" -f  "debugA.mk" clean
