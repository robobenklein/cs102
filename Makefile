.PHONY: clean All

All:
	@echo "----------Building project:[ labC - Debug ]----------"
	@cd "labC" && "$(MAKE)" -f  "labC.mk"
clean:
	@echo "----------Cleaning project:[ labC - Debug ]----------"
	@cd "labC" && "$(MAKE)" -f  "labC.mk" clean
