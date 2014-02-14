FILE = copy1
default: clean all
all:
	mkdir -p build/
	g++ -std=c++11 -o build/$(FILE) $(FILE).cpp
	chmod +x build/$(FILE)
clean:
watch:
	while true; do while inotifywait -e close_write $(FILE).cpp; do make; done; done
