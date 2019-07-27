
basic: basic.cpp
	g++ -std=c++17 basic.cpp histogram.cpp `pkg-config opencv --cflags --libs`

lbp_detector: lbp_detector.cpp
	g++ -std=c++17 lbp_detector.cpp lbp.cpp `pkg-config opencv --cflags --libs`

clean:
	rm a.out
