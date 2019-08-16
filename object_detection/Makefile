
basic: basic.cpp
	g++ -std=c++17 basic.cpp histogram.cpp `pkg-config opencv --cflags --libs`

lbp_detector: lbp_detector.cpp
	g++ -std=c++17 lbp_detector.cpp lbp.cpp histogram.cpp `pkg-config opencv --cflags --libs`

webcam: webcam.cpp
	g++ -std=c++17 webcam.cpp `pkg-config opencv --cflags --libs`

candidates: candidates.cpp
	g++ -std=c++17 candidates.cpp sliding_window.cpp `pkg-config opencv --cflags --libs`

clean:
	rm a.out
