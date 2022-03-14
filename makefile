name = faffa
fag = -Wall 
lib = -lSDL2
sur = $(wildcard source/*.cpp)
obj = $(patsubst source/%.cpp, obj/%.o, $(wildcard source/*.cpp))
dep = $(patsubst source/%.cpp, obj/%.o.d, $(wildcard source/*.cpp))

$(name): $(obj)
	@echo -n "\033[35mlinking\033[0m "
	@g++ $(obj) -o $(name) -I include  $(flag) $(lib)
	@echo "\033[32mdone\033[0m"

%.d:
	@touch $@

include $(dep)

obj/%.o: source/%.cpp
	@echo -n "\033[35mcompiling \033[34m$< \033[0m"
	@g++ -c $< -o $@ -I include  $(flag) $(lib)
	@g++ -I include -MM $< -MT '$@' > '$@.d'
	@echo "\033[32mdone\033[0m"

clean:
	@echo "\033[31mremoving objects\033[0m"
	@rm $(obj) $(dep)

remove: clean
	@echo "\033[31mremoving exe\033[0m"
	@rm $(name)
 
run: $(name)
	@echo "starting $(name):"
	@./$(name)

dir:
	@echo "creating driectory"
	@mkdir include
	@mkdir obj
	@mkdir source
	@sudo rm -R .git
	@echo "#include<iostream>\nusing namespace std;\n\nint main(int argc, char** argv)\n{\n\n}" > source/main.cpp
