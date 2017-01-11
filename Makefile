.PHONY: clean All

All:
	@echo "----------Building project:[ labJ-d - Debug ]----------"
	@cd "labJ-d" && "$(MAKE)" -f  "labJ-d.mk"
clean:
	@echo "----------Cleaning project:[ labJ-d - Debug ]----------"
	@cd "labJ-d" && "$(MAKE)" -f  "labJ-d.mk" clean
