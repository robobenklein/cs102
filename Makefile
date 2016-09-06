.PHONY: clean All

All:
	@echo "----------Building project:[ labD - Debug ]----------"
	@cd "labD" && "$(MAKE)" -f  "labD.mk"
clean:
	@echo "----------Cleaning project:[ labD - Debug ]----------"
	@cd "labD" && "$(MAKE)" -f  "labD.mk" clean
