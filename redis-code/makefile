.PHONY:hello
.PHONY:clean
.PHONY:generate

generate:generate.cpp
	g++ -o $@ $^ -std=c++17 /usr/local/lib64/libredis++.a /usr/local/lib/libhiredis.a -pthread

hello:hello.cpp
	g++ -o $@ $^ -std=c++17 /usr/local/lib64/libredis++.a /usr/local/lib/libhiredis.a -pthread

clean:
	rm -f hello generate