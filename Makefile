.PHONY: clean All

All:
	@echo "----------Building project:[ fileintoarray - Debug ]----------"
	@cd "fileintoarray" && "$(MAKE)" -f  "fileintoarray.mk"
clean:
	@echo "----------Cleaning project:[ fileintoarray - Debug ]----------"
	@cd "fileintoarray" && "$(MAKE)" -f  "fileintoarray.mk" clean
