.PHONY: clean All

All:
	@echo "----------Building project:[ collatz - Debug ]----------"
	@cd "collatz" && "$(MAKE)" -f  "collatz.mk"
clean:
	@echo "----------Cleaning project:[ collatz - Debug ]----------"
	@cd "collatz" && "$(MAKE)" -f  "collatz.mk" clean
