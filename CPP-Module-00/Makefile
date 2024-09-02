EX00 := ex00
EX01 := ex01

MAKE := make
TARGETS := $(EX00) $(EX01)

all: $(TARGETS)

$(TARGETS):
	@$(MAKE) -C $@

clean:
	@for dir in $(TARGETS); do \
		$(MAKE) clean -C $$dir ; \
	done

fclean:
	@for dir in $(TARGETS); do \
		$(MAKE) fclean -C $$dir ; \
	done

m%:
	@$(MAKE) -C $(EX0$(@:m%=%))

c%:
	@$(MAKE) clean -C $(EX0$(@:c%=%))

f%:
	@$(MAKE) fclean -C $(EX0$(@:f%=%))

r%:
	@$(MAKE) re -C $(EX0$(@:r%=%))

re: fclean all

.PHONY: all clean fclean re $(TARGETS) m% c% f%
