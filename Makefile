compile:
	cd $(DAY); clang++ solve$(PART).cpp

run:
	cd $(DAY); clang++ solve$(PART).cpp; ./a.out

new:
	mkdir $(DAY)
	cp -r template/ $(DAY)/
	touch $(DAY)/example.txt
	touch $(DAY)/input.txt

next:
	cp $(DAY)/solve1.cpp $(DAY)/solve2.cpp

.PHONY: compile run new next
