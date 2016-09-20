.PHONY: clean All

All:
	@echo "----------Building project:[ labE - Debug ]----------"
	@cd "labE" && "$(MAKE)" -f  "labE.mk"
clean:
	@echo "----------Cleaning project:[ labE - Debug ]----------"
	@cd "labE" && "$(MAKE)" -f  "labE.mk" clean
