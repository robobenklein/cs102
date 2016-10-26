.PHONY: clean All

All:
	@echo "----------Building project:[ labI - Debug ]----------"
	@cd "labI" && "$(MAKE)" -f  "labI.mk"
clean:
	@echo "----------Cleaning project:[ labI - Debug ]----------"
	@cd "labI" && "$(MAKE)" -f  "labI.mk" clean
