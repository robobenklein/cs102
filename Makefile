.PHONY: clean All

All:
	@echo "----------Building project:[ labA - Debug ]----------"
	@cd "labA" && "$(MAKE)" -f  "labA.mk"
clean:
	@echo "----------Cleaning project:[ labA - Debug ]----------"
	@cd "labA" && "$(MAKE)" -f  "labA.mk" clean
