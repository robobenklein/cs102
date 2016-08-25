.PHONY: clean All

All:
	@echo "----------Building project:[ conditionals-tests - Debug ]----------"
	@cd "conditionals-tests" && "$(MAKE)" -f  "conditionals-tests.mk"
clean:
	@echo "----------Cleaning project:[ conditionals-tests - Debug ]----------"
	@cd "conditionals-tests" && "$(MAKE)" -f  "conditionals-tests.mk" clean
